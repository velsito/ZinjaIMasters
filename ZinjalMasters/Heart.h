#ifndef HEART_H
#define HEART_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Heart {
public:
	Heart(Texture &texture);
	void Update(vector<RectangleShape> muros);
	void Draw(RenderWindow &window);
	
	Vector2f getPosition() 
	{
		return h_sprite.getPosition();
	}
	
	FloatRect getGlobalBounds()
	{
		return h_sprite.getGlobalBounds();
	}
	
private:
	Sprite h_sprite;
	vector<RectangleShape> muros;
};

#endif

