//
// Given an array of integers
// Find the length of the longest increasing, decreasing or increasing-decreasing subsequence
// n<100000, a[i]<100000
//

#include<iostream>
using namespace std;

const int maxi=100001;
int n, input[maxi], max_ans=0;

int maxup(int in[], int c)
{
    int max_up=0;
    int matrix[c+1];
    matrix[0]=1;
    for(int i=1; i<c; i++)
    {
        int biggest=0;
        for(int j=i-1; j>=0; j--)
        {
            if(in[i]>in[j]&&matrix[j]>biggest)
            {
                biggest=matrix[j];
            }
        }
        matrix[i]=biggest+1;
        if(matrix[i]>max_up)
        {
            max_up=matrix[i];
        }
    }
    return max_up;
}

int maxdown(int in[], int c)
{
    int max_down=0;
    int matrix[c+1];
    matrix[0]=1;
    for(int i=1; i<c; i++)
    {
        int biggest=0;
        for(int j=i-1; j>=0; j--)
        {
            if(in[i]<in[j]&&matrix[j]>biggest)
            {
                biggest=matrix[j];
            }
        }
        matrix[i]=biggest+1;
        if(matrix[i]>max_down)
        {
            max_down=matrix[i];
        }
    }
    return max_down;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    for(int i=-1; i<n; i++)
    {
        int arr1[i+1], arr2[n-i-1], counter=0;
        for(int j=0; j<i+1; j++)
        {
            arr1[j]=input[j];
        }
        for(int j=i+1; j<n; j++)
        {
            arr2[counter]=input[j];
            counter++;
        }
        int a=maxup(arr1, i+1)+maxdown(arr2, n-i-1);
        if(max_ans<a)
        {
            max_ans=a;
        }
    }
    cout<<max_ans<<endl;
    return 0;
}
