#pragma once
#include "Character.h"
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
struct backpack{
    std::vector<Item>backpack{};
    //std::string name_;
    //std::string description_;
    void addItem(Item& item){
        backpack.push_back(item);
    }
};
    
class Hero:public Character{
private:
    int countGold_=0;
    int XP_=0;
    backpack inventory;
public:
    Hero(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int lvl):
        Character(name,HP,maxHP,damage,Crit,ChanceCrit,lvl){
            Item sword{"sword","assd"};
            inventory.addItem(sword);
        }
    void attack(Character& target)override{
        std::cout<<name_<<" strikes "<<target.getName()<<std::endl;
        target.takeDamage(damage_);
    }
    void RegenHP(){
        HP_*=1.15;
    }
    void stealGold(int amount){
        if(countGold_>0){
            countGold_*= 1-amount;
        }
        return;
    }
    int countGold(){return countGold_;}
    void getGold(int amount){
        countGold_+=amount;
    }
    int countXP(){return XP_;}
    void getXP(int amount){
        if(XP_+amount>=100){
            levelUP();
            XP_=-1*(100-(XP_+amount));
        }
        else{
            XP_+=amount;
        }
    }
};