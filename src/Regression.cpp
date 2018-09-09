/* 
 * File:   Regression.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:59 PM
 */

#include "Regression.h"

Regression::Regression() {
}



std::vector<DataXy*> Regression::dataSet() {
/*
    for (int i = 0 ; i < 12; i++){
        int y = 2*i*i -i;
        DataXy* dataxy = new DataXy(i,y);
        datas.push_back(dataxy);
    }
*/

     std::vector<DataXy*> datas;
     std::ifstream datastream("./res/data.txt");
     int x, y;
     char dummy;
     while ( datastream >> x >> dummy >> y)
	{
	    //std::cout << x << dummy << y << std::endl;
	    DataXy* dataxy = new DataXy(x,y);
	    datas.push_back(dataxy);
	}
    return datas;
}

unsigned int Regression::getValues(Node* tree, std::vector<DataXy*> res) {
    int dif = 0;
    for (unsigned int i = 0; i <res.size(); i++){
         std::vector<int> X ;
        X.push_back(res[i]->getX()) ;
        int val = tree->Eval(X);
        dif += std::abs(val-res[i]->getY());
    }
    return dif;

}
std::vector<Score*> Regression::ranking(std::vector<Node*> population){
    std::vector<Score*> scores ;
    std::vector<DataXy*> datas = Regression::dataSet();
    for (unsigned int i = 0; i < population.size(); i++){
        unsigned int val = Regression::getValues(population[i],datas);
        scores.push_back(new Score(val, population[i]));
    }
    
    std::sort(scores.begin(), scores.end(), Regression::compareScores);
    return scores;
    
    
}

bool Regression::compareScores(Score* s1, Score* s2){
    return (s1->getScoreValue() < s2->getScoreValue());
}    


Regression::~Regression() {
    
}
