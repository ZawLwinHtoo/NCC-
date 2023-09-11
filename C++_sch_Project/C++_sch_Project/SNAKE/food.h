//
// Created by zl_shit_h on 25/07/23.
//

#ifndef C___SCH_PROJECT_FOOD_H
#define C___SCH_PROJECT_FOOD_H
#include "cstdlib"
#include "ctime"
#define WIDTH 50
#define HEIGHT 25
//#include "Snake.h"
struct COORD{
    int x;
    int y;
};
class Food{

private:
    COORD pos{};

public:
//    Food();
    COORD get_food_pos();
    COORD current_food_pos();
};



COORD Food::get_food_pos() {
        srand(static_cast<unsigned>(time(0)));
         pos.x = (rand()%(WIDTH-2)+1);
         pos.y = (rand()%(HEIGHT-2)+1);
        return pos;

}
COORD Food::current_food_pos() {
    return pos;
}




#endif //C___SCH_PROJECT_FOOD_H
