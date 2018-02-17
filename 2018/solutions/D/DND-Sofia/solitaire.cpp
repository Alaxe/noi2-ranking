#include <iostream>
#include <utility>

using namespace std;

pair<char, char> cards[101][101];

long long get_points_for(char c) {
    if(c >= '2' && c <= '9')
        return c - '0';
    else {
        switch(c) {
        case 'A':
            return 1;
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        }
    }
    return 0;
}

int main() {
    long long n, x, y, s = 0;
    cin>>n;
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < n; j++) {
            cin>>cards[i][j].first;
            cin>>cards[i][j].second;
        }
    }
    x = 0;
    y = n - 1;

    s += get_points_for(cards[y][x].first);

    while(x != n - 1 || y != 0) {
        if(x == n - 1) {
            y--;
            s += get_points_for(cards[y][x].first);
        } else if(y == 0) {
            x++;
            s += get_points_for(cards[y][x].first);
        } else {
            long long pu = get_points_for(cards[y - 1][x].first), pr = get_points_for(cards[y][x + 1].first);
            if(pu > pr) {
                y--;
                s += pu;
            } else {
                x++;
                s += pr;
            }
        }
    }

    cout<<s;

    cout<<endl;
}
