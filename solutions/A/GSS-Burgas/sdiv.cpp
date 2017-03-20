#include<iostream>
#include<string>
using namespace std;
string a;
int n;
long long m,fbr,num;

int main(){
    cin>>a>>n>>m;
    for(int i=0;i<a.size();i++)if(((int)a[i]-48)%n==0)fbr++;
    for(int first=0;first<a.size();first++){
        for(int br=1;br<a.size();br++){
            for(int pos=first+1;pos<=a.size()-br;pos++){
                num=(int)a[first]-48;
                for(int pl=pos;pl<pos+br;pl++){
                    num=num*10;
                    num+=(int)a[pl]-48;
                }
                if(num%n==0){
                    fbr++;
                }
            }
        }
    }
    cout<<fbr%m<<endl;
    return 0;
}
