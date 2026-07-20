#pragma once
#include <exception>
#include "Shape.h"
class Rectangle : public Shape{
private:
    double x_,y_;
    double heigth_,width_;
public:
    double getX(){
        return x_;
    }
    double getY(){
        return y_;
    }
    double getHeight(){
        return heigth_;
    }
    double getWidth(){
        return width_;
    }
    Rectangle (double x,double y,double height,double width):x_(x),y_(y){
        if(height >0 && width>0){
            heigth_=height;
            width_=width;
        }else {
            throw std::invalid_argument("This is not the Rectangle");
        }
    }
    double getP()const override {return 2*(heigth_+width_);}
    double getS()const override {return heigth_*width_;}
};