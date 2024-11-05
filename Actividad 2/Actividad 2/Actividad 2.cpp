#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Texture texture;
Sprite sprite1, sprite2, sprite3, sprite4;
bool isDragging = false;
Sprite* draggedSprite = nullptr;
Vector2f offset;


int main() {
	if (!texture.loadFromFile("rcircle.PNG")) {
		std::cerr << "error al cargar la textura rcircle.PNG" << std::endl;
	}
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sprite4.setTexture(texture);

	sprite1.setPosition(0, 0);
	sprite2.setPosition((800 - 128), 0);
	sprite3.setPosition(0, (600 - 128));
	sprite4.setPosition((800 - 128), (600 - 128));

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Actividad 2");

	Event evt;

	while (App.isOpen()) {
		App.clear();
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::KeyPressed:
				if ((evt.key.code) == sf::Keyboard::Escape){
					App.close();
				}
				break;
			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Left) {
					for (Sprite* sprite : { &sprite1, &sprite2, &sprite3, &sprite4 }) {
						if (sprite->getGlobalBounds().contains(evt.mouseButton.x, evt.mouseButton.y)) {
							isDragging = true;
							draggedSprite = sprite;
							offset = sprite->getPosition() - Vector2f(evt.mouseButton.x, evt.mouseButton.y);
							break;
						}
					}
				}
				break;
			case Event::MouseButtonReleased:
				if (evt.mouseButton.button == Mouse::Left) {
					isDragging = false;
					draggedSprite = nullptr;
				}
				break;
			case Event::MouseMoved:
				if (isDragging && draggedSprite) {
					Vector2i mousePos = Mouse::getPosition(App);
					draggedSprite->setPosition(static_cast<float>(mousePos.x) + offset.x, static_cast<float>(mousePos.y) + offset.y);
				}
				break;
			}
		}
		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);
		App.display();
	}
}