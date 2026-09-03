#include <iostream>
void quick_sort(int* array, int low, int high);
int partition(int* array, int low, int high);
int main() {
  int arr[] = {5, 1, 1, 1, 1, 1};
  quick_sort(arr, 0, 5);

  for (int i = 0; i < 6; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

void quick_sort(int* array, int low, int high) {
  if (low >= high) {
    return;
  }

  for (int i = low; i <= high; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  int pivot_idx = partition(array, low, high);
  quick_sort(array, low, pivot_idx - 1);
  quick_sort(array, pivot_idx + 1, high);
}

int partition(int* array, int low, int high) {
  int left_ptr = low + 1;
  int right_ptr = high;
  int pivot = array[low];
  int temp;

  while (left_ptr < right_ptr) {

    // swap till left elements greater than pivot
    while ( left_ptr <= high - 1 && array[left_ptr] < pivot) {
      left_ptr++;
    }

    // swap till right elements are less than equal to pivot.
    while (right_ptr >= low + 1 && array[right_ptr] >= pivot) {
      right_ptr--;
    }

    if (left_ptr < right_ptr) {
      temp = array[left_ptr];
      array[left_ptr] = array[right_ptr];
      array[right_ptr] = temp;
    }
  }

  // swap pivot
  array[low] = array[right_ptr];
  array[right_ptr] = pivot;

  return right_ptr;
}