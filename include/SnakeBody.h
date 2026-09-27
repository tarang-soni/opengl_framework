#pragma once
#include "GameObject.h"
class Quad;
class SnakeBody :
    public GameObject
{
public:
    SnakeBody(glm::fvec3 pos);

    void Update(float dT) override;
    void Render(Shader& shaderProgram) override;
    void SetPosition(glm::fvec3 pos) override;
    void SetScale(glm::fvec3 scale) override;
    glm::fvec3 _lastPosition;

private:
    Quad* gfx;
};

