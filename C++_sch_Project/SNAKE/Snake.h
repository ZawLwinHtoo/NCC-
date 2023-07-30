//
// Created by zl_shit_h on 25/07/23.
//

#ifndef C___SCH_PROJECT_SNAKE_H
#define C___SCH_PROJECT_SNAKE_H



#include <iostream>
#include "ncurses.h"
#include "unistd.h"
#include "kbhit.h"
#include "food.h"
#include "ctime"
#include "cstdlib"
#include "vector"
#define WIDTH 50
#define HEIGHT 25
using namespace std;
class Snake{

public:
    Snake(COORD pos, int vel);
    void change_dir(char dir);
    void move_snake();
    COORD get_snake_pos();
    bool eaten(COORD food_pos);
    void snake_grow();
    bool collide();
    vector<COORD> get_snake_body_pos();
    int direction_X = 1;
    int direction_Y = 0;
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector<COORD> body;


};

Snake::Snake(COORD pos, int vel) {
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'd';
    body.push_back(pos);
}

void Snake::change_dir(char dir) {
        direction = dir;

}

void Snake::move_snake() {

    switch (direction) {
        case 'w':
            if(pos.y>=0){
                direction_X=0;
                direction_Y=-1;
//                    pos.y-=1;
            }
            break;

        case 'a':
            if (pos.x>=0){
                direction_X=-1;
                direction_Y=0;
//                    pos.x-=1;
            }
            break;

        case 's':
            if(pos.y<=24){
                direction_X=0;
                direction_Y=1;
//                    pos.y+=1;
            }
            break;

        case 'd':
            if (pos.x<=49){
                direction_Y=0;
                direction_X=1;
//                    pos.x+=1;
            }
            break;

    }

    pos.x+=direction_X;
    pos.y+=direction_Y;
    body.push_back(pos);
    if (body.size() > len){
        body.erase(body.begin());
    }
}

COORD Snake::get_snake_pos() {
    return pos;
}

bool Snake::eaten(COORD food_pos) {
    if (food_pos.x == pos.x && food_pos.y == pos.y){
        return true;
    } else{
        return false;
    }
}


void Snake::snake_grow() {
    len++;
}

bool Snake::collide() {
    for (int count = 1; count<body.size()-1; count++){
        if (pos.x == body[count-1].x && pos.y == body[count-1].y){
            return false;
        }
    }
    if (pos.x == 0 || pos.x== WIDTH-1 || pos.y == 0 || pos.y == HEIGHT-1){
        return false;
    } else{
        return true;
    }

}

vector<COORD> Snake::get_snake_body_pos() {
    return body;
}
#endif //C___SCH_PROJECT_SNAKE_H
