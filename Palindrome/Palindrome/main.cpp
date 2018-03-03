//
//  main.cpp
//  Palindrome
//
//  Created by Esteban Gomez on 12/18/17.
//  Copyright © 2017 esteban. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "hello";
    cout << s << endl;
    cout << s.size() << endl;
    s.append("!");
    cout << s << endl;
    s.pop_back();
    cout << s[5] << endl;
    cout << s << endl;
    char a = 'a';
    s.insert(0, 1, a); //arguments are position length and element
    cout << s << endl;
    char c = s[0];
    s.erase(0, 1);
    cout << s << " " << c << endl;
    return 0;
}
