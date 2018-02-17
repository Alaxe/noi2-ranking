#include<iostream>
using namespace std;
int main()
{
    long long E,K,sbor=0,nomer=0,chislo[200],broich=0,broi=0,counter=0,pg=0,pm=0,nomer2;
    cin>>E>>K;
    while(sbor<K)
    {
        cin>>chislo[counter];
        if(chislo[counter]%2==0)
        {
            broich++;
            sbor=sbor+chislo[counter];
        }
        broi++;
        counter++;
    }
    long long nb=E-chislo[0];
    for( counter=0; counter<broi; counter++)
    {
        if(E-chislo[counter]<nb or chislo[counter]-E<nb)
        {
         nomer2=counter;
        }
        counter++;
    }
    if(nomer2==0){
        nomer2=1;   }
    cout<<nomer2<<" "<<sbor;
    return 0;
}
