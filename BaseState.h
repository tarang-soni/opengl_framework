#pragma once
#include <GLFW/glfw3.h>
class BaseState
{
public:
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void HandleInput(GLFWwindow& window) = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;
};

