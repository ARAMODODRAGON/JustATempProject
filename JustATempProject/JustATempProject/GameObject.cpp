#include "GameObject.h"
#include "Parts.h"
#include "Transform.h"

GameObject::GameObject(std::string name_) {
	name = name_;
	partslist = std::vector<Part*>();
	transform = new Transform(this);
}

GameObject::~GameObject() {
	for(unsigned int i = 0; i < partslist.size(); i++) {
		delete partslist[i];
	}
	partslist.clear();
}

Transform* GameObject::GetTransform() {
	return transform;
}

const std::string& GameObject::GetName() {
	return name;
}

int GameObject::Init() {
	// init all parts
	for(unsigned int i = 0; i < partslist.size(); i++) {
		partslist[i]->Init();
	}

	return 0;
}

int GameObject::Exit() {
	int result;
	for(unsigned int i = 0; i < partslist.size(); i++) {
		result = partslist[i]->Exit();
		if(result != 0) return result;
	}
	return 0;
}

void GameObject::Update(const float delta) {
	for(size_t i = 0; i < partslist.size(); i++) {
		partslist[i]->Update(delta);
	}

}

void GameObject::Render() {}

template<>
Box* GameObject::CreatePart<Box>() {
	// create part
	Box* part = new Box();
	// add part to list
	partslist.push_back(part);
	// return the pointer to the part
	return part;
}

template<>
RigidBody* GameObject::CreatePart<RigidBody>() {
	// create part
	RigidBody* part = new RigidBody(transform);
	// add part to list
	partslist.push_back(part);
	// return the pointer to the part
	return part;
}