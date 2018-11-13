#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;

struct cloud {
    float speed;
    bool isActive;
    Sprite sprite;
} ;

void updateBranches(int seed);
const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];
enum class side {LEFT, RIGHT, NONE};
side branchPositions[NUM_BRANCHES];


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

    // Texts and Fonts
    int score = 0;
    Text messageText;
    Text scoreText;

    Font font;
    font.loadFromFile("../assets/KOMIKAP_.ttf");
    messageText.setFont(font);
    scoreText.setFont(font);

    messageText.setString("Press enter to begin!");
    scoreText.setString("Score = 0");
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    // position the text
    scoreText.setPosition(20,20);
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(
            textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f
            );
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

    // The Time bar
    RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((1920 / 2) - (timeBarStartWidth / 2), 980);

    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    Clock clock;
    bool paused = true;

    // Deal with branches
    Texture textureBranch;
    textureBranch.loadFromFile("../assets/branch.png");

    for (int i = 0; i < NUM_BRANCHES; i++) {
        branches[i].setTexture(textureBranch);
        branches[i].setPosition(-2000,-2000);
        branches[i].setOrigin(220, 20);
    }

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
            if (Keyboard::isKeyPressed(Keyboard::Return)) {
            paused = false;
            score = 0;
            timeRemaining = 5;
        }

        /*
         * ********************
         * Update the scene
         * ********************
        */

        Time dt = clock.restart();

        if (timeRemaining <= 0.0f) {
            paused = true;
            messageText.setString("Out of time!");

            messageText.setOrigin(
                    textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f
            );
            messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
        } else {
            timeRemaining -= dt.asSeconds();
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
        }

        if(!paused) {
            if (!beeActive) {
                srand((int) time(0) * 10);
                beeSpeed = (rand() % 200) + 200;

                srand((int) time(0) * 10);
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
                    srand((int) time(0) * 10 * (i + 1));
                    clouds[i].speed = (rand() % 200);

                    srand((int) time(0) * 10 * (i + 1));
                    float height = (rand() % 150);
                    clouds[i].sprite.setPosition(-200, height);
                    clouds[i].isActive = true;
                } else {
                    clouds[i].sprite.setPosition(
                            clouds[i].sprite.getPosition().x + (clouds[i].speed * dt.asSeconds()),
                            clouds[i].sprite.getPosition().y);

                    if (clouds[i].sprite.getPosition().x > 1920) {
                        clouds[i].isActive = false;
                    }
                }
            }
        }

        // Update the score
        std::stringstream ss;
        ss << "Score = " << score;
        scoreText.setString(ss.str());

        // Update branches
        for (int i = 0; i < NUM_BRANCHES; i++) {
            float height = i * 150;
            if (branchPositions[i] == side::LEFT) {
                branches[i].setPosition(610, height);
                branches[i].setRotation(180);
            } else if (branchPositions[i] == side::RIGHT) {
                branches[i].setPosition(1330, height);
                branches[i].setRotation(0);
            } else {
                branches[i].setPosition(3000, height);
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

        for (int i = 0; i < NUM_BRANCHES; i++) {
            window.draw(branches[i]);
        }

        window.draw(spriteTree);
        window.draw(spriteBee);

        window.draw(scoreText);
        window.draw(timeBar);
        if (paused) window.draw(messageText);
        window.display();
    }

    return 0;
}

void updateBranches(int seed) {
    for (int i = NUM_BRANCHES -1; i > 0; i--) {
        branchPositions[i] = branchPositions[i - 1];
    }

    srand((int) time(0) + seed);
    int r = rand() % 5;
    switch (r) {
        case 0:
            branchPositions[0] = side::LEFT;
            break;

        case 1:
            branchPositions[0] = side::RIGHT;
            break;

        default:
            branchPositions[0] = side::NONE;
    }
}