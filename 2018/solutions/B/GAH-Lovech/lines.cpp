#include <iostream>

using namespace std;

int ix[1001],iy[1001];
int main()
{int i,n,max=0,j,g,br=0;
cin>>n;
for(i=0;i<n;i++)
cin>>ix[i]>>iy[i];

for (g=0;g<n;g++)//x1,y1
   {
    for (j=0;j<n;j++)//x2,y2
{
         for (i=0;i<n;i++) // x,y
        {if (i!=j && i!=g && j!=g)
            {if ((ix[i]-ix[g])*(iy[j]-iy[g]) == (ix[j]-ix[g])*(iy[i]-iy[g]) )
          br++;
            }
       if (br>max)
       max=br;

       }
br=0;
   }
   }
cout<<max+2;
    return 0;
}
