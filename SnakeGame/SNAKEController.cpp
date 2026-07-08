//
// Created by Pawel Czarzasty on 23/05/2024.
//

#include "SNAKEController.h"
#include <iostream>
SNAKEController::SNAKEController(SNAKEBoard &board, SNAKEView &view) : board(board), view(view){

}
void SNAKEController::menu(sf::RenderWindow &window) {
    while(window.isOpen()) {
        view.displayMenu(window);
        window.display();
        sf::Event event1;
        while (window.pollEvent(event1)) {
            if (event1.type == sf::Event::MouseButtonPressed) {
                if (event1.mouseButton.x > 100 and event1.mouseButton.x < 300 and event1.mouseButton.y > 100 and
                    event1.mouseButton.y < 200) {
                    if (event1.mouseButton.button == sf::Mouse::Left) {
                        board.Gamestate = RUNNING;
                        play(window, 130);
                        board.updateHighScores(board.points);
                        board.saveHighScores();

                    }

                }
                if (event1.mouseButton.x > 310 and event1.mouseButton.x < 510 and event1.mouseButton.y > 100 and
                    event1.mouseButton.y < 200) {
                    if (event1.mouseButton.button == sf::Mouse::Left) {
                        board.Gamestate = RUNNING;
                        play(window, 100);
                        board.updateHighScores(board.points);
                        board.saveHighScores();
                    }

                }
                if (event1.mouseButton.x > 520 and event1.mouseButton.x < 720 and event1.mouseButton.y > 100 and
                    event1.mouseButton.y < 200) {
                    if (event1.mouseButton.button == sf::Mouse::Left) {
                        board.Gamestate = RUNNING;
                        play(window, 70);
                        board.updateHighScores(board.points);
                        board.saveHighScores();
                    }
                }
                if (event1.mouseButton.x > 610 and event1.mouseButton.x < 720 and event1.mouseButton.y > 620 and
                    event1.mouseButton.y < 710) {
                    if (event1.mouseButton.button == sf::Mouse::Left) {
                        window.close();
                    }
                }

            }
        }
    }
}
void SNAKEController::play(sf::RenderWindow &window, int lvl) {
    board.points = 0;
    board.segments = {{3, 3},{4,3},{5, 3}};
    board.direction = RIGHT;
    board.SetApple();
    while (board.GetGameState() == RUNNING)
    {
            sf::Event event;
            while (window.pollEvent(event))
            {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    board.changeDirection(1);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    board.changeDirection(2);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    board.changeDirection(3);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    board.changeDirection(4);
                }
            }
            sf::sleep(sf::milliseconds(lvl));
            board.move();
            window.clear();
            view.display(window);
            window.display();
    }

}
