#include "Boton.h"
using namespace sf;

Boton::Boton() {
	boton.setFillColor(Color::White);
	fuente.loadFromFile("Alinore.otf");
	texto.setFont(fuente);
	boton.setOutlineColor(Color(50,50,100));
	boton.setOutlineThickness(2);
}

