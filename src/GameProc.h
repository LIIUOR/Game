#pragma once
#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
enum class Action{
    Exit=0,Attack=1,Heal=2
};
class GameProcess{
private:
    Enemy& enemy_;
    Hero& mainHero_;
    bool wantsToQuit=false;
public:
    GameProcess(Enemy& enemy, Hero& hero):mainHero_(hero),enemy_(enemy){srand(time (0));}
    bool StartGame(){
        std::cout<<"Первый ваш враг на пути это бандит"<<std::endl;
        while(mainHero_.isAlive() && !wantsToQuit){
            std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n0) Выйти из игры";
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
            std::cout<<"Куда ты хочешь пойти\n1) Сундук\n2) Дом\n3) Квест\n4) Следующий враг\n5) Босс\n0) Выйти";
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
                        std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n0) Выйти из игры";
                        int choice;
                        std::cin>>choice;
                        switch (choice)
                        {
                            case 1:
                                mainHero_.attack(enemy_);
                                enemy_.attack(mainHero_);
                                break;
                            case 2:
                            {   
                                mainHero_.RegenHP();
                                int number=rand();
                                if(number%2==0){
                                enemy_.attack(mainHero_);}
                                break;
                            }
                            case 0:
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
                        std::cout<<"Что ты хочешь сделать\n1) Атаковать \n2) Восстановить здоровье\n0) Выйти из игры";
                        int choice;
                        std::cin>>choice;
                        switch (choice)
                        {
                            case 1:
                                mainHero_.attack(enemy_);
                                enemy_.attack(mainHero_);
                                break;
                            case 2:
                            {   
                                mainHero_.RegenHP();
                                int number=rand();
                                if(number%2==0){
                                enemy_.attack(mainHero_);}
                                break;
                            }
                            case 0:
                                wantsToQuit=true;
                                break;
                            default:
                                std::cout<<"Неверный ввод, попробуйте еще раз";
                                break;
                        }
                    }
                    mainHero_.getGold(enemy_.getGold());
                    mainHero_.getXP(enemy_.GainXp());
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