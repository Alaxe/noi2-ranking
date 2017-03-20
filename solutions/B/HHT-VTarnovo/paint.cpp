#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct points{
    int x;
    int y;
    int w;
    int h;
    int s;
    int x2;
    int y2;
}t[11001];
bool operator<(points a, points b){
    return a.s<b.s;
}
int grid[11001][11001], n, ultx, ulty, h=1, d[11001], s[11001], br=1, dots, answ[11001];
main(){
    priority_queue <points> qu;
    //vector <int> prinadlejnost[11001];
    cin>>ultx>>ulty;
    cin>>n;
    s[0] = ultx*ulty;
    for(int i=0;i<n;i++){
        cin>>t[i].x>>t[i].y>>t[i].w>>t[i].h;
        t[i].s = t[i].w*t[i].h;
        t[i].x2 = t[i].x+t[i].w;
        t[i].y2 = t[i].y+t[i].h;
        qu.push(t[i]);
    }
   while(!qu.empty()){
        int f=0;
        points x;
        x = qu.top();
        s[br] = x.s;
        br++;
        for(int i=x.y;i<x.y2;i++){
            for(int j=x.x;j<x.x2;j++){

                if(!f){
                    //prinadlejnost[grid[i][j]].push_back(h);
                    d[grid[i][j]] += x.s;
                    f++;
                }
                grid[i][j] = h;
            }
        }
        qu.pop();
        h++;

    }
    /*for(int i=0;i<ulty;i++){
        for(int j=0;j<ultx;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    /*for(int i=0;i<=n;i++){
        cout<<i;
        for(int j=0;j<prinadlejnost[i].size();j++){
            cout<<" "<<prinadlejnost[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<=n;i++){
        cout<<d[i]<<" "<<s[i]<<endl;;
    }
    cout<<endl;*/
    cin>>dots;
    for(int i=0;i<dots;i++){
        int cordx, cordy;
        cin>>cordx>>cordy;
        answ[i]=s[grid[cordy][cordx]] - d[grid[cordy][cordx]];
    }
    for(int i=0;i<dots;i++)cout<<answ[i]<<endl;
}
/*
11 7
3
1 1 1 1
3 3 3 3
7 7 1 1
-----------
10 10
4
1 1 3 3
2 2 1 1
4 4 6 6
5 5 2 2
-----------
11 7
3 2 1 5 5
8 2 2 3
 3 2 3 2
4
4 3
3 5
10 1
9 3
*/
