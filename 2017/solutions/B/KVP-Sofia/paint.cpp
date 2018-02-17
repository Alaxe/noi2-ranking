#include <stdio.h>

int w, h, n, xywh[11000][4], t, x, y, curr, s[11001], mx, my;

int main () {
    scanf("%d %d %d", &w, &h, &n);
    s[0] = w * h;
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d %d", &xywh[i][0], &xywh[i][1], &xywh[i][2], &xywh[i][3]);
        s[i + 1] = xywh[i][2] * xywh[i][3];
        mx = 0;
        my = 0;
        curr = 0;
        for(int j = 0; j < i; j ++) {
            if(xywh[j][0] < xywh[i][0] && xywh[j][1] < xywh[i][1] && xywh[j][2] + xywh[j][0] > xywh[i][0] && xywh[j][3] + xywh[j][1] > xywh[i][1] && (mx < xywh[j][0] || my < xywh[j][1])) {
                mx = xywh[j][0];
                my = xywh[j][1];
                curr = j + 1;
            } else {
                if(xywh[j][0] > xywh[i][0] && xywh[j][1] > xywh[i][1] && xywh[j][0] < xywh[i][0] + xywh[i][2] && xywh[j][1] < xywh[i][1] + xywh[i][3]) s[i + 1] -= s[j + 1];
            }
        }
        s[curr] -= s[i + 1];
    }
    scanf("%d", &t);
    for(int i = 0; i < t; i ++) {
        scanf("%d %d", &x, &y);
        mx = 0;
        my = 0;
        curr = 0;
        for(int j = 0; j < n; j ++) {
            if(xywh[j][0] < x && xywh[j][1] < y && xywh[j][2] + xywh[j][0] > x && xywh[j][3] + xywh[j][1] > y && (mx < xywh[j][0] || my < xywh[j][1])) {
                mx = xywh[j][0];
                my = xywh[j][1];
                curr = j + 1;
            }
        }
        printf("%d\n", s[curr]);
    }
    return 0;
}
