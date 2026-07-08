//
// Created by Pawel Czarzasty on 16/05/2024.
//
using namespace std;
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "SNAKEBoard.h"
SNAKEBoard::SNAKEBoard() {
    srand( time( NULL ) );
    direction = RIGHT;
    Gamestate = RUNNING;
    points = 0;
    segments = {{3, 3},{4,3},{5, 3},{6,3},{7,3},{8,3}};
}
void SNAKEBoard::SetApple() {
    Apple.x = rand()%20;
    Apple.y = rand()%18;
}
void SNAKEBoard::move() {
    SnakePart head = segments.front();
    SnakePart new_head = head;
    if(Gamestate == RUNNING){
        switch (direction) {
            case UP:
                new_head.y -= 1;
                break;
            case DOWN:
                new_head.y += 1;
                break;
            case LEFT:
                new_head.x -= 1;
                break;
            case RIGHT:
                new_head.x += 1;
                break;
        }
        segments.insert(segments.begin(), new_head);
        segments.pop_back();
    }
    if(eatHimself()){
        Gamestate = FINISHED_LOSS;
    }
    if(Apple.x == head.x and Apple.y == head.y){
        Gamestate = RUNNING;
        Eat();
        SetApple();
    }
    if(head.x <=0 or head.x>19 or head.y<=0 or head.y>17){
        Gamestate = FINISHED_LOSS;
    }

}
bool SNAKEBoard::eatHimself() {
    int count = 0;
    SnakePart head = segments.front();
    for (SnakePart part : segments) {
        if(part.x == head.x and part.y == head.y and part.x!=3 and part.y!=3){
            count++;
        }
    }
    if(count >1){
        return true;
    }
    return false;
}
void SNAKEBoard::changeDirection(int dir) {
    switch (dir) {
        case 1:
            if(direction != LEFT){
                direction = RIGHT;
            }
            break;
        case 2:
            if(direction != RIGHT){
                direction = LEFT;
            }
            break;
        case 3:
            if(direction != DOWN){
                direction = UP;
            }
            break;
        case 4:
            if(direction != UP){
                direction = DOWN;
            }
            break;

    }
}

void SNAKEBoard::loadScores() {
    ifstream file("../scores.txt");

    if (file.is_open()) {
        int score;
        while (file >> score) {
            Points.push_back(score);
        }
        file.close();
    }
}
void SNAKEBoard::saveHighScores() {
    std::ofstream file("../scores.txt");
    if (file.is_open()) {
        for (int score : Points) {
            file << score << std::endl;
        }
        file.close();
    }
}
void SNAKEBoard::updateHighScores(int newScore) {
    Points.push_back(newScore);
    sort(Points.begin(), Points.end(), std::greater<int>());
    if (Points.size() > 10) {
        Points.resize(10);
    }
}

void SNAKEBoard::Eat() {
    SnakePart new_head = segments.front();
    switch (direction) {
        case UP:    new_head.y -= 1; break;
        case DOWN:  new_head.y += 1; break;
        case LEFT:  new_head.x -= 1; break;
        case RIGHT: new_head.x += 1; break;
    }
    segments.insert(segments.begin(), new_head); // Dodajemy nową głowę, bez usuwania ogona
    points ++;
}
GameState SNAKEBoard::GetGameState() const {
    return Gamestate;
}
const vector<SnakePart>& SNAKEBoard::getSegments() const {
    return segments;
}

