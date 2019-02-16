#include<cstdio>

int main(){
    unsigned long long n;
    scanf("%lld", &n);
    n /= (unsigned long long)42;
    n *= (unsigned long long)42;
    n += (unsigned long long)26;
    printf("%lld", n);
    return 0;
}
