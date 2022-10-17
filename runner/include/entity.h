#include <SFML/Graphics.hpp>
#include <vector>

//TODO:
//Change name of get_picture



struct Component {
	virtual ~Component() = default;
	virtual void get_picture(std::string _path) = 0;
	virtual void update(float _delta) = 0;
	virtual void render(sf::RenderWindow& _window) = 0;
};


class Entity {
public:
	Entity();
	~Entity();
	void update(float _delta);
	void get_picture(std::string _path); //Delete this shit
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
	void update(float _delta) override {}
	void render(sf::RenderWindow& _window) override {}

	sf::Vector2f delta_position;

};

struct Transform : Component {
	Transform(Entity* _parent) { //This doesnt follow Modern c++ standards!!!
		parent = _parent;
	};

	void get_picture(std::string _path) override {}
	void update(float _delta) override {
		Velocity* velocity = parent->get_component<Velocity>();
		if (velocity) {
			position += velocity->delta_position;
		}

	}
	void render(sf::RenderWindow& _window) override {}

	sf::Vector2f position = { 0,0 };
	float rotation = 0;

	Entity* parent;
};

struct Animation : Component {

	Animation(sf::Texture* _texture) {
		current_image = 0;
		switch_time = 0.3f;
		total_time = 0.0f;
		texture = _texture;
		image_count = 3;
		uv_rect.width = texture->getSize().x / image_count;
		uv_rect.height = texture->getSize().y / image_count;
	};

	sf::Texture* texture;

	void get_picture(std::string _path) override {}
	void update(float _delta) override {

		total_time += _delta;

		if (total_time >= switch_time) {

			total_time -= switch_time;
			current_image++;

			if (current_image >= image_count) {
				current_image = 0;
			}
		}

		uv_rect.left = current_image * uv_rect.width;
		uv_rect.top = current_image * uv_rect.height;

	}
	void render(sf::RenderWindow& _window) override {}

	int image_count;
	int current_image;

	sf::IntRect uv_rect;

	float total_time;
	float switch_time;
};

struct Illustrator : Component {
	Illustrator(Entity* _parent) { //This doesnt follow Modern c++ standards!!!
		parent = _parent;
	};
	sf::RectangleShape visual;

	sf::Texture texture;

	void get_picture(std::string _path) override {
		if (!texture.loadFromFile(_path)) {

		}
		//sprite.setTexture(texture);
		visual.setTexture(&texture);
		visual.setSize({ 50,50 }); //Has to be the size of one frame
	}
	void update(float _delta) override {
		Animation* anim = parent->get_component<Animation>();
		Transform* transform = parent->get_component<Transform>();
		if (transform) {
			visual.setPosition(transform->position);
		}
		if (anim) {
			visual.setTextureRect(anim->uv_rect);
		}
	}
	void render(sf::RenderWindow& _window) override {
		_window.draw(visual);
	}


	Entity* parent = nullptr;
};

