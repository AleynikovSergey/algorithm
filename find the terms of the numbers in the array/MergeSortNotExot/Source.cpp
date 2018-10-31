#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <array>

using namespace std;

void merge(int *arr, int size1, int size2) {
	int *temp = new int [size1 + size2]();
	int ptr1 = 0, ptr2 = 0;
	int *arr1 = arr, *arr2 = arr + size1;

	while (ptr1 + ptr2 < size1 + size2) {
		if (ptr1 < size1 && arr1[ptr1] <= arr2[ptr2] || ptr1 < size1 && ptr2 >= size2)
			temp[ptr1 + ptr2] = arr1[ptr1++];

		if (ptr2 < size2 && arr2[ptr2] < arr1[ptr1] || ptr2 < size2 && ptr1 >= size1)
			temp[ptr1 + ptr2] = arr2[ptr2++];
	}

	for (int i = 0; i < size1 + size2; i++)
		arr[i] = temp[i];

}

void mergeSort(int *arr, int size) {
	if (size == 1)
		return;

	int size1 = size / 2, size2 = size - size1;
	mergeSort(arr, size1);
	mergeSort(arr + size1, size2);
	merge(arr, size1, size2);
}

int binary_search(int* arr, int right, int x) {
	int midd = 0;
	int left = 0;

	while (1)
	{
		midd = (left + right) / 2;

		if (x < arr[midd])       // если искомое меньше значени€ в €чейке
			right = midd - 1;      // смещаем правую границу поиска
		else if (x > arr[midd])  // если искомое больше значени€ в €чейке
			left = midd + 1;    // смещаем левую границу поиска
		else                       // иначе (значени€ равны)
			return midd;           // функци€ возвращает индекс €чейки

		if (left > right)          // если границы сомкнулись 
			return -1;
	}
}

int main(int argc, char** argv) {
	int num = 11;
	int a[] = { 1, 4, 2, 3, 7, 2, 4, 7, 8, 1, 2 };

	// Start merge sort
	mergeSort(a, num);

	cout << binary_search(a, num, 10) << endl;
	// Print the sorted array
	cout << endl;
	for (int i = 0; i < num; i++) {
		cout << binary_search(a, num, a[i]) << " " << a[i] << endl;
	}
	cout << endl;

	int x = 5;

	for (int i = 0; i < num; ++i) {
		int index = binary_search(a, num, x - a[i]);

		if (index != -1) {
			cout << "indexes: " << index << " " << i << "; " << a[index] << " + " << a[i] << " = " << x << endl;
		}
	}
		

	return 0;
}