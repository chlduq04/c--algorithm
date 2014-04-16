#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
	int input[4] = {0,};
	char result[5] = {'E','A','B','C','D'};
	int check = 0;
	for (int i = 0;i<3;i++){
		check = 0;
		cin >> input[0] >> input[1] >> input[2] >> input[3];
		for (int j = 0;j<4;j++){
			if (input[j] == 0){
				check++;
			}
		}
		cout << result[check] << endl;
	}
	return 0;
}