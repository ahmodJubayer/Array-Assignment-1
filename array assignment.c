#include <stdio.h>

void add(int arr[], int *n);
void update(int arr[], int n);
void removeNumber(int arr[], int *n);
void sortArray(int arr[], int n);
void search(int arr[], int n);
void display(int arr[], int n);

int main() {
    int arr[100], n = 0, choice;

    printf("How many numbers to start with? ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add number at end\n");
        printf("2. Update number\n");
        printf("3. Remove a number\n");
        printf("4. Sort numbers\n");
        printf("5. Search number\n");
        printf("6. Show all numbers\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Bye!\n");
            break;
        }

        switch (choice) {
            case 1:
                add(arr, &n);
                break;
            case 2:
                update(arr, n);
                break;
            case 3:
                removeNumber(arr, &n);
                break;
            case 4:
                sortArray(arr, n);
                break;
            case 5:
                search(arr, n);
                break;
            case 6:
                display(arr, n);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add(int arr[], int *n) {
    int num;
    printf("Enter number to add: ");
    scanf("%d", &num);
    arr[*n] = num;
    (*n)++;
}

void update(int arr[], int n) {
    int pos, val;
    printf("Enter position to update (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
}

void removeNumber(int arr[], int *n) {
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    int val, i, found = 0;
    printf("Enter number to remove: ");
    scanf("%d", &val);
    for (i = 0; i < *n; i++) {
        if (arr[i] == val) {
            for (int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            found = 1;
            printf("Number removed.\n");
            break;
        }
    }
    if (!found) {
        printf("Number not found.\n");
    }
}

void sortArray(int arr[], int n) {
    int order;
    printf("Sort order: 1 for Ascending, 2 for Descending: ");
    scanf("%d", &order);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((order == 1 && arr[i] > arr[j]) || (order == 2 && arr[i] < arr[j])) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    printf("Array sorted.\n");
}

void search(int arr[], int n) {
    int val, found = 0;
    printf("Enter number to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Not found.\n");
    }
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
