#pragma once
#include "BaseState.h"
class Quad;
class GameState :
    public BaseState
{

	void EnterState() override;
	void ExitState() override;
	virtual void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods) override;

	virtual void Update() override;
	virtual void Render(Shader& shader) override;
private:

	Quad* quad;
};

