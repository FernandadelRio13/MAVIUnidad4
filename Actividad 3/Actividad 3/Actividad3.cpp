#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;

Texture texture_r, texture_b;

int main() {
    RenderWindow App(VideoMode(800, 600), "Actividad 3");

    if (!texture_r.loadFromFile("rcircle.PNG")) {
        std::cerr << "Error al cargar rcircle.PNG" << std::endl;
        return -1;
    }
    if (!texture_b.loadFromFile("rcircleb.PNG")) {
        std::cerr << "Error al cargar bcircle.PNG" << std::endl;
        return -1;
    }

    std::vector<Sprite> circles;

    Event evt;

    while (App.isOpen()) {
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case Event::Closed:
                App.close();
                break;
            case sf::Event::KeyPressed:Escape:
                App.close();
                break;
            case Event::MouseButtonPressed:
                Sprite newCircle;
                if (evt.mouseButton.button == Mouse::Left) {
                    newCircle.setTexture(texture_r);
                }
                else if (evt.mouseButton.button == Mouse::Right) {
                    newCircle.setTexture(texture_b);
                }
                Vector2i mousePos = Mouse::getPosition(App);
                FloatRect bounds = newCircle.getGlobalBounds();
                newCircle.setPosition(static_cast<float>(mousePos.x) - bounds.width / 2.f,
                    static_cast<float>(mousePos.y) - bounds.height / 2.f);
                circles.push_back(newCircle);
                break;
            }
        }

        App.clear(sf::Color::White);

        for (const auto& circle : circles) {
            App.draw(circle);
        }

        App.display();
    }
    return 0;
}