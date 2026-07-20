#pragma once
#include "Enemy.h"
#include <string>
#include <iostream>
class Beast:public Enemy{
private:
    int damageBleed_=1;
    int durationBleed_=3;
public:
    Beast(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int amountGainXP,int lootGold,int lvl):
        Enemy(name,HP,maxHP,damage,Crit,ChanceCrit,amountGainXP,lootGold,lvl){}
    void attack(Character& target)override{
        //МОЖНО сделать удар с кровотечением
        std::cout<<name_<<" strikes "<<target.getName()<<" and inflicts a bleeding effect"<<std::endl;
        target.takeDamage(damage_);
        
    }
};