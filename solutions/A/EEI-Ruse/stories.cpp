#include<iostream>
#include<deque>
using namespace std;
const long long MAX_N=10000100;
long long n,k;
long long first,mul,add,mod;
long long ans;
void input()
{
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
}
void stress_test()
{
    n=10000000;
    //n=133742;
    k=666;
    first=20;
    mul=3;
    add=17;
    mod=1000000007;
}
void output()
{
    cout<<ans<<endl;
}
struct MyDeque
{
    long long array[MAX_N+100];
    int back_pos;
    int front_pos;
    MyDeque()
    {
        back_pos=0;
        front_pos=1;
    }
    int plus1(int pos)
    {
        return (pos+1+MAX_N)%MAX_N;
    }
    int minus1(int pos)
    {
        return (pos-1+MAX_N)%MAX_N;
    }
    bool empty()
    {
        return plus1(back_pos)==front_pos;
    }
    long long back()
    {
        return array[plus1(back_pos)];
    }
    long long front()
    {
        return array[minus1(front_pos)];
    }
    void pop_back()
    {
        back_pos=plus1(back_pos);
    }
    void pop_front()
    {
        front_pos=minus1(front_pos);
    }
    void push_back(long long curr)
    {
        array[back_pos]=curr;
        back_pos=minus1(back_pos);
    }
    void push_front(long long curr)
    {
        array[front_pos]=curr;
        front_pos=plus1(front_pos);
    }
};
struct MonotonicRmq
{
    //MyDeque d; tozi moment kogato si napishesh deque sys statichna pamet za da e po byrz
    deque<long long> d; //ama stl-skiq pak e po byrz s 3.5 deseti ot sekundata
    //typoto e che stress testa mi vyrvi za 3.35 sekundi pyk tl-to malko taka e 0.6s
    //obache daje i bez deque-a i rmq-to
    //a prosto da smetna elementite (koeto e s O(N)) otnema malko nad 0.6s
    //pyk nqkvo na okej kompove 1 miliard operacii im otnemat 1 sekunda
    //sq obache se chudq shtoto, okej, kompjutyra na kojto se testvat shte e po-byrz
    //ama vse pak se zabavq 6 pyti pochti kato realno reshavam zadachata
    //a ne prosto da smetna elemntite
    //pyk i onq komp ne e nqkvo chudo na chudesata nqkvo 2.2GHz
    //toq tuk e 1.8GHz
    //i da znam che ne e samo chestota ama vse pak
    //dali shte vyrvi 6 pyti po byrzo
    //predpolagam shte razberem shtoto nqmam genialni idei
    //PS znam che slojostta na monotonic rmq pak e O(N)
    //ama se opitah da mu podobrq konstantata kato smenq deque-a
    //sled kato tova failna reshih da napisha tova shtoto ima oshte 1:30 pyk maj sym gotov
    //PPS leet 42 rly?
    //TL;DR vyrvi za 3.35 sekundi i se chudq dali prosto toq komp e mnogo baven
    //ili ima reshenie sys slojnost pod O(N)
    void insert(long long curr)
    {
        while (!d.empty() && curr>d.back()) d.pop_back();
        d.push_back(curr);
    }
    void erase(long long curr)
    {
        if (!d.empty() && curr==d.front()) d.pop_front();
    }
    long long get()
    {
        if (!d.empty()) return d.front();
        //cerr<<"ALERT"<<endl;
        return 0;
    }
};
long long get_next(long long curr)
{
    return (curr*mul+add)%mod;
}
MonotonicRmq mrmq;
void solve()
{
    ans=0;
    long long curr,del;
    curr=first;
    for (int i=0;i<k;++i)
    {
        mrmq.insert(curr);
        ans+=mrmq.get();
        curr=get_next(curr);
    }
    del=first;
    for (int i=k;i<n;++i)
    {
        mrmq.erase(del);
        mrmq.insert(curr);
        ans+=mrmq.get();
        curr=get_next(curr);
        del=get_next(del);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    //stress_test();
    solve();
    output();
    return 0;
}