#ifndef PART_H
#define PART_H

class Part {
public:
	bool isActive;
	inline Part() : isActive(true) { }

	virtual int Init() = 0;
	virtual int Exit() = 0;
	virtual void Update(const float delta) = 0;
};


#endif // !PART_H