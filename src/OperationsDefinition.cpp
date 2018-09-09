/* 
 * File:   OperationsDefinition.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 7:07 PM
 */

#include "OperationsDefinition.h"

OperationsDefinition::OperationsDefinition() {
    
    this->basicOpsTable.push_back(new Operations(O_add,2,"+"));
    this->basicOpsTable.push_back(new Operations(O_sub,2,"-"));
    this->basicOpsTable.push_back(new Operations(O_mul,2,"*"));
    //this->basicOpsTable.push_back(new Operations(O_div,2,"/"));
    
    this->booleanOpsTable.push_back(new Operations(O_if,3,"If"));
    this->booleanOpsTable.push_back(new Operations(O_lt,2,"<"));
    this->booleanOpsTable.push_back(new Operations(O_gt,2,">"));
    this->booleanOpsTable.push_back(new Operations(O_and,2,"&"));
    this->booleanOpsTable.push_back(new Operations(O_or,2,"Or"));
    this->booleanOpsTable.push_back(new Operations(O_xor,2,"^"));

    this->allOpsTable.push_back(new Operations(O_add,2,"+"));
    this->allOpsTable.push_back(new Operations(O_sub,2,"-"));
    this->allOpsTable.push_back(new Operations(O_mul,2,"*"));
    
    this->allOpsTable.push_back(new Operations(O_if,3,"If"));
    this->allOpsTable.push_back(new Operations(O_lt,2,"<"));
    this->allOpsTable.push_back(new Operations(O_gt,2,">"));
    this->allOpsTable.push_back(new Operations(O_and,2,"&"));
    this->allOpsTable.push_back(new Operations(O_or,2,"Or"));
    this->allOpsTable.push_back(new Operations(O_xor,2,"^"));

    
    
}

OperationsDefinition::~OperationsDefinition() {
}

std::vector<Operations*> OperationsDefinition::getBasicOperationsTable() {
    return this->basicOpsTable;
}

std::vector<Operations*> OperationsDefinition::getBooleanOperationsTable() {
    return this->booleanOpsTable;
}

std::vector<Operations*> OperationsDefinition::getAllOperationsTable() {
    return this->allOpsTable;
}
