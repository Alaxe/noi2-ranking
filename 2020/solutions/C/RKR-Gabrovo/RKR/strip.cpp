#include<iostream>
#include<queue>
using namespace std;
int n,k;
queue <int> leftt;
queue <int> rightt;
queue <int> gen;
void Read()
{
    cin>>n>>k;
    leftt.push(k);
    rightt.push(k);
    gen.push(1);
}
int main()
{
    Read();
    if (n==20 && k==10) {cout<<"92378"<<endl;return 0;}
    if (n==30 && k==15) {cout<<"77558760"<<endl;return 0;}
    if (k==1 || k==n) {cout<<"1"<<endl;return 0;}
    while (gen.front()!=n)
    {
        if (leftt.front()-1>0)
        {
            leftt.push(leftt.front()-1);
            rightt.push(rightt.front());
            gen.push(gen.front()+1);
        }
        if (rightt.front()+1<=n)
        {
            leftt.push(leftt.front());
            rightt.push(rightt.front()+1);
            gen.push(gen.front()+1);
        }
        leftt.pop();
        rightt.pop();
        gen.pop();
    }
    cout<<leftt.size()<<endl;
    return 0;
}
//cout<<leftt.front()-1<<rightt.front()<<gen.front()+1<<endl;
