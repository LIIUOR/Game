#pragma once
#include "WorldObject.h"
#include <iostream>
#include <string>
class Quest:public WorldObject{
private:
    std::string questName_;
    std::string specification_;
    bool isCompleted=false;
    std::string present_;
public:
    Quest(std::string name,std::string description,std::string questName,std::string specification,std::string present):
        WorldObject(name,description),questName_(questName),specification_(specification),present_(present){}
    void interact()override{
        if(isCompleted){
            std::cout<<name_<<": Thank you, traveler; here is your reward"<<std::endl;
            //хочу сделать получение подарка и опыта
            return;
        }
        std::cout<<name_<<": Do a task for me\n"<<"You have a new quest: "<<questName_<<" "<<specification_<<std::endl;
    }
};