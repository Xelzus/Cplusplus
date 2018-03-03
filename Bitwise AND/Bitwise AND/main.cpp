//
//  main.cpp
//  Bitwise AND
//
//  Created by Esteban Gomez on 1/15/18.
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
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        int ans = 0;
        
        cin >> n >> k;
        for (int i = n; i >= 2 ; --i)
        {
            for (int j = i-1; j >= 1; --j)
            {
                int bit = (i & j);
                if (bit < k && bit > ans)
                {
                    ans = bit;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

