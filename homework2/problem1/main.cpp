#include "sLinkList.cpp"
#include <cstring>
//2019/10/17

int main() {
	sLinkList<int> list1;
	int i, x, y,tmp;
	i = 0;

	while (true) {
		cin >> tmp;
		list1.insert(i, tmp);
		i++;
		char ch = getchar();//�˴�������getchar()���������㴦������ʹ�õ�ʱ�����Ҫ����س�
		if (ch == '\n')
			break;
	}
	cin >> x >> y;
	list1.erase(x, y);//ɾ���м�ֵ
	list1.traverse();//�������
	cout << endl;
	return 0;
}
