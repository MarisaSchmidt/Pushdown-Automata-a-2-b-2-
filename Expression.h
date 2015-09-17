/* ----------- EXPRESSION.H for PDA ---------- */

//
//  Expression.h
//  
//
//  Created by Marisa Schmidt on 12/13/14.
//
//

#ifndef _Expression_h
#define _Expression_h

#include "Stack.h"
#include<iostream>
using namespace std;


class Expression {
    
public:
    Expression(); //default constructor
    //AlgebraicExpression(const &string); //copy constructor
    ~Expression();
    void setExpression(); //accessor functions
    void consume(); //convert infix to postfix
    //void Display();
    
private:
    string expression;
    int finalVal;

};


Expression::Expression() {
    //make some default values
    expression = " ";
    //postfix = "e";
}

Expression::~Expression() {
    //not sure what to do here for PDA
}


void Expression::setExpression() {
    cout << "Expression? " << endl;
    cin >> expression;
}


void Expression::consume () {
 
    Stack<char> s;
    char ch;
    int count = 0; //number of iterations

    int top = expression[0];
    
    
    while (top != 'e') { //there is still input) {

        cout << "STEP" << "\tSTATE" << "\tUNREAD INPUT" << "\tSTACK" << "\tDELTA USED" << "\tR USED" << endl;
        
        //display original step 0
        cout << count << "/t" << "p" <<"\t";
        ch = s.getTop(); //equal to top, where you will start to pop

        //display input
        for (int j=0; j < expression.length(); j++) {
        cout << expression[j];
        }
        
        //display stack
        cout << "\t" << ch;
        //delta rule
        cout << "\t-";
        //R-rule
        cout << "\t " << endl;
    
        
        if (ch=='e') {
            if (top != 'e') {
                s.pop();
                s.push('S'); //
            }
            count++;
            cout << count << "\tq" <<"\t";
            //display expression
            for (int j = 0; j < expression.length(); j++) {
                cout << expression[j];
            }
            
            //..DISPLAY STACK?
            
            //deltarules
            cout << "\t" << 1;
            //R-rules
            cout << "\t ";
        }
        else if (ch=='S') {
            //'aSb' //
            char topInput = expression[0];
            count++;
            
            if (topInput =='a') {
            //get rid of ch in infix expression at top
                expression[0] =' ';

                cout << count << "\tq" <<"\t";
                //display expression
                for (int j = 0; j < expression.length(); j++) {
                    cout << expression[j];
                }
                
                //..DISPLAY STACK?
                
                //deltarules
                cout << "\t" << 2;
                //R-rules
                cout << "\t ";
            }
            else if (topInput=='b') {
                ch = s.getTop();
                s.pop();
                s.push('e');
                cout << count << endl;
                cout << "\tq" << "\t";
                
                //display expression
                for (int j = 0; j < expression.length(); j++) {
                    cout << expression[j];
                }
                
                //..DISPLAY STACK?
                
                //deltarules
                cout << "\t" << 3;
                //R-rules
                cout << "\t ";

                
            }
        }
        else { //a or b is at top of STACK
            char topInput = expression[0];
            
            while (topInput=='a') {
                count++;
                cout << count << "\tq" << "\t";
                
                //display expression
                for (int j = 0; j < expression.length(); j++) {
                cout << expression[j];
                }
                
                s.push(topInput);
                
                    //display STACK ?
                    
                    //deltarules
                cout << "\t" << 3;
                    //R-rules
                cout << "\t ";
                    
            }
            
            while (topInput=='b') {
                

                count ++;
                cout << count << "\tq" << "\t";
                
                //display expression
                for (int j = 0; j < expression.length(); j++) {
                    cout << expression[j];
                }
                
                s.pop();
                s.push(topInput);
                
                //DISPLAY STACK?
                
                //deltarules
                cout << "\t" << 4;
                //R-rules
                cout << "\t ";

            }//end while loop
            
        }//end else statement
    
    
    /* WHAT ABOUT $ ???

     */
    
    
    }//end while loop

}//end function




/*
void AlgebraicExpression::Display() {
    
    cout << finalVal << endl;
}
*/

#endif
