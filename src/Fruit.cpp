#include "Fruit.h"
#include "Quad.h"
Fruit::Fruit(glm::fvec3 pos):gfx(0)
{
	gfx = new Quad();
	gfx->SetScale(glm::fvec3(10));
	SetPosition(pos);
}

void Fruit::Update(float dT)
{
	
}

void Fruit::Render(Shader& shaderProgram)
{
	gfx->Render(shaderProgram);
}

void Fruit::SetPosition(glm::fvec3 pos)
{
	GameObject::SetPosition(pos);
	gfx->SetPosition(pos);
}
