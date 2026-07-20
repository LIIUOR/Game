#pragma once
#include <exception>
#include <cmath>
#include "Shape.h"
class Triangle : public Shape{
private:
    double x_,y_;
    double First_side,Second_side,Third_side;
    double P_;
public:
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
    double getFirst_side(){
        return First_side;
    }
    double getSecond_side(){
        return Second_side;
    }
    double getThird_side(){
        return Third_side;
    }
    Triangle(double x,double y,double F_side,double S_side,double T_side,double P):x_(x),y_(y),First_side(F_side),
        Second_side(S_side),Third_side(T_side){
        if(P>0){
            P_=P;
        }else {
            throw std::invalid_argument("It's not a Triangle");
        }
    }
    double getP()const override {return First_side+Second_side+Third_side;}
    double getS()const override {
        double p=getP()/2.0;
        return std::sqrt(p*(p-First_side)*(p-Second_side)*(p-Third_side));
    }
};