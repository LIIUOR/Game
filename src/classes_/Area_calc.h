#include <cmath>
double AreaCalc(Rectangle a){
    return a.getHeight*a.getWidth;
}
double AreaCalc(Square a){
    return std::pow(a.getHeight,2);
}
