#include "circularList.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



int main()
{
	CircularList<int> cl;

	for(int i=0; i<9; i++){
		cl.insert(0,(i));
	}


	cl.insert(10,(10));

	cl.insert(5,(11));

	cout<<"cl: "<<cl<<endl;

	cout<<endl<<"Copy constr: "<<endl;
	CircularList<int> cl2(cl);
	cl=cl2;

	cout<<"cl2: "<<cl2<<endl;

	cout<<endl<<"Removing: "<<endl;
	for (int i = 0; i<4; i++){
		cout<<"cl: "<<cl.remove(i)<<endl;
	}


	cout<<"cl: "<<cl2<<endl;

	cout<<endl<<"Assignment: "<<endl;

	cl=cl2;

	cout<<"cl: "<<cl<<endl;
	cl.clear();


	return 0;
}
