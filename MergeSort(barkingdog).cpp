#include<iostream>
using namespace std;
#define MAX 1000001

int n = 10;
int arr[MAX];
int tmp[MAX];
/*
	Merge Sort (���� ����)
	�ð� ���⵵ : O(NlgN)
	
	�� �迭�� �� ���� �迭�� ����Ͽ� ����Ѵٰ� �����ϸ� ��
	�̸� ���� st, mid, en ���� ������ ���
*/
void Merge(int st, int en) {
	int mid = (st + en) >> 1;		// bit operation of (st + en) / 2
	int left = st;
	int right = mid;
	for (int i = st; i < en; i++) {
		if (right == en) tmp[i] = arr[left++];
		else if (left == mid) tmp[i] = arr[right++];
		else if (arr[left] < arr[right]) tmp[i] = arr[left++];
		else tmp[i] = arr[right++];	//**Inversion Counting �� �ش� else������ ������ ����**//
		/*
		1. ������ �����Ͱ� ���� ����ų �� -> ���� left�� ��� �迭�� �ٿ�����
		2. ���� �����Ͱ� mid�� ����ų �� -> ���� right�� ��� �迭�� �ٿ�����
		3. �� ���������� ���� �迭�� 1�� ������ ������ �迭�� 1�� ���� Ŭ �� -> ���� �迭 ����
		4. �� ���������� ������ �迭�� 1�� ������ ���� �迭�� 1�� ���� Ŭ �� -> ������ �迭 ����
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