//
// Created by zl_shit_h on 03/08/23.
//

#ifndef C___SCH_PROJECT_MAIN_FOR_SNAKE_H
#define C___SCH_PROJECT_MAIN_FOR_SNAKE_H
#include "Snake.h"
#define WIDTH 50
#define HEIGHT 25


using namespace std;

//GLOBAL VARIABLE
//int pos_x = 1;
//int pos_y = 1;
bool flag_for_food= true;
COORD snake_pos;
COORD food_pos;
bool game_runner = true;
vector<COORD> body_pos;
//FUNCTION
void board();
void runner();
void print_snake();
void make_food();
int Main_Snake();
//STRUCTURE

//Object & Class
Snake snake({WIDTH/2, HEIGHT/2},1);
Food food;



void board(){

    for (int y=0;y<HEIGHT; y++){
        for (int x=0; x<WIDTH; x++){

            if (y==0 || y== HEIGHT-1 || x==0 || x== WIDTH-1){
                mvprintw(y,x,"#");
            }  else {
                mvprintw(y,x," ");
            }


        }
    }
    make_food();
    //SNAKE
    print_snake();



}


void runner(){

    while (snake.collide()){
        clear();
//        if (pos_x == 19){
//            pos_x = 2;
//            pos_y++;
//        }
//        if (pos_y == 9){
//            pos_x =1;
//            pos_y=1;
//        }

        board();
//        pos_x++;

//        if(kbhit()) {
        char ch = getch();
        snake.change_dir(ch);
        snake.move_snake();



//        }
        flag_for_food = false;
        if(snake.eaten(food.current_food_pos())){
            flag_for_food = true;
            make_food();
            snake.snake_grow();
        }


        refresh();
        usleep(100000);
    }






}


void make_food(){
    if (flag_for_food){
        food_pos = food.get_food_pos();
//        flag_for_food= true;
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x==food_pos.x && y==food_pos.y){
                mvprintw(y,x,"f");
            }
        }
    }
}

void print_snake() {

    snake_pos = snake.get_snake_pos();
    body_pos = snake.get_snake_body_pos();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            if ((x == snake_pos.x && y == snake_pos.y)) {
                mvprintw(y, x, "0");
            } else {
                for (int count = 0; count<body_pos.size()-1; count++){
                    if (x== body_pos[count].x && y == body_pos[count].y){
                        mvprintw(y,x,"_");
                    }
                }
            }
        }


    }
}
int Main_Snake(){
    initscr();
    cbreak(); //Turn off line buffering
    noecho(); //Turn off character echoing
    curs_set(0); //Hide the cursor
    nodelay(stdscr, true);
//    timeout(500);


    runner();


    endwin();

    return 0;

}

#endif //C___SCH_PROJECT_MAIN_FOR_SNAKE_H
