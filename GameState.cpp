#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include <iostream>
void GameState::EnterState()
{
	std::cout << "Entered Game State" << std::endl;
}

void GameState::ExitState()
{
	std::cout << "Exiting Game State" << std::endl;
}

void GameState::HandleInput(GLFWwindow& window)
{
	//GameStateManager::GetInstance()->ChangeState(new MenuState());

}

void GameState::Update()
{
}

void GameState::Render()
{
}
