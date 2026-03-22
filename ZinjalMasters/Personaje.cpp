#include "Personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "constantes.h"
#include <cstdlib>
#include <cmath>

using namespace sf; 

Personaje::Personaje() 
{ 
	this->initvariables();
	m_sprite.setPosition(320,150);
	m_texture.loadFromFile("KarateMan.png");
	m_sprite.setTexture(m_texture);
	this->currentframe = IntRect(0, 0, 47, 70); // primer sprite a usar
	/// el tercer argumento es el ancho, el cuarto el alto
	
	/// para calcular que sprite usar divido la cantidad de sprites por el ancho del png y obtengo un sprite

	this->m_sprite.setTextureRect(this->currentframe); // texturerect me dice cuanto tengo que renderizar de la imagen
	this->m_sprite.setScale(0.7f,0.7f);
	this->initanimations();
};	

void Personaje::initvariables() 
{
	this->animstate = PLAYER_ANIMATION_STATES::IDLE;
	this->hpmax = 10;
	this->hp = hpmax;
}

void Personaje::updateanimations() 
{

/// cada sprite tiene 56 de ancho y 86 de alto !!!

	if(this->animstate == PLAYER_ANIMATION_STATES::IDLE )
	{
		if(this->animationtimer.getElapsedTime().asSeconds() >= 0.5f || this->getanimswitch())
		{
			this->currentframe.top = 96.f;
			this->currentframe.left += 208.f;
			if(this->currentframe.left >= 265.f) 
			{
				this->currentframe.top = 0.f;
				this->currentframe.left = 0.f;
			}
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		this->m_sprite.setScale(.7,.7);
		this->m_sprite.setOrigin(0.f, 0.f);
		
	} else if(this->animstate == PLAYER_ANIMATION_STATES::MOVING_LEFT) 
	{
		if(this->animationtimer.getElapsedTime().asSeconds() >= 0.1f || this->getanimswitch())
		{
			this->currentframe.top = 0.f;
			this->currentframe.left += 50.f;
			if(this->currentframe.left >= 200.f) this->currentframe.left = 50.f;
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		this->m_sprite.setScale(-.7,.7); /// LA MISMA ESCALA PERO EN NEGATIVO PARA QUE SE DE VUELTA EL SPRITE
		this->m_sprite.setOrigin(this->m_sprite.getGlobalBounds().width / 0.7f, 0.f);
		
	} else if (this->animstate == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
	
		if(this->animationtimer.getElapsedTime().asSeconds() >= 0.1f || this->getanimswitch())
		{
			this->currentframe.top = 0.f;
			this->currentframe.left += 50.f;
			if(this->currentframe.left >= 250.f) this->currentframe.left = 50.f;
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		this->m_sprite.setScale(.7,.7);
		this->m_sprite.setOrigin(0.f, 0.f);
		
	} else if(this->animstate == PLAYER_ANIMATION_STATES::JUMPING) 
	
	{
		if(this->animationtimer.getElapsedTime().asSeconds() >= 0.1 || this->getanimswitch())
		{
			this->currentframe.top = 0.f;
			this->currentframe.left += 248.f;
			if(this->currentframe.left >= 298.f) this->currentframe.left = 250.f;
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		
		this->m_sprite.setScale(.7,.7);
		this->m_sprite.setOrigin(0.f, 0.f);
		
	} else if(this->animstate == PLAYER_ANIMATION_STATES::CROUCHING) 
	{
	
		if(this->animationtimer.getElapsedTime().asSeconds() >= .01 || this->getanimswitch())
		{
			this->currentframe.top = 0.f;
			this->currentframe.left = 288.f;
			if(this->currentframe.left >= 338.f) this->currentframe.left = 288.f ;
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		this->m_sprite.setScale(.7,.7);
		this->m_sprite.setOrigin(0.f, 0.f);
	
	} else if (this->animstate == PLAYER_ANIMATION_STATES::DEAD)
	{	
		if(this->animationtimer.getElapsedTime().asSeconds() >= 0.6f || this->getanimswitch())
		{	
			
			this->currentframe.top = 180.f;
			this->currentframe.left += 50.f;
			
			if(this->currentframe.left >= 240.f) this->currentframe.left = 0.f;
			
			this->animationtimer.restart(); /// cuando pasa medio segundo se reinicia
			this->m_sprite.setTextureRect(this->currentframe);
		}
		this->m_sprite.setScale(.7,.7);
		this->m_sprite.setOrigin(0.f, 0.f);
	
	} else this->animationtimer.restart();
}

void Personaje::initanimations() 
{
	this->animationtimer.restart(); // se reinicia al iniciar cada animacion
	this->animationswitch = true;
}

const bool &Personaje::getanimswitch()  // para corregir el error en el timer 
{
	bool anim_switch = this->animationswitch;
	if(this->animationswitch) this->animationswitch = false;
	return this->animationswitch = false;
}

void Personaje::setHp(const int hp)
{
	this->hp = hp;
}

void Personaje::resetanimationtimer() 
{
	this->animationtimer.restart();
	this->animationswitch = true;
}

void Personaje::recibirdanio()
{
	if(this->hp > 0)
		this-> hp -= 1; /// cant de daño que recibe 
	
	if(this->hp < 0 )
		this->hp = 0; /// para que la vida nunca quede en numeros negativos
}

void Personaje::curarse(const int vida)
{
	if(this->hp < this->hpmax)
		this->hp += vida;
		
	if(this->hp > this->hpmax)
		this->hp = this->hpmax; /// para que nunca se pase de la vida maxima
}

std::pair<float,float> collide(FloatRect b1, FloatRect b2) { /// sistema de colisiones 

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

void Personaje::Update(vector<RectangleShape> muros){ /// recibe la ubicacion exacta de las plataformas
	
	this->animstate = PLAYER_ANIMATION_STATES::IDLE;
	FloatRect player_bounds = m_sprite.getGlobalBounds(); /// COLISIONES DEL JUGADOR
	Vector2f p = m_sprite.getPosition(); ///getposition nos da un struct con su posicion en x e y

	this->agachado = false;
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		this->animstate = PLAYER_ANIMATION_STATES::CROUCHING;
		this->agachado = true;
	} 
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		m_speed.x = -3;
		this->animstate = PLAYER_ANIMATION_STATES::MOVING_LEFT; /// cambio de estado a moviendo a la izquierda

	} else if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		m_speed.x = 3;
		this->animstate = PLAYER_ANIMATION_STATES::MOVING_RIGHT; /// cambio de estado a moviendo a la derecha
		
	} else if (Keyboard::isKeyPressed(Keyboard::W)) 
	{
		this->animstate = PLAYER_ANIMATION_STATES::JUMPING; 
	} else m_speed.x = 0;
	
	/// colisiones con los margenes de la pantalla 
	
	if(p.x < 0) {
		p.x = 0; m_speed.x = 0;
	}
	if(p.x + player_bounds.width > WINDOW_WIDTH) {
		p.x = WINDOW_WIDTH - player_bounds.width; m_speed.x = 0;
	}
	if(player_bounds.top < 40) {
		p.y = player_bounds.top; m_speed.y = 0;
	}
	
	m_speed.y += .5 ; /// en cada update se va incrementando la velocidad de caida entonces da un efecto
	/// de caida mas realista
	p += m_speed; /// le sumo la velocidad a la posicion actual
	
	m_sprite.setPosition(p);
	
	///cuando el personaje hace la fuerza para saltar la gravedad lo frena y lo hace ir hacia abajo

	/// para todas las plataformas en el vector...
	for(const auto&plataforma : muros) {
		FloatRect colisionesp = m_sprite.getGlobalBounds();
		FloatRect colisionesmuro = plataforma.getGlobalBounds();
		
		colisionesp.left+=5; colisionesp.width-=10; /// para corregir la hitbox
		colisionesp.top+=5; colisionesp.height-=6;
		
		auto col = collide(colisionesp,colisionesmuro);
		
		if (col.second!=0) { 	
			p.y += col.second;
			if (m_speed.y >= 0 && Keyboard::isKeyPressed(Keyboard::W)) {
				m_speed.y = -9.0f;  ///velocidad negativa significa que esta yendo para arriba
				this->animstate = PLAYER_ANIMATION_STATES::JUMPING; /// cambio de estado a saltando
			} else
				m_speed.y = 0.f;
				m_sprite.setPosition(p);
		} 
	}
	this->updateanimations(); /// actualizo las animaciones en el update del personaje
}

void Personaje::draw (RenderWindow & window) {
window.draw(m_sprite);

}



