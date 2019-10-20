#include "sLinkList.h"


template<class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i)
{
	node *p = head;
	while (i >= 0) {
		p = p->next;
		i--;
	}
	return p;
}

template<class elemType>
sLinkList<elemType>::sLinkList()
{
	head = new node;
	currentLength = 0;
}
template<class elemType>
void sLinkList<elemType>::clear()
{
	node *p = head->next,*q;
	head->next = NULL;
	while (p!=NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	currentLength = 0;
}
template<class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x) 
{
	node *pos;
	pos = move(i - 1);
	pos->next = new node(x, pos->next);
	currentLength=currentLength+1;
}
template<class elemType>
void sLinkList<elemType>::remove(int i)
{
	node *pos, *q;

	pos = move(i - 1);
	q = pos->next;
	pos->next = q->next;
	delete q;
	currentLength=currentLength-1;
}
template<class elemType>
int sLinkList<elemType>::search(const elemType & x) const
{
	node *p = head->next;
	int i = 0;

	while (p != NULL && p->next != x) {
		p = p->next;
		i++;
	}
	if (p == NULL) return -1;
	else return i;
}
template<class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
	return move(i)->data;
}
template<class elemType>
void sLinkList<elemType>::traverse() const
{
	node *p = head ->next;
	cout << '\n';
	while (p!=NULL)
	{
		cout << p->data << "  ";
		p=p->next;
	}
	cout << endl;
}
template<class elemType>
void sLinkList<elemType>::erase(elemType x, elemType y) 
{
	node *p=head,*q;
	q = p->next;
	while (q != NULL ) {
		if (q->data <= y && q->data >= x) {
			p->next = q->next;
			delete q;
			q = p->next;
			currentLength--;
		}
		else {
			p = p->next;
			q = p->next;
		}
	}
	cout << endl;
	cout << currentLength;
}