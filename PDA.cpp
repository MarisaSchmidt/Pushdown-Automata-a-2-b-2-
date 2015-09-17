/* MAIN PROGRAM for PDA */

//
//  PDA.cpp
//  
//
//  Created by Marisa Schmidt on 12/13/14.
//
//

#include "Expression.h"
#include<iostream>
using namespace std;

int main() {

    char answer;
    
    do {
       
        Expression a;
        
        a.setExpression();
        a.consume();
        //a.Display();
    
        cout << "Enter another input? Y/N" << endl;
        cin >> answer;

    } while (answer=='Y'||answer=='y');


    cout << "Exiting program..." << endl;
    return 0;
    
}
