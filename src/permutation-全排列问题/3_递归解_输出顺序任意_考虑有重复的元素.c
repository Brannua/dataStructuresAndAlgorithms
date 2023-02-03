#include <stdio.h>

void _swap(int arr[], int i, int begin);
void _printArr(int arr[], int arrLen);

void permutation(int arr[], int begin, int end) {

  if (begin > end) { return; }
  if (begin == end) { _printArr(arr, end + 1); return; }

  // add
  int _set[100] = { 0 };

  for (int i = begin; i <= end; i ++) {

    // add
    if (_set[arr[i]] == 1) {
      continue;
    } else {
      _set[arr[i]] = 1;
    }

    _swap(arr, i, begin);
    permutation(arr, begin + 1, end);
    _swap(arr, i, begin);
  }
}

int main(void) {
  int arr[] = { 1, 1, 3 },
      arrLen = sizeof(arr) / sizeof(int);

  permutation(arr, 0, arrLen - 1);
  return 0;
}

/*-- Utils are under below. --*/

void _swap(int arr[], int i, int begin) {
  int tmp = arr[begin];
  arr[begin] = arr[i];
  arr[i] = tmp;
}

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
