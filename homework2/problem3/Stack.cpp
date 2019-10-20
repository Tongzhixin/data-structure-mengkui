#include "Stack.h"
Stack::Stack(){
	top_p = NULL;
}
Stack::~Stack(){
	node *tmp;
	while (top_p != NULL) {
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}
bool Stack::isEmpty() {
	return (nullptr==top_p  );
}
void Stack::push(const char & x){
	top_p =new node(x, top_p);
}
char Stack::pop(){
	char ch;//缓冲，并取出相应的字节
	node *tmp;
	tmp = top_p;
	top_p = top_p->next;
	ch = tmp->data;
	delete tmp;
	return ch;
}
char Stack::top(){
	return top_p->data;
}

void Stack::transport(char * ch)
{
	Stack link;
	char num[50];
	char gp;//扔掉'('
	int i = 0;//记录后缀表达式的内容
	while (*ch != '\0'){
		switch (*ch) {
		case '+':
		case'-':
 			while (link.top_p!=nullptr&&link.top_p->data !='(') {
				num[i] = link.pop();
				i++;
			}
			link.push(*ch);
			break;
		case '*':
		case'/':
			link.push(*ch);
			break;
		case '(':
			link.push(*ch);
			break;
		case')':
			while (link.top_p != NULL) {
				if (link.top_p->data == '('){
					gp = link.pop(); break;
			    }
				num[i] = link.pop();
				i++;
			}
			break;
		default:
			num[i] = *ch; i++;
		}
		ch++;
	}

	while (link.top_p!=NULL) {                              //将剩余栈里的符号取出
		num[i] =link.pop();
		i++;
	}
	num[i] = '\0';            //设置结尾点
	cout << endl;              //清空缓存区
	int j = 0;
	for (int j = 0; num[j] != '\0'; j++) {
		cout << num[j] << ' ';
	}
}


bool isError(char * ch)
{
	Stack link1;
	char r;
	while (*ch != '\0') {
		if (*ch == '(')
			link1.push(*ch);
		if (*ch == ')') {
			if (link1.isEmpty()) return true;
			else r = link1.pop();
		}
		ch++;
	}
	if (link1.isEmpty()) return false;
	else return true;
}