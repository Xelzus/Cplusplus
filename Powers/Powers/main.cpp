//
//  main.cpp
//  Powers
//
//  Created by Esteban Gomez on 12/15/17.
//  Copyright © 2017 esteban. All rights reserved.
//
#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class Calculator {
public:
    int power(int n, int p)
    {
        //if (p == 0) return 1;
       if ( n < 0 || p < 0)
       {
           throw runtime_error("n and p should be non-negative");
       }
        /*if (p != 1)
         {
             return (n * power(n, p-1));
         }
         else
                return n;
         */
        return pow(n, p);
        
    }
    
    
    
};
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
        if(scanf("%d %d",&n,&p)==2){
            try{
                int ans=myCalculator.power(n,p);
                cout<<ans<<endl;
            }
            catch(exception& e){
                cout<<e.what()<<endl;
            }
        }
    }
    
}
