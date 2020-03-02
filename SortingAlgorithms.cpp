#include <iostream>
using namespace std;

#define SIZE 10

void BubbleSort (int arr[SIZE], int limit)
{
  int temp, index;

  for (; limit > 0; limit--)
  {
    for (index = 0; index < limit; index++)
    {
      if (arr[index] > arr[index+1])
      {
        temp = arr[index];
        arr[index] = arr[index+1];
        arr[index+1] = temp;
      }
    }
  }
}

void SelectionSort (int arr[], int limit)
{
  int temp, indexOfLargest, index;

  for (; limit > 0; limit--)
  {
    indexOfLargest = 0;
    for (index = 1; index <= limit; index++)
    {
      if (arr[index] > arr[indexOfLargest])
      {
        indexOfLargest = index;
      }
    }
    if (limit != indexOfLargest)
    {
      temp = arr[limit];
      arr[limit] = arr[indexOfLargest];
      arr[indexOfLargest] = temp;
    }
  }
}

void InsertionSort (int arr[])
{
  int i, j, temp;

  for (i=1; i < SIZE; i++)
  {
    for (j=i; j>0 && arr[j] < arr[j-1]; j--)
    {
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
    }
  }
}

void ShellSort (int arr[], int n)
{
  int temp;

  for (int gap=n/2; gap >= 1; gap = gap/2)
  {
    for (int i=gap; i < n; i++)
    {
      for (int j=i; j>=gap && arr[j-gap]>arr[j]; j=j-gap)
      {
        temp = arr[j-gap];
        arr[j-gap] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void DisplayArray (int arr[])
{
  cout << "Displaying array:\n" << endl;
  for (int i=0; i<SIZE; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main()
{
  int arr[] = {1,4,6,3,5,9,2,8,0,7};
  int arrB[SIZE], arrSel[SIZE], arrI[SIZE], arrSh[SIZE];

  DisplayArray(arr);

  for(int i=0; i<SIZE; i++)
  {
    arrB[i] = arr[i];
    arrSel[i] = arr[i];
    arrI[i] = arr[i];
    arrSh[i] = arr[i];
  }
  cout << "arrB:";
  DisplayArray(arrB);
  cout << "Bubble:\n";
  BubbleSort(arrB, SIZE);
  DisplayArray(arrB);

  cout << "arrSel:";
  DisplayArray(arrSel);
  cout << "Selection:\n";
  SelectionSort(arrSel, SIZE);
  DisplayArray(arrSel);

  cout << "arrI:";
  DisplayArray(arrI);
  cout << "Insertion:\n";
  InsertionSort(arrI);
  DisplayArray(arrI);

  cout << "arrSh:";
  DisplayArray(arrSh);
  cout << "Shell:\n";
  ShellSort(arrSh, SIZE);
  DisplayArray(arrSh);

  return 0;
}
