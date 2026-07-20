#pragma once
#include "WorldObject.h"
#include <iostream>
#include <string>
class Chest:public WorldObject{
private:
    std::string itemInside;
public:
    Chest(std::string name,std::string description,std::string item):WorldObject(name,description),itemInside(item){}
    void interact()override{
        if(!isInteractable_){
            std::cout<<"empty chest\n";
            return;
        }
        std::cout<<"Open->"<<name_<<" find: "<<itemInside<<std::endl;
        //хочу сделать получение предмета
        isInteractable_=false;
    }
};