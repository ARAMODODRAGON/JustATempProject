#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "Part.h"
#include "Vector3.h"

class Transform;

class RigidBody : public Part {
private:
	Transform* transform;
public:
	RigidBody(Transform* transform);

	Vector3 velocity;
	Vector3 acceleration;

	virtual int Init() override;
	virtual int Exit() override;
	virtual void Update(const float delta) override;
};


#endif // !RIGIDBODY_H