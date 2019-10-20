#include "Stack.h"


int main() {
	char ch[50];
	cin.getline(ch,50);
	Stack link;
	if (isError(ch)) { 
		//cout << "-1";
		return -1;
	}
	else {
		link.transport(ch);
	}
	return 0;
}