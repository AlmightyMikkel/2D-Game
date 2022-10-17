#include "player.h"



Player::Player() {

	add_component(new Transform);
	add_component(new Velocity);
	add_component(new Illustrator(this));

	speed = 10;
	Initialize();
}


void Player::Initialize() {
	Transform* transform = this->get_component<Transform>();
	if (transform) {
		transform->position = {200, 200};
	}

	Illustrator* sprite = this->get_component<Illustrator>();
	if (sprite) {
		sprite->get_picture("assets/player.png");
	}
}


void Player::Move() {
	Velocity* velocity = this->get_component<Velocity>();



}