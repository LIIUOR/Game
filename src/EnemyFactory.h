#pragma once
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Boss.h"
#include "Beast.h"
#include "Bandit.h"
enum class RequestedType{
    Bandit=0,Boss,Beast,Random
};
class EnemyFactory{
public:
    Enemy makeEnemy(int lvl=1,RequestedType type=RequestedType::Random){
        switch(type)
        {
            case RequestedType::Bandit:
                return makeBandit(lvl);
            case RequestedType::Boss:
                return makeBoss(lvl);
            case RequestedType::Beast:
                return makeBeast(lvl);
            case RequestedType::Random:
            default
                return makeRandom(lvl);
        }
    }
};