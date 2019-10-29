#ifndef TESTLEVEL0_H
#define TESTLEVEL0_H
#include "Level.h"


class TestLevel0 : public Level {
private:
	class Player* player;
	float timer;
public:

	virtual int Init() override;
	virtual void Update(const float delta) override;
	virtual void Render() override;
	virtual int Exit() override;
};


#endif // !TESTLEVEL0_H