#include <stdio.h>
int main() {
    int arr[10][10], r, c;
    printf("Enter number of rows and cols: "); 
    scanf("%d %d", &r, &c);
    printf("Enter matrix:\n"); 
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            scanf("%d", &arr[i][j]);
    printf("Row sums:\n");
    for (int i = 0; i < r; i++) { 
        int sum = 0;
        for (int j = 0; j < c; j++) 
            sum += arr[i][j];
        printf("Row %d sum = %d\n", i + 1, sum); 
    }
    printf("Column sums:\n"); 
    for (int j = 0; j < c; j++) { 
        int sum = 0;
        for (int i = 0; i < r; i++) 
            sum += arr[i][j];
        printf("Column %d sum = %d\n", j + 1, sum); 
    }
}
