#include<iostream>
using namespace std;

 unsigned long long refTable[128][128];
 void fillTable()
 {
     int i,y;

     for(i=0; i<128; i++)
     {
         refTable[i][i]=1;
         refTable[0][i]=1;
     }

     for(i=1; i<128; i++)
     {
         for(y=i+1; y<128; y++)
         {
             refTable[i][y] = refTable[i][y-1] + refTable[i-1][y-1];
         }
     }

     return;
 }

int main()
{
    unsigned long long s, t, ansS, ansT;
    int z, zj;

    fillTable(); ///ZA K I Z VRASHTASH [Z+1][K]  !!!!!!

    cin>>s>>t>>z;
    s--;

    long long p;
    bool hasBegun=false;
    ansS=0; zj=z;
    for(p = 63; p>=0; p--)
    {
        if(!(s&((unsigned long long)(1)<<p)))
        {
            if(!hasBegun) continue;
            zj--;
            if(zj<0) break;
            continue;
        }
        if(!hasBegun)
        {
            ansS+=refTable[zj+1][p];
        }
        else
        {
            for(int l=1; (zj>=l) && (p+1>=l); l++)
            {
                ansS+=refTable[zj-l][p+1-l];
                if(zj==p) ansS++;
            }
        }
        hasBegun=true;
    }

    hasBegun=false;
    ansT=0; zj=z;
    for(p = 63; p>=0; p--)
    {
        if(!(t&((unsigned long long)(1)<<p)))
        {
            if(!hasBegun) continue;
            zj--;
            if(zj<0) break;
            continue;
        }
        if(!hasBegun)
        {
            ansT+=refTable[zj+1][p];
        }
        else
        {
            for(int l=1; (zj>=l) && (p+1>=l); l++)
            {
                ansT+=refTable[zj-l][p+1-l];
                if(zj==p) ansT++;
            }
        }
        hasBegun=true;
    }

    cout<<ansT-ansS<<endl;

    return 0;
}
