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
		char ch = getchar();//此处利用了getchar()函数，方便处理，但是使用的时候最后要输入回车
		if (ch == '\n')
			break;
	}
	cin >> x >> y;
	list1.erase(x, y);//删除中间值
	list1.traverse();//遍历输出
	cout << endl;
	return 0;
}
