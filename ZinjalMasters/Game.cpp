 #include "Game.h"
#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "Match.h"
#include <SFML/Window/Keyboard.hpp>
using namespace sf; 

Game::Game(Scene *e):m_window(VideoMode(640,480),"Zinjai Masters"){//crear la ventana
	m_window.setFramerateLimit(60);
	m_scene = e;
}

void Game::ProcessEvents() 
{
	Event Event;
	while(m_window.pollEvent(Event)) {
		if (Event.type == Event::Closed) m_window.close();
		else 
			m_scene->ProcessEvent(*this, Event);
	}
}

void Game::Run ( ) {	//loop de eventos
	
	music.openFromFile("musiquita.ogg");
	if(!music.openFromFile("musiquita.ogg"))
		cout << "ERROR OPENING MUSIC FILE" << endl;
	music.play();
	
	while(m_window.isOpen()) {
		ProcessEvents();
		m_scene -> Update(*this, m_window);
		m_scene -> Draw(m_window);
		m_window.display();
		if(m_next_scene)
		{	//con esto nos aseguramos que si hay una nueva escena en uso
			//borramos la anterior sin miedo a q todo reviente.
			delete m_scene;//borramos la anterior
			m_scene = m_next_scene;//la actualizamos a la que estamos usando o queremos usar
			m_next_scene=nullptr;//asignamos como "vacia" a la siguiente para seguir con el ciclo
		}
	}
}

void Game::SetScene (Scene *next_scene) {
	m_next_scene = next_scene;
}

Game::~Game ( ){
	delete m_scene;
}

