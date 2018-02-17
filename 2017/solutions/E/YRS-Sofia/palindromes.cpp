#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    long long ogr;
    cin>>ogr;
    long long proizv=0;
    long long mnoz1=0, mnoz2=0;
    for(long long i=0; i<ogr; i++){
            for(long long z=0; z<ogr; z++){
                if(i*z>proizv){
                        if(i*z<10){
                                proizv=i*z;
                                mnoz1=i;
                                mnoz2=z;
                                goto ready;
                        }
                        string str;
                        ostringstream ostr;
                        ostr<<i*z;
                        str=ostr.str();
                        string rotstr=str;
                        for(long long x=0; x<rotstr.size()/2; x++){
                            swap(rotstr[x], rotstr[rotstr.size()-x-1]);
                        }
                        if(str==rotstr){
                                proizv=i*z;
                                mnoz1=i;
                                mnoz2=z;
                        }
                }
                ready:
            ;}
    }
    cout<<min(mnoz1, mnoz2)<<" "<<max(mnoz1, mnoz2)<<endl;
    cout<<proizv;
    return 0;
}




