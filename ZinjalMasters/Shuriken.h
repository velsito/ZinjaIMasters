#ifndef SHURIKEN_H
#define SHURIKEN_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
class Shuriken {
public:
	Shuriken(Texture &texture);
	void Update();
	void Draw(RenderWindow &window);
	
	Vector2f getPosition() 
	{
		return sh_sprite.getPosition();
	}
	
	FloatRect getGlobalBounds()
	{
		return sh_sprite.getGlobalBounds();
	}
	
private:

	float velocidad, direccionx;
	Sprite sh_sprite;
	
};

#endif
