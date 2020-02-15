#include<bits/stdc++.h>
using namespace std;
vector <int> a;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,z=n;
        cin>>x;
        bool f=1;
        if(x==0){
            f=0;
            while(f==0){
                f=1;
                for(int j=0;j<a.size();j++){
                    if(a[j]==z){
                        f=0;
                        z--;
                    }
                }
            }
        }
        else{
            while(x>0){
                z--;
                f=1;
                for(int j=0;j<a.size();j++)if(a[j]==z)f=0;
                if(f)x--;
            }
        }
        a.push_back(z);
        if(i>0)cout<<" ";
        cout<<z;
    }
    cout<<endl;
}
