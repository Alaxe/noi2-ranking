#include<iostream>
using namespace std;
int a[100];
int main()
{
    long long n,u,v,i,j=0,k,s=0,l,br=0,g;
    cin>>n>>u>>v;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    l=n;
    for(i=0;i<n;i++)
    {   
        if(a[j]>a[j+1])
        {j++;g=j;l=l-1;
            do
            {
                if(a[j]<a[j+1]){br++;k=j;j++;}
            }while(l!=0); 
            l=l-br;
            if(a[k]>a[g]) 
            {
                s=s+a[g]*u*(br+u);
            } 
            else {s=s+a[k]*u*(br+u);}
            br=0;
        }
        else 
        {
            s=s+a[j]*u;
            l=l-1;
        }
    }
    cout<<s<<endl;
    return 0;
}