#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scene.h"
#include "Game.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Boton.h"
using namespace sf;

class Menu: public Scene {
public:
	Menu();
	void ProcessEvent(Game &game, Event &event) override;
	void Update(Game &game, RenderWindow &window) override;
	void Draw(RenderWindow &window) override;
	void updatemousepositions();
	
private:
	
	RenderWindow window;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Font m_font; 
	Text m_t1, m_t2, m_t3, b_t4;
	Texture t_fondo;
	Sprite s_fondo;
	RectangleShape fondito;
	Boton boton;
};

#endif
