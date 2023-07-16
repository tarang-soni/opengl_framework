#pragma once
#include "BaseState.h"
class MenuState :
    public BaseState
{
	void EnterState() override;
	void ExitState() override;
	virtual void HandleInput(GLFWwindow& window) override;

	virtual void Update() override;
	virtual void Render() override;
};

