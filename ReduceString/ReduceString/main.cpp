//
//  main.cpp
//  ReduceString
//
//  Created by Esteban Gomez on 2/22/18.
//  Copyright © 2018 esteban. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string super_reduced_string(string s){
    for(int i =0; i < s.length(); ++i)
    {
        if (s[i] == s[i+1])
        {
            s = s.erase(i, 2);
            i = -1;
        }
    }
    if (s =="")
    {
        return "Empty String";
    }
    else return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
