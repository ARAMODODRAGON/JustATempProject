#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Vector3.h"
#include <vector>

class GameObject;

class Transform {
private:
	GameObject* gameObject;
public:
	Transform* parent;
	std::vector<Transform*> childeren;
	
	Vector3 position;
	Vector3 eularAngles;
	Vector3 scale;

	Transform(GameObject* gameObject ,Transform* parent = nullptr);

	GameObject* GetGameObject();

};


#endif // !TRANSFORM_H