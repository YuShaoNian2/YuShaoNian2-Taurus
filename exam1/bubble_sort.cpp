#include <iostream>
using namespace std;

int main()
{
	int arr[10] = { 5,8,2,10,7,15,13,11,20,18 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < len - 1;i++) {
		for (int j = 0;j < len - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0;i < len;i++) {
		cout << arr[i] << endl;
	}
	cout <<"ok了兄弟们，我终于完成云上传了哈哈"<<endl;
	system("pause");
	return 0;
}