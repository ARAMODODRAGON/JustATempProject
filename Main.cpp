#include "Game.h"

int main() {
	
	int result = 0;
	Game* game = new Game();

	// init the game
	result = game->Init();
	if(result != 0) {
		delete game, game = nullptr;
		return result;
	}

	// main loop
	game->Run();
	
	result = 0;
	// exit game
	result = game->Exit();

	if(result != 0) {
		delete game, game = nullptr;
		return result;
	}

	// end
	delete game, game = nullptr;
	return 0;
}