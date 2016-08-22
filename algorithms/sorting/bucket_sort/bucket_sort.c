#include <stdio.h>

void bucket_sort(double a[], int n)
{
    if (n <= 1) {
        return;
    }
    double b[10][10];
    int count[10];

    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = (int)(a[i] * 10);
        b[index][count[index]] = a[i];
        int j = count[index]++;

        while (j>0 && b[index][j-1] > a[i]) {
            b[index][j] = b[index][j-1];
            j--;
        }
        b[index][j] = a[i];
    }

    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            a[k++] = b[i][j];
        }
    }
}

void print(double a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", a[i]);
    }
    printf("\n");
}

int main()
{
    double a[7] = {0.31,0.39,0.2,0.6,0.44,0.81,0.18};
    print(a, 7);
    bucket_sort(a, 7);
    print(a, 7);
}
