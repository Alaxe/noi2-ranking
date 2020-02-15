#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
int a[100005];

int binarySearch(int x)
{
    int first = 0,last = n - 1,mid = (n - 1) / 2;
    
    while(last - first > 5)
    {
        if(a[first] == x)
        {
            return first;
        }
        if(a[last] == x)
        {
            return last;
        }
        
        if(a[mid] == x)
        {
            return mid;
        }
        
        if(a[mid] < x)
        {
            first = mid;
        }
        else if(a[mid] > x)
        {
            last = mid;
        }
        
        mid = first + last;
        mid /= 2;
        
        if(first >= last)
        {
            break;
        }
    }
    
///cout<<first<<" a "<<last<<" "<<x<<endl; 
    
    for(int i = first;i <= min(last,n);i++)
    {
        if(a[i] > x)
        {
            return i - 1;
        }
        if(i == n - 1)
        {
            return i;
        }
    }
}

int solve(int f, int l)
{
    int x = binarySearch(f);
    int y = binarySearch(l);
    
    if(a[x] != f)
    {
        x++;
    }
    
    while(x > 1)
    {
        if(a[x - 1] == a[x])
        {
            x--;
        }
        else
        {
            break;
        }
    }
    
    while(y < n - 1)
    {
        if(a[y + 1] == a[y])
        {
            y++;
        }
        else
        {
            break;
        }
    }
    
    if(x >= n)
    {
        return 0;
    }
    
    return y - x + 1;
}

int main()
{
    cin>>n;
    
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    
    sort(a,a + n);
    
    int m;
    
    cin>>m;
    
    int rez[m];
    
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin>>a>>b;
        rez[i] = solve(a,b);
    }
    
    for(int i = 0;i < m;i++)
    {
        cout<<rez[i]<<endl;
    }
    
    return 0;
}

/*
6
9 1 3 10 3 4
1
3 8

9
2 3 5 7 10 11 13 16 17
3
1 4
9 12
15 20

13
1 3 5 7 2 3 5 7 10 11 13 16 17
4
2 6
1 4
9 12
15 20
*/