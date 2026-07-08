//
// Created by Pawel Czarzasty on 16/05/2024.
//

#ifndef SNAKE_SNAKEVIEW_H
#define SNAKE_SNAKEVIEW_H
#include "SNAKEBoard.h"
#include <SFML/Graphics.hpp>
using namespace std;

class SNAKEView {
    SNAKEBoard &board;
    int windowWidth = 800;
    int windowHeight = 770;
    int col = 20;
    int row = 18;
    int Sizex = 40;
    int Sizey = 40;
    sf::Font font;
    string pkt;

public:
    SNAKEView(SNAKEBoard &board);
    void display(sf::RenderWindow &window);
    void displayMenu(sf::RenderWindow &window);
    void drawSnake(sf::RenderWindow &window, const std::vector<SnakePart> &positions);
};


#endif //SNAKE_SNAKEVIEW_H
