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

FloatRect Player::getPosition() {
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
void Player::moveLeft() {
    leftPressed = true;
}
void Player::moveRight() {
    rightPressed = true;
}

// Stops
void Player::stopUp() {
    upPressed = false;
}
void Player::stopDown() {
    downPressed = false;
}
void Player::stopLeft() {
    leftPressed = false;
}
void Player::stopRight() {
    rightPressed = false;
}


// UPDATE THE PLAYER
void Player::update(float elapsedTime, Vector2i mousePosition) {
    if (upPressed) {
        position.y -= speed * elapsedTime;
    }
    if (downPressed) {
        position.y += speed * elapsedTime;
    }
    if (leftPressed) {
        position.x -= speed * elapsedTime;
    }
    if (rightPressed) {
        position.x += speed * elapsedTime;
    }

    sprite.setPosition(position);

    if (position.x > arena.width - tileSize) {
        position.x = arena.width - tileSize;
    }

    if (position.x < arena.left + tileSize) {
        position.x = arena.left + tileSize;
    }

    if (position.y > arena.height - tileSize) {
        position.y = arena.height - tileSize;
    }

    if (position.y < arena.top + tileSize) {
        position.y = arena.top + tileSize;
    }

    float angle = (atan2(mousePosition.y - resolution.y / 2, mousePosition.x - resolution.x / 2) * 180) / 3.141;
    sprite.setRotation(angle);
}

void Player::upgradeSpeed() {
    speed += START_SPEED * .2;
}

void Player::upgradeHealth() {
    health += START_HEALTH * .2;
}

void Player::increaseHealthLevel(int amount) {
    health += amount;

    if (health > maxHealth) {
        health = maxHealth;
    }
}