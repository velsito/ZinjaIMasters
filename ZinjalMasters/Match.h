//#ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H
#include "Scene.h"
#include <SFML/Graphics/Texture.hpp>
#include "Personaje.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "shuriken.h"
#include <SFML/System/Clock.hpp>
#include "endscene.h"
#include "Heart.h"
#include "Kunai.h"


using namespace std;
using namespace sf;
class Game;
class Match : public Scene {
public:
	Match();
	void ProcessEvent(Game &game, Event &event) override;
	void Update(Game &game, RenderWindow &window) override;
	void Draw(RenderWindow &window) override;
	void Generar_Shuriken(Texture &texture);
	void Generar_Kunai(Texture &texture);
	void Generar_Hearts(Texture &texture);
	const void iniciarvariables();
	bool tiempo();
	void updatecolision();
	int vervidas();
	void updatejugador(Game &game);
	void renderhpbar(RenderWindow &window);
	void updatehpbar();
	void Chrono();
	
private:
	
	/// vectores de elementos
	vector<Shuriken> sh_vec;
	vector<Kunai> k_vec;
	vector<Heart> h_vec;
	vector<RectangleShape> muros;
	vector<Sprite> s_vector;
	
	/// barra de vida
	RectangleShape hpbar;
	RectangleShape hpbarback;
	
	/// spawn
	float spawntimerkunai, spawntimerhearts;
	float spawntimerkunaimax, spawtimerheartsmax;
	int maxkunai, maxhearts;
	
	/// texturas
	Texture t_shuriken, t_kunai, t_heart;
	Texture t_piso, t_fondo1, t_fondo2, t_plat, t_lifebar;
	Sprite s_piso, s_fondo1, s_fondo2, s_plat, s_lifebar;
	
	///fuente,Text y clases
	Font t_fuente,c_fuente;
	Text t_vidas,text_cronometro;
	bool temporizador,endgame = false;
	Personaje personaje;
	RectangleShape m_suelo;
	RectangleShape muro1, muro2, muro3, muro, muro4, muro5, muro6, muro7, muro8, muro9, muro10, muro11, muro12, muro13, muro14;
	Clock m_clock, v_clock,m_cronometro,m_cronomuerte;
	int NewScore;
	vector<int> BestScores;
	
};



