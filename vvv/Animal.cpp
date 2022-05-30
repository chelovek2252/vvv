#include "Animal.h"
#include <iostream>
#include "Constants.h"
#include <stdlib.h>
#include <time.h> 
#include <algorithm>
Animal::Animal()
{
}
Animal::~Animal()
{
}
void Animal::move()
{
    int code_movement = get_random(1, 9);
    if ((code_movement == 1) && (y != FIELD_Y_m)) {
        y -= 1;
    }
    if ((code_movement == 2) && (x != FIELD_X_m)) {
        x -= 1;
    }
    if ((code_movement == 3) && (y != FIELD_Y_M)) {
        y += 1;
    }
    if ((code_movement == 4) && (y != FIELD_X_M)) {
        x += 1;
    }
    if ((code_movement == 5) && (x != FIELD_X_m) && (y != FIELD_Y_M)) {
        x -= 1;
        y += 1;
    }
    if ((code_movement == 6) && (x != FIELD_X_m) && (y != FIELD_Y_m)) {
        x -= 1;
        y -= 1;
    }
    if ((code_movement == 7) && (x != FIELD_X_M) && (y != FIELD_Y_M)) {
        x += 1;
        y += 1;
    }
    if ((code_movement == 8) && (x != FIELD_X_M) && (y != FIELD_Y_m)) {
        x += 1;
        y -= 1;
    }
    if (code_movement == 9) {
    }
}
int Animal::get_random(int from, int to)
{
    int random;
    random = rand() % to + from;
    return random;
}
