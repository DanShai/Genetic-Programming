
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef VARIABLETERMINAL_H
#define VARIABLETERMINAL_H
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"
#pragma once

class VariableTerminal : public Node
{

	/**
	*  this is the variable terminal Node, it will hold one of the variables of the problem
	*  passed to the program, the Eval function
	* will return the variable specified by the index.
	* for example in the regression example we have only one variable X ! the index
	* in this case will be 0 because the vector Data given as input to the program
	* contains only one value  "X", and as we give the input as vector therfore
	* the index of first only element in this case is 0
	* I formated the variables to X,Y Z in case we have 3 variables otherwise if we have
	* a problem with more than 3 variables then the 4 variable for example will be written
	* X4 (X + the index!) idem X5 etc...
	* for this project we have Regression demo for one variable so in this case the
	* Variable will be denoted simply : X
	*/

  public:
	VariableTerminal();
	VariableTerminal(int index);
	virtual ~VariableTerminal();
	void setIndex(int val);
	int getIndex();
	virtual int Eval(std::vector<int> variables);
	virtual void draw(int level = 0);
	virtual char getType();
	virtual std::string print();

  private:
	int myIndex;
};

#endif /* VARIABLETERMINAL_H */
#endif	/* VARIABLETERMINAL_H */
