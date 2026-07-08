//
// Created by Pawel Czarzasty on 16/05/2024.
//

#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H
#include <vector>
#include <fstream>
using namespace std;
enum GameState {RUNNING, FINISHED_LOSS};
enum Direction { UP, DOWN, LEFT, RIGHT };
struct SnakePart{
    int x;
    int y;
};
struct apple{
    int x;
    int y;
};
class SNAKEBoard {
public:
    int points;
    vector <SnakePart> segments;
    vector <int> Points;
    void Eat();
    void changeDirection(int dir);
    SNAKEBoard();
    GameState Gamestate;
    Direction direction = RIGHT;
    void move();
    apple Apple;
    void SetApple();
    bool eatHimself();
    const vector<SnakePart>& getSegments() const;
    GameState GetGameState() const;
    void loadScores();
    void saveHighScores();
    void updateHighScores(int newScore);

};


#endif //SNAKE_SNAKEBOARD_H
