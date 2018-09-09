/* 
 * File:   Tree.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:37 PM
 */

#include "Tree.h"

Tree::Tree(Operations* op, std::vector<Node*>* children) {
    this->myName = op->getFName();
    this->myFunction = op->getFunction();
    this->numParams = op->getParamNums();
    this->myArity = op->getParamNums();
    this->myChildren = children;
    this->myOperations = op;
}

void Tree::setChildren(std::vector<Node*>* children) {
    this->myChildren = children;
}

Operations* Tree::getOperations() {
    return this->myOperations;
}

std::vector<Node*>* Tree::getChildren() {
    return this->myChildren;
}

char Tree::getType() {
    return 'T';
}

int Tree::Eval(std::vector<int> variables) {
    std::vector<int> resVector;
    int resultat = 0;
    for (unsigned int n = 0; n < this->myChildren->size(); n++) {
        Node* nd = (*this->myChildren)[n];
        resVector.push_back(nd->Eval(variables));
    }

    resultat = this->myFunction(resVector);
    return resultat;
}

std::string Tree::print(){
    
    std::string res = "";

    for (size_t n = 0; n < this->myChildren->size(); n++) {
        Node* nd = (*this->myChildren)[n];
        res += nd->print();
        
    }
    res += this->myName +" ";

    return res;
}



void Tree::draw(int level) {
    std::cout << std::string(level, ' ') << this->myName << "___"  << std::endl;
    for (size_t n = 0; n < this->myChildren->size(); n++) {
        Node* nd = (*this->myChildren)[n];
        std::cout << std::string(level+3, ' ') << "|" << std::endl ;
        nd->draw(level+3);
        
    }
    // std::cout << std::string(level, ' ') << std::endl;

}

Tree::~Tree() {
}
