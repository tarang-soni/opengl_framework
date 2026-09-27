#pragma once

#include <string>
class Shader
{
public:
	Shader(const char* fPath,const char* vPath);
	unsigned int ID;

	void Bind();
	void Unbind();
	
private:
	std::string ReadFile(const char* path);
};

