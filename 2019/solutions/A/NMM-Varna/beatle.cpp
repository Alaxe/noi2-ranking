#include <iostream>
#include <algorithm>
#define maxn 100000
int dyn[maxn];
using namespace std;
int main(){
    int n;
    cin>>n;
    int x, y, d;
    int maxx=0, maxy=0;
    pair<int, pair<int, int> > b[maxn];
    for(int i = 0; i < n; i ++){
        cin>>x>>y>>d;
        if(x+d>maxx)
            maxx=x+d;
        if(y>maxy)
            maxy =y;
        b[i].first = y;
        b[i].second.first = x;
        b[i].second.second = d;
    }
    sort(b, b+n);
    int ind = 0, new_val, x1;
    for(y = 1; y<=maxy; y++){
        while(true){
            if(b[ind].first == y){
                x = b[ind].second.first;
                x1 = x + b[ind].second.second;
                new_val = min(dyn[x-1], dyn[x1]) + 1;
                for(int q = x; q < x1; q++){
                    dyn[q] = new_val;
                }
                ind++;
            }
            else{
                break;
            }
        }
    }
    int k,a;
    cin>>k;
    for(int i = 0; i < k; i ++){
        cin>> a;
        cout<<dyn[a]<<" ";
    }
    cout<<endl;
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
