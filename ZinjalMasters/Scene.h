#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
using namespace sf;

class Game;
class Scene {
public:
	Scene();
	virtual void ProcessEvent(Game &game, Event &event) =0;
	virtual void Update(Game &game, RenderWindow &window) = 0;//metodos virtuales puro, los van a implementar la clase de Match, Menu y endscene
	virtual void Draw(RenderWindow &window) = 0;
private:
};

#endif
