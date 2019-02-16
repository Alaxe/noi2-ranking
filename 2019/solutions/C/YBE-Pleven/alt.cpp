#include <iostream>
using namespace std;

int n,m,k,otg;

int alt(int nach){
    int i,pos=0,br=0;
    int t = nach;
    i=2;
    while(1){
        if(i == n+1)break;
        if(t+k < m && t-k > 0){
           pos++;
           t=t+k;
        }
        else
        if(t+k < m){
            t=t+k;
        }
        else
        if(t-k > 0){
            t=t-k;
        }
        else
            break;

        i++;
    }
    br=1;
    for(i=1;i<=pos;i++){
        br = br*2;
    }
    return br;


}


int main()
{
int i,j;
    cin>>k>>m>>n;
    for(i=1;i<m;i++){
        otg+=alt(i);
        //cout<<otg<<endl;
    }
    cout<<otg<<endl;



    return 0;
}
