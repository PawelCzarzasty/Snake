//
// Created by Pawel Czarzasty on 23/05/2024.
//

#ifndef SNAKE_SNAKECONTROLLER_H
#define SNAKE_SNAKECONTROLLER_H
#include "SNAKEBoard.h"
#include "SNAKEView.h"
#include "SFML/Graphics.hpp"
class SNAKEController {
    SNAKEView &view;
    SNAKEBoard &board;
public:
    SNAKEController(SNAKEBoard &board, SNAKEView &view);
    void play(sf::RenderWindow &window, int lvl);
    void menu(sf::RenderWindow &window);
};


#endif //SNAKE_SNAKECONTROLLER_H
