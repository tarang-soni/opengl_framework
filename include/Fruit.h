#pragma once
#include "GameObject.h"
class Quad;
class Fruit :
    public GameObject
{
public:
    Fruit(glm::fvec3 pos);

    void Update(float dT) override;
    void Render(Shader& shaderProgram) override;
    void SetPosition(glm::fvec3 pos) override;
    glm::fvec3 _lastPosition;


private:
    Quad* gfx;
};

