#ifndef ENDSCENE_H
#define ENDSCENE_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "scene.h"
#include "Menu.h"

class Game;
class endscene : public Scene {
public:
	endscene();
	void ProcessEvent(Game &game, Event &event) override;
	void Update(Game &game, RenderWindow &window) override;
	void Draw(RenderWindow &window) override;
private:
	Texture t_fondo;
	Sprite s_fondo;
	Font d_fuente;
	Text d_text, r_text,ti_scores;
	vector<int> BestScores;
};

#endif

