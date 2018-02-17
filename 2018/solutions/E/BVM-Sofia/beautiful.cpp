#include<iostream>
using namespace std;
int main()
{
    long long dulzhina,del,chislo=1;
    cin>>dulzhina>>del;
    for(int i = 1 ; i < dulzhina ; i++)chislo*=10;
    if(chislo % del != 0){
    chislo += del - chislo%del;
    }
    cout<<chislo<<"\n";
    return 0;
}
