#include <stdio.h>

int dp(int *arr, int n)
{
    int num[n];
    num[0] = 1;
    int top = 0;
    for(int i = 1; i < n; i++) {
        num[i] = 1;
        for(int j = 0; j < i; j++) {
            if((arr[i] > arr[j]) && (num[i] <= num[j])) {
                num[i] = num[j]+1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(top < num[i]) {
            top = num[i];
        }
    }
    return top;
}

int main()
{
    int n;
    int arr[300] = {0};
    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        printf("%d\n", dp(arr, n));
    }
    return 0;
}
