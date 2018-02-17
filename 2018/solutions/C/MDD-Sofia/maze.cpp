#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn =101;
const int maxm = 101;
bool notpassed[maxn][maxm];
pair<int, int> b;
pair<int, int> e;
vector< pair<int, int> > frontier;
int fronEnd=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            notpassed[i][j]=true;
        }
    }
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            if(s[j]=='#'){
                notpassed[i][j] =false;
            }
            if(s[j]=='B'){
                b = make_pair(i, j);
            }
            if(s[j]=='E'){
                e = make_pair(i, j);
            }
        }
    }
    frontier.push_back(b);
    int countt = 0;
    pair<int, int> last = b;
    bool sega=false;
    while(fronEnd<frontier.size()){
        pair<int, int> curr = frontier[fronEnd];
        if(curr.first==last.first && curr.second==last.second){
            countt++;
            bool sega=true;
        }
        int currX= curr.first;
        int currY= curr.second;
        notpassed[currX][currY]=false;
        fronEnd++;
        if(curr.first==e.first && curr.second==e.second){
            break;
        }
        if(notpassed[currX+1][currY]){
            frontier.push_back(make_pair(currX+1, currY));
            if(sega){
                last=make_pair(currX+1, currY);
            }
        }
        if(notpassed[currX-1][currY]){
            frontier.push_back(make_pair(currX-1, currY));
            if(sega){
                last=make_pair(currX-1, currY);
            }
        }
        if(notpassed[currX][currY+1]){
            frontier.push_back(make_pair(currX, currY+1));
            if(sega){
                last=make_pair(currX, currY+1);
            }
        }
        if(notpassed[currX][currY-1]){
            frontier.push_back(make_pair(currX, currY-1));
            if(sega){
                last=make_pair(currX, currY-1);
            }
        }
        if(sega) sega=false;
    }
    cout << countt << endl;

    return 0;
}
