#pragma once
#include <iostream>
#include "Bandit.h"
#include "GameProc.h"
#include "Hero.h"
enum class Menu{
    Exit=0,NewGame=1,LoadGame=2,Settings=3
};
class MainMenu{
private:
    bool isRunning_=true;
    void Print(){
        std::cout<<"\n1) Начать новую игру\n"<<"2) Загрузить игру\n"<<"3) Настройки\n"<<"0) Выход"<<std::endl;
    }
    void StartNewGame(){
        Hero hero{"hero",100,100,10,15.,30.,1};
        Bandit bandit{"bandit",20,20,5,10.,10.,40,25,1};
        GameProcess game1{bandit,hero};
        game1.StartGame();
    }
    void ShowSwitch(int choice){
    switch(static_cast<Menu>(choice)){
                case Menu::NewGame:
                    StartNewGame();
                    break;
                case Menu::LoadGame:
                    //LoadGame();
                    break;
                case Menu::Settings:
                    Settings();
                    break;
                case Menu::Exit:
                    isRunning_=false;
                    std::cout<<"Выход из игры"<<std::endl;
                    break;
                default:
                    std::cout<<"Неверный ввод, попробуйте еще раз"<<std::endl;
            }
}
    // void LoadGame(){
    //     Hero hero{"hero",100,100,10,15.,30.,1};
    //     int currentEnemyIndex=0;
    //     if(GameProcess::LoadGame(hero,currentEnemyIndex)){
    //         GameProcess game{hero,currentEnemyIndex};
    //         game.StartGame();
    //     }
    // }
    void Settings(){
        std::cout<<"Пока не готово"<<std::endl;
    }
public:
    void Show(){
        while(isRunning_){
            int choice;
            Print();
            std::cin>>choice;
            ShowSwitch(choice);
        }
    }
};