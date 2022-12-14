#include <iostream>
#include <vector>

using namespace std;
vector<int>arr, sorted;

void	merge(int left, int mid, int right) {
	
	int p1 = left;
	int p2 = mid + 1;
	int k = left;

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

void	mergeSort(int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, mid, right);
	}
}

int main () {

	int	num;
	cin >> num;

	arr.assign(num, 0);
	sorted.assign(num, 0);

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	mergeSort(0, num - 1);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << "\n";
	}

	return (0);
}