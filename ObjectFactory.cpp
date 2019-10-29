#include "ObjectFactory.h"

ObjectFactory* ObjectFactory::Singleton = nullptr;

ObjectFactory::ObjectFactory() {
	objects = std::vector<GameObject*>();
}

ObjectFactory::~ObjectFactory() {}

int ObjectFactory::Init() {
	// Init all objects (if there is any)
	for(unsigned int i = 0; i < objects.size(); i++) {
		objects[i]->Init();
	}
	return 0;
}

void ObjectFactory::UpdateObjects(const float delta) {
	for(unsigned int i = 0; i < objects.size(); i++) {
		objects[i]->Update(delta);
	}
}

int ObjectFactory::Exit() {
	// delete all objects
	for(unsigned int i = 0; i < objects.size(); i++) {
		objects[i]->Exit();
		delete objects[i];
	}
	// clear object array
	objects.clear();
	return 0;
}

GameObject* ObjectFactory::CreateGameObject(std::string name) {
	// create generic gameobject
	GameObject* gameobject = new GameObject(name);
	// add object to list
	Singleton->objects.push_back(gameobject);
	// return object
	return gameobject;
}

void ObjectFactory::AddGameObject(GameObject* gameobject) {
	Singleton->objects.push_back(gameobject);
}

bool ObjectFactory::TryDestroyGameObject(GameObject* gameobject) {
	for(unsigned int i = 0; i < Singleton->objects.size(); i++) {
		if(Singleton->objects[i] == gameobject) {
			delete Singleton->objects[i];
			Singleton->objects;
			return true;
		}
	}
	return false;
}
