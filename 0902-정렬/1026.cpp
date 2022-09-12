/*
가장 큰 수와 가장 작은 수를 곱하도록 한다. 
합병정렬로 정렬하고, 두 배열을 반대로 곱한다(가장 작은 수 * 가장 큰 수)
*/

#include <iostream>
#include <vector>

using namespace	std;

void	merge(vector<int> &arr, int left, int mid, int right) {
	
	int p1 = left;
	int p2 = mid + 1;
	int k = left;
	vector<int> sorted(arr.size()); 

	while (p1 <= mid && p2 <= right) {
		if (arr[p1] < arr[p2]) {
			sorted[k++] = arr[p1++];
		}
		else {
			sorted[k++] = arr[p2++];
		}
	}

	while (p1 <= mid) {
		sorted[k++] = arr[p1++];
	}
	while (p2 <= right) {
		sorted[k++] = arr[p2++];
	}

	for (int i = left; i < right + 1; i++) {
		arr[i] = sorted[i];
	}
}

void	mergeSort(vector<int> &arr, int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

int	main () {

	int	n;
	cin >> n;

	int	input;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	mergeSort(a, 0, n - 1);
	mergeSort(b, 0, n - 1);

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// for (int i = 0; i < n; i++) {
	// 	cout << b[i] << " ";
	// }

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + (a[i] * b[n - 1 - i]);
	}
	cout << sum;
	return (0);
}
