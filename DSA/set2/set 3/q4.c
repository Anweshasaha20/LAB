#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n) {
    printf("\nInsertion Sort:\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

void selectionSort(int arr[], int n) {
    printf("\nSelection Sort:\n");
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

void bubbleSort(int arr[], int n) {
    printf("\nBubble Sort:\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d: ", i + 1);
        printArray(arr, n);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high, int pass, int n) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Pass %d: ", pass);
        printArray(arr, n);
        quickSortHelper(arr, low, pi - 1, pass + 1, n);
        quickSortHelper(arr, pi + 1, high, pass + 1, n);
    }
}

void quickSort(int arr[], int n) {
    printf("\nQuick Sort:\n");
    quickSortHelper(arr, 0, n - 1, 1, n);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSortHelper(int arr[], int left, int right, int *pass, int n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid, pass, n);
        mergeSortHelper(arr, mid + 1, right, pass, n);
        merge(arr, left, mid, right);
        printf("Pass %d: ", (*pass)++);
        printArray(arr, n);
    }
}

void mergeSort(int arr[], int n) {
    printf("\nMerge Sort:\n");
    int pass =1;
    mergeSortHelper(arr, 0, n - 1, &pass, n);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    printf("\nHeap Sort:\n");
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    printf("Build Heap: ");
    printArray(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printf("Pass %d: ", n - i);
        printArray(arr, n);
        heapify(arr, i, 0);
    }
}

int main() {
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], copy[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nMenu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (int i = 0; i < n; i++)
            copy[i] = arr[i];

        switch (choice) {
        case 1:
            insertionSort(copy, n);
            break;
        case 2:
            selectionSort(copy, n);
            break;
        case 3:
            bubbleSort(copy, n);
            break;
        case 4:
            quickSort(copy, n);
            break;
        case 5:
            mergeSort(copy, n);
            break;
        case 6:
            heapSort(copy, n);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
