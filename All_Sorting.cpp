
include <iostream>
// Function to print the array
void printArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
}
// Selection Sort
void selectionSort(int arr[], int n) {
 for (int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (arr[j] < arr[minIndex]) {
 minIndex = j;
 }
 }
 std::swap(arr[i], arr[minIndex]);
 }
}
// Insertion Sort
void insertionSort(int arr[], int n) {
 for (int i = 1; i < n; i++) {
 int key = arr[i];
 int j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j--;
 }
 arr[j + 1] = key;
 }
}
// Bubble Sort
void bubbleSort(int arr[], int n) {
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 std::swap(arr[j], arr[j + 1]);
 }
 }
 }
}
// Quick Sort
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low - 1);
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] < pivot) {
 i++;
 std::swap(arr[i], arr[j]);
 }
 }
 std::swap(arr[i + 1], arr[high]);
 return (i + 1);
}
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// Merge Sort
void merge(int arr[], int l, int m, int r) {
 int n1 = m - l + 1;
 int n2 = r - m;
 int* L = new int[n1];
 int* R = new int[n2];
 for (int i = 0; i < n1; i++) {
 L[i] = arr[l + i];
 }
 for (int i = 0; i < n2; i++) {
 R[i] = arr[m + 1 + i];
 }
 int i = 0;
 int j = 0;
 int k = l;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
 delete[] L;
 delete[] R;
}
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = l + (r - l) / 2;
 mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
}
// Counting Sort
void countingSort(int arr[], int n) {
 int maxVal = arr[0];
 int minVal = arr[0];
 for (int i = 1; i < n; i++) {
 if (arr[i] > maxVal) {
 maxVal = arr[i];
 }
 if (arr[i] < minVal) {
 minVal = arr[i];
 }
 }
 int range = maxVal - minVal + 1;
 int* count = new int[range];
 int* output = new int[n];
 for (int i = 0; i < range; i++) {
 count[i] = 0;
 }
 for (int i = 0; i < n; i++) {
 count[arr[i] - minVal]++;
 }
 for (int i = 1; i < range; i++) {
 count[i] += count[i - 1];
 }
 for (int i = n - 1; i >= 0; i--) {
 output[count[arr[i] - minVal] - 1] = arr[i];
 count[arr[i] - minVal]--;
 }
 for (int i = 0; i < n; i++) {
 arr[i] = output[i];
 }
 delete[] count;
 delete[] output;
}
int main() {
 int n;
 std::cout << "Enter the number of elements: ";
 std::cin >> n;
 int* arr = new int[n];
 std::cout << "Enter the elements: ";
 for (int i = 0; i < n; i++) {
 std::cin >> arr[i];
 }
 int choice;
 std::cout << "Choose a sorting algorithm:" << std::endl;
 std::cout << "1. Selection Sort" << std::endl;
 std::cout << "2. Insertion Sort" << std::endl;
 std::cout << "3. Bubble Sort" << std::endl;
 std::cout << "4. Quick Sort" << std::endl;
 std::cout << "5. Merge Sort" << std::endl;
 std::cout << "6. Counting Sort" << std::endl;
 std::cout << "Enter your choice: ";
 std::cin >> choice;
 switch (choice) {
 case 1:
 selectionSort(arr, n);
 break;
 case 2:
 insertionSort(arr, n);
 break;
 case 3:
 bubbleSort(arr, n);
 break;
 case 4:
 quickSort(arr, 0, n - 1);
 break;
 case 5:
 mergeSort(arr, 0, n - 1);
 break;
 case 6:
 countingSort(arr, n);
 break;
 default:
 std::cout << "Invalid choice." << std::endl;
 return 1;
 }
 // Print the sorted array
 std::cout << "Sorted array: ";
 printArray(arr, n);
 delete[] arr;
 return 0;
}
