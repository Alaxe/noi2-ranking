#include<iostream>
using namespace std;

int main(){
    int n,u,v;
    int arr[100];
    cin>>n>>u>>v;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=0;
    bool bigger=true;
    long long sum=0;
    for(int i=0;i<n-1;){
         if(arr[i]>arr[i+1]){
            bigger=false;
            for(j=i+1;j<n;j++){
                if(arr[i]<=arr[j]){
                    //cout<<"In the 'if':"<<arr[i]<<" "<<arr[j]<<endl<<"j="<<j<<" i="<<i<<endl<<"sum="<<((j-i)*u)*v*arr[i]<<endl;
                    sum=sum+((j-i)*u)*v*arr[i];
                    bigger=true;
                    break;
                }
            }
        if(bigger){i=j;}
        if(!bigger){
            //cout<<"In !bigger with "<<arr[i]<<endl;
            int max_el=arr[i+1];
            int max_in=i+1;

            for(j=i+2;j<n;j++){
                if(max_el<arr[j]){
                    max_el=arr[j];
                    max_in=j;
                }
            }
            //cout<<max_el<<" "<<max_in;
            sum=sum+max_el*v*((max_in-i)*u);
            i=max_in;
        }

        }

        else{
            sum=sum+arr[i]*u*v;i+=1;
            //cout<<"Else: "<<arr[i]<<" "<<arr[i+1]<<endl<<"sum: "<<arr[i]*u*v<<endl;
        }
    }
    //cout<<"Answer: "<<sum<<endl;
    cout<<sum<<endl;
}
