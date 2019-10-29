#include "Game.h"
#include "Time.h"
#include "ObjectFactory.h"

Game::Game() : time(nullptr), objectFactory(nullptr) {}

Game::~Game() {}

int Game::Init() {
	// create time class
	time = new Time();
	// create object factory
	objectFactory = new ObjectFactory();

	return 0;
}

void Game::Run() {

	// Game Loop
	while(true) {

		
	}
}

int Game::Exit() {
	// delete time pointer
	delete time, time = nullptr;
	// exit and delete objectfactory
	objectFactory->Exit();
	delete objectFactory, objectFactory = nullptr;
	return 0;
}
