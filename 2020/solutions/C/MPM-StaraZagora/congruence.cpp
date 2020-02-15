#include <iostream>
#include <string>

int main () {

    std::string v;
    std::cin >> v;

    char t = 'A';
    for(char k = 'A'; k <= 'Z' ; k++) {
        bool f = false;
        for(char &c : v) {
            if(c == k){
                f = true;
                c = t;
            }
        }
        if(f) t++;
    }
    std::cout << v << std::endl;

    int d = 'Z' - t + 1;
    for(char &c : v) {
        c += d;
    }
    std::cout << v << std::endl;
    return 0;
}
