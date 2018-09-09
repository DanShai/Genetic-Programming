/**
 * @author dan
 * @version 1.0
 *
 */

#ifndef NODE_H
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iterator>
#include <typeinfo>

class Node
{
    /**
	* this is the Node interface should be implemented by all
	* Nodes
	* because we have different kind of nodes: operations
	* nodes,  constant nodes...
	*/

  public:
    Node();
    virtual ~Node();
    virtual int Eval(std::vector<int> variables) = 0;
    virtual void draw(int level = 0) = 0;
    virtual char getType() = 0;
    virtual std::string print() = 0;

  private:
};

#endif /* NODE_H */
#endif	/* NODE_H */
