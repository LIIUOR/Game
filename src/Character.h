#pragma once
#include <string>
#include <iostream>
class Character{
protected:
    std::string name_;
    int HP_;
    int maxHP_;
    int damage_;
    double CritDamage_;
    double ChanceCrit_;
    int level_;
public:
    Character(std::string name,int HP,int maxHP,int damage,double Crit,double ChanceCrit,int level):name_(name),HP_(HP),
        maxHP_(maxHP),damage_(damage),CritDamage_(Crit),ChanceCrit_(ChanceCrit),level_(level){}
    virtual ~Character(){};
    std::string getName(){return name_;}
    int getHP(){return HP_;}
    int getDamage(){return damage_;}
    double getCritDamage(){return CritDamage_;}
    double getChanceCrit(){return ChanceCrit_;}
    int getLevel(){return level_;}
    int getMaxHP(){return maxHP_;}
    virtual void takeDamage(int amount){
        HP_-=amount;
        if(HP_<0)HP_=0;
        std::cout<<name_<<"take: "<<amount<<" damage\nleft"<<HP_<<"/"<<maxHP_<<std::endl;
    }
    virtual void attack(Character& target)=0;
    bool isAlive(){
        return HP_>0;
    }
    void levelUP(){
        //надо сделать получение уровня по набиранию полоски опыта
        level_++;
        maxHP_+=10;
        HP_=maxHP_;
        damage_+=5;
        std::cout<<"The level is elevated"<<std::endl;
    }
};