#include<iostream>
using namespace std;
int main()
{
    int den,mesec,godina,grip,sed,br=1;
    char a;
    cin>>den>>a>>mesec>>a>>godina>>grip;
    sed=(den-1)%7;
    grip++;
    while(grip!=0)
    {
        if(sed!=6)
        {
            br++;
            sed++;
            grip--;
        }
        else
        {
            br=br+2;
            sed=1;
        }
    }
    br=br+den;
    if(br>365)
    {
        godina=2020;
        br=br-365;
    }
    mesec=br/31+1;
    den=br%31;
    if(den<10)
    {
        cout<<"0"<<den<<".";

    }
    else
    {
        cout<<den<<".";
    }
    if(mesec<10)
    {
        cout<<"0"<<mesec<".";

    }
    else
    {
        cout<<mesec<<".";
    }
    cout<<"."<<godina<<endl;
    return 0;
}
