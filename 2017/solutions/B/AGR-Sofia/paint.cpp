#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
    int x, y, w, h;
    long long area;
    node* par;
    vector<node*> ch;
    node* find_point(int a, int b) {
        for(int i = 0; i < ch.size(); i ++) {
            if(!(a  <= ch[i]->x || b <= ch[i]->y || a >= ch[i]->x + ch[i]->w || b >= ch[i]->y + ch[i]->h ) ){
                return ch[i]->find_point(a, b);
            }
        }
        return this;
    }
    void init() {
        area = w * h;
        for(int i = 0; i < ch.size(); i ++) {
            area -= ch[i]->w * ch[i]->h;
            ch[i]->init();
        }
    }
};
int n;
node rec[11002];
bool reccmp(node a, node b) {
    return (a.w * a.h > b.w * b.h);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rec[0].x = 0;
    rec[0].y = 0;
    cin >> rec[0].w >> rec[0].h ;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> rec[i].x >> rec[i].y >> rec[i].w >> rec[i].h;
    }
    sort(rec, rec + n + 1, reccmp);
    for(int i = 1; i <= n; i ++) {
        node* p = rec[0].find_point(rec[i].x, rec[i].y);
        p->ch.push_back(&rec[i]);
        rec[i].par = p;
    }
    rec[0].init();


    int t;
    cin >> t;
    for(int i = 0; i < t; i ++) {
        int a, b;
        cin >> a >> b;
        cout << rec[0].find_point(a,b) -> area << endl;
    }
}
/*
11 7
3
8 2 2 3
2 1 5 5
3 2 3 2
4
4 3
3 5
10 1
9 3
*/
/*
10 10
2
2 2 6 6
4 4 2 2
3
1 1
3 3
5 5
*/
