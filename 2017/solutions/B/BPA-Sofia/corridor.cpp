#include<iostream>
#include<vector>
#include<math.h>
#include<utility>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
return fabs(x1-x2)+fabs(y1-y2);
}

int main(){

int w, h;
cin>>w>>h;
int n;
cin>>n;

int hx = 0;
int hy = 0;

bool skipped = false;

vector<pair<int, int> > lines;
for(int i = 0; i<n; i++){
    int x, y;
    cin>>x>>y;
    if(hy<=y and hx<=x){
        lines.push_back(pair<int, int>(x, y));
    }else if(hy<=y){
        if(skipped){
            pair<int, int> last = lines.back();
            lines.push_back(pair<int, int>(x, last.second));
            skipped = false;

        }
        lines.push_back(pair<int, int>(x, y));
    }else{
        skipped = true;
    }

    if(hx<x) hx = x;
    if(hy<y) hy = y;

}
if(lines.size()>2){
    for(int i = 2; i<lines.size(); i++){
        pair<int, int> e1 = lines[i-2];
        pair<int, int> e2 = lines[i-1];
        pair<int, int> e3 = lines[i];
        if(e2.first == e1.first and e2.first==e3.first){
            lines.erase(lines.begin()+(i-1));
        }else if(e2.second == e1.second and e2.second==e3.second){
            lines.erase(lines.begin()+(i-1));
        }

        if(i>=lines.size()) break;
    }


}
int face = 0;
for(int i = 0; i<lines.size(); i+=2){
    pair<int, int> e1 = lines[i];
    pair<int, int> e2 = lines[i+1];
    face+=dist(0, e1.second, e1.first, e1.second)*dist(e1.first, e1.second, e2.first, e2.second);
}

cout<<w*h-face<<endl;

return 0;
}
