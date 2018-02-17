#include<iostream>
using namespace std;
long long otg=0, MOD = 1000000007;

bool pal(string k)
{
    for(int i=0;i<k.size()/2;i++)
    {
        if(k[i]!=k[k.size()-i-1])
            return false;
    }
    return true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str;
    string h;
    cin>>str;
    for(int i=1/*(1<<(str.size()-1))*/;i<(1<<(str.size()+1)-1);i++)
    {
        h="";
        int c= i;
        for(int j=0;c>0;j++)
        {
            //cout<<c%2;
            if(c%2)
            {
                h+=str[j];
            }
            c/=2;
        }
        if(pal(h))
            otg=(otg+1)%MOD;
       // cout<<h<<" "<<pal(h)<<endl;

    }
    cout<<otg<<endl;
return 0;
}
