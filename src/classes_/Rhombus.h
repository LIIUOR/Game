#pragma once
#include <exception>
#include <cmath>
#include "Shape.h"
class Rhombus : public Shape{
private:
    double side_,angle_;
    double x_,y_;
    double PI=3.14159;
public:
    double getSide(){
        return side_;
    }
    double getAngle(){
        return angle_;
    }
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
    Rhombus(double side,double angle,double x,double y):x_(x),y_(y){
        if(angle >=0 && angle <=180 && side >0){
            angle_=angle;
            side_=side;
        }else if(side<=0){
            throw std::invalid_argument("Side must be positive");
        }else {
            throw std::invalid_argument("Angle must be >=0 and <=180");
        }
    }
    double getS()const override{return std::pow(side_,2)*std::sin(angle_*(PI/180.0));}
    double getP()const override{return 4*side_;}
};