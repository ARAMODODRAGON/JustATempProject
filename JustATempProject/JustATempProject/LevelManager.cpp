#include "LevelManager.h"
#include "TestLevel0.h"
#include <stdio.h>

LevelManager* LevelManager::Singleton = nullptr;

LevelManager::LevelManager() : level(nullptr), levelToLoad(LevelID::none) {
	if(Singleton == nullptr) Singleton = this;
}

LevelManager::~LevelManager() {
	if(Singleton == this) Singleton = nullptr;
}

int LevelManager::Init(LevelID levelID) {
	levelToLoad = levelID;
	CheckForAndLoadLevel();
	return 0;
}

void LevelManager::UpdateLevel(const float delta) {
	if(level != nullptr) level->Update(delta);
}

void LevelManager::CheckForAndLoadLevel() {
	// check the level to load
	switch(levelToLoad) {
		case LevelID::none: return;
		case LevelID::testlevel0:
			// destroy old level
			if(level != nullptr) {
				level->Exit();
				delete level;
			}
			// load new level and init
			printf("[Loaded Level]: \"TestLevel0\"\n\n");
			level = new TestLevel0();
			level->Init();
			break;
		case LevelID::testlevel1:
			return; // TODO: add test level 1
			break;
		case LevelID::testlevel2:
			return; // TODO: add test level 2
			break;
		default: return;
	}
	// if loaded then set level to load to none
	levelToLoad = LevelID::none;
}

int LevelManager::Exit() {
	return 0;
}

void LevelManager::LoadLevel(LevelID levelToLoad) {
	Singleton->levelToLoad = levelToLoad;
}
