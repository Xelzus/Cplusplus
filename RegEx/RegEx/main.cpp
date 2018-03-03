//
//  main.cpp
//  RegEx
//
//  Created by Esteban Gomez on 1/12/18.
//  Copyright © 2018 esteban. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int N;
    size_t pos;
    string temp;
    cin >> N;
    vector <string> alpha;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        pos = emailID.find("@gmail.com");
        //pos returns the first position where "@gmail.com" is found, npos returns greatest possible value for the given element. It is used to indicate if it matches
        if (pos != std::string::npos)
        {
            alpha.push_back(firstName);
        }
    }
    sort(alpha.begin(), alpha.end());
    vector<string> :: iterator it;
    for (it = alpha.begin(); it != alpha.end(); ++it)
    {
        cout << *it << endl;
    }
    
//    for (int i = 0; i < alpha.size() ; ++i)
//    {
//
//        if (alpha[i].compare(alpha[i+1]) > 0 && i+1 < alpha.size()) //using str.compare() argument is the next string in vector, it returns
//            // a negative number if it comes before in the alphabet.
//        {
//            //cout << alpha[i+1] << " comes before " << alpha [i] << endl;
//
//            iter_swap(alpha.begin() + i, alpha.begin() + (i+1));
//
//        }
//        cout << alpha[i] << endl;
//    }
    return 0;
    
}

