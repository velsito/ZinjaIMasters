#include "Kunai.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
using namespace std;

Kunai::Kunai(Texture &texture) {
	this->k_sprite.setOrigin(Vector2f(k_sprite.getPosition().x, k_sprite.getPosition().y));
	this->k_sprite.setTexture(texture);
	this->k_sprite.setScale(1.5f,2.f);
	this->k_sprite.setPosition(rand()%640,40.0f);
	this->k_sprite.getGlobalBounds().height / 2.0f;
}

void Kunai::Update()
{	
	this->k_sprite.move(0.f, 5.f);
}

void Kunai::Draw(RenderWindow &window)
{
	window.draw(this->k_sprite);
}
