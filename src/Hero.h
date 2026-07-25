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
    std::vector<std::string> defeatedEnemies_{};
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
    void setStats(int HP,int maxHP,int damage,int level,int gold,int XP){
        HP_=HP;
        maxHP_=maxHP;
        damage_=damage;
        level_=level;
        countGold_=gold;
        XP_=XP;
    }
    void addDefeatedEnemy(const std::string& enemyName){
        defeatedEnemies_.push_back(enemyName);
    }
    const std::vector<std::string>& getDefeatedEnemies()const{
        return defeatedEnemies_;
    }
    void setDefeatedEnemies(const std::vector<std::string>& defeatedEnemies){
        defeatedEnemies_=defeatedEnemies;
    }
    void printDefeatedEnemies()const{
        if(defeatedEnemies_.empty()){
            std::cout<<"История побежденных врагов пуста"<<std::endl;
            return;
        }
        std::cout<<"История побежденных врагов:"<<std::endl;
        for(size_t i=0;i<defeatedEnemies_.size();++i){
            std::cout<<i+1<<") "<<defeatedEnemies_[i]<<std::endl;
        }
    }
};