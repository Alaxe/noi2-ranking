#include <iostream>
using namespace std;
int main(){
    long long a,b,delitel=1,brDeliteli=0,brNamereni=0;
    cin>> a >> b;
    for(int i=a;i<=b;i++){
        brDeliteli=0;
        for(int delitel=1; delitel<=i;delitel++){
            if(i%delitel==0) brDeliteli++;
        }
        if(brDeliteli%2!=0) brNamereni++;
    }
    cout<< brNamereni;
    return 0;
}

