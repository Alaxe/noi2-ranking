#include<bits/stdc++.h>

using namespace std;

pair < int, int > towhere[51];

vector < vector < int > > levels;

vector < int > abc;

int main () {

    int k, m, n;

    cin >> k >> m >> n;

    for(int i =  0 ; i <= n ; i ++){

        levels.push_back(abc);

    }

    for(int i = 1 ; i < m ; i ++){

        levels[1].push_back(i);

        int f1 = -1, f2 = -1;

        if(i - k > 0){

            f1 = i - k;

        }

        if(i + k < m){

            f2 = i + k;

        }

        pair < int, int > cba;

        cba.first = f1;
        cba.second = f2;

        towhere[i] = cba;

    }

    ///////////////////

    int level = 1;

    while(level != n){

        for(int i = 0 ; i < levels[level].size() ; i ++){

            int r1 = towhere[levels[level][i]].first;
            int r2 = towhere[levels[level][i]].second;


            if(r1 != -1){

                levels[level + 1].push_back(r1);

            }

            if(r2 != -1){

                levels[level + 1].push_back(r2);

            }

        }

        level ++;

    }

    cout << levels[n].size() << endl;

    return 0;
}
