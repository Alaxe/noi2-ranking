#include<iostream>
using namespace std;
int n;
int a[100000];

int Rastqshta()
{
    int br=0;
    int x=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=x)br++;
        else x=a[i];
    }

//cout<<"Raste "<<br<<endl;
    return n-br;

}


int Namalqshta()
{
    int br=0;
    int x=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=x)br++;
        else x=a[i];
    }
   // cout<<"Namalq "<<br<<endl;
    return n-br;

}

int Smesena()
{

    int br=0;
    int minbr=n;

    for(int k=0;k<n-1;k++)
    for(int i=k+1;i<n;i++)
    {
       if(a[i]>a[k]){

        br=i-k-1;
        br+=k;
        int x=a[i];
        for(int j=i+1;j<n;j++)
        {

            if(a[j]>=x)br++;
            else x=a[j];
        }
      //  cout<<a[i]<<" "<<br<<endl;
        if(br<minbr)minbr=br;
        br=0;
       }
       else br++;
    }




   // cout<<"Smesva "<<minbr<<endl;
    return n-minbr;
}



int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

     cout<<max(max(Rastqshta(),Namalqshta()),Smesena())<<endl;
     return 0;
}
