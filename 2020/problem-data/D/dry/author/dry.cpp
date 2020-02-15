// Task - dry
//Author - Pano Panov

#include <iostream>
#define MAX_W 102
using namespace std;
int n, u, v, wl[MAX_W];
bool deleted[MAX_W];
bool left(int ind){
  int i;
  for(i=ind-1; i>=0; i--){
     if(deleted[i]==true)continue;
     if(wl[i]>=wl[ind]) return true;
  }
  return false;
}
bool right(int ind){
  int i;
  for(i=ind+1; i<n; i++){
     if(deleted[i]==true)continue;
     if(wl[i]>=wl[ind]) return true;
  }
  return false;
}
int main(){
    int i, vol=0;
    cin>>n>>u>>v;
    for(i=0; i<n; i++) {cin>>wl[i]; deleted[i] = false;}
    for(i=1; i<n-1; i++){
        if(deleted[i] == true)continue;
        if(left(i)==true && right(i)==true){deleted[i] = true;}
    }
    int oldi=0;
    while(deleted[oldi])oldi++;
    for(i=oldi+1; i<n; i++){
       if(deleted[i])continue;
       vol += u*(i-oldi)*v*min(wl[oldi], wl[i]);
       oldi=i;
    }
    cout<<vol<<endl;
    return 0;
}
/* End of File */
