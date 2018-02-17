#include<iostream>
using namespace std;
int main()
{
int a,i,j,ost=0,br=0,n,r,mas[1000],y,ch;
cin>>a;
for(i=1;i<=a;i++)
{
    for(j=1;j<=n;j++)
    {
        r=i*j;
        while(ost!=0)
        {
            ost=r%10;br++;
            r=r/r;
            mas[y]=ost;y++;
            ost=0;
        }
        for(y=0;y<br;y++)
        {
            ch=ch*10+mas[y];
        }
        if(ch==r){
            if(i>j) cout<<j<<" "<<i<<" "<<ch<<endl;
            else cout<<j<<" "<<j<<" "<<ch<<endl;
        }
    }
}
return 0;
}
