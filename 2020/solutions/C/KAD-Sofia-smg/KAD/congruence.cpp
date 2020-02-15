#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=15e6+3;
char res[2][MAXN];
vector<int> pos[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i){
        int curr=s[i]-'A';
        pos[curr].push_back(i);
    }
    int counter=0;
    for(int i=0;i<26;++i){
        if(!pos[i].empty()){
            for(int curr_pos : pos[i]){
                res[0][curr_pos]='A'+counter;
            }
            ++counter;
        }
    }
    counter=0;
    for(int i=25;i>=0;--i){
        if(!pos[i].empty()){
            for(int curr_pos : pos[i]){
                res[1][curr_pos]='Z'-counter;
            }
            ++counter;
        }
    }
    cout<<res[0]<<endl<<res[1]<<endl;
return 0;
}
