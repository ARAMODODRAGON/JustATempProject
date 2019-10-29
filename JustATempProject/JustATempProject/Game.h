#ifndef GAME_H
#define GAME_H

class Game {
private:
	static Game* Singleton;
	bool rungame;
	class Time* time;
	class ObjectFactory* objectFactory;
	class LevelManager* levelManager;
public:
	Game();
	~Game();

	int Init();
	int Exit();
	void Run();

	static void ExitGame();
};


#endif // !GAME_H