//
//  main.cpp
//  Pointers
//
//  Created by Esteban Gomez on 9/1/17.
//  Copyright © 2017 esteban. All rights reserved.
//

#include <iostream>

using namespace std;


int main()
{
    int firstValue, * myPointer;
    
    
    myPointer = &firstValue;
    
    cout << "The first one is the address of my pointer " << &myPointer << endl;
    
    cout << "This one is the address held by myPointer " << myPointer << endl;
    
    cout << "It should be the same as the address of firstValue " << &firstValue << endl;
    
    firstValue = 5;
    
    cout <<"This is the value of the address myPointer is pointing to " << *myPointer <<endl;
    
    return 0;
    
    
}
