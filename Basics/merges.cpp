#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArray[n1], rightArray[n2];

  for (int i = 0; i < n1; i++)
    leftArray[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0;

  int k = left;
  while (i < n1 && j < n2) {
    if (leftArray[i] <= rightArray[j]) {
      arr[k] = leftArray[i];
      i++;
    } else {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightArray[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[] = {18,56,27,7,8,4,9,31,81,1};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, arr_size - 1);

  cout << "Sorted array: \n";
  for (int i = 0; i < arr_size; i++)
    cout << arr[i] << " ";
  return 0;
}