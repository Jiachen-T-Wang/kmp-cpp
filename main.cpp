//
//  main.cpp
//  A4Q4
//
//  Created by Tianhao Wang on 17/11/14.
//  Copyright © 2017年 Tianhao Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> failureArray(string P);
vector<int> fail(string p);

int main(int argc, const char * argv[]) {
    vector<int> F = fail("S?E SE?LS SEASHELLS");
    
    for (int i = 0; i < 19; ++i)
        cout << F[i] << endl;
    return 0;
}

vector<int> failureArray(string P){
    vector<int> F;
    F.emplace_back(0);  //F[0] = 0
    int i = 1;
    int j = 0;
    int m = P.size();
    while (i < m){
        if (P[i] == P[j] || P[i] == '?' || P[j] == '?'){
            F.emplace_back(j+1);
            i++;
            j++;
        }
        else if (j>0){
            int y = j - F[j-1] + 1;
            int k = 0;
            int x = y;
            while (y <= j){
                if (P[k] == P[x] || P[k] == '?' || P[x] == '?'){
                    k++;
                    if (x == j){
                        i++;
                        F.emplace_back(k);
                        break;
                    }
                    x++;
                }
                else{
                    y++;
                    x = y;
                }
            }
            if (y > j)
                j = 0;
            else{
                j=k;
            }
            
        }
        else{
            F.emplace_back(0);
            ++i;
        }
    }
    return F;
}

vector<int> fail(string p) {
    vector<int> f;
    int m = p.size();
    for (int i = 0; i < m; ++i) {
        f.emplace_back(0);
    }
    int i = 1;
    int j = 0;
    while (i < m) {
        if (p[i] == p[j] || p[i] == '?' || p[j] == '?') {
            f[i] = j+1;
            ++i;
            ++j;
        } else if (j > 0) {
            while (true) {
                j = f[j-1];
                int k = j-1;
                while (k >= 0) {
                    if (p[k] != p[i-j+k] && p[k] != '?' && p[i-j+k] != '?') {
                        break;
                    }
                    --k;
                }
                if (k == -1) {
                    break;
                }
            }
        } else {
            f[i] = 0;
            ++i;
        }
    }
    return f;
}

