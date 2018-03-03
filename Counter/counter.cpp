//
//  counter.cpp
//  
//
//  Created by Esteban Gomez on 12/9/17.
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
    int n, counter =0;
    cin >> n;
    string num = bitset<16>(n).to_string();
    cout << num << endl;
    int maxCounter = 0;
    
    for (int i = 0; i < num.length(); ++i)
    {
        if (num[i] == '1')
        {
            counter++;
            for (int j = i; j < num.length(); ++j)
            {
                if (num[j + 1] == '1')
                {
                    counter++;
                }
                else {
                    i = j;
                    break;
                }
            }
            if (counter >= maxCounter )
            {
                maxCounter = counter;
                //counter = 0;
            }
            counter = 0;
        }
    }
    cout << maxCounter;
    return 0;
}
