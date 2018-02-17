#include <iostream>
#include <map>
#include <utility>
using namespace std;
#define MAXN 1024

map<pair<double, double>, int> m;
int x[MAXN]={}, y[MAXN]={}, v[MAXN]={};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;
    cin>>n;
    int maxn=-1;

    for(i=0; i<n; i++){
        cin>>x[i]>>y[i];
        if(i!=0){
            for(map<pair<double, double>, int>::iterator it=m.begin(); it!=m.end(); it++){
                if(x[i]*(it->first).first+(it->first).second == y[i]){
                    (it->second)++;
                }

                if((it->second)>maxn)
                maxn=(it->second);
            }

            for(j=0;j<i;j++){


                if(x[i]-x[j]!=0){
                    double a = (double) (y[i]-y[j])/(x[i]-x[j]);

                    double b = y[i] -x[i]*a;

                    if(m.count(make_pair(a, b))==0) m[make_pair(a, b)]=2;
                }
                else{
                    if(v[x[i]]==0) v[x[i]]=2;
                    else v[x[i]]++;

                    if(v[x[i]]>maxn) maxn=v[x[i]];
                }
            }
        }
    }

    cout<<maxn<<"\n";
    return 0;
}
