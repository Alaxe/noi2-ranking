#include <iostream>
#include <vector>
using namespace std;

class rect{
    public:
    int x1,x2,y1,y2,w,h, S, level=1;
    vector <rect> inner;


    rect(int x, int y, int w1, int h1){
        x1 = x;
        x2 = x+w1;
        y1 = y;
        y2 = y+h1;
        h = h1;
        w = w1;
        S = (w)*(h);

    }
    rect(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        h = 0;
        w = 0;
        S = 0;
    }

    bool in(int pX, int pY){

        if(pX<x2 && pX>x1 && pY<y2 && pY>y1){
            return 1;
        }
        return 0;
    }

    void add(rect r){
        //cout<<"adding r "<<r.level<<endl;
        //r.level++;
        //cout<<r.level<<endl;
        inner.push_back(r);
    }

    int localize(int px, int py){
        //cout<<"localizing "<<S<<" elements: "<<inner.size()<<" ";
        bool inners = false;
        for(int i=0; i<inner.size(); i++){
            //cout<<" searching i "<<i<<" ";
            if(inner[i].in(px,py)){
                //cout<<"found "<<i<<endl;
                //cout<<"found in "<<i<<" "<<inner[i].S<<endl;
                inners = 1;
                return inner[i].localize(px,py);
            }
        }
        if(!inners){
            //cout<<"return S "<<endl;
            return getS();
        }

    }

    int getS(){
        int s = S;
        //cout<<"elements in "<<S<<" "<<inner.size()<<endl;
        for(int i=0; i<inner.size(); i++){
            if(inner[i].level == level+1){
                //cout<<"S- "<<inner[i].S<<" with level "<<inner[i].level<<" ; my level: "<<level<<endl;
                s-= inner[i].S;
            }
        }
        return s;
    }





};



rect data[11000];



    void test(rect r){
        cout<<"TEST----------"<<endl;
        cout<<r.inner.size()<<endl;
        test(r.inner[0]);
        cout<<"------------------"<<endl;
    }
int main(){
    int wF, hF;
    cin>>wF>> hF;

    int n;
    cin>>n;
    const int m = n+1;

    data[0] = rect(0,0, wF, hF);
    data[0].level = 1;

    for(int i=1; i<m; i++){
        int x,y,w,h;
        cin>>x>>y>>w>>h;
        data[i] = rect(x,y,w,h);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            int x1 = data[j].x1;
            int y1 = data[j].y1;
            int xB1 = data[i].x1;
            int xB2 = data[i].x2;
            int yB1 = data[i].y1;
            int yB2 = data[i].y2;

            if(x1<xB2 && x1>xB1 && y1 < yB2 && y1 > yB1){
                    data[j].level++;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            int x1 = data[j].x1;
            int y1 = data[j].y1;
            int xB1 = data[i].x1;
            int xB2 = data[i].x2;
            int yB1 = data[i].y1;
            int yB2 = data[i].y2;

            if(x1<xB2 && x1>xB1 && y1 < yB2 && y1 > yB1){
                    data[i].add(data[j]);
                    //cout<<"ADD "<<data[j].S<<" IN "<<data[i].S<<endl;
            }
        }
    }

    /*for(int i=0; i<m; i++){
        rect r = data[i];
        //cout<<"CURR RECT "<< r.S<<" level  "<<r.level<<endl;
        for(int j=0; j<r.inner.size(); j++){
            //cout<<r.inner[j].S<<endl;
        }
        cout<<endl;
    }*/

    //test(data[1]);

    int t;
    /*for(int i=0; i<m; i++){
        //cout<<"i: "<<i<<" "<<data[i].S<<" "<<data[i].inner.size()<<endl;
    }
    cout<<"------"<<endl;
    cout<<data[0].inner[0].S<<endl;
    cout<<data[1].inner.size()<<endl;


    /*cout<<"LICE "<<data[0].getS()<<endl;

    /*for(int i=0; i<m; i++){
        cout<<data[i].S<<endl;
    }*/
    cin>>t;

    for(int i=0; i<t; i++){
        int x,y;
        cin>>x>>y;
        cout<<data[0].localize(x,y)<<endl;
    }
    return 0;

}
