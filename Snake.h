#pragma once
#include <glm/glm.hpp>
#include "Quad.h"
#include <vector>
class SnakeBody;
class Snake
{
public:
	Snake();
	
	void SetPosition(glm::fvec3 _pos);
	void NewNode(glm::fvec3 pos);
	glm::fvec3 GetScale();
	void SetScale(glm::fvec3);
	void Update(float dT);
	void Render(Shader& shaderProgram);
private:

	SnakeBody *quad;
	std::vector<SnakeBody*> snakeBody;
	glm::fvec3 _scale;

	
};

