#include <iostream>

using namespace std;

int main(){
    int w,h;

    cin>>w>>h;

    int area[h];
    for(int i=0; i<h; i++) area[i] = 0;

    int n, x, y, x2, y2, swap;
    cin>>n;

    for(int i=0; i<n; i+=2){
        cin>>x>>y>>x2>>y2;

        if(y>y2){
            swap = y;
            y = y2;
            y2 = swap;
        }

        //if(x!=x2) cout<<"wronng data ? "<<endl;

        for(int j=y; j<y2; j++){
            if(area[j] < x){
                area[j] = x;
            }
        }
    }

    int result = 0;

    for(int i=0; i<h; i++) result += w-area[i];

    cout<<result<<endl;
}
