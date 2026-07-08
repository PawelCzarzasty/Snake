//
// Created by Pawel Czarzasty on 16/05/2024.
//

#include "SNAKEView.h"

SNAKEView::SNAKEView(SNAKEBoard &board) : board(board){
    font.loadFromFile("../comic.ttf");

}
void SNAKEView::displayMenu(sf::RenderWindow &window) {


    sf::RectangleShape rectangle(sf::Vector2f(windowWidth, windowHeight));
    rectangle.setPosition(0, 0);
    rectangle.setFillColor(sf::Color(0,100,0));
    window.draw(rectangle);

    sf::Text Snake("SNAKE" , sf::Font(), 60);
    Snake.setFont(font);
    Snake.setPosition(280, 5);
    Snake.setFillColor(sf::Color(250,240,0));
    window.draw(Snake);

    sf::RectangleShape table(sf::Vector2f(400, 450));
    table.setPosition(200, 270);
    table.setFillColor(sf::Color(255,255,255));
    window.draw(table);

    sf::RectangleShape easy(sf::Vector2f(200, 100));
    easy.setPosition(100, 100);
    easy.setFillColor(sf::Color(0,255,0));
    window.draw(easy);

    sf::RectangleShape medium(sf::Vector2f(200, 100));
    medium.setPosition(310, 100);
    medium.setFillColor(sf::Color(100,100,0));
    window.draw(medium);

    sf::RectangleShape hard(sf::Vector2f(200, 100));
    hard.setPosition(520, 100);
    hard.setFillColor(sf::Color(255,0,0));
    window.draw(hard);

    sf::RectangleShape exit(sf::Vector2f(150, 90));
    exit.setPosition(610, 620);
    exit.setFillColor(sf::Color(255,0,0));
    window.draw(exit);

    sf::Text Exit("EXIT" , sf::Font(), 30);
    Exit.setFont(font);
    Exit.setPosition(640, 640);
    Exit.setFillColor(sf::Color(250,240,0));
    window.draw(Exit);

    sf::Text Easy("EASY" , sf::Font(), 30);
    Easy.setFont(font);
    Easy.setPosition(150, 130);
    Easy.setFillColor(sf::Color(250,240,0));
    window.draw(Easy);

    sf::Text Medium("MEDIUM" , sf::Font(), 30);
    Medium.setFont(font);
    Medium.setPosition(350, 130);
    Medium.setFillColor(sf::Color(250,240,0));
    window.draw(Medium);

    sf::Text Hard("HARD" , sf::Font(), 30);
    Hard.setFont(font);
    Hard.setPosition(570, 130);
    Hard.setFillColor(sf::Color(250,240,0));
    window.draw(Hard);

    sf::Text Score("TABLICA WYNIKOW" , sf::Font(), 40);
    Score.setFont(font);
    Score.setPosition(190, 210);
    Score.setFillColor(sf::Color(250,240,0));
    window.draw(Score);

    for (size_t i = 0; i < board.Points.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(i + 1) + ". " + std::to_string(board.Points[i]));
        text.setCharacterSize(27);
        text.setFillColor(sf::Color::Black);
        text.setPosition(220, 35 * i + 300);
        window.draw(text);
    }

}
void SNAKEView::display(sf::RenderWindow &window) {
    for (int y = 0; y < row; ++y) {
        for (int x = 0; x < col; ++x) {
            sf::RectangleShape square(sf::Vector2f(Sizex, Sizey));
            square.setPosition(x * Sizex, y * Sizey+50);
            if ((x + y) % 2 == 0) {
                square.setFillColor(sf::Color(0,255,0));
            } else {
                square.setFillColor(sf::Color(0,120,0));
            }
            window.draw(square);
        }
    }
    drawSnake(window, board.getSegments());

    sf::CircleShape circle(Sizey / 2.2f);
    circle.setFillColor(sf::Color(200,0,0));
    circle.setPosition(board.Apple.x * Sizey + Sizey/2, (board.Apple.y * Sizey+ Sizey/2)+50);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    window.draw(circle);

    sf::RectangleShape rectangle(sf::Vector2f(windowWidth, 50));
    rectangle.setPosition(0, 0);
    rectangle.setFillColor(sf::Color(0,0,0));
    window.draw(rectangle);

    pkt = to_string(board.points);
    sf::Text points(pkt , sf::Font(), 40);
    points.setFont(font);
    points.setPosition(600, 5);
    points.setFillColor(sf::Color(250,240,0));
    window.draw(points);

    sf::Text punkty("PUNKTY: " , sf::Font(), 40);
    punkty.setFont(font);
    punkty.setPosition(400, 5);
    punkty.setFillColor(sf::Color(250,240,0));
    window.draw(punkty);

}

void SNAKEView::drawSnake(sf::RenderWindow &window, const std::vector<SnakePart> &positions) {
    for (const auto &position : positions) {
        sf::CircleShape circle(Sizey / 2.1f);
        circle.setFillColor(sf::Color(255,0,255));
        circle.setOrigin(circle.getRadius(), circle.getRadius());
        circle.setPosition(position.x * Sizey + Sizey/2, (position.y * Sizey + Sizey/2)+50);
        window.draw(circle);
    }
}
