#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Texture texture_cuad, texture_cir;
Sprite sprite_cuad, sprite_cir;

int main() {
	if (!texture_cuad.loadFromFile("cuad_yellow.PNG")) {
		std::cerr << "error en la carga de textura" << std::endl;
	}
	if (!texture_cir.loadFromFile("rcircleg.PNG")) {
		std::cerr << "error en la carga de textura" << std::endl;
	}
	sprite_cuad.setTexture(texture_cuad);
	sprite_cir.setTexture(texture_cir);

	bool isVisible_cuad = true;
	bool isVisible_cir = false;

	float scaleFactor = 0.25f;
	sprite_cuad.setScale(scaleFactor, scaleFactor);

	//al reducir la escala, en vez de 512x512 quedo en 128x128
	sprite_cuad.setPosition((800 - 128) / 2, (600 - 128) / 2);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Actividad 4");

	Event evt;

	while (App.isOpen()) {
		App.clear();
		while (App.pollEvent(evt)) {
			switch (evt.type) {
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::KeyPressed:
				if ((evt.key.code) == (Keyboard::Escape)) {
					App.close();
				}
				else if ((evt.key.code) == (Keyboard::Up)) {
					sprite_cuad.setPosition(sprite_cuad.getPosition().x, sprite_cuad.getPosition().y - 10);
					sprite_cir.setPosition(sprite_cir.getPosition().x, sprite_cir.getPosition().y - 10);
				}
				else if ((evt.key.code) == (Keyboard::Down)) {
					sprite_cuad.setPosition(sprite_cuad.getPosition().x, sprite_cuad.getPosition().y + 10);
					sprite_cir.setPosition(sprite_cir.getPosition().x, sprite_cir.getPosition().y + 10);
				}
				else if ((evt.key.code) == (Keyboard::Left)) {
					sprite_cuad.setPosition(sprite_cuad.getPosition().x - 10, sprite_cuad.getPosition().y);
					sprite_cir.setPosition(sprite_cir.getPosition().x - 10, sprite_cir.getPosition().y);
				}
				else if ((evt.key.code) == (Keyboard::Right)) {
					sprite_cuad.setPosition(sprite_cuad.getPosition().x + 10, sprite_cuad.getPosition().y);
					sprite_cir.setPosition(sprite_cir.getPosition().x + 10, sprite_cir.getPosition().y);
				}
				else if ((evt.key.code) == (Keyboard::Space)) {
					sprite_cir.setPosition(sprite_cuad.getPosition().x, sprite_cuad.getPosition().y);
					isVisible_cuad = !isVisible_cuad;
					isVisible_cir = !isVisible_cir;
				}
			}
			if (sprite_cuad.getPosition().x < 0) {
				sprite_cuad.setPosition(0, sprite_cuad.getPosition().y);
			}
			if (sprite_cuad.getPosition().x > (800-128)) {
				sprite_cuad.setPosition((800 - 128), sprite_cuad.getPosition().y);
			}
			if (sprite_cuad.getPosition().y < 0) {
				sprite_cuad.setPosition(sprite_cuad.getPosition().x, 0);
			}
			if (sprite_cuad.getPosition().y > (600-128)) {
				sprite_cuad.setPosition(sprite_cuad.getPosition().x, (600 - 128));
			}
			if (sprite_cir.getPosition().x < 0) {
				sprite_cir.setPosition(0, sprite_cir.getPosition().y);
			}
			if (sprite_cir.getPosition().x > (800 - 128)) {
				sprite_cir.setPosition((800 - 128), sprite_cir.getPosition().y);
			}
			if (sprite_cir.getPosition().y < 0) {
				sprite_cir.setPosition(sprite_cir.getPosition().x, 0);
			}
			if (sprite_cir.getPosition().y > (600 - 128)) {
				sprite_cir.setPosition(sprite_cir.getPosition().x, (600 - 128));
			}
		}
		if (isVisible_cuad == true) {
			App.draw(sprite_cuad);
		}
		if (isVisible_cir == true) {
			App.draw(sprite_cir);
		}
		App.display();
	}
}