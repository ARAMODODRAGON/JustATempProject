#include "Box.h"

Box::Box() : Part(), positionX(0.0f), positionY(0.0f), extentX(0.0f), extentY(0.0f) {

}

int Box::Init() {
	return 0;
}

int Box::Exit() {
	return 0;
}

void Box::Update(const float delta) {}
