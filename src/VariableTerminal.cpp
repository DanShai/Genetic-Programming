/* 
 * File:   VariableTerminal.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:42 PM
 */


#include "VariableTerminal.h"
using namespace std;

VariableTerminal::VariableTerminal() {
}

VariableTerminal::VariableTerminal(int index) {
    this->myIndex = index;
}

void VariableTerminal::setIndex(int index){
    this->myIndex = index;
}

int VariableTerminal::getIndex(){
    return this->myIndex; 
}
char VariableTerminal::getType(){
    return 'V';
}

int VariableTerminal::Eval(std::vector<int> variables){
    return variables[this->myIndex];
}
void VariableTerminal::draw(int level){
    if(this->myIndex == 0 )
	cout << string(level, ' ') << "|___"<< "X" << endl;
    else if (this->myIndex == 1 )
	cout << string(level, ' ') << "|___"<< "Y" << endl;
    else if(this->myIndex == 2 )
	cout << string(level, ' ') << "|___"<< "Z" << endl;
    else
    	cout << string(level, ' ') << "|___"<< "X" << this->myIndex << endl;
    
}

std::string VariableTerminal::print(){
    

    std::stringstream ss;

    if(this->myIndex == 0 )
   	ss << "X" << " ";
    else if (this->myIndex == 1 )
   	ss << "Y" << " ";
    else if(this->myIndex == 2 )
   	ss << "Z" << " ";
    else
	ss << "X" << this->myIndex << " ";
 
    
    std::string  sss = ss.str();
    return  sss;
    

    
}

VariableTerminal::~VariableTerminal() {
}
