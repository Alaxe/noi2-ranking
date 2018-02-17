#include<iostream>
using namespace std;
int main() {
    long long a,b,n,zb = 0,minzb = 100000,mini = 1,i = 0,minn = 0;
    cin>>a>>b;
    while(zb <= b&&i != 200 - 1) {
        cin>>n;
        if(n % 2 == 0) {
            zb += n;
            if(minzb >= b - zb) 
            {
                //cout<<i<<endl;
                if(zb > b) 
                {
                    minzb = zb - b;
                    mini = i;
                }
                 else 
                {
                    minzb = b - zb;
                    mini = i;
                }
            }
        }
        //cout<<zb<<endl;
        i++;
    }
    if(mini == 0)
    cout<<mini + 1<<" "<<zb<<endl;
    else cout<<mini<<" "<<zb<<endl;
    return 0;
}
