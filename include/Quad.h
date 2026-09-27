#pragma once

#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader;
class Quad
{
public:
	Quad();

	void Render(Shader& shaderProgram);
	void SetPosition(glm::fvec3 pos) { _position = pos; }
	void SetScale(glm::fvec3 scale) { _scale = scale; }
	glm::fvec3 GetScale() { return _scale; }
	glm::fvec3 GetPosition() { return _position; }

	void Bind();
	void Unbind();
	//void SetRotation(glm::fvec3 rot) { _rotation = rot; }
protected:
	unsigned int VAO;
	glm::fvec3 _position;
	glm::fvec3 _scale;


};

