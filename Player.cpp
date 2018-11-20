//
// Created by multiojuice on 11/18/18.
//

#include "Player.h"

Player::Player() {
    speed  = START_SPEED;
    health = START_HEALTH;
    maxHealth = START_HEALTH;

    texture.loadFromFile("../assets/player-zombie.png");
    sprite.setTexture(texture);
    sprite.setOrigin(25,25);
}

void Player::spawn(IntRect tempArena, Vector2f tempResolution, int tempTileSize) {
    position.x = arena.width / 2;
    position.y = arena.height / 2;

    arena.left = tempArena.left;
    arena.width = tempArena.width;
    arena.height = tempArena.height;
    arena.top = tempArena.top;

    tileSize = tempTileSize;

    resolution.x = tempResolution.x;
    resolution.y = tempResolution.y;
}

void Player::resetPlayerStats() {
    speed  = START_SPEED;
    health = START_HEALTH;
    maxHealth = START_HEALTH;
}

Time Player::getLastTimeHit() {
    return lastHit;
}

bool Player::hit(Time timeHit) {
    if (timeHit.asMilliseconds() - lastHit.asMilliseconds() > 2000) {
        lastHit = timeHit;
        health -= 10;
        return true;
    }

    return false;
}

Sprite Player::getSprite() {
    return sprite;
}

float Player::getPosition() {
    sprite.getGlobalBounds();
}

float Player::getRotation() {
    sprite.getRotation();
}

Vector2f Player::getCenter() {
    return position;
}

int Player::getHealth() {
    return health;
}

// Moves
void Player::moveUp() {
    upPressed = true;
}
void Player::moveDown() {
    downPressed = true;
}
void Player::moveLeft(){
    leftPressed = true;
}
void Player::moveRight(){
    rightPressed = true;
}

// Stops
void Player::stopUp() {
    upPressed = false;
}
void Player::stopDown() {
    downPressed = false;
}
void Player::stopLeft(){
    leftPressed = false;
}
void Player::stopRight(){
    rightPressed = false;
}


// UPDATE THE PLAYER
