#include "Heart.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
using namespace sf;

Heart::Heart(Texture &texture) {
	this->h_sprite.setTexture(texture);
	this->h_sprite.setScale(1.1f,1.1f);
	this->h_sprite.setOrigin(h_sprite.getLocalBounds().width * 0.5f, h_sprite.getLocalBounds().height * 0.5f);
	this->h_sprite.setPosition(
		Vector2f(
			static_cast<float>(rand() % 640 - this->h_sprite.getGlobalBounds().width),
			static_cast<float>(rand()%361 + 40 + this->h_sprite.getGlobalBounds().width) 
		)
	);
}

std::pair<float,float> collide2(FloatRect b1, FloatRect b2) { /// sistema de colisiones 

	b1.width += b1.left; b1.height += b1.top; 
	b2.width += b2.left; b2.height += b2.top; 
	if (b1.width<b2.left) return {0,0}; // b1 está completamente a la izquierda de b2
	if (b1.left>b2.width) return {0,0}; // b1 está completamente a la derecha de b2
	if (b1.height<b2.top) return {0,0}; // b1 está completamente arriba de b2
	if (b1.top>b2.height) return {0,0}; // b1 está completamente abajo de b2
	
	float dx, dy;
	
	if (b1.left+b1.width<b2.left+b2.width) // comparo los centros para decir izquierda/derecha
		dx = b2.left-b1.width; // si esta a la izquierda, dx da negativo
	else
		dx = b2.width-b1.left; // si esta a la derecha, dx da positivo
	if (b1.top+b1.height<b2.top+b2.height) // comparo los centros para decir arriba/abajo
		dy = b2.top-b1.height; // si esta arriba, dy da negativo
	else
		dy = b2.height-b1.top; // si esta abajo, dy da positivo
	return {dx,dy};
}

void Heart::Update(vector<RectangleShape> muros)
{
	
	Vector2f p = h_sprite.getPosition();
	for(const auto&plataforma : muros) {
	
		FloatRect colisionesh = h_sprite.getGlobalBounds();
		FloatRect colisionesmuro = plataforma.getGlobalBounds();
		
		auto col = collide2(colisionesh,colisionesmuro);
		
		if (col.second!=0) { 	
			p.y += col.second;
			p.x += col.first;
			h_sprite.setPosition(p); /// corrijo la posicion del corazon con los flotantes que me arroje la funcion
		} 
	}
}

void Heart::Draw(RenderWindow &window)
{
	window.draw(this->h_sprite);
}

