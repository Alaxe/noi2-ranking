#include<bits/stdc++.h>
using namespace std;
string a;
char heh='A';
pair<int,int> b[15000000];
int dylj;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a;
    dylj=a.size();
    for(int i=0;i<dylj;i++){
        b[i].first=a[i]-'A';
        b[i].second=i;
    }
    sort(b,b+dylj);
    a[b[0].second]=heh;
    for(int i=1;i<dylj;i++){
        if(b[i].first>b[i-1].first){
            heh++;
        }
        a[b[i].second]=heh;
    }
    cout<<a<<"\n";
    heh='Z';
    a[b[dylj-1].second]=heh;
    for(int i=dylj-2;i>=0;i--){
        if(b[i].first<b[i+1].first){
            heh--;
        }
        a[b[i].second]=heh;
    }
    cout<<a<<"\n";
    return 0;
}

