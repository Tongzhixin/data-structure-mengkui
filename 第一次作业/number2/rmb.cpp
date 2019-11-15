#include <iostream>
#include "rmb.h"

int main()
{
    int y1,j1,f1,y2,j2,f2;
    cout<<"input RMB1(yuan jiao fen):";
    cin>>y1>>j1>>f1;
    cout<<"input RMB2(yuan jiao fen):";
    cin>>y2>>j2>>f2;
    RMB r1(y1,j1,f1),r2(y2,j2,f2),r3,r4;
    r3=r1+r2;
    r4=r1-r2;

	return 0;

}