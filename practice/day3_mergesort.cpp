#include <iostream>

void merge_sort(int* array, int low, int high);
void merge(int* array, int low, int mid, int high);

int main() {
  int array [] = {5, 1, 6, 9 , 3, 8};
  merge_sort(array, 0, 5);
  for (int i = 0; i <= 5; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

void merge_sort(int* array, int low, int high) {
  if (low >= high) {
    return;
  }

  for (int i = low; i <= high; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  int mid = low + (high - low) / 2;
  merge_sort(array, low, mid);
  merge_sort(array, mid + 1, high);

  merge(array, low, mid, high);
}

void merge(int* array, int low, int mid, int high) {
  int left_ptr = low;
  int right_ptr = mid + 1;
  int temp_arr[high - low + 1];
  int temp_ptr = 0;

  while (left_ptr <= mid && right_ptr <= high) {

    if (array[left_ptr] <= array[right_ptr]) {
      temp_arr[temp_ptr] = array[left_ptr];
      temp_ptr++;
      left_ptr++;
    } else {
      temp_arr[temp_ptr] = array[right_ptr];
      temp_ptr++;
      right_ptr++;
    }
  }

  while (left_ptr <= mid) {
    temp_arr[temp_ptr] = array[left_ptr];
    temp_ptr++;
    left_ptr++;
  }

  while(right_ptr <= high) {
    temp_arr[temp_ptr] = array[right_ptr];
    temp_ptr++;
    right_ptr++;
  }

  // copy elements to main array
  for (int i = low; i <= high; i++) {
    array[i] = temp_arr[i - low];
  }

}
