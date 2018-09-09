
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef SCORE_H
#define SCORE_H
#include "Node.h"
#pragma once

class Score
{
    /** this is an important class, it will store the the fitness value aka score
	*	with its corresponding tree aka program. then the ranking function
	*	used by the Gene class will rank the programs upon their scores.
	*	so when we get the best score value its easer to return the corresponding
	*	tree program!
	*/

  public:
    Score();
    Score(unsigned int val, Node *tree);
    unsigned int getScoreValue();
    Node *getTree();
    void setScoreValue(unsigned int val);
    void setTree(Node *tree);

    virtual ~Score();

  private:
    unsigned int scoreValue;
    Node *myTree;
};

#endif /* SCORE_H */
#endif	/* SCORE_H */
