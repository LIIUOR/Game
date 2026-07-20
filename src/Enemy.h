#pragma once
#include "Character.h"
#include <string>
#include <iostream>
class Enemy:public Character{
protected:
    int amountGainXP_;
    int lootGold_;
public:
    Enemy(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int amountGainXP,int lootGold,int lvl):
        Character(name,HP,maxHP,damage,Crit,ChanceCrit,lvl),amountGainXP_(amountGainXP),lootGold_(lootGold){}
    int GainXp(){return amountGainXP_;}
    int getGold(){return lootGold_;}
};