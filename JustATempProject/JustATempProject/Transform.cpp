#include "Transform.h"

Transform::Transform(GameObject* gameObject_, Transform* parent_) : position(Vector3::Zero), eularAngles(Vector3::Zero), scale(Vector3::Zero) {
	gameObject = gameObject_;
	parent = parent_;
	childeren = std::vector<Transform*>();
}

GameObject* Transform::GetGameObject() {
	return gameObject;
}
