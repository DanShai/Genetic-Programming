/* 
 * File:   SubExpression.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:35 PM
 */

#include "SubExpression.h"

SubExpression::SubExpression(std::string expre, std::string op){
    this->_mexp = expre;
    this->_mop = op;
}

std::string SubExpression::getExp(){
    
    return this->_mexp;
}
std::string SubExpression::getOp(){
    
    return this->_mop;
}


SubExpression::~SubExpression() {
}
