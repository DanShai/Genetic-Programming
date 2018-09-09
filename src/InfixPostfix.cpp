/* 
 * File:   InfixPostfix.cpp
 * Author: dan
 * 
 * Created on April 11, 2015, 6:39 PM
 */


#include "InfixPostfix.h"
using namespace std;

InfixPostfix::InfixPostfix(std::string expression) {
    this->setExpressionTree(NULL);
    this->setExpressionType(false);
    this->setExpression(expression);
    this->formatExpression();
    this->expresVector = this->splitExpression(this->getExpression(), " ");
    if (this->isPostfix())
        this->setExpressionType(true);
}

InfixPostfix::InfixPostfix() {
    this->setExpressionTree(NULL);
    this->setExpressionType(false);
}

void InfixPostfix::InitExpression(std::string expression) {

    this->setExpression(expression);
    this->formatExpression();
    this->expresVector = this->splitExpression(this->getExpression(), " ");
    if (this->isPostfix())
        this->setExpressionType(true);

}

InfixPostfix::~InfixPostfix() {
}

void InfixPostfix::setExpressionType(bool mytype) {
    this->expressionType = mytype;
}

bool InfixPostfix::getExpressionType() {
    return this->expressionType;
}

bool InfixPostfix::isPostfix() {
    std::string lastElement = this->getExpressionVector().back();
    if (this->isOperator(lastElement))
        return true;
    return false;
}

std::vector<std::string> InfixPostfix::getExpressionVector() {
    return this->expresVector;
}

std::string InfixPostfix::addWhiteSpace(std::string expression, const std::string from, const std::string to) {
    size_t pos = 0;
    while ((pos = expression.find(from, pos)) != std::string::npos) {
        expression.replace(pos, from.length(), to);
        pos += to.length();
    }

    return expression;
}


void InfixPostfix::formatExpression() {
   
   std::string s(this->getExpression());
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
            s.erase(i, 1);
            i--;
        }
    }
    
   this->setExpression(s);

}

std::string InfixPostfix::formatExpression(std::string expr) {
   
   std::string s(expr);
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
            s.erase(i, 1);
            i--;
        }
    }
    

   return s;

}


// basic error checking...
bool InfixPostfix::chekBasicValidity() {
    if (this->myExpression.empty())
        return false;


    bool error = false;
    bool postfix = this->getExpressionType();
    if (!postfix) {
        size_t opened = std::count(this->myExpression.begin(), this->myExpression.end(), '(');
        size_t closed = std::count(this->myExpression.begin(), this->myExpression.end(), ')');
        if (opened != closed)
            return false;

        std::vector<std::string> expresVect = this->getExpressionVector();
        
        std::vector<std::string>::iterator s_it = expresVect.begin();
        while( s_it!= expresVect.end()-1){
            if (this->isOperator(*s_it) && this->isOperator(*(s_it+1)))
                error = true;
            if(this->isAnOperand(*s_it) && *(s_it+1)=="(")
                error=true;
            if(*s_it==")" && this->isAnOperand(*(s_it+1)))
                error=true;
            if(*s_it=="(" && this->isOperator(*(s_it+1)))
                error=true;
            if(this->isOperator(*s_it) && *(s_it+1)==")")
                error=true;
            
            ++s_it;
        }


    }

    if (error)
        return false;
    return true;
}

bool InfixPostfix::isAnOperand(std::string operand){
    if( !this->isOperator(operand) && operand != "(" && operand != ")" )
        return true;
    
    return false;
}


std::string InfixPostfix::infixToPostfix() {

    if (!this->chekBasicValidity())
        return "";

    std::vector<std::string> expresVect = this->getExpressionVector();
    std::vector<std::string>::iterator s_it = expresVect.begin();
    std::string postfixString = "";
    std::stack<std::string> myStack;
    while (s_it != expresVect.end()) {

        if (this->isOperator(*s_it)) {
            while (!myStack.empty() && myStack.top() != "(" && isPrioritized(myStack.top(), *s_it)) {
                postfixString += myStack.top();
                myStack.pop();
            }
            myStack.push(*s_it);


        } else if (this->isAnOperand(*s_it)) {
            //postfixString += " ";
            postfixString += *s_it;
            postfixString += " ";
        } else if (*s_it == "(") {
            myStack.push(*s_it);

        } else if (*s_it == ")") {
            while (!myStack.empty() && myStack.top() != "(") {
                postfixString += myStack.top();
                myStack.pop();
            }
            myStack.pop();
        }

        ++s_it;
    }

    while (!myStack.empty()) {
        postfixString += myStack.top();
        myStack.pop();
    }


    //this->setExpression(postfixString);
    //postfixString  = this->formatExpression(postfixString);

    return postfixString;
}

bool InfixPostfix::isPrioritized(std::string oper_1, std::string oper_2) {
    int op_prior1 = this->GetOperatorPriority(oper_1);
    int op_prior2 = this->GetOperatorPriority(oper_2);

    if(op_prior1 > op_prior2)
        return true;
    else
        return false;
}


int InfixPostfix::GetOperatorPriority(std::string op) {

    int priority = -1;
    if (op == "+" )
        priority = 1;
    else if (op == "-")
        priority = 2;
    else if (op == "*")
        priority = 3;
    else if (op == "/")
        priority = 4;

    return priority;
}

void InfixPostfix::print() {
    Node* tree = this->expressionTotree();
    if (tree != NULL) {
        std::cout << " Printing the Expression Tree.." << std::endl;
        tree->draw();
    } else
        std::cout << " You Entred Invalid Expression.." << std::endl;
}



void InfixPostfix::setExpression(std::string expression) {
    this->myExpression = expression;
}

std::string InfixPostfix::getExpression() {
    return this->myExpression;
}

// this will split a string and put the elements in a vector

std::vector<std::string> InfixPostfix::splitExpression(const std::string &s, std::string separator) {

    std::string res = "";
    for (size_t i = 0; i < s.length(); i++) {
        std::string temp = "";
        std::string mystrs(1, s[i] );
        if ( !this->isAnOperand (mystrs))
            temp = separator + mystrs + separator;
        else
            temp = mystrs;
        res += temp;
    }

    
    std::vector<std::string> tokens;
    std::vector<std::string> atlast;
    
    string::size_type lastPos = res.find_first_not_of(separator, 0);
    string::size_type pos     = res.find_first_of(separator, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(res.substr(lastPos, pos - lastPos));
        lastPos = res.find_first_not_of(separator, pos);
        pos = res.find_first_of(separator, lastPos);
    }
    
    
    
    
    std::vector<std::string>::iterator s_it = tokens.begin();
    while (s_it != tokens.end()) {
        if (*s_it != separator)
        {
        atlast.push_back(*s_it);
            
        }
        ++s_it;
    }

    
    return atlast;
}

// this will be used when constructing the tree in the expressionTotree() method
// it translates a string operator to an Operations class will be used for 
//tree Nodes.
Operations* InfixPostfix::operatorToOperations(std::string anOperator) {

    if (anOperator == "+")
        return new Operations(O_add, 2, "+");
    else if (anOperator == "*")
        return new Operations(O_mul, 2, "*");
    else if (anOperator == "/")
        return new Operations(O_div, 2, "/");
    else if (anOperator == "-")
        return new Operations(O_sub, 2, "-");
    else
        return NULL;

}

std::string  InfixPostfix::operationToOperator(Operations* op) {

    return op->getFName();

}

bool InfixPostfix::isOperator(std::string anop) {
    if (anop == "+" || anop == "-" || anop == "*" || anop == "/")
        return true;
    return false;
}

Node* InfixPostfix::getExpressionTree() {
    return this->myExpresionTree;
}
void InfixPostfix::setExpressionTree(Node *thetree) {
    this->myExpresionTree = thetree;
}

bool InfixPostfix::verifyOperandIsNumber(std::string operand){
    std::string::const_iterator si;
    bool adigit = true;
    for (si = operand.begin(); si != operand.end(); si++) {
          if(!isdigit(*(si)))
              adigit = false;

    }
    return adigit;
}

std::string InfixPostfix::treeToPostfix(Node* theThree){
    //theThree = this->getExpressionTree();
    std::string res = theThree->print();
    return res;
    
    
}

std::string InfixPostfix::postfixToInfix(std::string expression) {
    std::stack<SubExpression*> myStack;
    std::vector<std::string> tokens = this->splitExpression(expression, " ");
    std::vector<std::string>::iterator s_it = tokens.begin();
    while (s_it != tokens.end()) {
        if (*s_it == "+" || *s_it == "-")
        {
            SubExpression* rightExp = myStack.top();
            myStack.pop();
            SubExpression* leftExp = myStack.top();
            myStack.pop();

            std::string newExpr = leftExp->getExp() + *s_it + rightExp->getExp();

            myStack.push(new SubExpression(newExpr, *s_it));
        }
        else if (*s_it == "*" || *s_it == "/")
        {
            std::string lExp, rExp;
            
            
            SubExpression* rightExp = myStack.top();
            myStack.pop();
            if (rightExp->getOp() == "+" || rightExp->getOp() == "-")
            {
                rExp = "(" + rightExp->getExp() + ")";
            }
            else
            {
                rExp = rightExp->getExp();
            }

            SubExpression* leftExp = myStack.top();
            myStack.pop();
            if (leftExp->getOp() == "+" || leftExp->getOp() == "-")
            {
                lExp = "(" + leftExp->getExp() + ")";
            }
            else
            {
                lExp = leftExp->getExp();
            }

            std::string newExpr = lExp + *s_it + rExp;

            myStack.push(new SubExpression(newExpr, *s_it));
        }
        else 
        {
            myStack.push(new SubExpression(*s_it, ""));
        }
      ++s_it;

    }
    SubExpression* res = myStack.top(); 
    return res->getExp();
}



Node* InfixPostfix::expressionTotree() {

    std::string expression = this->getExpression();
    // if Expression was infix , we convert it first to postfix
    if (!this->getExpressionType()) {
        //this one will set the expression to postfix if no errors!
        expression = this->infixToPostfix(); 
        if (expression == "")
            return NULL;

        std::cout << "Converted Expression to Postfix: " << expression << std::endl;

    }

    bool error = false;
    std::stack<Node*> myStack;
    std::vector<std::string> tokens = this->splitExpression(expression, " ");
    std::vector<std::string>::iterator s_it = tokens.begin();
    while (s_it != tokens.end()) {

        if (this->isAnOperand(*s_it)) {
            if(!this->verifyOperandIsNumber(*s_it))
                return NULL;
            int value = atoi((*s_it).c_str());
            ConstantTerminal* opterm = new ConstantTerminal(value);
            myStack.push(opterm);

        } else {
            Node* operand_1 = NULL;
            Node* operand_2 = NULL;
            if (!myStack.empty()) {
                operand_2 = myStack.top();
                myStack.pop();
            } else {
                error = true;
                break;
            }
            if (!myStack.empty()) {
                operand_1 = myStack.top();
                myStack.pop();
            } else {
                error = true;
                break;
            }
            Operations* curOperation = this->operatorToOperations(*s_it);
            std::vector<Node*>* children = new std::vector<Node*>();
            children->push_back(operand_1);
            children->push_back(operand_2);
            Node* tree = new Tree(curOperation, children);
            myStack.push(tree);

        }
        ++s_it;
    }
    if (error)
        return NULL;

    Node* finalTree = myStack.top();
    myStack.pop();
    Node* myTree = NULL;
    if (myStack.empty())
        myTree = finalTree;

    this->setExpressionTree(myTree);
    return myTree;

}
