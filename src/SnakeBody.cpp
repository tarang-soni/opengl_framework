#include "SnakeBody.h"
#include "Quad.h"
SnakeBody::SnakeBody(glm::fvec3 pos):gfx(0)
{	
	_lastPosition = glm::fvec3(0);
	gfx = new Quad();
	SetPosition(pos);
	
}

void SnakeBody::Update(float dT)
{
	gfx->SetPosition(_position);
}

void SnakeBody::Render(Shader& shaderProgram)
{
	gfx->Render(shaderProgram);
}

void SnakeBody::SetPosition(glm::fvec3 pos)
{
	GameObject::SetPosition(pos);
	gfx->SetPosition(pos);
}

void SnakeBody::SetScale(glm::fvec3 scale)
{
	_scale = scale;
	gfx->SetScale(scale);
}
