#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "Match.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "Boton.h"
using namespace sf;

Menu::Menu() {

	t_fondo.loadFromFile("fondo_menu.jpg");
	s_fondo.setTexture(t_fondo); 

	s_fondo.setPosition(0,0);
	s_fondo.setScale(1.2,1.45);
	m_font.loadFromFile("Alinore.otf");
	m_t1.setFont(m_font);
	m_t2.setFont(m_font);
	m_t3.setFont(m_font);
	
	m_t1.setFillColor({30,30,30});//COLOR DE RELLENO
	m_t1.setPosition(180,150);//POSICION
	m_t1.setCharacterSize(60);//TAMAÑO
	m_t1.setString("Zinjai Masters");
	
	m_t2.setFillColor({30,30,30});
	m_t2.setCharacterSize(20);
	m_t2.setPosition(225,220);
	m_t2.setString("¿Estás listo para el desafío?");
	
	boton.generar(Vector2f (262,280), Vector2f (120,30));
	b_t4.setFont(m_font);
	b_t4.setPosition(290,282);
	b_t4.setFillColor({30,30,30});
	b_t4.setCharacterSize(20);
	b_t4.setString("COMENZAR");
	
}


void Menu::ProcessEvent(Game &game, Event &event)
{
	if (event.type == Event::KeyPressed and event.key.code==Keyboard::Escape)
		game.~Game();
}

void Menu::Update (Game &game, RenderWindow &window) {
	
	if(boton.estatocando(window)) {
		boton.setFillColor({205,205,205});
		if(Mouse::isButtonPressed(Mouse::Left)) game.SetScene(new Match);
	} else {
		boton.setFillColor(Color::White);
	}
	
}

void Menu::Draw (RenderWindow &window){
	window.draw(s_fondo);
	boton.drawto(window);
	window.draw(m_t1);
	window.draw(m_t2);
	window.draw(m_t3);
	window.draw(b_t4);
}

