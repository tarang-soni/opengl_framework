#include <iostream>
#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include "Shader.h"
#include "Utilities.h"
#include "Snake.h"
#include "Quad.h"
#include "Fruit.h"
void GameState::EnterState()
{
	std::cout << "Entered Game State" << std::endl;
	snake = new Snake();
	moveStep = 20.f;
	std::cout << snake->GetScale().x / 2;
	movePosition = glm::vec3(snake->GetScale().x / 2, snake->GetScale().y / 2, 0);
	snake->SetPosition(movePosition);
	moveDir = glm::vec3(0,0,0);
	moveInterval = 0.1f;
	currentInterval = 0;
	srand(glfwGetTime());
	fruit = new Fruit(glm::fvec3(100+ snake->GetScale().x / 2,100+ snake->GetScale().y / 2,0));

}

void GameState::ExitState()
{
	std::cout << "Exiting Game State" << std::endl;
}

void GameState::HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		GameStateManager::GetInstance()->ChangeState(new MenuState());

	if (action == GLFW_PRESS) {

		switch (key)
		{
			case GLFW_KEY_W:
				moveDir = glm::vec3(0, 1, 0);
				break;
			case GLFW_KEY_S:
				moveDir = glm::vec3(0, -1, 0);

				break;
			case GLFW_KEY_A:
				moveDir = glm::vec3(-1, 0, 0);
				break;
			case GLFW_KEY_D:
				moveDir = glm::vec3(1, 0, 0);
				break;
		}

	}
	if (action == GLFW_RELEASE) {
		switch (key)
		{
		case GLFW_KEY_W:
			break;
		case GLFW_KEY_S:
			break;
		case GLFW_KEY_A:
			break;
		case GLFW_KEY_D:
			break;
		}
	}

}

void GameState::Update(float dT)
{
	currentInterval += dT;
	if (currentInterval >= moveInterval) {
		currentInterval = 0;
		movePosition += moveDir * moveStep;
		snake->SetPosition(movePosition);
		SpawnFruit();
	}

	if (movePosition.x > 400.f) {
		movePosition.x = -400.f + snake->GetScale().x/2.f;
	}
	else if(movePosition.x<-400.f){
		movePosition.x = 400.f-snake->GetScale().x / 2.f;
	}
	if (movePosition.y > 300.f) {
		movePosition.y = -300.f+ snake->GetScale().y / 2.f;
	}
	else if(movePosition.y< -300.f){
		movePosition.y = 300- snake->GetScale().y / 2.f;
	}
	snake->Update(dT);

}

void GameState::Render(Shader& shader)
{
	snake->Render(shader);
	if (fruit) {
		fruit->Render(shader);
	}
}

void GameState::SpawnFruit()
{

	int randomX = rand() % SCREEN_WIDTH - SCREEN_WIDTH / 2;
	glm::clamp(randomX, -SCREEN_WIDTH/2+(int)snake->GetScale().x/2, SCREEN_WIDTH / 2 - (int)snake->GetScale().x / 2);
	int randomY = rand() % SCREEN_HEIGHT -SCREEN_HEIGHT/2;
	glm::clamp(randomX, -SCREEN_HEIGHT/2+(int)snake->GetScale().y/2, SCREEN_HEIGHT / 2 - (int)snake->GetScale().y / 2);

	std::cout << randomX << " " << randomY << std::endl;
	fruit->SetPosition(glm::fvec3(randomX + snake->GetScale().x / 2, randomY+ snake->GetScale().y / 2, 0));
}
