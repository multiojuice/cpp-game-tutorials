//
// Created by multiojuice on 11/18/18.
//

#ifndef CPP_GAME_TUTORIALS_PLAYER_H
#define CPP_GAME_TUTORIALS_PLAYER_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;

    Vector2f position;
    Sprite sprite;
    Texture texture;

    Vector2f resolution;
    IntRect arena;
    int tileSize;

    bool upPressed;
    bool downPressed;
    bool rightPressed;
    bool leftPressed;

    int health;
    int maxHealth;

    Time lastHit;
    float speed;

public:
    Player();

    void spawn();
    void resetPlayerStats();

    bool hit(Time timeHit);

    Time getLastTimeHit();
    FloatRect getPosition();
    Vector2f getCenter();
    float getRotation();
    Sprite getSprite();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

};


#endif //CPP_GAME_TUTORIALS_PLAYER_H
