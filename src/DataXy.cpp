/* 
 * File:   DataXy.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:53 PM
 */

#include "DataXy.h"

DataXy::DataXy(int x,int y) {
    this->xF = x;
    this->yF = y;
}

int DataXy::getX(){
    return this->xF;
}
int DataXy::getY(){
    return this->yF;
    
}
DataXy::~DataXy() {
}
