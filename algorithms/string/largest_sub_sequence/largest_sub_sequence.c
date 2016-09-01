#include<stdio.h>

long max_sub_sum(int a[], int n)
{
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        if (max_sum < sum) {
            max_sum = sum;
        } else if (sum < 0) {
            sum = 0;
        }
    }

    return max_sum;
}

int main()
{
    int a[] = {2,-1,4,3,35,-54,36};
    int ret = 0;
    ret = max_sub_sum(a, 7);

    printf("max sum: %d", ret);

    return 0;
}
