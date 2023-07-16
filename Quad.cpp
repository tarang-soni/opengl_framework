#include "Quad.h"
#include "Shader.h"

//TODO:
//Shader parser
//vao vbo setup

float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
	 -0.5f,  0.5f, 0.0f,
};
unsigned int indices[]={
	0,1,2,
	0,2,3
};
Quad::Quad():_position(glm::fvec3(0))
{
	GLuint VBO, EBO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Quad::Update()
{
}

void Quad::Render(Shader& shaderProgram)
{
	
	
	
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position); //rotation and scale under construction
	GLuint transformLoc = glGetUniformLocation(shaderProgram.ID, "model");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model));

	
	Bind();
	glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT,0);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	Unbind();
}

void Quad::Bind()
{
	glBindVertexArray(VAO);
}

void Quad::Unbind()
{
	glBindVertexArray(0);
}
