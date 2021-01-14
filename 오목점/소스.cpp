#include <stdio.h>
#include <stdlib.h>
typedef struct point {
	int x; //x�� ��ǥ
	int y; //y�� ��ǥ
}Point;


int ccw(Point P1, Point P2, Point P3) {
	int temp1= (P2.x - P1.x) * (P3.y - P1.y);
	int temp2=(P2.y-P1.y)*(P3.x-P1.x);
	if (temp1 - temp2 > 0)
		return 1;
	else if (temp1 - temp2 == 0)
		return 0;
	else 
		return -1;
}
int main() {
	int n; // �ٰ����� �������� ���� n �Է�
	scanf_s("%d",&n);
	Point* arr;
	arr= (Point*)malloc(sizeof(Point) * n);
	
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d", &arr[i].x, &arr[i].y);
	}
	int ct=0; //�������� ����
	for (int i = 0; i < n-3; i++) {
		int answer= ccw(arr[i], arr[i + 1], arr[i + 2]);
		int answer2 = ccw(arr[i+1], arr[i + 2], arr[i + 3]);
		printf("%d %d", answer, answer2);
		if (answer==1 && ccw(arr[i+1], arr[i + 2], arr[i + 3])==-1 || answer == -1 && ccw(arr[i + 1], arr[i + 2], arr[i + 3]) == 1)
			ct += 1;
	}
	printf("�������� ����: %d", ct);
	//�����Ҵ�..?
	return 0;
}