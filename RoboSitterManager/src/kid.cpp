#include "kid.h"

Kid::Kid()
{

    x = -1;
    y = -1;
    width = -1;
    height = -1;
    area = -1;
    start_area = -1;
    start_width = -1;
    start_height = -1;
    screen_width = -1;
    screen_height = -1;
}

void Kid::setX(int x){
    this->x = x;
}

int Kid::getX(){
    return x;
}

void Kid::setY(int y ){
    this->y = y;
}
int Kid::getY(){
    return y;
}

void Kid::setWidth(int w){
    width = w;
}
int Kid::getWidth(){
    return width;
}

void Kid::setHeight(int h){
    height = h;
}
int Kid::getHeight(){
    return height;
}

void Kid::setArea(int area){
    this->area = area;
}
int Kid::getArea(){
    return area;
}

void Kid::setLost(bool l){
    lost = l;
}

bool Kid::getLost(){
    if(lostable)return lost;
    else return false;
}

void Kid::setLostable(bool l){
}

bool Kid::getLostable(){
    return lostable;
}

void Kid::setStartValues(int area, int width,int height,int sw,int sh){
    start_area = area;
    start_width = width;
    start_height = height;
    screen_width = sw;
    screen_height = sh;
    lostable = true;
}

int Kid::getStart_area(){
    return start_area;
}

int Kid::getStart_width(){
    return start_width;
}

int Kid::getStart_height(){
    return start_height;
}

int Kid::getScreen_width(){
    return screen_width;
}

int Kid::getScreen_height(){
    return screen_height;
}
