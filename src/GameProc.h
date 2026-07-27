#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <vector>
enum class Action{
    Exit=0,Attack=1,Heal=2,Save=3
};
class GameProcess{
private:
    Enemy& enemy_;
    Hero& mainHero_;
    bool wantsToQuit=false;
    int currentEnemyIndex_=0;
    const std::string saveFile_="savegame.txt";

public:
    GameProcess(Enemy& enemy, Hero& hero):mainHero_(hero),enemy_(enemy){srand(time (0));}
    //ashags
    void SaveGame(){
        std::ofstream save(saveFile_);
        save<<mainHero_.getName()<<'\n'
            <<mainHero_.getHP()<<' '<<mainHero_.getMaxHP()<<' '<<mainHero_.getDamage()<<' '
            <<mainHero_.getLevel()<<' '<<mainHero_.countGold()<<' '<<mainHero_.countXP()<<' '
            <<currentEnemyIndex_<<'\n';
        const auto& defeatedEnemies=mainHero_.getDefeatedEnemies();
        save<<defeatedEnemies.size()<<'\n';
        for(const auto& enemyName:defeatedEnemies){
            save<<enemyName<<'\n';
        }
        std::cout<<"Игра сохранена"<<std::endl;
    }
    static bool LoadGame(Hero& hero,int& currentEnemyIndex){
        std::ifstream save("savegame.txt");
        if(!save){
            std::cout<<"Сохранение не найдено"<<std::endl;
            return false;
        }
        std::string name;
        int HP,maxHP,damage,level,gold,XP;
        size_t historySize;
        save>>name;
        save>>HP>>maxHP>>damage>>level>>gold>>XP>>currentEnemyIndex;
        save>>historySize;
        std::vector<std::string> defeatedEnemies;
        for(size_t i=0;i<historySize;++i){
            std::string enemyName;
            save>>enemyName;
            defeatedEnemies.push_back(enemyName);
        }
        hero=Hero{name,HP,maxHP,damage,15.,30.,level};
        hero.setStats(HP,maxHP,damage,level,gold,XP);
        hero.setDefeatedEnemies(defeatedEnemies);
        std::cout<<"Игра загружена"<<std::endl;
        return true;
    }
    bool StartGame(){
        std::cout<<"Первый ваш враг на пути это бандит"<<std::endl;
        while(mainHero_.isAlive() && !wantsToQuit){
            std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n3) Сохранить игру\n0) Выйти из игры";
            Action choice;
            int x;
            std::cin>>x;
            choice = static_cast<Action>(x);
            switch (choice)
            {
                case Action::Attack:
                    mainHero_.attack(enemy_);
                    enemy_.attack(mainHero_);
                    break;
                case Action::Heal:
                {   
                    mainHero_.RegenHP();
                    int number=rand();
                    if(number%2==0){
                    enemy_.attack(mainHero_);}
                    break;
                }
                case Action::Save:
                    SaveGame();
                    break;
                case Action::Exit:
                    wantsToQuit=true;
                    break;
                default:
                    std::cout<<"Неверный ввод, попробуйте еще раз";
                    break;
            }
        }
        mainHero_.getGold(enemy_.getGold());
        mainHero_.getXP(enemy_.GainXp());
        while(mainHero_.isAlive() && !wantsToQuit){
            std::cout<<"Куда ты хочешь пойти\n1) Сундук\n2) Дом\n3) Квест\n4) Следующий враг\n5) Босс\n6) Сохранить игру\n7) История врагов0) Выйти";
            int choice;
            std::cin>>choice;
            switch(choice){
                case 1:
                case 2:
                case 3:
                    std::cout<<"Пока в разработке"<<std::endl;
                    break;
                case 4:
                    std::cout<<"Ваш новый враг это животное"<<std::endl;
                    while(mainHero_.isAlive() && enemy_.isAlive() && !wantsToQuit){
                        std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n3) Сохранить игру\n0) Выйти из игры";
                        Action choice;
                        int x;
                        std::cin>>x;
                        choice = static_cast<Action>(x);
                        switch (choice)
                        {
                            case Action::Attack:
                                mainHero_.attack(enemy_);
                                enemy_.attack(mainHero_);
                                break;
                            case Action::Heal:
                            {   
                                mainHero_.RegenHP();
                                int number=rand();
                                if(number%2==0){
                                enemy_.attack(mainHero_);}
                                break;
                            }
                            case Action::Save:
                                SaveGame();
                                break;
                            case Action::Exit:
                                wantsToQuit=true;
                                break;
                            default:
                                std::cout<<"Неверный ввод, попробуйте еще раз";
                                break;
                        }
                    }
                    mainHero_.getGold(enemy_.getGold());
                    mainHero_.getXP(enemy_.GainXp());
                case 5:
                    std::cout<<"Ваш новый противник Босс";
                    while(mainHero_.isAlive() && enemy_.isAlive() && !wantsToQuit){
                        std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n3) Сохранить игру\n0) Выйти из игры";
                        Action choice;
                        int x;
                        std::cin>>x;
                        choice = static_cast<Action>(x);
                        switch (choice)
                        {
                            case Action::Attack:
                                mainHero_.attack(enemy_);
                                enemy_.attack(mainHero_);
                                break;
                            case Action::Heal:
                            {   
                                mainHero_.RegenHP();
                                int number=rand();
                                if(number%2==0){
                                enemy_.attack(mainHero_);}
                                break;
                            }
                            case Action::Save:
                                SaveGame();
                                break;
                            case Action::Exit:
                                wantsToQuit=true;
                                break;
                            default:
                                std::cout<<"Неверный ввод, попробуйте еще раз";
                                break;
                        }
                    }
                    mainHero_.getGold(enemy_.getGold());
                    mainHero_.getXP(enemy_.GainXp());
                case 6:
                    SaveGame();
                    break;
                case 7:
                    mainHero_.printDefeatedEnemies();
                    break;
                case 0:
                    wantsToQuit=true;
                    break;
                default:
                    std::cout<<"Неверный ввод, попробуйте еще раз";
                    break;
            }
        }
        return mainHero_.isAlive();
    }
};