#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    short dsL = 1001;
    short ds[dsL];

    short n;
    cin>>n;
    short arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            short diff = arr[j] - arr[i];
            //cout<<"Found a diff of "<<diff<<" "<<i<<" "<<j<<endl;
            if(diff>0) ds[diff] = 10;
        }
    }

    int result = 0;
    int d, tmpAdd = 0;

    int last;
    bool flag = false;

    for(int i=0; i<dsL; i++){
        if(ds[i] == 10){
            d = i;

            for(int j=0; j<n-1; j++){
                tmpAdd += d;
                for(int k=j+1; k<n; k++){
                    if(arr[j] + tmpAdd == arr[k]){
                        result++;
                        tmpAdd += d;
                        if(!flag){
                            flag = true;
                            last = k;
                        }
                    } else if(flag && k==n-1){
                        flag = false;
                        k = last;
                        tmpAdd = d;
                    }
                }

                tmpAdd = 0;
            }
        }
    }

    cout<<result;
}
