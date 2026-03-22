#include "Shuriken.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <thread>
#include <chrono>
using namespace sf;
using namespace std;

///640x480

Shuriken::Shuriken(Texture &texture)
{
 
	this->sh_sprite.setTexture(texture);
	this->sh_sprite.setScale(0.043,0.043);
	this->sh_sprite.setOrigin(sh_sprite.getLocalBounds().width * 0.5f, sh_sprite.getLocalBounds().height * 0.5f);
	this->sh_sprite.setPosition(0.0f, rand()%(361)+50);
	
	///valor por default
	this->direccionx = 1.0f; 
	
}

void Shuriken::Update() {
	
	if(sh_sprite.getPosition().x > 640.f) /// si se pasa de alguno de los bordes del ancho de la pantalla
	{
		direccionx *= -1.0f; /// va pal otro lado
	} 
	
	sh_sprite.move(direccionx * 4.0f, 0.0f);
	sh_sprite.rotate(10.f);
	
}

void Shuriken::Draw (RenderWindow &window) {
	window.draw(sh_sprite);
}


