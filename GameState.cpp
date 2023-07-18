#include <iostream>
#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include "Shader.h"

#include "Quad.h"
void GameState::EnterState()
{
	std::cout << "Entered Game State" << std::endl;
	quad = new Quad();
}

void GameState::ExitState()
{
	std::cout << "Exiting Game State" << std::endl;
}

void GameState::HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		GameStateManager::GetInstance()->ChangeState(new MenuState());

}

void GameState::Update()
{
}

void GameState::Render(Shader& shader)
{
	quad->Render(shader);
}
