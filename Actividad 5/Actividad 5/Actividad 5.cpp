#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

using namespace sf;

int main() {
    RenderWindow App(VideoMode(800, 600), "Actividad 5");

    Event evt;

    while (App.isOpen()) {
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case Event::Closed:
                App.close();
                break;
            case Event::KeyPressed:
                if (evt.key.code == Keyboard::Escape) {
                    App.close();
                    break;
                }
                if (evt.key.code == Keyboard::Up) {
                    Vector2u size = App.getSize();
                    if (size.x < 1000 && size.y < 1000) {
                        App.setSize(Vector2u(std::min(size.x + 11, 1000u), std::min(size.y + 11, 1000u)));
                    }
                    break;
                }
                if (evt.key.code == Keyboard::Down) {
                    Vector2u size = App.getSize();
                    if (size.x > 100 && size.y > 100) {
                        App.setSize(Vector2u(std::max(size.x - 11, 100u), std::max(size.y - 11, 100u)));
                    }
                    break;
                }
            }

        }
        App.clear();
        App.display();
    }
    return 0;
}

