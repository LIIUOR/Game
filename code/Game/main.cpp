#include <iostream>
#include <format>
#include "Enemy.h"
#include <string>
#include "Character.h"
#include "Boss.h"
#include "Beast.h"
#include "Bandit.h"
#include "Hero.h"
#include "WorldObject.h"
#include "Quest.h"
#include "House.h"
#include "Chest.h"
#include "GameProc.h"
int main(){
    Hero hero{"hero",100,100,10,15.,30.,1};
    Bandit bandit{"bandit",20,20,5,10.,10.,40,25,1};
    GameProcess game1{bandit,hero};
    game1.StartGame();
    return 0;
}