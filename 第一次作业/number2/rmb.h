//#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;

class RMB{
    friend RMB operator+(const RMB &r1,const RMB &r2);
    friend RMB operator-(const RMB &r1,const RMB &r2);
	friend double convert(const RMB &r1);//��RMBת��Ϊdouble
    private:
    int yuan,jiao,fen;

    public:
    RMB(int y=0,int j=0,int f=0){yuan=y;jiao=j;fen=f;}
    RMB fconvert(double sum) ;//��һ����doubleת��ΪRMB�ĺ���
     
};

#endif