#include <iostream>

using namespace std;

int main() 
{
    
    int k,i;
    cin>>k>>i;
    int sum=0,br=0,minr=100001;
    int n;
    int num=1,rzl;
    do
    {
        br++;
        cin>>n;
        if(n%2==0)sum+=n;
        if(k>n)
        {
            rzl=k-n;
        }
        else rzl=n-k;
        if(minr>=rzl)
        {
            minr=rzl;
            num=br;
        }
        
        
    }while(sum<i);
    cout<<num<<" "<<sum<<endl;
	
		return 0;
}
