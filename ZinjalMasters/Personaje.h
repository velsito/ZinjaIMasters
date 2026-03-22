#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <SFML/System/Clock.hpp>

using namespace std;
using namespace sf;

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT = 1, MOVING_RIGHT, JUMPING, FALLING, CROUCHING, JUMPING_RIGHT, JUMPING_LEFT, DEAD}; /// diferentes estados del personaje 

class Personaje{
public:
	Personaje();
	void Update(vector<RectangleShape> muros);
	void draw(RenderWindow &window);
	void updateanimations();
	
	void setposition(Vector2f nuevapos) {
		m_sprite.setPosition(m_pos);
	}
	
	const Vector2f getPosition() const {
		return this->m_sprite.getPosition();
	}
	
	auto getGlobalBounds()
	{
		return this->m_sprite.getGlobalBounds();
	}
	
	int verhp() const
	{
		return hp;
	}
	
	const int & gethpmax() const
	{
		return this->hpmax;
	}
	
	bool veragachado()
	{
		return agachado;
	}
	
	void curarse(const int vida);
	void recibirdanio();
	void setHp(const int hp);
	const bool& getanimswitch();
	void resetanimationtimer();
	
private:
	
	int hp;
	int hpmax;
	bool agachado;
	
	/// animacion
	IntRect currentframe;
	short animstate;
	bool animationswitch;
	
	Clock animationtimer;
	
	/// nucleo
	Vector2f m_speed;
	void initanimations();
	void initvariables();
	Vector2f m_pos; 
	Texture m_texture;
	Sprite m_sprite;
	vector<RectangleShape> muros;
};

#endif

