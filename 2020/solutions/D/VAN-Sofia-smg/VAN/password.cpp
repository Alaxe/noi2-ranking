#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long br[27],ind=0;
string bukvi;
int main(){
    for(int i=0;i<200;i++){
        bukvi[i]=(char)('%'+i);
    }
    string a;
    cin>> a;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(i>1 && a[i-1]==a[i] && a[i]==a[i-2]){
            a[i]=bukvi[ind];
            if(ind==199) ind=0;
            else ind++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]>='a' && a[i]<='z'){
            br[a[i]-'a']++;
        }
    }
    //sort(br,br+27);
  //  for(int i=0;i<27;i++) cout<< br[i] << " ";
    for(int i=0;i<27;i++){
        if(br[i]>(n/2)){
            for(int j=0;j<n;j++){
                if(a[i]==('a'+i)){
                    a[i]=bukvi[ind];
                    if(ind==199) ind=0;
                    else ind++;
                }
            }
        }
    }
    cout<< a;


    return 0;
}


