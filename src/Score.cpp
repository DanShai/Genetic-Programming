/* 
 * File:   Score.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:56 PM
 */

#include "Score.h"

Score::Score() {
}
Score::Score(unsigned int val, Node* tree) {
    this->scoreValue = val;
    this->myTree = tree;
}

Score::~Score() {
}
unsigned int Score::getScoreValue(){
    return this->scoreValue;
    
}
Node* Score::getTree(){
    return this->myTree;
    
}
void Score::setScoreValue(unsigned int val){
    this->scoreValue = val;
    
}
void Score::setTree(Node* tree){
    this->myTree = tree;
    
}
