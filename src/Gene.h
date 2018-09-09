
/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef GENE_H
#define GENE_H
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <typeinfo>

#include "Operations.h"
#include "Node.h"
#include "ConstantTerminal.h"
#include "VariableTerminal.h"
#include "Tree.h"
#include "OperationsDefinition.h"
#include "Score.h"

typedef std::vector<Score *> (*rankFunction)(std::vector<Node *>);

class Gene
{
    /** this is the Gene class , in here everything happend!
	* creating trees, mutation, crosover and evolution.
	* it has set of variables that will define our gene such as
	* population size, max generetions, probabilities etc..
	*/

  public:
    Gene();
    virtual ~Gene();
    Node *createTree(int max_depth);
    Node *mutate(Node *atree, int max_depth);
    Node *crossOver(Node *treeFather, Node *treeMother, bool stop = true);
    Node *evoluate(int max_depth);
    void setProblemSize(int ps);
    int getProblemSize();
    void setNewNodePb(double newN);
    double getNewNodePb();
    double getTreePb();
    double getVarPb();
    void setPopulationSize(unsigned int ps);
    void setMaxGenerations(unsigned int mg);
    unsigned int getPopulationSize();
    unsigned int getMaxGenerations();
    void setRankingFunction(rankFunction rk);
    void setMutationPb(double mu);
    void setCrossingPb(double cr);
    double getMutationPb();
    double getCrossingPb();
    void setTreePb(double tpb);
    void setVarPb(double vpb);
    Node *clone(Node *anode);
    void setGeneOperations(std::string gops);
    std::vector<Operations *> getGeneOperations();
    Operations *getRandomOperation();
    Node *getRandomNode(std::vector<Node *> ch);
    void setScoreVector(std::vector<Score *> score);
    std::vector<Score *> getScoreVector();

  private:
    int problemSize;
    int populationSize;
    int maxGenerations;
    double mutationPb;
    double crossOverPb;
    double treePb;
    double VarPb;
    double newNodePb;
    rankFunction rankingFunction;
    OperationsDefinition *opDefinitions;
    std::vector<Operations *> currentOpTable;
    std::vector<Score *> scoreVector;
};

#endif /* GENE_H */
#endif	/* GENE_H */
