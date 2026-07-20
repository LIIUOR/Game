#include <iostream>
#include <format>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "Shape.h"
void print(Circle a){
    std::cout<<"R="<<a.getR()<<std::endl;
    std::cout<<std::format("x,y=({},{})",a.getX(),a.getY())<<std::endl;
}
void print(Rectangle a){
    std::cout<<std::format("x,y,heigth,width=({},{},{},{})",a.getX(),a.getY(),a.getHeight(),a.getWidth())<<std::endl;
}
void print(Square a){
    std::cout<<std::format("x,y,heigth,width,P=({},{},{},{},{})",a.getX(),a.getY(),a.getHeight(),a.getWidth(),a.getP())<<std::endl;
}
void print(Triangle a){
    std::cout<<std::format("x,y,First_side,Second_side,Third_side=({},{},{},{},{})",a.getX(),a.getY(),
    a.getFirst_side(),a.getSecond_side(),a.getThird_side())<<std::endl;
}
void print(Rhombus a){
    std::cout<<std::format("side,angle,x,y=({},{},{},{})",a.getSide(),a.getAngle(),a.getX(),a.getY())<<std::endl;
}
double AreaCalc(Shape& a){
    return a.getS();
}
class A{
public:
    virtual int getNumber(){return 5;}
};
class B : public A{
public:
    int getNumber()override {return 10;}
};
void get(A& a){
    std::cout<<a.getNumber()<<std::endl;
}
void getg(A a){
    std::cout<<a.getNumber()<<std::endl;
}
int main()
{
    A a;
    B b;
    A*c=new B();
    std::cout<<a.getNumber()<<std::endl;
    std::cout<<b.getNumber()<<std::endl;
    std::cout<<c->getNumber()<<std::endl;
    get(b);
    getg(b);
}