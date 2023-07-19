#include "Snake.h"
#include "Shader.h"
#include "SnakeBody.h"
Snake::Snake()
{
	_scale = glm::fvec3(20,20,1);
	quad = new SnakeBody(glm::fvec3(0));
	snakeBody.push_back(quad);
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
	NewNode(glm::fvec3(0));
}

void Snake::SetPosition(glm::fvec3 _pos)
{
	quad->_lastPosition = quad->GetPosition();
	quad->SetPosition(_pos);
	for (int i = 0; i < snakeBody.size()-1; i++)
	{
		snakeBody[i + 1]->_lastPosition = snakeBody[i + 1]->GetPosition();
		snakeBody[i+1]->SetPosition(snakeBody[i]->_lastPosition);
	}
}

void Snake::NewNode(glm::fvec3 pos)
{
	auto s = new SnakeBody(pos);
	s->SetScale(_scale);
	snakeBody.push_back(s);

}


glm::fvec3 Snake::GetScale()
{
	return _scale;
}

void Snake::SetScale(glm::fvec3 scale)
{
	_scale = scale;
	for (auto& body : snakeBody)
	{
		body->SetScale(scale);
	}
}

void Snake::Update(float dT)
{
	for (auto& body : snakeBody) {
		body->Update(dT);
	}
}

void Snake::Render(Shader& shaderProgram)
{
	for (auto& body : snakeBody) {
		body->Render(shaderProgram);
	}
}
