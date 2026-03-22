#ifndef BOTON_H
#define BOTON_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>
using namespace sf;
using namespace std;

class Boton {
public:
	Boton();

	void drawto(RenderWindow &window) {
		window.draw(boton);
		//window.draw(texto);
	}
	
	void setFillColor(Color nuevo) {
		boton.setFillColor(nuevo);
	}
	
	void generar(Vector2f pos, Vector2f tam) {
		boton.setPosition(pos);
		float xpos = (pos.x + boton.getGlobalBounds().width / 4) - (texto.getGlobalBounds().width / 2); 
		float ypos = (pos.y + boton.getGlobalBounds().height / 2) - (texto.getGlobalBounds().height / 2); 
		texto.setPosition(xpos, ypos);
		boton.setSize(tam);
	}
	
	auto getGlobalBounds()
	{
		return boton.getGlobalBounds();
	}
	
	bool estatocando(RenderWindow &window) {
	
		this->mousePosWindow = Mouse::getPosition(window);
		this->mousePosView = window.mapPixelToCoords(this->mousePosWindow); /// mapeo a floats 
		
		if(this->boton.getGlobalBounds().contains(mousePosView)) return true;
		return false;
		
	}
	
private:
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Font fuente;
	Text texto;
	RectangleShape boton;
};

#endif

