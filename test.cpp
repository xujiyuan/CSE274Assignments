//
//  test.cpp
//  Assignment2
//
//  Created by xuj4 on 10/6/14.
//  Copyright (c) 2014 xuj4. All rights reserved.
//

#include <iostream>
#include "DLList.h"

using namespace ods;
using namespace std;


void testAbdorb();
void testDeal();
void testIsPalindrome();
void testRotate();


int main() {
    
    cout <<"Start testing DLList class: " << endl;

    testIsPalindrome();
    testAbdorb();
    testDeal();
    testRotate();

    return 0;
}

void testRotate(){
    DLList<char> rotate;
    rotate.add('A');
    rotate.add('B');
    rotate.add('C');
    rotate.add('D');
    rotate.add('E');
    rotate.add('F');
    
    rotate.Rotate(1);
    cout << "test Rotate: " << endl;
    for (int i=0; i<rotate.size();i++){
        cout << "value1: " << rotate.get(i) << endl;
    }
}

void testAbdorb(){
    DLList<char> abs1;
    DLList<char> abs2;
    
    abs1.add('M');
    abs1.add('N');
    abs1.add('O');
    abs2.add('P');
    abs2.add('Q');
    abs2.add('R');

    abs1.Absorb(abs2);
    
    cout << "test absorb: " << endl;
    for (int i=0; i<abs1.size();i++){
        cout << "value1: " << abs1.get(i) << endl;
    }
    
    
}

void testIsPalindrome(){
    DLList<int> alist;

    alist.add(1);
    alist.add(2);
    alist.add(1);
    alist.add(4);
    alist.add(1);
    alist.add(2);
    alist.add(1);


    cout <<"**Size of the list is:" << alist.size() << endl;

    cout <<"**Test IsPalindrome : " << alist.IsPalindrome() << " (This should return 1)"<< endl;
    alist.add(9);
    cout <<"**Test IsPalindrome : " << alist.IsPalindrome() << " (This should return 0)"<< endl;

    }

void testDeal(){
    
    DLList<char> deal;
    
    deal.add('G');
    deal.add('H');
    deal.add('I');
    deal.add('J');
    deal.add('K');
    deal.add('L');
    
    DLList<char> deal2 =  deal.deal();
    
    cout << "test deal: " << endl;
    for (int i=0; i<deal.size();i++){
        cout << "value1: " << deal.get(i) << endl;
    }
    
    for (int i=0; i<deal.size();i++){
        cout << "value2: " << deal2.get(i) << endl;
    }
}