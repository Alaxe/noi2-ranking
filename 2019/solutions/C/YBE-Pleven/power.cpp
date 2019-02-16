#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int pr[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
int a[44];


int c[44];

int Razlagane(int a1){
int j,l,y;
    for(j=1;j<=44;j++)c[j]=0;
    for(j=0;j<14;j++){
        if(a1%pr[j] == 0){
            a1 = a1/pr[j];
            c[pr[j]]++;
            j--;
        }
    }


}



int main()
{
int i,j,l,pos=1,y,br=0,a1;
    cin>>n>>k;
    for(j=1;j<=n;j++){
        cin>>a1;
        Razlagane(a1);
        for(i=0;i<14;i++){
            if(c[pr[i]] >= 1){
                if(a[pr[i]] < c[pr[i]])a[pr[i]] = c[pr[i]];
            }
        }

    }
    int sum=1;
     for(i=0;i<14;i++){
        if(a[pr[i]] >= 1){
            sum=sum*pr[i];
            if(a[pr[i]] > k){
                int t = a[pr[i]] - k;
                for(j=1;j<=t;j++){
                    sum = sum*pr[i];
                }
            }
        }
    }
    cout<<sum<<endl;


    return 0;
}
