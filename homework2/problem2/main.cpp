#include "sLinkString.h"
//2019/10/18
int main() {
	char ch1[20], ch2[20];//定义20的数组存放字符串
	int i = 0,j=0;
	sLinkString l1, l2,l3;
	cin.getline(ch1, 20);
	cin.getline(ch2, 20);
	for (int i = 0; ch1[i] != '\0'; i++) l1.push(ch1[i]);
	for (int j = 0; ch2[j] != '\0'; j++) l2.push(ch2[j]);
	l3 = l1.same_index(&l1, &l2);//l3为共同区间
	l3.print();//打印
	return 0;
}