#include "player.h"



Player::Player() {

	add_component(new Transform(this));
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
		sf::Texture* _temp = &sprite->texture;
		add_component(new Animation(_temp));
	}
}


void Player::input(sf::Keyboard::Key _key) {

	float _value = 0;

	Velocity* vel = this->get_component<Velocity>();

	if (_key == sf::Keyboard::Key::W) {
		vel->delta_position = {0, -1};
	}
	if (_key == sf::Keyboard::Key::S) {
		vel->delta_position = { 0, 1 };
	}
	if (_key == sf::Keyboard::Key::D) {
		vel->delta_position = { 1, 0 };
	}
	if (_key == sf::Keyboard::Key::A) {
		vel->delta_position = { -1, 0 };
	}
}

