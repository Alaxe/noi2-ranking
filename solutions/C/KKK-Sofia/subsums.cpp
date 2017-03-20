#include<iostream>
#include<set>
using namespace std;
set<int> sums,sumsnew;
bool zero=1;
int main()
{
    cin.tie();
    sums.insert(0);
    sumsnew=sums;
    int n=200,k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(set<int>::iterator a=sums.begin();a!=sums.end();a++){
                sumsnew.insert(*a+k);
                if(*a+k==0){
                    zero=0;
                }
        }
        sums=sumsnew;
    }
    cout<<sums.size()-zero<<endl;
    return 0;
}
