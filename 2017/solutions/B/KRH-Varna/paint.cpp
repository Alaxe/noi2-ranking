#include<iostream>
#include<vector>
using namespace std;
struct rect
{
    short x;
    short y;
    short right;
    short down;
    int s;
    vector<rect> children;
} board;
///sortirani parvo po x, posle po y
/**int b_search(vector<rect> v,dummy)
{
    if(v.size()==0) return 0;
    int left=0,right=v.size()-1,middle;
    while(left<=right)
    {
        middle=(left+right)/2;
        if(v[middle]->x>dummy->x) {right=middle-1;continue;}
        if(v[middle]->x<dummy->x) {left=middle+1;continue;}
        if(v[middle]->y>dummy->y) {right=middle-1;continue;}
        if(v[middle]->y<dummy->y) {left=middle+1;continue;}
    }
    return middle;
}*/
void recurse(rect &a,rect dummy)
{
    if(a.x>dummy.x||a.x+a.right<dummy.x||a.y>dummy.y||a.y+a.down<dummy.y) return;
    ///int ind=b_search(a->children,dummy);
    bool flag=0;
    for(int i=0;i<a.children.size();i++)
    {
        if(a.children[i].x<dummy.x&&a.children[i].x+a.children[i].right>dummy.x&&a.children[i].y<dummy.y&&a.children[i].y+a.children[i].down>dummy.y)
        {
            flag=1;
            recurse(a.children[i],dummy);
            return;
        }
    }
    if(flag==0)
    {
        ///cout<<"[[[ ";
        a.children.push_back(dummy);
        a.s-=dummy.s;
        ///cout<<a.s<<" "<<a.children.size()<<endl;
        return;
    }
}
void lookie(rect &a,rect dummy)
{
    if(a.x>dummy.x||a.x+a.right<dummy.x||a.y>dummy.y||a.y+a.down<dummy.y) return;
    ///int ind=b_search(a->children,dummy);
    bool flag=0;
    for(int i=0;i<a.children.size();i++)
    {
        if(a.children[i].x<dummy.x&&a.children[i].x+a.children[i].right>dummy.x&&a.children[i].y<dummy.y&&a.children[i].y+a.children[i].down>dummy.y)
        {
            flag=1;
            lookie(a.children[i],dummy);
            return;
        }
    }
    if(flag==0)
    {
        cout<<a.s<<endl;
        return;
    }
}

void test_output(rect a)
{
    cout<<">>>> "<<a.x<<"+"<<a.right<<" "<<a.y<<"+"<<a.down<<" "<<a.s<<"   ch "<<a.children.size()<<endl;
    for(int i=0;i<a.children.size();i++)
    {
        test_output(a.children[i]);
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    short x0,y0,n,i,t;
    bool k;
    cin>>x0>>y0>>n;
    rect dummy;
    board.x=0;
    board.y=0;
    board.right=x0;
    board.down=y0;
    board.s=int(x0)*int(y0);
    for(i=0;i<n;i++)
    {
        cin>>dummy.x>>dummy.y>>dummy.right>>dummy.down;
        dummy.s=int(dummy.right)*int(dummy.down);
        recurse(board,dummy);
    }

    /**cout<<"=================="<<endl;
    test_output(board);
    cout<<"=================="<<endl;*/
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>dummy.x>>dummy.y;
        lookie(board,dummy);
    }
    return 0;
}
