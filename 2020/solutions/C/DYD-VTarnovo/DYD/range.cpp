#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
int main(){
    int n;
    cin>>n;
    int m;
    int vhod[n+100];
    int maxChislo = -1;
    int a, b;

    for(int i = 0;i < n;++i){
        cin>>vhod[i];
        if(vhod[i] > maxChislo){
            maxChislo = vhod[i];
        }
    }
    cin>>m;
    int index = 0;
    for(int i = 0;i < m;++i){
        cin>>a>>b;
        if(a > maxChislo) {
            ans.push_back(0);
            continue;
        }
        ans.push_back(0);
        for(int i = 0;i < n;++i){
            if(vhod[i] >= a && vhod[i] <= b){
                ans[index]++;
            }
        }
        index++;
    }
    for(int i = 0;i < m;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}
