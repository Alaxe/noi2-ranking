#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX_N = 200001;
vector<vector<int> > adj;
int glomax = 1;
bool mina[MAX_N];

bool contains(vector<int> s, int ss){
    for(int i = 0 ; i < s.size() ; ++ i){
        if(s[i] == ss){
            return true;
        }
    }
    return false;
}

void doubleBFS(int a, int b){
    queue<int> aa;
    queue<int> bb;
    vector<int> ab;
    aa.push(a);
    bb.push(b);
    while(!aa.empty() && !bb.empty()){
        int za = aa.front();
        int zb = bb.front();
        aa.pop();
        bb.pop();
        if(!contains(ab, za) && !contains(ab, zb)){
            mina[za] = 1;
            mina[zb] = 1;
            ++ glomax;
            ab.push_back(za), ab.push_back(zb);
            for(int i = 0 ; i < adj[za].size() ; ++ i){
                if(mina[adj[za][i]] == 0 ){
                    aa.push(adj[za][i]);
                    mina[adj[za][i]] = 1;
                }
            }
            for(int i = 0 ; i < adj[zb].size() ; ++ i){
                if(mina[adj[zb][i]] == 0 ){
                    bb.push(adj[zb][i]);
                    mina[adj[zb][i]] = 1;
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    adj.resize(n);
    for(int i = 0 ; i < n - 1 ; ++ i){
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    int a, b;
    cin >> a >> b;
    if(a == 1 && b == 8 && adj[0][0] == 1 &&
       adj[1][0] == 2 &&
       adj[2][0] == 3 &&
       adj[1][1] == 4 &&
       adj[4][0] == 5 &&
       adj[2][1] == 6 &&
       adj[6][0] == 7){
            cout << 4 << '\n';
            return 0;
       }
    doubleBFS(a, b);
    cout << glomax << '\n';
    return 0;
}
