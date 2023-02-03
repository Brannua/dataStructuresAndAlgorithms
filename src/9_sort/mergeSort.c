/**
 * 归并排序
 */

#include <stdio.h>

int _tmpArrSize;

void _printArr(int arr[], int arrLen) {
  for (int i = 0; i < arrLen; i ++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void _merge(int arr[], int low, int mid, int high) {

  // 申请辅助空间
  int _tmpArr[_tmpArrSize];
  for (int i = low; i <= high; i ++) {
    _tmpArr[i] = arr[i];
  }

  // 将辅助空间的数据，写回原数组

  int i = low, j = mid + 1;

  int k = low;

  while (i <= mid && j <= high) {
    arr[k++] = _tmpArr[i] <= _tmpArr[j] ? _tmpArr[i++] : _tmpArr[j++];
  }

  while (i <= mid) { arr[k++] = _tmpArr[i++]; }
  while (j <= high) { arr[k++] = _tmpArr[j++]; }
}

void mergeSort(int arr[], int low, int high) {

  if (low >= high) return;

  int mid = (low + high) / 2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  _merge(arr, low, mid, high);

}

int main() {

  int arr[] = { 4, -1, 7, 0, 6, 2, 8, -4, 0, 2, -1 },
      arrLen = sizeof(arr) / sizeof(int);

  _tmpArrSize = arrLen;

  mergeSort(arr, 0, arrLen - 1);

  _printArr(arr, arrLen);

  return 0;
}

