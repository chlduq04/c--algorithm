#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void cul(int input2, int *resultx,int *resulty, int sx1, int sx2){
	for (int i = 0; i < input2 / 2; i++){
		int check = input2;
		check -= sx1 * i;
		if (check % sx2 == 0){
			*resultx = i;
			*resulty = check / sx2;
			break;
		}
	}
}

int main(){
	int input1, input2;
	int sx1[2] = { 1, 1 };
	int sx2[2] = { 1, 2 };
	int resultx, resulty;
	cin >> input1 >> input2;
	if (input1 == 3){
		cul(input2, &resultx, &resulty, sx1[0],sx2[0]);
	}
	else if (input1 >= 4){		
		for (int i = 0;i<input1-4;i++){
			int resu = sx1[0] + sx1[1];
			sx1[0] = sx1[1];
			sx1[1] = resu;

			resu = sx2[0] + sx2[1];
			sx2[0] = sx1[1];
			sx2[1] = resu;
		}
		cul(input2, &resultx, &resulty, sx1[1], sx2[1]);

	}
	cout << resultx << " " << resulty << endl;
	return 0;
}