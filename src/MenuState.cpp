#include "MenuState.h"
#include <iostream>
#include "GameStateManager.h"
#include "GameState.h"
#include "Shader.h"
void MenuState::EnterState()
{
	std::cout << "Entered Menu State"<<std::endl;
}

void MenuState::ExitState()
{
	std::cout << "Exiting Menu State"<<std::endl;
}

void MenuState::HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE&& action == GLFW_PRESS)
		GameStateManager::GetInstance()->ChangeState(new GameState());
}

void MenuState::Update(float dT)
{
}

void MenuState::Render(Shader& shader)
{
}
