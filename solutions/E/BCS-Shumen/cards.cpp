#include <iostream>

using namespace std;

int main() 
{
    int n;
    int a,b,pr1,pr2,maxbr=1,br=1;
    cin>>n;
    cin>>a>>b;
    for(int i=0;i<n-1;i++)
    {
        pr1=a;
        pr2=b;
        cin>>a>>b;
        if((a*b)<=(pr1*pr2))
        {
            br++;
        }
        else
        {
            if(maxbr<br)
            {
                maxbr=br;
            }
            br=1;
        }
            
    }
    if(maxbr<br)
            {
                maxbr=br;
            }
    cout<<maxbr<<endl;
	
		return 0;
}
