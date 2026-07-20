#pragma once
#include "Enemy.h"
#include "Hero.h"
#include <string>
#include <iostream>
class Bandit:public Enemy{
public:
    Bandit(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int amountGainXP,int lootGold,int lvl):
        Enemy(name,HP,maxHP,damage,Crit,ChanceCrit,amountGainXP,lootGold,lvl){}
    void attack(Character& target){
        std::cout<<name_<<" strikes "<<target.getName()<<" and steals 20 '%' of the gold"<<std::endl;
        target.takeDamage(damage_);
        Hero& targetHero=dynamic_cast<Hero&>(target);
        targetHero.stealGold(0.2);
        lootGold_*=1.2;
    }
};