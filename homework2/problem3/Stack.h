#pragma once
#ifndef _STACK_H
#define __STACK_H
#include <iostream>
using namespace std;
class Stack
{
	
private:
	struct node {
		char data;
		node *next;
		node(const char x,node *n=NULL):data(x),next(n){}//初始化
		node():next(NULL){}
		~node(){}
	};
	node *top_p;

public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(const char &x);
	char pop();
	char top();
	
	void transport(char *ch);
};
    bool isError(char *ch);//平衡检查

#endif
