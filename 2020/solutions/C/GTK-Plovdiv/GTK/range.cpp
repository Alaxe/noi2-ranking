#include<iostream>
#include<algorithm>
using namespace std;

int nums[100000+1000];
int reqs[100000+1000];
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    sort(nums, nums+n);

    int m, st, fin, minn, maxx, curr;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>st>>fin;

        minn=0, maxx=n-1;
        while(true)
        {
            if(st>nums[n-1] || fin<nums[0])
            {
                st = 0;
                fin = -1;
                break;
            }

            if(st <= nums[0])
            {
                st = 0;
                break;
            }

            if(st == nums[n-1])
            {
                st = n - 1;
                break;
            }

            //cout<<minn<<" "<<maxx<<endl;
            curr = minn + (maxx-minn)/2;

            if(st<nums[curr])
            {
                maxx = curr;
            }
            else if(st>nums[curr])
            {
                minn = curr;
            }
            else if(st == nums[curr])
            {
                st = curr;
                break;
            }
            else if(st < nums[curr] && st > nums[curr-1])
            {
                st = curr;
                break;
            }
            else if(st > nums[curr] && st < nums[curr+1])
            {
                st = curr+1;
                break;
            }
        }
        //cout<<st<<endl;

        minn=0, maxx=n-1;
        while(true)
        {
            if(st>nums[n-1] || fin<nums[0])
            {
                break;
            }

            if(fin >= nums[n-1])
            {
                fin = n-1;
                break;
            }

            if(fin == nums[0])
            {
                fin = 0;
                break;
            }

            //cout<<minn<<" "<<maxx<<endl;
            curr = minn + (maxx-minn)/2;
            if(fin<nums[curr])
            {
                maxx = curr;
            }
            else if(fin>nums[curr])
            {
                minn = curr;
            }
            else if(fin == nums[curr])
            {
                fin = curr;
                break;
            }
            else if(fin < nums[curr] && fin > nums[curr-1])
            {
                fin = curr-1;
                break;
            }
            else if(fin > nums[curr] && fin < nums[curr+1])
            {
                fin = curr;
                break;
            }
        }
        //cout<<fin<<endl;

        reqs[i] = (fin - st) + 1;
        //cout<<reqs[i]<<endl;
    }

    //cout<<"-------------------------"<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<reqs[i]<<endl;
    }

    return 0;
}
