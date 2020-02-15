#include<iostream>
using namespace std;
void func(int l,int r,int& ans)
{
bool ml=0,mr=0;
if(l>0 && r>0)
    {
    while(ml==0 || mr==0)
    {
    if(l>0 && ml==0){l--;ml=1;}
    else{r--;mr=1;}
    func(l,r,ans);
    }
    }
else
    {
    while(l+r!=0)
        {
        if(l>0){l--;}
        else{r--;}
        func(l,r,ans);
        }
    if(l+r==0){ans++;}
    }
}

int main()
{
int ans=0;
short int n,k,l,r;;
cin>>n>>k;n--;k--;
l=k-1;r=n-k;
func(l,r,ans);
cout<<ans<<endl;
return 0;
}
