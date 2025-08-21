#include <stdio.h>
void removeDuplicates(int arr[], int *n) { 
    for (int i = 0; i < *n; i++) { 
        for (int j = i + 1; j < *n; ) { 
            if (arr[i] == arr[j]) {
                for (int k = j; k < *n - 1; k++) 
                    arr[k] = arr[k + 1]; 
                (*n)--;
            } else { 
                j++; 
            } 
        }
    } 
}
int main() {
    int arr[100], n;
    printf("Enter number of elements: "); 
    scanf("%d", &n);
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    removeDuplicates(arr, &n);
    printf("Array after removing duplicates:\n"); 
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
}