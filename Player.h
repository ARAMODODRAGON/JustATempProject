#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
#include <string>

class Player : public GameObject {
private:
	class RigidBody* rb;
	class Box* box;
	float timer;
public:
	Player(std::string name);

	int Init();
	int Exit();
	void Update(const float delta);
	void Render();
};


#endif // !PLAYER_H