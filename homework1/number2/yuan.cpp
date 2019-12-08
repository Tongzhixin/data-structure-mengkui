#include "rmb.h"


RMB operator+(const RMB &r1,const RMB &r2){
    double sum,a1,a2;
	RMB tmp;
	a1 = convert(r1);
	a2 = convert(r2);
    sum=a1+a2;
    /*y1=int(sum);原本想设计的
    j1=sum*10%10;
    f1=sum*100%10;
    tmp.yuan=y1;
    tmp.jiao=j1;
    tmp.fen=f1;
    */
   tmp.fconvert(sum);
    cout<<"Sum:"<<sum<<"yuan"<<'\n';
    return tmp;
}
RMB operator-(const RMB &r1,const RMB &r2){
	double difference,a1,a2;
	RMB tmp;
	a1 = convert(r1);
	a2 = convert(r2);
	difference = a1 - a2;
    /*y1=int(sum);
    j1=sum*10%10;
    f1=sum*100%10;
    tmp.yuan=y1;
    tmp.jiao=j1;
    tmp.fen=f1;
    */
   tmp=tmp.fconvert(difference);
    cout<<"Difference:"<<difference<<"yuan"<<'\n';
    return tmp;
}
double convert(const RMB &r1){
    double a;
    a=r1.yuan+r1.jiao*0.1+r1.fen*0.01;
    return a;
}
RMB RMB::fconvert(double sum){
	int y1, j1, f1;
    RMB tmp;
    y1=int(sum);
    j1=int((sum*10))%10;
    f1=int((sum*100))%10;
    tmp.yuan=y1;
    tmp.jiao=j1;
    tmp.fen=f1;
    return tmp;
}
