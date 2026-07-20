#pragma once
#include <exception>
#include <cmath>
#include "Shape.h"
class Square : public Shape{
private:
    double x_,y_;
    double height_,width_;
    double P_;
public:
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
    double getHeight(){
        return height_;
    }
    double getWidth(){
        return width_;
    }
    Square (double x,double y,double height,double width,double P):x_(x),y_(y),height_(height),width_(width){
        if(P>0 && height==width){
            P_=P;
        }else if(P<=0){
            throw std::invalid_argument("P<=0");
        }else {
            throw std::invalid_argument("It's not a Square");
        }
    }
    double getP()const override {return 4*height_;}
    double getS()const override {return std::pow(height_,2);}
};