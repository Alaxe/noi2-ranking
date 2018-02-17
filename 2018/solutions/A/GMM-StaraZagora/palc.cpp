#include <iostream>
#include <cstring>
using namespace std;
char A[100];
char res[100];
int result = 0;
int positions[100];
bool isPolindrom(char Word[], int n){
    for(int i=0; i<n/2;i++){
        if(Word[i]!= Word[n-i-1]){
            return false;
        }
    }
    return true;
}
void Variate(int all, int target,int position, int counter){
    if(target == position-1){
        int br= 0;
        for(int i = 0;i<=target;i++){
            res[br] = A[positions[i]];
            br++;
        }
        if(isPolindrom(res, br)){
            result++;
        }
        return;
    }
    for(int i = counter;i<all;i++){
            positions[position] = i;
            Variate(all, target, position+1, i+1);
    }
    
}
int main()
{
    cin>>A;
    int n = strlen(A);
    for(int i = 0;i<n;i++)Variate(n,i,0,0);
    cout<<result;
    return 0;
}