#pragma once
#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader;
class GameObject
{
public:

	virtual void Update(float dT) = 0;
	virtual void Render(Shader& shaderProgram) = 0;
	virtual void SetPosition(glm::fvec3 pos) { _position = pos; }
	virtual void SetScale(glm::fvec3 scale) { _scale = scale; }
	virtual glm::fvec3 GetScale() { return _scale; }
	virtual glm::fvec3 GetPosition() { return _position; }


protected:
	glm::fvec3 _position;
	glm::fvec3 _scale;
};

