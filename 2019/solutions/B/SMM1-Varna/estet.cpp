#include<bits/stdc++.h>
using namespace std;
int listm(int arr[], int n, int* max_ref)
{
    if(n==1)
        return 1;
    int res;
   int max_ending_here=-1;
    for(int i=1; i<n; i++)
    {
        res=listm(arr,i,max_ref);
        //max_ending_here=res;

        if(arr[i-1]<arr[n-1]&&res+1>max_ending_here)
        {
            max_ending_here=res+1;
        }
    }


    if(*max_ref<max_ending_here)
    {
        *max_ref=max_ending_here;
        return max_ending_here;
    }

}


int listmt(int arr[], int n, int* max_ref)
{
    if(n==1)
        return 1;
    int res;
   int max_ending_here;
    for(int i=1; i<n; i++)
    {
        res=listmt(arr,i,max_ref);


        if(arr[i-1]>arr[n-1]&&res+1>max_ending_here)
        {
            max_ending_here=res+1;
        }
    }


    if(*max_ref<max_ending_here)
    {
        *max_ref=max_ending_here;
        return max_ending_here;
    }
    //cout<<max_ending_here<<endl;

}

int lismt(int arr[],int n)
{
    int max=1;
    listmt(arr,n,&max);
    return max;
}
int lism(int arr[],int n)
{   int max=1;
    listm(arr,n,&max);
    return max;
}
int main()
{ int arr[100000];
   int n;
   cin>>n;
   for(int i=0;i<n-1;i++)
   {
       cin>>arr[i];
   }
   cout<<max(lism(arr,n),lismt(arr,n))<<endl;
   return 0;
}
