#include "MenuState.h"
#include <iostream>
#include "GameStateManager.h"
#include "GameState.h"
void MenuState::EnterState()
{
	std::cout << "Entered Menu State"<<std::endl;
}

void MenuState::ExitState()
{
	std::cout << "Exiting Menu State"<<std::endl;
}

void MenuState::HandleInput(GLFWwindow& window)
{
	//GameStateManager::GetInstance()->ChangeState(new GameState());
}

void MenuState::Update()
{
}

void MenuState::Render()
{
}
