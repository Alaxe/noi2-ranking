#include<iostream>
using namespace std;

int main (){
    long long m,n,p,q,teglo,t,br=0,i,maxs=0,maxc=0,brTekushtiS;
    cin>>m>>n>>p>>q;
    teglo=n-m;
    t=teglo;
    br=br+2;
    maxs=t/p;
    if(maxs*p<t){
        maxs++;
    }
    maxc=t/(p-q);
    if(maxc*(p-q)+p<t){
        maxc++;
    }

cout<<maxs<<" "<<maxc<<" ";
    for(i=1; i<maxc; i++){
            t=t+i*q;
        brTekushtiS=t/p;
        if(brTekushtiS*p<t){
            brTekushtiS++;
        }
        br=br+(i+brTekushtiS-2-maxs)*2;
        t=t-i*q;

    }
cout<<br;
return 0;
}
