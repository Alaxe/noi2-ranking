#include<bits/stdc++.h>
using namespace std;
int main()
{
    char date[10],pd,pm,py;
    long long d,m,y,lv,br=0;
    cin>>date>>lv;
    for(int i=0;i<9;i++)
    {
        if(date[i]=='/')br++;
        else
        {
            if(br==0)pd=pd+date[i];
            else
                if(br==1)pm=pm+date[i];
                else
                    if(br==2)py=py+date[i];
        }
    }
    cout<<pd<<" "<<pm<<" "<<py<<endl;
    return 0;
}
