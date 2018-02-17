#include<iostream>
#include<vector>
#include<math.h>
#include<utility>

using namespace std;

int w, h;

vector<pair<pair<int, int>, pair<int, int> > > points;
vector<pair<pair<int, int>, pair<int, int> > > whoContain;
int extFace = 0;
int extFaceB = 0;
int n;

bool contains(int xr, int yr, int wr, int hr, int x, int y){
    return (x>=xr and y>=yr and x<= xr + wr and y <= yr + hr);
}

void externalize(int depth){
    extFaceB = 0;
    for(int i = 0; i<n; i++){
        pair<pair<int, int>, pair<int, int> > obj = whoContain[i];
        pair<int, int> pos = obj.first;
        int x = pos.first;
        int y = pos.second;
        pair<int, int> siz = obj.second;
        int w = siz.first;
        int h = siz.second;

        int cont = 0;
        for(int ii = 0; ii<n; ii++){
            pair<pair<int, int>, pair<int, int> > obj2 = whoContain[ii];
            pair<int, int> pos = obj2.first;
            pair<int, int> siz = obj2.second;
            int xr = pos.first;
            int yr = pos.second;
            int wr = siz.first;
            int hr = siz.second;
            if( contains(xr, yr, wr, hr, x, y) ){
                cont++;
            }
        }
        if(cont>depth){
            extFaceB += w*h;
        }
    }
}

void externify(){
    for(int i = 0; i<n; i++){
        pair<pair<int, int>, pair<int, int> > obj = points[i];
        pair<int, int> pos = obj.first;
        int x = pos.first;
        int y = pos.second;
        pair<int, int> siz = obj.second;
        int w = siz.first;
        int h = siz.second;

        int cont = 0;
        for(int ii = 0; ii<n; ii++){
            pair<pair<int, int>, pair<int, int> > obj2 = points[ii];
            pair<int, int> pos = obj2.first;
            pair<int, int> siz = obj2.second;
            int xr = pos.first;
            int yr = pos.second;
            int wr = siz.first;
            int hr = siz.second;
            if( contains(xr, yr, wr, hr, x, y) ){
                cont++;
            }
        }
        if(cont==1){
            extFace += w*h;
        }
    }
}

int getFace(int x, int y){
    whoContain.clear();

    for(int i = 0; i<n; i++){
        pair<pair<int, int>, pair<int, int> > obj = points[i];
        pair<int, int> pos = obj.first;
        pair<int, int> siz = obj.second;
        int xr = pos.first;
        int yr = pos.second;
        int wr = siz.first;
        int hr = siz.second;
        if(contains(xr, yr, wr, hr, x, y)){
            whoContain.push_back(obj);
        }
    }

    if(whoContain.size() == 0){
        return w*h - extFace;
    }

    pair<pair<int, int>, pair<int, int> > parent = whoContain[0];
    int depth = 1;
    for(int i = 1; i<whoContain.size(); i++){

        pair<int, int> pos = parent.first;
        pair<int, int> siz = parent.second;
        int xr = pos.first;
        int yr = pos.second;
        int wr = siz.first;
        int hr = siz.second;

        pair<pair<int, int>, pair<int, int> > obj = whoContain[i];
        pos = obj.first;
        int xx = pos.first;
        int yy = pos.second;

        if(contains(xr, yr, wr, hr, xx, yy)){
            parent = obj;
            depth++;
        }
    }

    externalize(depth);
    int wr = parent.second.first;
    int hr = parent.second.second;

    return wr*hr - extFaceB;

}

int main(){


    cin>>w>>h;



    cin>>n;


    int x, y, ww, hh;
    for(int i = 0; i<n; i++){
        cin>>x>>y>>ww>>hh;
        pair<int, int> coords(x, y);
        pair<int, int> sizes(ww, hh);
        pair<pair<int, int>, pair<int, int> > toAdd(coords, sizes);
        points.push_back(toAdd);
    }

    externify();

    int p;
    cin>>p;

    vector<pair<int, int> > checks;
    for(int i = 0; i<p; i++){
        cin>>x>>y;
        checks.push_back(pair<int, int>(x, y));
    }

   for(int i = 0; i<p; i++){

        cout<<getFace(checks[i].first, checks[i].second)<<endl;
    }


    return 0;
}
