/* 
 * File:   ConstantTerminal.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:33 PM
 */


#include "ConstantTerminal.h"

ConstantTerminal::ConstantTerminal() {
}

ConstantTerminal::ConstantTerminal(int val) {
    this->myValue = val;
}

void ConstantTerminal::setValue(int val){
    this->myValue = val;
}

int ConstantTerminal::getValue(){
    return this->myValue; 
}

int ConstantTerminal::Eval(std::vector<int> variables){
    return this->myValue;
}

char ConstantTerminal::getType(){
    return 'C';
}
void ConstantTerminal::draw(int level){
    std::cout << std::string(level, ' ') << "|___"<< this->myValue << std::endl ;
}

std::string ConstantTerminal::print(){
std::stringstream ss;
ss << this->myValue;
std::string  sss = ss.str() + " ";
return sss ;

}


ConstantTerminal::~ConstantTerminal() {
}
