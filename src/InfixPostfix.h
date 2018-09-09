
/**
 * @author dan
 * @version 1.0
 *
 */

#ifndef INFIXPOSTFIX_H
#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <typeinfo>
#include <algorithm>
#include "Node.h"
#include "ConstantTerminal.h"
#include "Tree.h"
#include "OperationsDefinition.h"
#include "Operations.h"
#include "SubExpression.h"

class InfixPostfix
{
    /**
	 * This is the InfixPostfix class
	 * @param none
	 * or
	 * @param an Expression
	 *
	 * This class handles all expressions types Infix
	 * or postfix and converting between them
	 *
	 */

  public:
    InfixPostfix(std::string expression);
    InfixPostfix();
    virtual ~InfixPostfix();
    std::string infixToPostfix();
    void print();
    void setExpression(std::string expression);
    std::string getExpression();
    Node *expressionTotree();
    Operations *operatorToOperations(std::string anOperator);
    std::vector<std::string> splitExpression(const std::string &expression, std::string separator);
    bool isOperator(std::string anop);
    std::string addWhiteSpace(std::string expression, const std::string from, const std::string to);
    void formatExpression();
    std::string formatExpression(std::string expr);
    bool chekBasicValidity();
    bool isPostfix();
    void setExpressionType(bool mytype);
    std::vector<std::string> getExpressionVector();
    bool getExpressionType();
    int GetOperatorPriority(std::string op);
    bool isPrioritized(std::string oper_1, std::string oper_2);
    Node *getExpressionTree();
    void setExpressionTree(Node *thetree);
    bool isAnOperand(std::string operand);
    bool verifyOperandIsNumber(std::string operand);
    std::string treeToPostfix(Node *theThree);
    std::string operationToOperator(Operations *op);
    std::string postfixToInfix(std::string expression);
    void InitExpression(std::string expression);

  private:
    std::string myExpression;
    bool expressionType;
    std::vector<std::string> expresVector;
    Node *myExpresionTree;
};
#endif /* INFIXPOSTFIX_H */
#endif	/* INFIXPOSTFIX_H */
