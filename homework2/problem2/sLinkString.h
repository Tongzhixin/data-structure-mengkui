#pragma once
#ifndef _SLINKSTRING_H
#define __SLINKSTRING_H
#include <iostream>
using namespace std;

class sLinkString {
private:
	struct node {
		char data;
		node *next;
		node(char x,node *n=nullptr):data(x),next(n){}
		node():next(nullptr){}
		~node(){}
	};
	node *head;
	node *tail;
	node *move(int i);
	int currentLength;
public:
	sLinkString();
	~sLinkString() { 
    //clear(); 
	}
	void clear();
	int length()const { return currentLength; }
	void push(char ch);
    sLinkString same_index(sLinkString *l1, sLinkString *l2);//判断是否相同，并且返回共同尾部的链表
	void print();//打印链表
};







#endif