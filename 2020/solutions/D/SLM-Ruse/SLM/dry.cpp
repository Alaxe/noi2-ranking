include<iostream>
using namespace std;

int main();
{
    int n, u, v, c //razmeri;
    for(n=3;n<100;n++)
    for(u=2;u<5;u++)
    for(v=2;v<5;v++)
    cin >> n;cout << setw (1); cin >> u;cout << setw (1);cin >> v;cout << setw(1);
    cin >> c;
    cout << c+u+v; << endl;
}