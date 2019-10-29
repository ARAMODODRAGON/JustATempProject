#ifndef GAME_H
#define GAME_H

class Game {
private:
	class Time* time;
	class ObjectFactory* objectFactory;
public:
	Game();
	~Game();

	int Init();
	int Exit();
	void Run();

};


#endif // !GAME_H