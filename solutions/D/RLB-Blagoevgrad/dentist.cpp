#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
int br = 1;
struct chas{
    int a;
    int b;
};
bool cmp(chas p, chas g){
   return p.a < g.a;
}
int main(){

    int i = 0;
    chas c[720];
    while(cin >> c[i].a >> c[i].b){
            i++;
    }
    cin.clear();

    sort(c, c + i, cmp);

    int last = c[0].a + c[0].b;
    for(int j = 1; j < i; j++){
        if(c[j].a < last){
            last = last - c[j].a + c[j].a + c[j].b;
        }
        else last = c[j].a + c[j].b;
    }
    cout << last - c[i - 1].a << endl;

    return 0;
}
