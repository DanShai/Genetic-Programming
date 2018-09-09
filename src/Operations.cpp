/* 
 * File:   Operations.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:29 PM
 */

#include "Operations.h"

Operations::Operations( aFunction fn,int num_params,std::string name) {
    this->myFunction = fn;
    this->funcParams = num_params;
    this->funcName = name;
}


std::string Operations::getFName(){
    return this->funcName;
}

int Operations::getParamNums(){
    return this->funcParams;
}

aFunction Operations::getFunction(){
    return this->myFunction;
}



Operations::~Operations() {
}