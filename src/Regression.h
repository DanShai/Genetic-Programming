
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef REGRESSION_H
#define REGRESSION_H
#include <fstream>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Score.h"
#include <algorithm>
#include "Node.h"
#include "DataXy.h"
#include "Score.h"

#pragma once
class Regression
{
    /**this is our regression class for finding the functions
	* note that it has the ranking function which we be used as
	* parameter for the Gene evolute fumction.
	*/

  public:
    Regression();
    virtual ~Regression();
    static std::vector<DataXy *> dataSet();
    static unsigned int getValues(Node *tree, std::vector<DataXy *> res);
    static std::vector<Score *> ranking(std::vector<Node *> population);
    static bool compareScores(Score *s1, Score *s2);

  private:
};

#endif /* REGRESSION_H */
#endif	/* REGRESSION_H */
