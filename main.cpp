#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    VideoMode vm(1920,1080);

    RenderWindow window(vm, "Timber", Style::Fullscreen);

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
        window.display();

    }

    return 0;
}