#include<string>
#include<iostream>
using namespace std;
string s;
long long byNow[1010], crnt[1010];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>s;
    long long n, m;
    cin>>n>>m;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            crnt[j]=0;
        }
        for(int j=0;j<n;j++){
            crnt[(j*10+s[i]-'0')%n]+=byNow[j];
        }
        crnt[(s[i]-'0')%n]++;
        for(int j=0;j<n;j++) byNow[j]+=crnt[j];
//        cout<<byNow[0]<<"\n";
    }
    cout<<byNow[0]%m<<"\n";
    return 0;
}
