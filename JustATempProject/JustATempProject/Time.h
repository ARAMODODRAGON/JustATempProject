#ifndef TIME_H
#define TIME_H
#include <ctime>

class Time {
private:
	static Time* Singleton;
	std::clock_t start;
	double currentDuration, lastDuration;
	float delta;
public:
	Time();
	~Time();

	void SetLastTime();
	void UpdateTime();
	float GetDeltaFloat();

	static float GetRuntime();
};


#endif // !TIME_H