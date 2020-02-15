#include <iostream>
#include <string.h>
using namespace std;
int change(char a[5000], int b, char c){
	a[b]=c;
}
int main() {
	char a[5000], changer;
	int times[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cin>>a;
    for(int i=0; i<strlen(a); i++){
    	times[a[i]-97]++;
    	if(i<strlen(a)-2){
    		if(a[i]==a[i+1]&&a[i]==a[i+2]){
    			times[a[i]-97]--;
    		if(a[i+2]=='a'){
    		change(a, i+2, 'b');
			times[1]++;	
    		}
    		else {
    		change(a, i+2, 'a');
    		times[0]++;
    		}}}
    	if(times[a[i]-97]>strlen(a)/2){
    		times[a[i]-97]--;
    		if(a[i]=='a'){
    		change(a, i, 'b');
			times[1]++;	
    		}
    		else {
    		change(a, i, 'a');
    		times[0]++;
			} }
    	
    }
    cout<<a;
	return 0;
}
