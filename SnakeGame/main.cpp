#include <iostream>
#include "SNAKEBoard.h"
#include "SNAKEController.h"
#include "SNAKEView.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 770), "SNAKE");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(120);
    SNAKEBoard board;
    board.loadScores();
    SNAKEView view(board);
    SNAKEController ctrl(board, view);
    ctrl.menu(window);

//    view.display(window);
//    ctrl.play(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }
    return 0;
}
