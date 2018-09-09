
/**
 * @author dan
 * @version 1.0
 *
 */

#ifndef CONSTANTTERMINAL_H
#define CONSTANTTERMINAL_H
#include <string>
#include <iostream>
#include "Node.h"
#include <vector>
#pragma once

class ConstantTerminal : public Node
{

    /** this is a constant node implements Node interface
	* constant node will represent constants like 1,5,3 etc..
	* so in this Node the Eval function will simply return the value
	* in which this node was initialized
	*/
  public:
    ConstantTerminal();
    ConstantTerminal(int val);
    virtual ~ConstantTerminal();
    void setValue(int val);
    int getValue();
    virtual int Eval(std::vector<int> variables);
    virtual void draw(int level = 0);
    virtual char getType();
    virtual std::string print();

  private:
    int myValue;
};

#endif /* CONSTANTTERMINAL_H */
