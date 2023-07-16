#include "Game.h"
#include <iostream>
#include "GameStateManager.h"
#include "MenuState.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
Game::Game():window(0),quad(0),shader(0)
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
    quad = new Quad();
    GameStateManager::GetInstance()->ChangeState(new MenuState());

    return true;
}

void Game::Run()
{
    shader = new Shader("default.vert","default.frag");
    while (!glfwWindowShouldClose(window))
    {

        Update();
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
void Game::HandleInput()//create keyboard events as events only
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    GameStateManager::GetInstance()->GetCurrentState().HandleInput(*window);
}

void Game::Update()
{
    GameStateManager::GetInstance()->GetCurrentState().Update();
}

void Game::Render()
{
    GameStateManager::GetInstance()->GetCurrentState().Render();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->Bind();
    glm::mat4 view = glm::mat4(1.f);
    view = glm::translate(view, glm::vec3(0.f, 0.f, -30.f));

    glm::mat4 proj = glm::ortho(-16.0f, +16.0f, -12.f, +12.f, 0.1f, 100.0f);
    GLuint transformLoc = glGetUniformLocation(shader->ID, "view");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(view));

    transformLoc = glGetUniformLocation(shader->ID, "projection");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(proj));
    //glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    quad->Render(*shader);
    shader->Unbind();
}
