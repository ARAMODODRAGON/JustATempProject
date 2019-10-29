#include "TestLevel0.h"
#include "ObjectFactory.h"
#include "Player.h"
#include "LevelManager.h"
#include "Game.h"
#include <stdio.h>

int TestLevel0::Init() {
	printf("[Test]: Rigidbody on player with an acceleration set to {0, -9.8, 0} for 10 seconds\n");
	timer = 0.0f;
	// create player and add to factory
	player = new Player("Player1");
	player->Init();
	ObjectFactory::AddGameObject(player);

	return 0;
}

void TestLevel0::Update(const float delta) {
	timer += delta;

	if(timer > 10.0f) {
		//printf("[End Test]: Now loading next test\n\n");
		//LevelManager::LoadLevel(LevelID::testlevel1);
		printf("[End Test]: Now exiting (press enter) \n\n");
		Game::ExitGame();
	}
}

void TestLevel0::Render() {}

int TestLevel0::Exit() {
	// destroy all objects from factory
	ObjectFactory::DestroyAllGameObjects();

	return 0;
}
