#include "Game.h"
#include "Time.h"
#include "ObjectFactory.h"
#include "LevelManager.h"

Game* Game::Singleton = nullptr;

Game::Game() : time(nullptr), objectFactory(nullptr), levelManager(nullptr), rungame(true) {}

Game::~Game() {}

int Game::Init() {
	// set singleton
	if(Singleton == nullptr) Singleton = this;
	// the result from init on objects
	int result = 0;
	// create time class
	time = new Time();
	// create object factory
	objectFactory = new ObjectFactory();
	result = objectFactory->Init();
	if(result != 0) {
		printf("[Error: objectfactory]");
		return result;
	}
	result = 0;
	// create level manager after object factory
	levelManager = new LevelManager();
	result = levelManager->Init(LevelID::testlevel0);
	if(result != 0) {
		printf("[Error: levelmanager]");
		return result;
	}
	return 0;
}

void Game::Run() {

	// Game Loop
	while(rungame) {
		// get time
		time->UpdateTime();

		// first, update the object factory
		objectFactory->UpdateObjects(time->GetDeltaFloat());

		// second, update level
		levelManager->UpdateLevel(time->GetDeltaFloat());

		// then test for next level
		levelManager->CheckForAndLoadLevel();

		// set the current duration to the last one
		time->SetLastTime();
	}
}

void Game::ExitGame() {
	Singleton->rungame = false;
}

int Game::Exit() {
	// remove singleton
	if(Singleton == this) Singleton = nullptr;
	// delete time pointer
	delete time, time = nullptr;
	// exit and delete objectfactory
	objectFactory->Exit();
	delete objectFactory, objectFactory = nullptr;
	// exit and delete levelmanager
	levelManager->Exit();
	delete levelManager, levelManager = nullptr;
	return 0;
}
