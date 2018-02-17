#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
#include<string.h>
using namespace std;
int b;
stack<int> tos(int a){
    stack<int> tr;
    while(a > 0){
            tr.push(a % b);
            a = a/b;
    }
    return tr;
}
stack<char> num(char *a){
    stack<char> nm;
    int len = strlen(a);
    for(int i = 0;i < len;i++){
        nm.push(a[i]);
    }
    return nm;
}
void sw(stack<int> &a){
    int ftl = a.top();
    a.pop();
    stack<int> z;
    while(a.size() != 1){
        z.push(a.top());
        a.pop();
    }
    int flt = a.top();
    a.pop();
    a.push(ftl);
    while(z.empty() == false)
    {
     a.push(z.top());
     z.pop();
    }
    a.push(flt);
}
stack<int> cti(stack<char> a)
{
    stack<int> b;
    while(a.empty() == false){
        switch(a.top())
        {
         case 'A': b.push(10); break;
         case 'B': b.push(11); break;
         case 'C': b.push(12); break;
         case 'D': b.push(13); break;
         case 'E': b.push(14); break;
         case 'F': b.push(15); break;
         case 'G': b.push(16); break;
        default: b.push(a.top() - '0');
        }
        a.pop();
    }
    return b;
}
int tonum(char* a){
    stack<char> c = num(a);
    stack<int> i = cti(c);
    int q =  i.size();
    int chislo = 0;
    while ( i.empty() == false){
    q--;
    chislo = chislo + pow(b,q)*i.top();
     i.pop();
    }
    return chislo;
}
int tonum2(stack<int> a)
{
 int q =  a.size();
    int chislo = 0;
    while ( a.empty() == false){
    q--;
    chislo = chislo + pow(b,q)*a.top();
     a.pop();
    }
    return chislo;
}
void print(stack<int> a)
{
    while(a.empty() == false){
        switch(a.top())
        {
         case 10: cout<<"A"; break;
         case 11: cout<<"B"; break;
         case 12: cout<<"C"; break;
         case 13: cout<<"D"; break;
         case 14: cout<<"E"; break;
         case 15: cout<<"F"; break;
         case 16: cout<<"G"; break;
        default: cout<<a.top();
        }
        a.pop();
    }
}
int main(){
    cin>>b;
    char a[10];
    char b[10];
    char c[10];
    char d[10];
    cin.clear();
    cin.sync();
    cin.getline(a,10);
   cin.clear();
    cin.sync();
    cin.getline(b,10);
    cin.clear();
  cin.sync();
    cin.getline(c,10);
    cin.clear();
    cin.sync();
    cin.getline(d,10);
    int ai = tonum(a);
    int bi = tonum(b);
    int ci = tonum(c);
    int di = tonum(d);
    bool np = true;
    for(int a = 1;a < ai;a++)
    {
        stack<int> temp = tos(a);
        sw(temp);
        int q = tonum2(temp);
        if(q + a == ai)
        {
         np = false;
         //stack<int> tp = tos(a);
         print(temp);
         cout<<endl;
         break;
        }
    }
    if(np == true) cout<<0<<endl;
    np = true;
    for(int b = 1;b < bi;b++)
    {
        stack<int> temp = tos(b);
        sw(temp);
        int q = tonum2(temp);
        if(q + b == bi)
        {
         np = false;
         //stack<int> tp = tos(b);
         print(temp);
         cout<<endl;
         break;
        }
    }
    if(np == true) cout<<0<<endl;
    np = true;
    for(int c = 1;c < ci;c++)
    {
        stack<int> temp = tos(c);
        sw(temp);
        int q = tonum2(temp);
        if(q + c == ci)
        {
         np = false;
        // stack<int> tp = tos(c);
         print(temp);
         cout<<endl;
         break;
        }
    }
    if(np == true) cout<<0<<endl;
    np = true;
    for(int d = 1;d < di;d++)
    {
        stack<int> temp = tos(d);
        sw(temp);
        int q = tonum2(temp);
        if(q + d == di)
        {
         np = false;
         //stack<int> tp = tos(d);
         print(temp);
         cout<<endl;
         break;
        }
    }
    if(np == true) cout<<0<<endl;
    np = true;

    return 0;
}
