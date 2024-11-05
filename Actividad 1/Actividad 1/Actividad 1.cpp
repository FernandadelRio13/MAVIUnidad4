#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
Sprite sprite;

int main() {
	texture.loadFromFile("crosshair.PNG");
	sprite.setTexture(texture);
	sprite.setPosition((800-128)/2, (600-128)/2);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Actividad 1");

	Event evt;

	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::KeyPressed:Escape:
				App.close();
				break;
			}
		}
		App.clear();
		App.draw(sprite);
		App.display();
	}
}