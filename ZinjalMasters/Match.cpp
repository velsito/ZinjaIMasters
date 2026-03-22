#include "Scene.h"
#include "Match.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"
#include <vector>
#include "Game.h"
#include<iostream>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <algorithm>
#include <sstream>
#include "Personaje.h"
#include "endscene.h"
#include "Kunai.h"
#include "Heart.h"
#include <fstream>
#include <iomanip>
using namespace sf;
using namespace std;

Match::Match() {
	
this->iniciarvariables();
	
	/// la mitad de la pantalla es 320x240
	
	t_fondo1.loadFromFile("Fondo_dojo.png");
	s_fondo1.setTexture(t_fondo1);
	s_fondo1.setPosition(0,0);
	s_fondo1.setScale(1.253,2.5); /// NO TOCAR

	this->t_plat.loadFromFile("plataforma.png");
	this->s_plat.setTexture(t_plat);

	t_fondo2.loadFromFile("fondo2.png");
	s_fondo2.setTexture(t_fondo2);
	s_fondo2.setPosition(0,0);
	s_fondo2.setScale(1.3,2.33);
	
	muro.setOutlineColor(Color::Black);
	muro.setOutlineThickness(1.0);
	muro.setFillColor({128, 64, 10});
	muro.setSize(Vector2f(640.0,300.0));
	muro.setPosition(0, 430); /// piso
	/// 640 
	muro1.setOutlineColor(Color::Black);
	muro1.setOutlineThickness(1.0);
	muro1.setFillColor(Color::Black);
	muro1.setSize(Vector2f(50,20.0));
	muro1.setPosition(310, 350); /// siempre le tengo que restar 40 a la posicion para ubicarlo realmente donde quiera
	this->s_vector.push_back(this->s_plat);
	this->s_vector[0].setScale(Vector2f(.086,.42));
	this->s_vector[0].setPosition(Vector2f(309, 348.7));
	
	muro2.setOutlineColor(Color::Black);
	muro2.setOutlineThickness(1.0);
	muro2.setFillColor(Color::Black);
	muro2.setSize(Vector2f(100.0,20.0));
	muro2.setPosition(70, 320);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[1].setScale(Vector2f(.169,.42));
	this->s_vector[1].setPosition(Vector2f(69, 318));
	
	muro3.setOutlineColor(Color::Black);
	muro3.setOutlineThickness(1.0);
	muro3.setFillColor(Color::Black);
	muro3.setSize(Vector2f(60.0,20.0));
	muro3.setPosition(225, 271);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[2].setScale(Vector2f(.105,.419));
	this->s_vector[2].setPosition(Vector2f(222.1, 269.8));
	
	
	muro4.setOutlineColor(Color::Black);
	muro4.setOutlineThickness(1.0);
	muro4.setFillColor(Color::Black);
	muro4.setSize(Vector2f(40.0,20.0));
	muro4.setPosition(570, 270);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[3].setScale(Vector2f(.0678,.42));
	this->s_vector[3].setPosition(Vector2f(569.4, 268.8));
	
	muro5.setOutlineColor(Color::Black);
	muro5.setOutlineThickness(1.0);
	muro5.setFillColor(Color::Black);
	muro5.setSize(Vector2f(60.0,20.0));
	muro5.setPosition(380, 271); 
	this->s_vector.push_back(this->s_plat);
	this->s_vector[4].setScale(Vector2f(.102,.42));
	this->s_vector[4].setPosition(Vector2f(379.4, 269.8));
	
	muro6.setOutlineColor(Color::Black);
	muro6.setOutlineThickness(1.0);
	muro6.setFillColor(Color::Black);
	muro6.setSize(Vector2f(60.0,20.0));
	muro6.setPosition(480, 200); 
	this->s_vector.push_back(this->s_plat);
	this->s_vector[5].setScale(Vector2f(.102,.42));
	this->s_vector[5].setPosition(Vector2f(479.4, 198.8));
	
	muro7.setOutlineColor(Color::Black);
	muro7.setOutlineThickness(1.0);
	muro7.setFillColor(Color::Black);
	muro7.setSize(Vector2f(100.0,20.0));
	muro7.setPosition(480, 350);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[6].setScale(Vector2f(.169,.42));
	this->s_vector[6].setPosition(Vector2f(479, 348.7));
	
	muro8.setOutlineColor(Color::Black);
	muro8.setOutlineThickness(1.0);
	muro8.setFillColor(Color::Black);
	muro8.setSize(Vector2f(70.0,20.0));
	muro8.setPosition(50, 130);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[7].setScale(Vector2f(.12,.42));
	this->s_vector[7].setPosition(Vector2f(48.8,128.7));
	
	muro9.setOutlineColor(Color::Black);
	muro9.setOutlineThickness(1.0);
	muro9.setFillColor(Color::Black);
	muro9.setSize(Vector2f(50.0,20.0));
	muro9.setPosition(30, 225);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[8].setScale(Vector2f(.086,.418));
	this->s_vector[8].setPosition(Vector2f(29, 224));
	
	muro10.setOutlineColor(Color::Black);
	muro10.setOutlineThickness(1.0);
	muro10.setFillColor(Color::Black);
	muro10.setSize(Vector2f(50.0,20.0));
	muro10.setPosition(170, 190);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[9].setScale(Vector2f(.086,.418));
	this->s_vector[9].setPosition(Vector2f(169,188.7));

	muro11.setOutlineColor(Color::Black);
	muro11.setOutlineThickness(1.0);
	muro11.setFillColor(Color::Black);
	muro11.setSize(Vector2f(80.0,20.0));
	muro11.setPosition(312, 190);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[10].setScale(Vector2f(.1355,.42));
	this->s_vector[10].setPosition(Vector2f(311, 188.7));
	
	muro12.setOutlineColor(Color::Black);
	muro12.setOutlineThickness(1.0);
	muro12.setFillColor(Color::Black);
	muro12.setSize(Vector2f(40.0,20.0));
	muro12.setPosition(550, 125);
	this->s_vector.push_back(this->s_plat);
	this->s_vector[11].setScale(Vector2f(.0679,.418));
	this->s_vector[11].setPosition(Vector2f(549.2, 123.7));

	muros.push_back(muro);
	muros.push_back(muro1);
	muros.push_back(muro2);
	muros.push_back(muro3);
	muros.push_back(muro4);
	muros.push_back(muro5);
	muros.push_back(muro6);
	muros.push_back(muro7);
	muros.push_back(muro8);
	muros.push_back(muro9);
	muros.push_back(muro10);
	muros.push_back(muro11);
	muros.push_back(muro12);

	
	t_fuente.loadFromFile("Alinore.otf");
	this->t_vidas.setFont(t_fuente);
	this->t_vidas.setFillColor(Color::White);
	this->t_vidas.setCharacterSize(30);
	this->t_vidas.setPosition(277,435);
	
	this->t_lifebar.loadFromFile("lifebar5.png");
	this->s_lifebar.setTexture(t_lifebar);
	this->s_lifebar.setPosition(237.f,433.f);
	this->s_lifebar.setScale(.307f,.75f);
	
	this->t_shuriken.loadFromFile("shuriken2.png");
	this->t_kunai.loadFromFile("Kunai_Pixel.png");
	this->t_heart.loadFromFile("heart.png");
	
	c_fuente.loadFromFile("Alinore.otf"); ///CRONOMETRO
	text_cronometro.setFont(c_fuente);
	text_cronometro.setCharacterSize(40);
	
	for(int i=0;i<4;i++) { BestScores.push_back(0); }
	
	ifstream a_puntajes("Puntajes.txt"); ///PUNTAJES
	if(a_puntajes.is_open()){
		int Score;
		int aux = 0;
		
		while (a_puntajes>>Score){
			BestScores[aux] = Score;
			if (aux>2) {break;}
			aux++;
		}
	}
	a_puntajes.close();

}



const void Match::iniciarvariables()
{
	this->endgame = false;
	this->maxkunai = 5; /// max kunai en pantalla
	this->maxhearts = 3; /// max de corazones en pantalla
	
	this->spawntimerkunaimax = 150.f;
	this->spawntimerkunai = spawntimerkunaimax;
	this->spawtimerheartsmax = 200.f; /// tiempo de spawn de los corazones
	this->spawntimerhearts = 0.f; /// para que no spawnee uno al principio
	
	/// barra de vida 
	this->hpbar.setSize(Vector2f(165.f,30.f));
	this->hpbar.setFillColor(Color{95,2,31});
	this->hpbar.setPosition(Vector2f(240.0f, 440.0f));
	
	this->hpbarback.setPosition(Vector2f(240.0f, 440.0f));
	this->hpbarback.setSize(Vector2f(160.f,30.f)); /// comienzan con el mismo tamaño
	this->hpbarback.setFillColor(Color(25,25,25,200));
}

void Match::renderhpbar(RenderWindow &window)
{
	window.draw(this->hpbarback);
	window.draw(this->hpbar);
}

void Match::updatehpbar()
{
	float porcentajehp = static_cast<float>(this->personaje.verhp()) / this->personaje.gethpmax(); /// static_cast para pasar todo a float
	this->hpbar.setSize(Vector2f(150.f * porcentajehp, this->hpbar.getSize().y));
}

void Match::Update(Game &game, RenderWindow &window) {
	
	Chrono();
	text_cronometro.setPosition(275.0f,8.0f);
	
	this->updatejugador(game);
	
	if(tiempo())
	{
		Generar_Shuriken(t_shuriken);
	}

	Generar_Kunai(t_kunai);
	Generar_Hearts(t_heart);
	
	for (auto i = 0 ; i<this->sh_vec.size(); i++){
		sh_vec[i].Update();
		
		if(sh_vec[i].getPosition().x < 0.0f ) sh_vec.erase(sh_vec.begin() + i); /// borro el shuriken cuando pasa el limite
	}
	
	for (auto i = 0 ; i<this->k_vec.size(); i++){
		k_vec[i].Update();
		
		if(k_vec[i].getPosition().y > 420.0f ) k_vec.erase(k_vec.begin() + i); /// borro el kunai cuando pasa el limite del alto de la pantalla
	}
	
	for(auto i=0; i<this->h_vec.size(); i++)
	{
		h_vec[i].Update(muros);
	}

	/// colision con las entidades
	this->updatecolision();
	this->updatehpbar();
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){//si tocamos escape en el juego, volvemos al menu
		game.SetScene(new Menu());
	}
}


int Match::vervidas()
{
	return personaje.verhp();
}

void Match::Generar_Shuriken (Texture &texture) 
{
	this->sh_vec.push_back(Shuriken(texture)); /// creo un shuriken
}

void Match::Generar_Kunai(Texture &texture)
{
	/// timer
	if(this->spawntimerkunai < this->spawntimerkunaimax) /// si no paso el tiempo...
	{
		this->spawntimerkunai += 1.f; /// sumo uno al contador
	} else /// si se pasó del tiempo...
	{
		if(this->k_vec.size() < this->maxkunai) 
		this->k_vec.push_back(Kunai(texture));  /// creo un kunai
		this->spawntimerkunai = 0.0f;	/// reinicio el contador
	}
}

void Match::Generar_Hearts(Texture &texture)
{
	if(this->spawntimerhearts < this->spawtimerheartsmax) /// si no paso el tiempo...
	{
		this->spawntimerhearts += 1.f; /// sumo uno al contador
	} else /// si se pasó del tiempo...
	{
		if(this->h_vec.size() < this->maxhearts) 
		{
			this->h_vec.push_back(Heart(texture));  /// creo un corazon
			this->spawntimerhearts = 0.0f;	/// reinicio el contador
		} else h_vec.erase(h_vec.begin() + rand()%2);
	}
}

void Match::updatecolision()
{	

 // Obtener las dimensiones originales del personaje
    auto player_bounds = personaje.getGlobalBounds();
    auto originalBounds = FloatRect(player_bounds.left += 5, player_bounds.top += 5, player_bounds.width -=10, player_bounds.height -= 6);
    FloatRect colisionesp;

    // Verificar si el personaje está agachado
    if (personaje.veragachado()) {
        // Reducir la altura del sprite a la mitad cuando el personaje está agachado
        colisionesp = FloatRect(originalBounds.left, originalBounds.top + originalBounds.height / 2.0f, originalBounds.width, originalBounds.height / 2.0f);
    } else {
        // Restablecer la altura original cuando el personaje no está agachado
        colisionesp = FloatRect(originalBounds.left, originalBounds.top, originalBounds.width, originalBounds.height);
    }
	
	for(size_t i=0; i < this->sh_vec.size(); i++)
	{
		if(sh_vec[i].getGlobalBounds().intersects(colisionesp)) /// si interseca con alguno de los shurikens...
		{
			this->personaje.recibirdanio();
			sh_vec.erase(sh_vec.begin() + i);
		}
	}
	
	for(size_t i=0; i<this->k_vec.size(); i++)
	{
		if(k_vec[i].getGlobalBounds().intersects(colisionesp)) /// si interseca con alguno de los kunai
		{
			k_vec.erase(k_vec.begin() + i);
			this->personaje.recibirdanio();
		}
	}
	
	for(size_t i=0; i<this->h_vec.size(); i++)
	{
		if(h_vec[i].getGlobalBounds().intersects(colisionesp))
		{
			h_vec.erase(h_vec.begin() + i);
			this->personaje.curarse(1);
		}
	}
}

void Match::updatejugador(Game &game)
{
	this->personaje.Update(muros);
	
	if(this->personaje.verhp() <= 0){
		this->endgame = true;
		NewScore = m_cronometro.getElapsedTime().asMilliseconds();
		BestScores.push_back(NewScore);
		sort(BestScores.begin(),BestScores.end());
		reverse(BestScores.begin(),BestScores.end());
		BestScores.pop_back();
		BestScores.push_back(NewScore);
		
		ofstream a_puntajes("Puntajes.txt",ios::trunc);
		if(a_puntajes.is_open()){
			for(const auto &puntos:BestScores){
				a_puntajes<<puntos<<"\n";
			}
		}
		a_puntajes.close();
		game.SetScene(new endscene);
	} else this->endgame = false;

}

void Match::ProcessEvent (Game &game, Event &event)
{
	if (event.type == Event::KeyPressed and event.key.code==Keyboard::Escape)
		game.SetScene(new Menu);
	
	if(this->endgame)  game.SetScene(new endscene);

	if (event.type == Event::KeyReleased && 
		(event.key.code == Keyboard::W || 
		event.key.code == Keyboard::A || 
		event.key.code == Keyboard::S ||
		event.key.code == Keyboard::D ))
	{
		this->personaje.resetanimationtimer(); /// reseteo el temporizador de la animacion al presionar cualquier tecla de movimiento
	}
	
}

void Match::Draw(RenderWindow &window) {
	
	window.clear({150,200,200,200});
	window.draw(s_fondo2);
	window.draw(s_fondo1);
	personaje.draw(window);
	for(size_t i=1; i<muros.size(); i++) {
		window.draw(muros[i]);
	}
	for(size_t i=0; i<this->s_vector.size(); i++)
	{
		window.draw(s_vector[i]);
	}
	for(Kunai &k:this->k_vec)
	{
		k.Draw(window);
	}
	for (Shuriken &s:sh_vec)
	{
		s.Draw(window);
	}
	for(Heart &h:h_vec)
	{
		h.Draw(window);
	}
	window.draw(text_cronometro);
	window.draw(s_lifebar);
	this->renderhpbar(window);
}

bool Match::tiempo ( ) {

	static int spawnCounter = 0;  /// Contador de veces que se ha llamado la función
	Time elapsed = m_clock.getElapsedTime();

    /// Ajusta el tiempo de spawn en base al contador
    float spawnTime = 2.0f / (2.0f + 0.01f * spawnCounter); /// el valor 0.1 lo puedo modificar para cambiar cuanto disminuye el tiempo de spawn a medida que aumenta el contador

    if (elapsed.asSeconds() >= spawnTime) {
        m_clock.restart();
        spawnCounter++;
        return true;
    }
    return false;
}

void Match::Chrono ( ) {
	int min = static_cast<int>(m_cronometro.getElapsedTime().asSeconds())/60;
	int sec = static_cast<int>(m_cronometro.getElapsedTime().asSeconds())%60;
	int mili = static_cast<int>(m_cronometro.getElapsedTime().asMilliseconds())%1000;
	
	ostringstream cronometroStream;
	cronometroStream << setfill('0') << setw(2) << min << ":"
		<< setfill('0') << setw(2) << sec << ":"
		<< setfill('0') << setw(2) << mili / 10; /// Mostrar solo 2 dígitos para milisegundos
	
	text_cronometro.setString(cronometroStream.str());
}

