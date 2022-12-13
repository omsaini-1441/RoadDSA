/*
COUNTING PSUEDO SORT
CountingSort(arr[], size, div) – take arr[size]

create output array called – output[size]

take a range (or no of unique elements. Default value 10 in our case)

create count array called – count[range] & initialize all values to 0

for(int i=0 to i<range)

count[i] = 0

Count each element & place it in the count[] array

for(int i = 0 to i<size)

count[ (arr[i]/div)%10 ]++

Modify count[] array to store previous counts (cumulative)

for(int i = 1 to i < range)

count[i] += count[i – 1];

Place elements from input array arr[] to output array output[] using this count[] array that has the actual positions of elements

for(int i=0 to i<size)

output[count[ (arr[i]/div)%10 ] – 1] = arr[i]

count[ (arr[i]/div)%10 ]–

Transfer sorted values from output[] array to input array arr[]

for(i=0 to i<size)

arr[i] = output[i]

 
RADIX SORT
PSUEDO CODE
radix sort(q,n)
int max = get max (A, n)


*/
#include<iostream>

#include<list>

#include<cmath>

using namespace std;

void display(int *array, int size) {

   for(int i = 0; i<size; i++)

      cout << array[i] << " ";

   cout << endl;

}

void radixSort(int *arr, int n, int max) {

   int i, j, m, p = 1, index, temp, count = 0;

   list<int> pocket[10];      //radix of decimal number is 10

   for(i = 0; i< max; i++) {

      m = pow(10, i+1);

      p = pow(10, i);

      for(j = 0; j<n; j++) {

         temp = arr[j]%m;

         index = temp/p;      //find index for pocket array

         pocket[index].push_back(arr[j]);

      }

      count = 0;

      for(j = 0; j<10; j++) {

         //delete from linked lists and store to array

         while(!pocket[j].empty()) {

            arr[count] = *(pocket[j].begin());

            pocket[j].erase(pocket[j].begin());

            count++;

         }

      }

   }

}

int main() {

   int n, max;

   cout << "Enter the number of elements: ";

   cin >> n;

   cout << "Enter the maximum digit of elements: ";

   cin >> max;

   int arr[n]; //create an array with given number of elements

   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {

      cin >> arr[i];

   }

   cout << "Data before Sorting: ";

   display(arr, n);

   radixSort(arr, n, max);

   cout << "Data after Sorting: ";

   display(arr, n);

}
