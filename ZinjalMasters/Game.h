#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
using namespace sf; 
class Scene;
class Game {
public:
	Game(Scene *e);
	void ProcessEvents();
	void Run();
	void SetScene(Scene *next_scene);
	void pausarmusica()
	{
		music.pause();
	}
	~Game();
private:
	RenderWindow m_window;
	Music music;
	Scene *m_scene;
	Scene *m_next_scene=nullptr;
};



#endif

