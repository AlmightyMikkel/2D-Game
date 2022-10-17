#include <SFML/Graphics.hpp>
#include <vector>


//TODO:
//	Make Animation Component
//TODO:
//Change name of get_picture



struct Component {
	virtual ~Component() = default;
	virtual void get_picture(std::string _path) = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& _window) = 0;
};


class Entity {
public:
	Entity();
	~Entity();
	void update();
	void get_picture(std::string _path);
	void render(sf::RenderWindow& _window);
	void add_component(Component* _component);
	template <typename T, typename...Ts>
	void add_component(Ts && ...types) {
		add_component(new Component(std::forward<Ts>(Ts)...));
	}
	template <class T>
	T* get_component() {
		for (auto& c : components) {
			if (T* ptr = dynamic_cast<T*>(c)) {
				return ptr;
			}
		}
		return nullptr;
	}

private:
	std::vector<Component*> components;
};




struct Velocity : Component {
	Velocity() = default;

	void get_picture(std::string _path) override {}
	void update() override {}
	void render(sf::RenderWindow& _window) override {}

	sf::Vector2f delta_position;

};

struct Transform : Component {
	Transform() = default;

	void get_picture(std::string _path) override {}
	void update() override {	}
	void render(sf::RenderWindow& _window) override {}

	sf::Vector2f position = { 0,0 };
	float rotation = 0;
};

struct Illustrator : Component {
	Illustrator(Entity* _parent) {
		parent = _parent;
	};
	sf::Texture texture;
	sf::Sprite sprite;

	void get_picture(std::string _path) override {
		if (!texture.loadFromFile(_path)) {

		}
		sprite.setTexture(texture);
	}
	void update() override {
		Transform* transform = parent->get_component<Transform>();
		if (transform) {
			sprite.setPosition(transform->position);
		}
	}
	void render(sf::RenderWindow& _window) override {
		_window.draw(sprite);
	}


	Entity* parent = nullptr;
};