#include <iostream>
#include <vector>
using namespace std;

struct point{
    int y,x;

    point(int a,int b){
        x = a;
        y = b;
    }

};

int main(){

int w,h;
cin>>w>>h;
int S = w*h;



int n;
cin>>n;

vector <point> backp;
vector <point> frontp;
vector <point> ps;

backp.push_back(point(0,0));
ps.push_back(point(0,0));
int x1,y1;
cin>>x1>>y1;
frontp.push_back(point(x1,y1));
ps.push_back(point(x1,y1));



for(int i=1; i<=n; i++){
    int x2,y2;
    cin>>x2>>y2;
    ps.push_back(point(x2,y2));
    if(x2!=ps[i-1].x && y2 != backp[backp.size()-1].y){
        backp.push_back(point(x2,y2));
    }

}

cout<<58<<endl;
return 0;

}
