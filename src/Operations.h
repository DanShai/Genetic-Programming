/**
 * @author dan
 * @version 1.0
 *
 */

#ifndef OPERATIONS_H
#pragma once
#include <string>
#include <iostream>
#include <vector>

typedef int (*aFunction)(std::vector<int>);

class Operations
{

    /**this class will be used by operators node, the tree
	* it encapsulate the operator used and its number of
	* parameters and its name! so it will be easer to evaluate
	* and draw the node later.
	*/

  public:
    Operations(aFunction fn, int num_param, std::string name);
    ~Operations();
    std::string getFName();
    aFunction getFunction();
    int getParamNums();

  private:
    aFunction myFunction;
    int funcParams;
    std::string funcName;
};

#endif /* OPERATIONS_H */#endif	/* OPERATIONS_H */

