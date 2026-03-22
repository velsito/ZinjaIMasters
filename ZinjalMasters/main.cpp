#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
using namespace sf;

int main(int argc, char *argv[]){
	Game g(new Menu);
	g.Run();
	return 0;
}

