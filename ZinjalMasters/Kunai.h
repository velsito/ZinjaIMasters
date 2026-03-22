#ifndef KUNAI_H
#define KUNAI_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace sf;

class Kunai {
public:

	Kunai(Texture &texture);
	void Update();
	void Draw(RenderWindow &window);
	
	Vector2f getPosition() 
	{
		return this->k_sprite.getPosition();
	}
	
	FloatRect getGlobalBounds()
	{
		return k_sprite.getGlobalBounds();
	}
	
private:
	Sprite k_sprite;
};

#endif

