#pragma once
#include "BaseState.h"
#include <glm/glm.hpp>
class Fruit;
class Snake;
class GameState :
    public BaseState
{

	void EnterState() override;
	void ExitState() override;
	virtual void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods) override;

	virtual void Update(float) override;
	virtual void Render(Shader& shader) override;
private:
	void SpawnFruit();

	glm::fvec3 moveDir;
	glm::fvec3 movePosition;
	float moveStep;
	float moveInterval;
	float currentInterval;
	Snake* snake;
	Fruit* fruit;
};

