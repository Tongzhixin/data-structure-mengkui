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
	char ch;//���壬��ȡ����Ӧ���ֽ�
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
	char gp;//�ӵ�'('
	int i = 0;//��¼��׺���ʽ������
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

	while (link.top_p!=NULL) {                              //��ʣ��ջ��ķ���ȡ��
		num[i] =link.pop();
		i++;
	}
	num[i] = '\0';            //���ý�β��
	cout << endl;              //��ջ�����
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