#include "endscene.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include <SFML/Audio/Music.hpp>
#include <fstream>
using namespace std;

endscene::endscene() {
	
	this->t_fondo.loadFromFile("fondo_menu.jpg");
	this->s_fondo.setTexture(t_fondo);
	this->s_fondo.setPosition(0,0);
	this->s_fondo.setScale(1.2,1.45);

	this->d_fuente.loadFromFile("Alinore.otf");
	this->d_text.setFont(d_fuente);
	this->d_text.setFillColor({30,30,30});
	this->d_text.setString("TE MORISTE");
	this->d_text.setPosition(225,150);
	this->d_text.setCharacterSize(60);
	
	this->r_text.setFont(d_fuente);
	this->r_text.setFillColor({30,30,30});
	this->r_text.setString("presiona escape para volver al menu");
	this->r_text.setPosition(203,240);
	this->r_text.setCharacterSize(20);
	
	ifstream a_scores("Puntajes.txt");
	if(a_scores.is_open()){
		int scores;
		while (a_scores>>scores){
			this->BestScores.push_back(scores);
		}
	}
	a_scores.close();
	
	string s_sc = "Mejores Puntuaciones \n";
	for(int i=0;i<3;i++) {
		s_sc += to_string(BestScores[i]) + "\n";
		
	}
	s_sc += "Tu Puntaje \n" + to_string(BestScores[4]);
	
	ti_scores.setFont(d_fuente);
	ti_scores.setPosition(203,270);
	ti_scores.setFillColor({30,30,30});
	ti_scores.setCharacterSize(25);
	ti_scores.setString(s_sc);
}

void endscene::Update(Game &game, RenderWindow & window) 
{

}

void endscene::Draw(RenderWindow &window) 
{
	window.clear();
	window.draw(this->s_fondo);
	window.draw(d_text); /// dibujo el texto y el fondo de muerte
	window.draw(r_text);
	window.draw(ti_scores);
}

void endscene::ProcessEvent(Game &game, Event &event) 
{
	if (event.type == Event::KeyPressed and event.key.code==Keyboard::Escape)
		game.SetScene(new Menu);
}

 
