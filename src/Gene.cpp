/* 
 * File:   Gene.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:54 PM
 */

#include "Gene.h"

Gene::Gene() {
    this->populationSize = 500;
    this->maxGenerations = 50;
    this->mutationPb = 0.05;
    this->crossOverPb = 0.8;
    this->VarPb = 0.6;
    this->treePb = 0.8;
    this->newNodePb = 0.4;
    this->opDefinitions = new OperationsDefinition();
    std::srand(std::time(0));

}

Gene::~Gene() {
}

Operations* Gene::getRandomOperation() {
    unsigned int r = std::rand() % this->currentOpTable.size();
    //std::cout << "TABLE SIZE  " << this->currentOpTable.size() << std::endl;
    std::vector<Operations*>::iterator itr = this->currentOpTable.begin();
    std::advance(itr, r);
    return *itr;

}

Node* Gene::getRandomNode(std::vector<Node*> ch) {
    unsigned int r = std::rand() % ch.size();
    std::vector<Node*>::iterator itr = ch.begin();
    std::advance(itr, r);
    return *itr;

}

Node* Gene::createTree(int max_depth) {
     double r = (( double) std::rand() / (RAND_MAX));
    if (r < this->getTreePb() && max_depth > 0) {
        Operations* op = this->getRandomOperation();
        std::vector<Node*>* children = new std::vector<Node*>();
        for (int i = 0; i < op->getParamNums(); i++)
            children->push_back(this->createTree(max_depth - 1));
        Node* tree = new Tree(op, children);
        return tree;
    }
    r = (( double)std::rand() / (RAND_MAX));
    if (r < this->getVarPb()) {
        Node* varNode = new VariableTerminal((unsigned int)std::rand() % (this->getProblemSize() ));
        return varNode;
    } else {
        Node* constNode = new ConstantTerminal((unsigned int)std::rand() % 10);
        return constNode;

    }

}

Node* Gene::mutate(Node* atree, int max_depth) {
     double r = (( double) std::rand() / (RAND_MAX));
    if (r < this->getMutationPb())
        return this->createTree(max_depth);
    else {
        Node* myTree = this->clone(atree);
        if (atree->getType() == 'T') {
            std::vector<Node*>* newChildren = new std::vector<Node*>();
            std::vector<Node*>* tchildren = (dynamic_cast<Tree*> (atree))->getChildren();

            for (unsigned int n = 0; n < tchildren->size(); n++) {
                Node* nd = (*tchildren)[n];
                newChildren->push_back(this->mutate(nd, max_depth-1));
            }
            (dynamic_cast<Tree*> (myTree))->setChildren(newChildren);
        }
        return myTree;
    }


}

Node* Gene::crossOver(Node* treeFather, Node* treeMother, bool stop) {
     double r = (( double) std::rand() / (RAND_MAX));
    if (r < this->getCrossingPb() && stop == false)
        return this->clone(treeMother);
    else { 
        Node* myTree = this->clone(treeFather);
        //std::cout << "=======FATHR======" << std::endl;
        //treeFather->draw();
        //std::cout << "=======FATHR CLONE======" << std::endl;
        //myTree->draw();
        //std::cout << "=======MOTHER======" << std::endl;
        //treeMother->draw();
        if (treeFather->getType() == 'T' && treeMother->getType() == 'T') {
            std::vector<Node*>* newChildren = new std::vector<Node*>();
            std::vector<Node*>* mchildren = (dynamic_cast<Tree*> (treeMother))->getChildren();
            std::vector<Node*>* fchildren = (dynamic_cast<Tree*> (treeFather))->getChildren();

            for (unsigned int n = 0; n < fchildren->size(); n++) {
                Node* nd = (*fchildren)[n];
                newChildren->push_back(this->crossOver(nd, this->getRandomNode(*mchildren), false));
            }
            (dynamic_cast<Tree*> (myTree))->setChildren(newChildren);
            
          //std::cout << "=======AFTER CROSS======" << std::endl;
          //myTree->draw();

        }
        return myTree;

    }
}



Node* Gene::clone(Node* anode) {
    //Node* aCopy;
    if (anode->getType() == 'T') {
        Operations* op = (dynamic_cast<Tree*> (anode))->getOperations();
        std::vector<Node*>* ch = (dynamic_cast<Tree*> (anode))->getChildren();
        std::vector<Node*>* tempo = new std::vector<Node*>();
        for (unsigned int i = 0 ; i < ch->size() ; i++ ){
            tempo->push_back(this->clone((*ch)[i]));
        }
        return (new Tree(op, tempo));
    }
        //*aCopy = new Tree(op, tempo);
    if (anode->getType() == 'V') {
        int ind = (dynamic_cast<VariableTerminal*> (anode))->getIndex();
         return (new VariableTerminal(ind));
        // *aCopy = new VariableTerminal(ind);
    }
    if (anode->getType() == 'C') {
        int val = (dynamic_cast<ConstantTerminal*> (anode))->getValue();
        return (new ConstantTerminal(val));
        //*aCopy = new ConstantTerminal(val);
    }

   // return aCopy;

}

void Gene::setScoreVector(std::vector<Score*> score) {
    this->scoreVector = score;
}

std::vector<Score*> Gene::getScoreVector() {
    //this->scoreVector.push_back(new Score(1,this->createTree(3)));
    return this->scoreVector;
}

Node* Gene::evoluate(int max_depth) {

    std::vector<Node*> population;
    for (unsigned int n = 0; n < this->getPopulationSize(); n++)
        population.push_back(this->createTree(max_depth));

    for (unsigned int i = 0; i < this->getMaxGenerations(); i++) {
        this->scoreVector = this->rankingFunction(population);
//        this->scoreVector = this->getScoreVector();
        int bestVal = this->scoreVector[0]->getScoreValue();
        Node* bestTree = this->scoreVector[0]->getTree();

        std::cout << "=======Generation: " << i << " ========" << std::endl;
        std::cout << "Best Score: " << bestVal << std::endl;
        //bestTree->draw();
        if (bestVal == 0)
            break;
        std::vector<Node*> newPopulation;
        newPopulation.push_back(bestTree);
        while (newPopulation.size() < this->getPopulationSize()) {
        //for (unsigned int n = 1; n < this->getPopulationSize(); n++){
             double r = (( double) std::rand() / (RAND_MAX));
            if (r > this->getNewNodePb()) {
                //unsigned int tree1_index = (unsigned int) rand() % (3) +1;
                unsigned int tree2_index = (unsigned int) rand() % 10 +1;

                newPopulation.push_back(
                        this->mutate(
                        this->crossOver(
                        this->scoreVector[0]->getTree(),
                        this->scoreVector[tree2_index]->getTree()), max_depth));
                /*
                newPopulation.push_back(
                        this->mutate(
                        this->crossOver(
                        this->scoreVector[tree1_index]->getTree(),
                        this->scoreVector[tree2_index]->getTree()), max_depth));
                 * */
            } else
                newPopulation.push_back(this->createTree(max_depth));


        }
    
        population = newPopulation;
       /*
        if(i%10 == 0){
            
            population.clear();
            for (unsigned int n = 0; n < this->getPopulationSize(); n++)
                population.push_back(this->createTree(max_depth));

            
        }
        */
            
    }
    Node* bestTree = this->scoreVector[0]->getTree();
    //bestTree->draw();
    return bestTree;

}

void Gene::setProblemSize(int ps) {
    this->problemSize = ps;
}

int Gene::getProblemSize() {
    return this->problemSize;
}

unsigned int Gene::getPopulationSize() {
    return this->populationSize;
}

unsigned int Gene::getMaxGenerations() {
    return this->maxGenerations;
}

void Gene::setTreePb(double tpb) {
    this->treePb = tpb;
}

double Gene::getTreePb() {
    return this->treePb;
}
void Gene::setNewNodePb(double newN) {
    this->newNodePb = newN;
}

double Gene::getNewNodePb() {
    return this->newNodePb;
}

void Gene::setVarPb(double vpb) {
    this->VarPb = vpb;
}

double Gene::getVarPb() {
    return this->VarPb;
}

void Gene::setPopulationSize(unsigned int ps) {
    this->populationSize = ps;
}

void Gene::setMaxGenerations(unsigned int mg) {
    this->maxGenerations = mg;
}

void Gene::setRankingFunction(rankFunction rk) {
    this->rankingFunction = rk;
}

void Gene::setMutationPb(double mu) {
    this->mutationPb = mu;
}

void Gene::setCrossingPb(double cr) {
    this->crossOverPb = cr;
}

double Gene::getMutationPb() {
    return this->mutationPb;
}

double Gene::getCrossingPb() {
    return this->crossOverPb;
}

void Gene::setGeneOperations(std::string gops) {
    if (gops == "BASIC")
        this->currentOpTable = this->opDefinitions->getBasicOperationsTable();
    else if (gops == "BOOLEAN")
        this->currentOpTable = this->opDefinitions->getBooleanOperationsTable();
    else if (gops == "ALL")
        this->currentOpTable = this->opDefinitions->getAllOperationsTable();

}

std::vector<Operations*> Gene::getGeneOperations() {
    return this->currentOpTable;
}
