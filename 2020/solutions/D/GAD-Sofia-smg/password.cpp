#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void promqna(char x[5001]);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[5001];
    cin>>a;
    promqna(a);
    return 0;
}

void promqna(char x[5001]){
    long b;
    char c='a';
    for (long i=0;i<strlen(x);i++){
        b=1;
        if (i!=strlen(x)-1){
            for (long j=i+1;j<strlen(x);j++){
                if (x[i]==x[j]){
                    b++;
                    if (b>strlen(x)/2){
                        x[j]=c;
                        c+=1;
                    }
                }
            }
        }
    }
    bool daliEPodred=false;
    for (long i=0;i<strlen(x);i++){
        b=1;
        if (i!=strlen(x)-1){
            for (long j=i+1;j<strlen(x);j++){
                if (x[i]==x[j]){
                    daliEPodred=true;
                    b++;
                    if (b==3 && daliEPodred){
                        if (x[j]!=c){
                            x[j]=c;
                            c+=1;
                            daliEPodred=false;
                        }else{
                            c+=1;
                            x[j]=c;
                            daliEPodred=false;
                        }
                    }
                }else{
                    daliEPodred=false;
                }
            }
        }
    }
    cout<<x<<endl;
}
