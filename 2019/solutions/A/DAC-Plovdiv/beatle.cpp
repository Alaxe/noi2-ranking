#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int n, t, maxx = -1;

struct plate{
    int x;
    int y;
    int d;
    int dpls = 1234567;
};

bool comp1(plate a, plate b){
    return a.y < b.y;
}

bool comp2(plate a, plate b){
    if(a.x < b.x) return 1;
    else if(a.x == b.x && a.y > b.y) return 1;
    else return 0;
}

vector<plate> pls;

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        plate c;

        scanf("%d %d %d", &c.x, &c.y, &c.d);

        maxx = max((c.x + c.d), maxx);

        pls.push_back(c);
    }

    sort(pls.begin(), pls.end(), comp1);

    for(int i = 0; i < n; i++){
        bool flag1 = false, flag2 = false;

        for(int j = i - 1; j >= 0; j--){
            if(pls[i].x > pls[j].x && pls[i].x <= (pls[j].x + pls[j].d)) {
                pls[i].dpls = min(pls[i].dpls, pls[j].dpls + 1);
                flag1 = true;
            }

            if((pls[i].x + pls[i].d) >= pls[j].x && (pls[i].x + pls[i].d) < (pls[j].x + pls[j].d)) {
                pls[i].dpls = min(pls[i].dpls, pls[j].dpls + 1);
                flag2 = true;
            }

            if(flag1 == true && flag2 == true) break;
        }

        if(flag1 == false || flag2 == false) pls[i].dpls = 1;
    }

    sort(pls.begin(), pls.end(), comp2);

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int z, ans = 0, height = 0;
        scanf("%d", &z);

        for(int j = 0; j < n; j++){
            if(pls[j].x > z) break;
            else{
                if(z >= pls[j].x && z < (pls[j].x + pls[j].d)&& pls[j].y > height){
                    ans = pls[j].dpls;
                    height = pls[j].y;
                }
            }
        }

        if(i == n - 1) printf("%d\n", ans);
        else printf("%d ", ans);
    }

    return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
