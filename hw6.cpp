#include <iostream>
using namespace std;

void FArray(int arr[], int a){ 
  for(int i = 0; i < a; i++)
    cin >> arr[i];
}

void PArray(int arr[], int a){ 
  for(int i = 0; i < a; i++)
    cout << arr[i] << " ";
}

void AArray(int arr[], int arr2[], int arr3[], int a){ 
  for(int i = 0; i < a; i++)
    arr3[i] = arr[i] + arr2[i];
}

void SArray(int arr[], int arr2[], int arr3[], int a){ 
  for(int i = 0; i < a; i++)
    arr3[i] = arr[i] - arr2[i];
}

int main(){
  int size;
  cin >> size;
  int array_1[size];
  FArray(array_1, size);
  char znak;
  cin >> znak;
  int array_2[size];
  FArray(array_2, size);
  int array_3[size];
  if(znak == '+')
    AArray(array_1, array_2, array_3, size);
  else 
    SArray(array_1, array_2, array_3, size);
  PArray(array_3, size);
}