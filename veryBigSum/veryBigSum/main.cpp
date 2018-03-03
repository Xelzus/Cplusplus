//
//  main.cpp
//  veryBigSum
//
//  Created by Esteban Gomez on 2/13/18.
//  Copyright © 2018 esteban. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

long aVeryBigSum(int n, vector <long> ar) {
    long result = 0L;
    
    for (int i = n; i >= 0; --i)
    {
        result += ar[i];
    }
    return result;
    // Complete this function
}

int main() {
    int n;
    cin >> n;
    vector<long> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        cin >> ar[ar_i];
    }
    long result = aVeryBigSum(n, ar);
    cout << result << endl;
    return 0;
}

