#pragma once
#include <string>
#include <iostream>
class WorldObject{
protected:
    std::string name_;
    std::string description_;
    bool isInteractable_;
public:
    WorldObject(std::string name,std::string description):name_(name),description_(description),isInteractable_(true){}
    virtual ~WorldObject(){};
    std::string getName() {return name_;}
    std::string getDescription(){return description_;}
    virtual void lookAt(){
        std::cout<<"\n"<<name_<<"\n";
        std::cout<<description_<<"\n";
    }
    virtual void interact()=0;
};