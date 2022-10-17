#include "entity.h"



class Player: public Entity {
public:
	Player();
	void Initialize();
	void Move();
private:
	float speed;
};