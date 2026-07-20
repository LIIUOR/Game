#pragma once
#include <exception>
#include <cmath>
#include <cassert>
#include "Shape.h"
class Circle : public Shape{
private:
    double R_;
    double x_,y_;
    double PI=3.14159;
public:
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
    double getR(){
        return R_;
    }
    double getD(){
        return R_*2;
    }
    Circle(double x,double y,  double R):x_(x),y_(y){
        if(R >=0){
            R_=R;
        }else {
            throw std::invalid_argument("Radius must be positive");
        }
    }
    double getP()const override{return 2*PI*R_;}
    double getS()const override{return PI*std::pow(R_,2);}
};