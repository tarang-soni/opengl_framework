#include "Game.h"
#include <iostream>
#include "GameStateManager.h"
#include "MenuState.h"
#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Utilities.h"
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
Game::Game():window(0),shader(0)
{

}

bool Game::Init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    GameStateManager::GetInstance()->ChangeState(new MenuState());
    glfwSetKeyCallback(window, KeyboardCallback);
    return true;
}

void Game::Run()
{
    double currentFrame = glfwGetTime(),deltaTime,lastFrame = currentFrame;
    
    shader = new Shader("default.vert","default.frag");
    while (!glfwWindowShouldClose(window))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Update(deltaTime);
        Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}

void Game::Exit()
{
    glfwDestroyWindow(window);
}
//TODO: @tarang-soni please fix keyboard events

void Game::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    GameStateManager::GetInstance()->GetCurrentState().HandleInput( window,  key,  scancode, action, mods);
}

void Game::Update(float dT)
{
    GameStateManager::GetInstance()->GetCurrentState().Update(dT);
}

void Game::Render()
{

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->Bind();
    glm::mat4 view = glm::mat4(1.f);
    view = glm::translate(view, glm::vec3(0,0,-3.f));
    float sWidthNew = SCREEN_WIDTH;
    float sHeightNew = SCREEN_HEIGHT;
    glm::mat4 proj = glm::ortho(-(sWidthNew / 2.0f), sWidthNew / 2.0f, -(sHeightNew / 2.0f), (sHeightNew / 2.0f), 0.1f, 1000.0f);
    GLuint transformLoc = glGetUniformLocation(shader->ID, "view");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(view));

    transformLoc = glGetUniformLocation(shader->ID, "projection");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(proj));
    //glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    GameStateManager::GetInstance()->GetCurrentState().Render(*shader);
    shader->Unbind();
}
