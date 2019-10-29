#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

enum class LevelID {
	none = 0,
	testlevel0 = 1,
	testlevel1 = 2,
	testlevel2 = 3,
};

class LevelManager {
private:
	static LevelManager* Singleton;
	class Level* level;
	LevelID levelToLoad;
public:
	LevelManager();
	~LevelManager();

	int Init(LevelID levelID = LevelID::none);
	void UpdateLevel(const float delta);
	void CheckForAndLoadLevel();
	int Exit();

	static void LoadLevel(LevelID levelToLoad);
};


#endif // !LEVELMANAGER_H