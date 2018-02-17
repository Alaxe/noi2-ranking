#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Card{
    int points;
    char boja;
    string val;
    void prepare(){
        if(val[0]>='2' && val[0]<='9') points = val[0]-'0';
        else{
                switch(val[0]){
                    case 'T': points = 10; break;
                    case 'J': points = 11; break;
                    case 'Q': points = 12; break;
                    case 'K': points = 13; break;
                    case 'A': points = 1; break;
                }
        }
    }
};
struct Coord{
    int x, y;

};
struct Three{
    Coord c;
    int points;
    Three(int p, int x, int y){
        c.x = x;
        c.y = y;
        points = p;
    }
};
int n;
bool exist(int x, int y){
    return x<n && y<n && x>=0 && y>=0;
}
int main(){
    cin>>n;
    Card table[n][n];
    for(int i=0; i<n; i++){
            for(int z=0; z<n; z++){
                    cin>>table[i][z].val;
                    table[i][z].prepare();

            }
    }
    vector<Three> v;
    v.push_back(Three(table[n-1][0].points, n-1, 0));
    for(int i=0; i < (2*n)-2; i++){
            vector<Three> nov;
            for(int z=0; z<v.size(); z++){
                    int x = v[z].c.x;
                    int y = v[z].c.y;
                    int zasega = v[z].points;
                    //cout<<zasega<<" "<<x<<" "<<y<<endl;
                    ///
                    x--;
                    if(exist(x, y)){
                            //cout<<"TUKQ"<<endl;
                            nov.push_back(Three(zasega + table[x][y].points, x, y));
                    }
                    x++;
                    ///

                    ///

                    ///

                    ///
                    y++;
                    if(exist(x, y)){
                            //cout<<"TUKr"<<endl;
                            nov.push_back(Three(zasega + table[x][y].points, x, y));
                    }
                    y--;

            }
            v=nov;
    }
    int maxpoints = 0;
    for(int i=0; i<v.size(); i++){
            if(v[i].points > maxpoints) maxpoints = v[i].points;
    }
    cout<<maxpoints<<endl;
    return 0;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/


