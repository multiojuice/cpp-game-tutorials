#include <SFML/Graphics.hpp>

using namespace sf;

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
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

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

        /*
         * ********************
         * Draw the scene
         * ********************
         */
        window.clear();

        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();

    }

    return 0;
}