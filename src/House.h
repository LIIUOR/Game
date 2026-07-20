#pragma once
#include "WorldObject.h"
#include <iostream>
#include <string>
class House:public WorldObject{
public:
    House(std::string name,std::string description):WorldObject(name,description){}
    void interact()override{
        std::cout<<"You have fully restored your health"<<std::endl;
        //хочу сделать востановление здоровья
    }

};