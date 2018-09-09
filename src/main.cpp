/* 
 * File:   main.cpp
 * Author: dan
 * 
 * Created on April 12, 2015, 6:42 AM
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "Regression.h"
#include "Gene.h"
#include "InfixPostfix.h"

using namespace std;



char* getOption(char ** start, char ** end, const std::string & option)
{
    char ** itr = std::find(start, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool isExists(char** start, char** end, const std::string& option)
{
    return std::find(start, end, option) != end;
}


int main(int argc, char *argv[])
{


	Gene* gene =  new Gene();
	InfixPostfix* infPos =  new InfixPostfix();
	Node* best_funct = NULL;

    	if(isExists(argv, argv+argc, "-h") || isExists(argv, argv+argc, "--help"))
	    {
		cout << " Help commands ..." << endl;
		cout << " --help or -h : displays this help." << endl;
		cout << " -g [Number] Number is the max generations for the gene." << endl;
		cout << " -p [Number] Number is the Population size for the gene." << endl;
		cout << " -d [Number] Number is the Tree depth for the gene." << endl;
		cout << " -v [Number] Number is the problem variables numbers to be solved by the gene. 1 means 1 variable! and depends on how many variables are in your data.txt file, in this example we have only 1 variable which is : X " << endl;

	    }

	else{


	    	gene->setRankingFunction(Regression::ranking);
	    	gene->setGeneOperations("BASIC");
	
		

		char* population = getOption(argv, argv + argc, "-p");

		    if (population)
		    {
			istringstream ss(population);
			int x;
			if (!(ss >> x)) {
				cout << " Population Should be a Number!! "<< endl;
				cout << " Using default value.. "<< endl;
			    	gene->setPopulationSize(1000);
			
			}
			else{
				cout << " Population used : " << population << endl;
		    		gene->setPopulationSize(x);
			}
		    }else
			{
		    	gene->setPopulationSize(1000);
	
			}
	
		char* maxgen = getOption(argv, argv + argc, "-g");

		    if (maxgen)
		    {
			istringstream s2(maxgen);
			int y;
			if (!(s2 >> y)) {
				cout << " Generations Should be a Number!! "<< endl;
				cout << " Using default value.. "<< endl;
			    	gene->setMaxGenerations(50);

			}else{
				cout << " Max generations used : " << maxgen << endl;
			    	gene->setMaxGenerations(y);
			}
		    }else
			{
		    	gene->setMaxGenerations(50);
	
			}


		char* variables  = getOption(argv, argv + argc, "-v");

		    if (variables)
		    {
			istringstream s3(variables);
			int z;
			if (!(s3 >> z)) {
				cout << " Variable Should be a Number!! "<< endl;
				cout << " Using default value.. "<< endl;
				gene->setProblemSize(1);
			
			}else{
				cout << " Num of Variables used : " << variables << endl;
			    	gene->setProblemSize(z);
			}
		    }else
			{
		    	gene->setProblemSize(1);
	
			}


		char* depth = getOption(argv, argv + argc, "-d");

		    if (depth)
		    {

			istringstream s4(depth);
			int t;
			if (!(s4 >> t)) {
				cout << " depth Should be a Number!! "<< endl;
				cout << " Using default value.. "<< endl;
			    	best_funct = gene->evoluate(2);
				
			}else{
				cout << " tree depth used : " << depth << endl;
			    	best_funct = gene->evoluate(t);
			}
		    }else
			{
		    	best_funct = gene->evoluate(2);
	
			}


	    	best_funct->draw();
	     	std::string postf = infPos->treeToPostfix(best_funct);
		cout << endl;       	
		cout << " The Function For The Given Datas is: " << "[ f(X) = " <<  infPos->postfixToInfix(postf) << " ]" << endl;
	}
	  	
	return 0;
}
