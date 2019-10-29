#include "Player.h"
#include <stdio.h>
#include "Parts.h"
#include "Transform.h"

Player::Player(std::string name) : GameObject(name), box(nullptr), rb(nullptr), timer(0.0f) {}

int Player::Init() {
	rb = CreatePart<RigidBody>();
	box = CreatePart<Box>();

	rb->acceleration.Y = -9.8f;
	return GameObject::Init();
}

int Player::Exit() {
	return GameObject::Exit();
}

void Player::Update(const float delta) {
	GameObject::Update(delta);
	timer += delta;

	if(timer > 0.2f) {
		timer -= 0.2f;
		Vector3 pos = GetTransform()->position;
		printf("[Player pos]: {%f, %f, %f}\n", pos.X, pos.Y, pos.Z);
	}
}

void Player::Render() {}
