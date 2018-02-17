#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
int n,k;
int dinamichno[2][1010];
void solve(){
    dinamichno[0][0]=1;
    int i,j;
    int da;
    for(i=0;i<s.size();i++){
        da=i%2;
        memset(dinamichno[da],0,sizeof(dinamichno[da]));
        for(j=0;j<n;j++){
            dinamichno[da][(j*10+s[i])%n]=(dinamichno[da][(j*10+s[i])%n]+dinamichno[da^1][j])%k;
            dinamichno[da][j]=(dinamichno[da][j]+dinamichno[da^1][j])%k;
        }
    }
    long long ans;
    if(dinamichno[da][0]<=0)ans=k;
    else ans=dinamichno[da][0];
    ans-=2;
    cout<<ans<<endl;
}
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++)s[i]-=48;
    cin>>n>>k;
    solve();
return 0;
}