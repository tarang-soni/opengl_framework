#pragma once
class BaseState;
class GameStateManager
{
public:
	static GameStateManager* GetInstance() {
		if (instance == nullptr) {
			instance = new GameStateManager();
		}
		return instance;
	}
	void ChangeState(BaseState* state);
	
	BaseState& GetCurrentState() { return *currentState; }

private:
	GameStateManager() :currentState(0)
	{

	}
	static GameStateManager* instance;
	BaseState* currentState;
};

