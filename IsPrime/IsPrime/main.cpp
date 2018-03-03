//
//  main.cpp
//  IsPrime
//
//  Created by Esteban Gomez on 1/10/18.
//  Copyright © 2018 esteban. All rights reserved.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int x, input;
    bool isPrime;
    cin >> x;
    int sq;
    while (cin >>input && x != 0)
    {
        sq = sqrt(input);
        for (int i = 2; i <= sq; ++i)
        {
            if (input % i == 0 )
            {
                isPrime = false;
                
            }
            else isPrime = true;
        }
        if (isPrime)
        {
            cout << "Prime" << endl;
        }
        else cout << "Not prime" << endl;
        x--;
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
