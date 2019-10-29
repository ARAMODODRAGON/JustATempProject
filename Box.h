#ifndef BOX_H
#define BOX_H
#include "Part.h"

class Box : public Part {
public:
	float positionX, positionY;
	float extentX, extentY;

	Box();

	virtual int Init();
	virtual int Exit();
	virtual void Update(const float delta);
};


#endif // !BOX_H