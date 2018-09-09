
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef TREE_H
#define TREE_H
#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Operations.h"
#include "Node.h"

class Tree : public Node
{

    /**
	*  this is the Tree class , it is a operations/functions terminal
	* it has an operation and children Nodes which they could be also
	* tree programs or Constant/Variables terminals.
	* when Eval is called it will Eval first the children recursivly
	* then apply the operator to them, the function/operator is encapsulated inside the
	* operation class.
	*/

  public:
    Tree(Operations *op, std::vector<Node *> *children);
    virtual int Eval(std::vector<int> variables);
    virtual void draw(int level = 0);
    void setChildren(std::vector<Node *> *children);
    std::vector<Node *> *getChildren();
    virtual char getType();
    Operations *getOperations();
    virtual std::string print();
    virtual ~Tree();

  private:
    std::vector<Node *> *myChildren;
    std::string myName;
    aFunction myFunction;
    int numParams;
    int myArity;
    Operations *myOperations;
};

#endif /* TREE_H */
#endif	/* TREE_H */
