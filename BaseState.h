#pragma once
#include <GLFW/glfw3.h>
class Shader;
class BaseState
{
public:
	virtual void EnterState() = 0;
	virtual void ExitState() = 0;
	virtual void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;

	virtual void Update() = 0;
	virtual void Render(Shader& shader) = 0;
};

