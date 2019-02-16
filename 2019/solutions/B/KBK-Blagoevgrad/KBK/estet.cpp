#include <iostream>
using namespace std;int a[100000];int n;int br1v=0,br2v=0,br3v=0;
void vavejdane()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
}
void rastqshta()
{
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {   int k=i+1;int br=1;
            while(a[k]<a[k+1]){br++;k++;}
            if(br>1){br1v=br1v+br; i=i+br-1;}


        }
        else if(a[i]==a[i+1]){i++;br1v+=2;while(a[i]==a[i+1])i++;}

              else br1v++;
    }
}
int main()
{
vavejdane();
rastqshta();
cout<<br1v-1;


return 0;
}
