#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "Objects.h"
#include <vector>
#include <string>

class ObjectFactory {
private:
	static ObjectFactory* Singleton;
	std::vector<class GameObject*> objects;
public:
	ObjectFactory();
	~ObjectFactory();

	int Init();
	int Exit();
	void UpdateObjects(const float delta);

	static GameObject* CreateGameObject(std::string name);
	static void AddGameObject(GameObject* gameobject);
	static bool TryDestroyGameObject(GameObject* gameobject);
};


#endif // !OBJECTFACTORY_H