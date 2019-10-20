#include "sLinkString.h"

sLinkString::node * sLinkString::move(int i){
	node *p = head;
	while (i >= 0) {
		p = p->next;
		i--;
	}
	return p;
}
sLinkString::sLinkString(){
	head = new node;
	tail = head;
	currentLength = 0;
}
void sLinkString::clear()
{
	node *p=head->next,*q;
	while (p!=nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
}
void sLinkString::push(char ch)
{
	currentLength++;
	node *p = new node(ch);
	tail->next = p;  
	tail = p;
}
sLinkString sLinkString::same_index(sLinkString * l1, sLinkString * l2)
{
	sLinkString tmp;
	node *p,* q;
	int i, j,t,h;
	bool flag = 0;
	h = 0;
	i = l1->currentLength;
	j = l2->currentLength;
	if (i > j) {
		int num = i - j;
		while (num >0) {
			p = l1->head;
			q = p->next;
			p->next = q->next;
			delete q;
			q = p->next;
			num--;
			l1->currentLength--;
		}
	}
	else {
		int num = j - i;
		while (num > 0) {
			p = l2->head;
			q = p->next;
			p->next = q->next;
			delete q;
			q = p->next;
			num--;
			l2->currentLength--;
		}
	}

	int ch[20] = { 0 };
	p = l1->head->next;
	q = l2->head->next;
	for (int s = 0; p!=nullptr&&q!=nullptr; s++) {
		if (p->data == q->data)   ch[s] = 1;
		else for (int g = 0; g <= s; g++) ch[g] = 0;
		p = p->next;
		q = q->next;
	}
	for (h = 0; h < 20; h++)
		if (ch[h] == 1) {
			t = h; 
			flag = true;
			break;
		}
	if (flag) {
		p = l1->move(t);
		while (p!=nullptr)		{
			tmp.push(p->data);
			p = p->next;
		}
	}
	return tmp;
}
void sLinkString::print()
{
	node *p = head->next;
	cout << '\n';
	while (p != nullptr)	{
		cout << p->data ;
		p = p->next;
	}
	cout << endl;
}