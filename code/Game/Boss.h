#pragma once
#include "Enemy.h"
#include <string>
#include <iostream>
class Boss:public Enemy{
private:
    std::string relic_;
public:
    Boss(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int amountGainXP,int lootGold,std::string relic,int level):
        Enemy(name,HP,maxHP,damage,Crit,ChanceCrit,amountGainXP,lootGold,level),relic_(relic){}
    void attack(Character& target)override{
        std::cout<<name_<<" strikes "<<target.getName()<<std::endl;
        target.takeDamage(damage_);
    }
    std::string getRelic(){return relic_;}
    // надо доделать получение реликвий
};