#include <iostream>

int partition(int* array, int low, int high);
void quick_sort(int* array, int low, int high);

int main() {
  int arr[] = {5, 1, 5};
  quick_sort(arr, 0, 2);
  return 0;
}

void quick_sort(int* array, int low, int high) {
  if (low >= high) {
    return;
  }
  int corret_pivot_idx = partition(array, low, high);
  quick_sort(array, low, corret_pivot_idx - 1);
  quick_sort(array, corret_pivot_idx + 1, high);
    for (int i = 0; i < 3; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;


}

int partition(int* array, int low, int high) {
  int pivot = array[low];
  int left_ptr = low;
  int right_ptr = high;
  int temp;
  while (left_ptr < right_ptr) {

    // move left pointer till it find elements Greater than or equal to pivot.
    while (left_ptr <= high - 1  && array[left_ptr] <= pivot) {
      left_ptr++;
    }

    // move right pointer till you find elements less than pivot
    while (right_ptr >= low + 1 && array[right_ptr] > pivot) {
      right_ptr--;
    }

    // swap
    if (left_ptr < right_ptr) {
      temp = array[left_ptr];
      array[left_ptr] = array[right_ptr];
      array[right_ptr]  = temp;
    } 
  }

  //move pivot
  array[low] = array[right_ptr];
  array[right_ptr] = pivot;

  return right_ptr;
}