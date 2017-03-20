#include<iostream>
#include<string.h>
using namespace std;
string a;
int stepen=0;
bool isd(long long a)
{
    long long br=1,tmp=2;
    for(;;)
    {
        if(tmp==a) return true;
        if(tmp>a) return false;
        tmp*=2;
        br++;
    }

}

bool next(long long br)
{
    long long tmp=0,br1=0,rez=0;
    for(long long i=(a.size()-1)-br; i>=0; i--)
    {
        tmp=a[i]-'0';
        if(br1!=0){for(int z=1; z<=br; z++){tmp*=10;}}
           rez+=tmp;
           if(isd(rez)) return true;
           br1++;
    }
    return false;
}
int main()
{
    cin>>a;
    long long tmp=0,br=0,rez=0;
    for(long long i=a.size()-1; i>=0; i--)
    {
        tmp=a[i]-'0';
        if(br!=0){ for(int z=1; z<=br; z++){tmp*=10;}}
        rez+=tmp;
        if(isd(rez) && next(br)){break;}
        br++;

    }
    int brs=1;
    for(int i=1;;i*=2)
    {
        if(i==rez){break;}
            brs++;
    }

    cout<<brs<<endl;

    return 0;
}
