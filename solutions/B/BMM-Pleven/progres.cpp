#include<iostream>
#include<algorithm>
using namespace std;
int n,br=0;
int a[1024];



int main()
{
    cin>>n;
    for(int i=1; i<=n;i++)
    {
        a[i]=0;

    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
   for(int i=1; i<n; i++)
   {
      for(int j=i+1; j<=n; j++)
      {
          if(a[i]<a[j])
          {
              int b= a[j]-a[i];
              for(int g=i; g<=n; g++)
              {
                  if(a[g]-a[i]==b)
                  {
                      if(a[g]==a[i]+2*b)
                      {
                          br+=2;
                      }
                      else
                      {
                        br++;
                      }



                  }
              }
          }
      }
   }

cout<<br<<endl;


    return 0;
}
