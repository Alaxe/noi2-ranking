#include<iostream>
#include<string.h>
using namespace std;
int S = 0;
int RecCount = 0;
void dels(int z,char*a)
{
    int wl = strlen(a);
    //cout<<"        deleting - "<<a[z]<<"  index - "<<z<<endl;
    for(int i = z;i < wl;i++)
        a[i] = a[i+1];
}
bool isp(char *a){
    if(strlen(a) == 1 ) return true;
    int wl = strlen(a);
    for(int i = 0;i < wl/2;i++){
    //cout<<a[i]<<" - "<<a[wl-i-1]<<endl;
     if(a[i] != a[wl-i-1]) return false;
    }
    return true;

}
void reccur(int rc,char *a,int last = 0)
{
   // cout<<"   Calling reccursion"<<endl;
    char newword[10];
    strcpy(newword,a);
    int wl = strlen(newword);
   // cout<<"     Str len - "<<wl<<"   word  - "<<newword<<endl;
    for(int i = last;i <wl;i++){
       // cout<<"         cycle   - "<<i<<"    rc  - "<<rc<<endl;
        dels(i,newword);
        if(rc > 1)
        {
        reccur(rc-1,newword,i);
        strcpy(newword,a);
        }
        else
        {
        if(isp(newword) == true ) S++;
       // cout<<"        checking word - "<<newword<<"    Old word  - "<<a<<endl;
        strcpy(newword,a);
        }
    }
   // cout<<"   End recc"<<endl;
}
int main(){
    char word[100];
    cin.getline(word,100);
    int wl = strlen(word);
    for(int i = 1;i < wl - 1;i++){
        //cout<<"i - "<<i<< endl;
        reccur(i,word);
    }
    S = S + wl;
    if(isp(word) == true) S++;
    cout<<S;
return 0;
}
