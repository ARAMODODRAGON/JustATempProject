#ifndef LEVEL_H
#define LEVEL_H

class Level {
private:
public:
	virtual int Init() = 0;
	virtual void Update(const float delta) = 0;
	virtual void Render() = 0;
	virtual int Exit() = 0;
};


#endif // !LEVEL_H