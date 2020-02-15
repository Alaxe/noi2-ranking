#include<bits/stdc++.h>
using namespace std;
int redica[15000000];
int pomost[15000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string vhod;
    char zam[26],zam2[26];
    cin>>vhod;
    for(unsigned long long a=0;a<vhod.size();a++){
        redica[a]=vhod[a]-'A';
        pomost[a]=vhod[a]-'A';
    //    cout<<redica[a];
    }
   // cout<<endl;
    sort(pomost,pomost+vhod.size());
    int n=0,n1=25;
    for(unsigned long long a=0;a<vhod.size();a++){
        if(a==0){
            zam[pomost[a]]='A';
        }else{
            if(pomost[a]!=pomost[a-1]){
                n++;
            }
            zam[pomost[a]]='A'+n;
        }

    }
   // cout<<zam[0]<<" "<<zam[1]<<endl;;
    n1=25;
    for(unsigned long long a=vhod.size()-1;a>=0;a=a-1){
        if(a==vhod.size()-1){
            zam2[pomost[vhod.size()-1]]='Z';
        }else{
            if(pomost[a]!=pomost[a+1]){
                n1--;
            }
            zam2[pomost[a]]='A'+n1;
        }
        if(a==0){
            break;
        }
    }
    for(unsigned long long a=0;a<vhod.size();a++){
        cout<<zam[redica[a]];
    }
    cout<<endl;
    for(unsigned long long a=0;a<vhod.size();a++){
     //   cout<<redica[a]<<endl;
        cout<<zam2[redica[a]];
    }
    cout<<endl;
    return 0;
}

