/**
 * @author dan
 * @version 1.0
 *
 */

#ifndef SUBEXPRESSION_H
#include <sstream>
#include <string>
#include <iostream>
#pragma once

class SubExpression
{

    /**
	 * SubExpression class is helper class for converting
	 * a postfix expression to an infix expression
	 *
	 */
  public:
    SubExpression(std::string expre, std::string op);
    virtual ~SubExpression();
    std::string getExp();
    std::string getOp();

  private:
    std::string _mexp;
    std::string _mop;
};

#endif /* SUBEXPRESSION_H */
#endif	/* SUBEXPRESSION_H */
