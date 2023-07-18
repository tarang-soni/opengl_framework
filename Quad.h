#pragma once

#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader;
class Quad
{
public:
	Quad();
	void Update();
	void Render(Shader& shaderProgram);
	void Bind();
	void Unbind();
	void SetPosition(glm::fvec3 pos) { _position = pos; }
	//void SetRotation(glm::fvec3 rot) { _rotation = rot; }
	//void SetScale(glm::fvec3 scale) { _scale = scale; }

private:
	unsigned int VAO;
	glm::fvec3 _position;


};

