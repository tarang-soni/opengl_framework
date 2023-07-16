#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Quad.h"
#include "Shader.h"
class Game
{
public:
	Game();
	bool Init();
	void Run();
	void Exit();

	GLFWwindow* GetWindow() { return window; }

private:
	void HandleInput();
	void Update();
	void Render();

	GLFWwindow* window;
	Shader* shader;
	Quad* quad;
	
};

