#include "GameStateManager.h"
#include "BaseState.h"
GameStateManager* GameStateManager::instance = nullptr;
void GameStateManager::ChangeState(BaseState* state)
{
	if (currentState == state) return;
	if (currentState != nullptr) {
		currentState->ExitState();
		currentState = nullptr;
	}
	currentState = state;
	if (currentState != nullptr) {
		currentState->EnterState();
	}
}
