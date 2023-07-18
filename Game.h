#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader;
class Game
{
public:
	Game();
	bool Init();
	void Run();
	void Exit();

	GLFWwindow* GetWindow() { return window; }

private:
	static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void Update();
	void Render();

	GLFWwindow* window;
	Shader* shader;

	
};

