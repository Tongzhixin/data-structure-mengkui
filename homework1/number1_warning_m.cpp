#include <iostream>
using namespace std;
//报警函数
void warning(int num) {
	int value = 0;
    if(num<0){
      cout << "error of input number";  
      return;
    }
	else {
        while (value < num-1)
        {
            ++value;
            cout << value << '\n';
        }
	cout << "Warning:" << num << "!";
    }
    return;
}

//main函数
int main() {
	int input_user;
	cout << "Warning value:";
    
	cin >> input_user;
	warning(input_user);
   // system("pause");
	return 0;
}