#include <SFML/Graphics.hpp>

using namespace sf;

struct cloud {
    float speed;
    bool isActive;
    Sprite sprite;
} ;

int main() {
    VideoMode vm(1920,1080);

    RenderWindow window(vm, "Timber", Style::Fullscreen);

    // The background
    Texture textureBackground;
    textureBackground.loadFromFile("../assets/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    // The tree
    Texture textureTree;
    textureTree.loadFromFile("../assets/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810,0);

    // The bee
    bool beeActive;
    float beeSpeed = 0.0f;
    Texture textureBee;
    textureBee.loadFromFile("../assets/insect.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0,800);

    //The Clouds
    Texture textureCloud;
    textureCloud.loadFromFile("../assets/cloud.png");
    cloud clouds [3];
    for (int i = 0; i < 3; i++) {
        cloud spriteCloud;
        spriteCloud.sprite.setTexture(textureCloud);
        spriteCloud.sprite.setPosition(0,250 * i);
        spriteCloud.isActive = false;
        spriteCloud.speed = 0.0f;
        clouds[i] = spriteCloud;
    }

    Clock clock;

    // GAME LOOP
    while (window.isOpen()) {

        /*
         * ********************
         * Handle Player Input
         * ********************
        */
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        /*
         * ********************
         * Update the scene
         * ********************
        */

        Time dt = clock.restart();

        if (!beeActive) {
            srand((int)time(0) * 10);
            beeSpeed = (rand() % 200) + 200;

            srand((int)time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        } else {
            spriteBee.setPosition(
                    spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y);

            if (spriteBee.getPosition().x < -100) {
                beeActive = false;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (!clouds[i].isActive) {
                srand((int)time(0) * 10 * (i + 1));
                clouds[i].speed = (rand() % 200);

                srand((int)time(0) * 10 * (i + 1));
                float height = (rand() % 150);
                clouds[i].sprite.setPosition(-200, height);
                clouds[i].isActive = true;
            } else {
                clouds[i].sprite.setPosition(
                        clouds[i].sprite.getPosition().x + (clouds[i].speed * dt.asSeconds()),
                        clouds[i].sprite.getPosition().y);

                if (clouds[i].sprite.getPosition().x > 1920) {
                    clouds[i].speed = false;
                }
            }
        }

        /*
         * ********************
         * Draw the scene
         * ********************
         */
        window.clear();

        window.draw(spriteBackground);
        for (int i = 0; i < 3; i++) {
            window.draw(clouds[i].sprite);
        }
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();

    }

    return 0;
}