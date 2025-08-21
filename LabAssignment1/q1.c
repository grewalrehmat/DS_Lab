#include <stdio.h>
#include <stdlib.h>
// ——MENU——
// 1. CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT
#include <stdio.h> 
#define MAX 100
void create(int arr[], int *n) {
    printf("Enter number of elements: "); 
    scanf("%d", n);
    printf("Enter elements:\n"); 
    for (int i = 0; i < *n; i++) { 
        scanf("%d", &arr[i]); 
    }
}
void display(int arr[], int n) { 
    printf("Array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
}
void insert(int arr[], int *n) { 
    int pos, val;
    printf("Enter position (0-based index): "); 
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);
    if (pos < 0 || pos > *n) { 
        printf("Invalid position!\n"); 
        return;
    }
    for (int i = *n; i > pos; i--) 
        arr[i] = arr[i-1];
    arr[pos] = val; 
    (*n)++;
}

void delete(int arr[], int *n) { 
    int pos;
    printf("Enter position to delete (0-based index): "); 
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) { 
        printf("Invalid position!\n"); 
        return;
    }
    for (int i = pos; i < *n - 1; i++) 
        arr[i] = arr[i+1];
    (*n)--; 
}
void linearSearch(int arr[], int n) { 
    int val, found = 0;
    printf("Enter value to search: "); 
    scanf("%d", &val);
    for (int i = 0; i < n; i++) { 
        if (arr[i] == val) {
            printf("Found at index: %d\n", i); 
            found = 1;
            break; 
        }
    }
    if (!found)
        printf("Not Found\n");
}

int main() {
    int arr[MAX], n = 0, choice; 
    while (1) {
        printf("\n——MENU——\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n"); 
        printf("Enter choice: ");
        scanf("%d", &choice); 
        switch (choice) {
            case 1: create(arr, &n); break;
            case 2: display(arr, n); break;
            case 3: insert(arr, &n); break;
            case 4: delete(arr, &n); break;
            case 5: linearSearch(arr, n); break;
            case 6: return 0;
            default: printf("Invalid choice\n"); 
        }
    } 
}