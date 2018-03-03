//
//  main.cpp
//  PalindromeSub
//
//  Created by Esteban Gomez on 12/18/17.
//  Copyright © 2017 esteban. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void pushCharacter(char ch) {
        stack.push_back(ch);
    }
    void enqueueCharacter(char ch) {
        //in order to insert a char into a string using the insert method we need 3 parameters, insert pos, size and char
        //queue.insert(0, 1, ch);
        queue.push_back(ch);
    }
    char popCharacter() {
        char a = stack[0];
        stack.erase(0, 1);
        return a;
    }
    char dequeueCharacter() {
        char b = queue[queue.size()-1];
        queue.pop_back();
        return b;
    }
    
private:
    string stack, queue;
    //Write your code here
    
};
int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
    // create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}
