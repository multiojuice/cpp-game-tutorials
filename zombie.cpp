#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

using namespace sf;

int main()
{
    enum class State {
        PAUSED, PLAYING, LEVELING_UP, GAME_OVER
    };

    State state = State::GAME_OVER;

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie Arena", Style::Fullscreen);

    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    Clock clock;
    Time gameTimeTotal;

    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;

    Player player;
    IntRect arena;

    while (window.isOpen()) {
        // Poll for Events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Return && state == State::PLAYING) {
                    state = State::PAUSED;
                } else if (event.key.code == Keyboard::Return && state == State::PAUSED) {
                    state = State::PLAYING;
                    clock.restart();
                } else if (event.key.code == Keyboard::Return && state == State::GAME_OVER) {
                    state = State::LEVELING_UP;
                }

                if (state == State::PLAYING) {

                }
            }
        } // End of polling

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (state == State::LEVELING_UP) {
            if (Keyboard::isKeyPressed(Keyboard::Num1)) {
                state = State::PLAYING;
            }

            if (Keyboard::isKeyPressed(Keyboard::Num2)) {
                state = State::PLAYING;
            }

            if (Keyboard::isKeyPressed(Keyboard::Num3)) {
                state = State::PLAYING;
            }

            if (Keyboard::isKeyPressed(Keyboard::Num4)) {
                state = State::PLAYING;
            }

            if (Keyboard::isKeyPressed(Keyboard::Num5)) {
                state = State::PLAYING;
            }

            if (Keyboard::isKeyPressed(Keyboard::Num6)) {
                state = State::PLAYING;
            }

            if(state == State::PLAYING) {
                arena.width = 500;
                arena.height = 500;
                arena.top = 0;
                arena.left = 0;

                int tileSize = 50;

                player.spawn(arena, resolution, tileSize);
            }

        }

        if (state == State::PLAYING) {
            // Handle movement
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player.moveUp();
            } else player.stopUp();
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                player.moveDown();
            } else player.stopDown();
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.moveLeft();
            } else player.stopLeft();
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                player.moveRight();
            } else player.stopRight();
        }
    }
    return 0;
}
