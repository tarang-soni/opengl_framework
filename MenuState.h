#pragma once
#include "BaseState.h"
class MenuState :
    public BaseState
{
	void EnterState() override;
	void ExitState() override;
	virtual void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods) override;

	virtual void Update(float) override;
	virtual void Render(Shader& shader) override;
};

