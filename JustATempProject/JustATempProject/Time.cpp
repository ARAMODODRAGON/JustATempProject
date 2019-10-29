#include "Time.h"
#include "Time.h"

Time* Time::Singleton = nullptr;

Time::Time() {
	// set singleton
	if(Singleton != nullptr) Singleton = this;
	// set variables
	start = std::clock();
	currentDuration = 0.0;
	lastDuration = 0.0;
	delta = 0.0f;
}

Time::~Time() {
	if(Singleton == this) Singleton = nullptr;
}

void Time::SetLastTime() {
	lastDuration = currentDuration;
}

void Time::UpdateTime() {
	currentDuration = (((double)std::clock()) - start) / (double)CLOCKS_PER_SEC;
	delta = (float)(currentDuration - lastDuration);
}

float Time::GetDeltaFloat() {
	return delta;
}

float Time::GetRuntime() {
	if(Singleton != nullptr) return (float)Singleton->currentDuration;
	else return 0.0f;
}
