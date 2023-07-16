#pragma once
#include <glad/glad.h>
#include <string>
class Shader
{
public:
	Shader(const char* fPath,const char* vPath);
	GLuint ID;

	void Bind() { glUseProgram(ID); }
	void Unbind() { glUseProgram(0); }
	
private:
	std::string ReadFile(const char* path);
};

