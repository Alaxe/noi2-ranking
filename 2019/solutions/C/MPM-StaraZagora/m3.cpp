#include <iostream>

inline void output(float* result);
inline void typeA(uint64_t k, int32_t a, int32_t b, int32_t c, float* result);
inline void typeB(uint64_t k, int32_t a, int32_t b, int32_t c, float* result);
inline void typeC(uint64_t k, int32_t a, int32_t b, int32_t c, float* result);
inline void typeD(uint64_t k, int32_t a, int32_t b, int32_t c, float* result);

int main()
{
    std::cout.precision(3);
    uint32_t s, a, b, c, d;
    uint64_t k;
    std::cin >> s >> k >> a >> b >> c >> d;

    int sec = 0;
    while(k >= 4*d) {
        k-=4*d;
        sec++;
    }
    sec%=4;

    float result[4] = {0, 0, 0, 0};

    if(!k){
        output(result);
        return 0;
    }

    switch(sec){
    case 0:
        typeA(k, a, b, c, result);
    break;
    case 1:
        typeB(k, a, b, c, result);
    break;
    case 2:
        typeC(k, a, b, c, result);
    break;
    case 3:
        typeD(k, a, b, c, result);
    break;
    }

    output(result);

    return 0;
}

inline void output(float* result) {
    std::cout << std::fixed
              << result[0] << ' '
              << result[1] << ' '
              << result[2] << ' '
              << result[3] << '\n';
}

inline void typeA(uint64_t k, int32_t a, int32_t b, int32_t c, float* result){
    const int seq[3] = {a, c, b};
    if(k < 2*seq[1]) {
        if(k < seq[0]) result[0] = k;
        else {
        result[0] = (float)k/2;
        result[1] = (float)k/2;
        }
    }
    else{
        result[0] = seq[0];
        result[1] = seq[1];
        k-=(seq[0] + seq[1]);
        result[2] = k;
        if(result[2] > seq[2]){
            result[3] = result[2] - seq[2];
            result[2] = seq[2];
        }
        if(result[3] > seq[2]){
            int t=result[3]-seq[2];
            result[2]+=(float)(t/2);
            result[3]+=(float)(t/2);
        }
    }
}

inline void typeB(uint64_t k, int32_t a, int32_t b, int32_t c, float* result){
    const int seq[3] = {b, a, c};
    if(k<3*seq[2]){
        if(k<seq[0]) result[0] = k;
        else{
            result[0] = seq[0];
            k-=seq[0];
            if(k<seq[1]) result[1] = k;
            else{result[1]=(float)k/2;result[2]=(float)k/2;}
        }
    }
    else{
        result[0] = seq[2];
        result[1] = seq[2];
        result[2] = seq[2];
        result[3] = k-3*seq[2];
    }

}

inline void typeC(uint64_t k, int32_t a, int32_t b, int32_t c, float* result){
    const int seq[3] = {b, c, a};


}

inline void typeD(uint64_t k, int32_t a, int32_t b, int32_t c, float* result){
    const int seq[3] = {c, a, b};
    if(k<seq[0]) result[0] = k;
    else{
        result[0] = seq[0];
        k-=seq[0];
        if(k<seq[2]) result[2] = k;
        else{
            if(k<2*seq[2]){
                result[1] = (float)k/2;
                result[2] = (float)k/2;
            }
            else{
                result[1] = seq[2];
                result[2] = seq[2];
            }
        }
    }

}
