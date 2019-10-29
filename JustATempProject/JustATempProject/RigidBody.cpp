#include "RigidBody.h"
#include "Transform.h"
#include <stdio.h>

RigidBody::RigidBody(Transform* transform_) {
	transform = transform_;
}

int RigidBody::Init() {
	return 0;
}

int RigidBody::Exit() {
	return 0;
}

void RigidBody::Update(const float delta) {
	velocity += acceleration * delta;
	transform->position += velocity * delta;
}
