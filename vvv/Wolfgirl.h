#pragma once
#include "Animal.h"
using namespace std;
class WolfGirl : public Animal
{
public:
    WolfGirl(int, int, vector<shared_ptr<Rabbit>>*, vector<shared_ptr<WolfGirl>>*);
    ~WolfGirl();
    vector<shared_ptr<Rabbit>>* all_rabbits;
    vector<shared_ptr<WolfGirl>>* all_wolfgirls;
    double life_points = 1;
    bool follow_rabbit = false;
    shared_ptr<Rabbit> followed_rabbit;
    int getx();
    int gety();
    void setx(int);
    void sety(int);
    int get_random(int, int);
    void tick();
    void search_rabbit();
};
