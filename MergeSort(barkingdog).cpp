#include<iostream>
using namespace std;
#define MAX 1000001

int n = 10;
int arr[MAX];
int tmp[MAX];
/*
	Merge Sort (병합 정렬)
	시간 복잡도 : O(NlgN)
	
	한 배열을 두 개의 배열로 취급하여 계산한다고 생각하면 됨
	이를 위해 st, mid, en 등의 변수를 사용
*/
void Merge(int st, int en) {
	int mid = (st + en) >> 1;		// bit operation of (st + en) / 2
	int left = st;
	int right = mid;
	for (int i = st; i < en; i++) {
		if (right == en) tmp[i] = arr[left++];
		else if (left == mid) tmp[i] = arr[right++];
		else if (arr[left] < arr[right]) tmp[i] = arr[left++];
		else tmp[i] = arr[right++];	//**Inversion Counting 시 해당 else문에서 조건을 변경**//
		/*
		1. 오른쪽 포인터가 끝을 가리킬 때 -> 남은 left의 모든 배열을 붙여넣음
		2. 왼쪽 포인터가 mid를 가리킬 때 -> 남은 right의 모든 배열을 붙여넣음
		3. 현 시점에서의 왼쪽 배열의 1번 값보다 오른쪽 배열의 1번 값이 클 때 -> 왼쪽 배열 대입
		4. 현 시점에서의 오른쪽 배열의 1번 값보다 왼쪽 배열의 1번 값이 클 때 -> 오른쪽 배열 대입
		*/
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void MergeSort(int st, int en) {
	if (st >= en) return;
	int mid = (st + en) >> 1;
	MergeSort(st, mid);
	MergeSort(mid, en);
	Merge(st, en);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	MergeSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	return 0;
}