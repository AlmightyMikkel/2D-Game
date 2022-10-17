#include "entity.h"



class Player: public Entity {
public:
	Player();
	void Initialize();
	void input(sf::Keyboard::Key _key); 
private:
	float speed;
};