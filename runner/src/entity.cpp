#include "entity.h"



Entity::Entity() {

}

Entity::~Entity() {
	for (auto c : components) {
		delete c;
	}
}

void Entity::add_component(Component* _component) {
	components.push_back(_component);
}

void Entity::update() {
	for (auto& c : components) {
		c->update();
	}
}

void Entity::render(sf::RenderWindow& _window) {
	for (auto& c : components) {
		c->render(_window);
	}
}

void Entity::get_picture(std::string _path) {
	for (auto& c : components) {
		c->get_picture(_path);
	}
}
