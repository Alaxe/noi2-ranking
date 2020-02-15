#include<iostream>
using namespace std;
int main()
{int m,br=0,e,d,s,h,dh;
cin>>m;
e=m%10;
d=m/10%10;
s=m/100%10;
h=m/1000%10;
dh=m/10000%10;
for(int i=1;i==m;i++)
{
if(e!=0 && d==0 && s==0 && h==0 && dh==0) br++;
else
    {
         if(e!=0 && d!=0 && s==0 && h==0 && dh==0  && e==d) br++;
    else
        {
            if(e!=0 && d!=0 && s!=0 && h==0 && dh==0 &&  e==d && d==s) br++;
       else
           {
                if(e!=0 && d!=0 && s!=0 && h!=0 && dh==0 &&  e==d && d==s && s==h) br++;
           else
               {
                    if(e!=0 && d!=0 && s!=0 && h!=0 && dh!=0 &&  e==d && d==s && s==h && h==dh) br++;
               }

           }

        }

    }

}
cout<<br<<endl;
return 0;
}
