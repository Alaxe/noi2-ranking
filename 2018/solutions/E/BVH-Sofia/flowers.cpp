#include<iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              z
using namespace std;
int main()
{
    int n,N,q,br=0,a,b,c;
    cin>>n;
    cin>>q;
    cin>>N;
    while(br>0){
        a=q;
        cin>>q;
        b=q;
        if(b>a){
            c=b-a;
        }
        else{
            c=a-b;
        }
        br=br+c;
        }

    cout<<br*N;
    return 0;
}
