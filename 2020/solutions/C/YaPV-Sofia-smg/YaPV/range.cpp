#include<iostream>
#include<algorithm>
using namespace std;
int a[100002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m;
    cin>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(x<a[0] and y<a[0]){
            cout<<0<<endl;
            continue;
        }
        if(x>a[n-1] and y>a[n-1]){
            cout<<0<<endl;
            continue;
        }
        ///Намираме индекса на първото число, което е по-голямо или равно на x.
        int l=-1;
        int r=n;
        int mid;
        while(l+1!=r){
            mid=(r+l)/2;
            if(a[mid]<x){
                l=mid;
            }else{
                r=mid;
            }
        }
        ///cout<<"The first number: ";
        ///cout<<a[r]<<endl;
        ///Намираме индекса на последното число, което е по-малко или равно на y.
        int l1=-1;
        int r1=n;
        int mid1;
        while(l1+1!=r1){
            mid1=(r1+l1)/2;
            if(a[mid1]>y){
                r1=mid1;
            }else{
                l1=mid1;
            }
        }
        ///cout<<"The last number: ";
        ///cout<<a[l1]<<endl;
        cout<<l1-(r-1)<<endl;
    }
    return 0;
}
