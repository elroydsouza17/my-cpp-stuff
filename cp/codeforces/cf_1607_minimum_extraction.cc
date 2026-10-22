#include <iostream>

void minExtraction(int arr[], int size);

int main() {
  // assign testcase nums
  int testcases;
  std::cin >> testcases;
    while (testcases) {
      // assign size of array
      int size;
      std::cin >> size;
      int arr[size];

      // assign array from input
      for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
      }
      std::cout << "array is : ";
      for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
      }
      std::cout << "\n";
      minExtraction(arr, size);

      testcases--;
    }

  return 0;
}

void minExtraction(int arr[], int size) {
  // int size = sizeof(arr)/sizeof(*arr);
  int operations = 0;

  while (size > 1) {

    // find min
    for (int i = 0; i < size - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      int temp = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = temp;
    }
  }
  // printf("Min element is %d\n", arr[size - 1]);

    for (int i = 0; i < size - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      int temp = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = temp;
    }
  }
  // printf("2nd Min element is %d\n", arr[size - 2]);
  // printf("Min value after extraction is %d\n", arr[size - 2] - arr[size - 1]);
  if ((arr[size - 2] - arr[size - 1]) > arr[size - 1]) {
    for (int j = 0; j < size; j++) {
      arr[j] -= arr[size - 1];
    }
    // arr[size - 2] = arr[size - 2] - arr[size - 1];
    size--;
    operations++;
  } else {
    break;
  }
  }

  printf("FInal answer is %d\n", arr[size - 1]);
  // std::cout << " operations: " << operations << "\n";
}

