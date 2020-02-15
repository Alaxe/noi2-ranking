#include <iostream>
#include <string>
using namespace std;
string s;
long long d,i,a[300],p,j;
int main()
{
    cin>>s;
    d=s.size();
    p=d/2;
    for(i=0;i<d;i++){
        if(s[i]==s[i+1] && s[i+1]==s[i+2]){s[i+2]=char(s[i]+1);}
        a[s[i]]++;
    }
    for(i=0;i<299;i++){
        //cout<<a[i]<<endl;
        if(a[i]>p){
            for(j=0;j<d;j++){
                if(s[j]!=char(i))continue;
                if(s[j-2]==char(i+1) && s[j-1]==char(i+1)){continue;}
                if(s[j+2]==char(i+1) && s[j+1]==char(i+1)){continue;}
                if(s[j+1]==char(i+1) && s[j-1]==char(i+1)){continue;}
                s[j]=char(i+1);
                a[i+1]++;a[i]--;
                if(a[i]<=p){break;}
            }

        }
    }




    cout<<s;




    return 0;
}
