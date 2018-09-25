#include "stdafx.h"
#include "cmath"
#include <iostream>

using namespace std;
int originA, originB, originC, originD;
int originBits;
int netNum;

void printarray(int arg[], int length) {
	for (int n = 0; n < length; ++n)
		cout << arg[n] << ' ';
	cout << '\n';
}

unsigned int whole(int *originArray, int boolean, int magic) {
	unsigned int ip_long = (originArray[0] << 24) | (originArray[1] << 16) | (originArray[2] << 8) | originArray[3];
	if (boolean == 0){
		return ip_long;
	};
	if (boolean == 1){
		return ip_long + magic;
	};
}


void backToIp(int *newArray, int ipWhole){
	newArray[0] = (ipWhole >> 24) & 0xff;
	newArray[1] = (ipWhole >> 16) & 0xff;
	newArray[2] = (ipWhole >> 8) & 0xff;
	newArray[3] = ipWhole & 0xff;
	cout << "|" << newArray[0] << "." << newArray[1] << "." << newArray[2] << "." << newArray[3] << "|    ";
}

int main()
{
	cout << "Sláðu inn upphafsnet: ";
	cin >> originA >> originB >> originC >> originD;
	cout << "Fjöldi netbita í upphafsneti: ";
	cin >> originBits;
	cout << "Fjöldi neta sem á að skipta upphafsnetinu í: ";
	cin >> netNum;
	int originArray[4] = { originA, originB, originC, originD };
	int newArray[4];
	int bitNum = log2(netNum);
	int power = 32 - (originBits + bitNum);
	int magicNumber = pow(2, power);
	int magicNumber2 = magicNumber;
	int i = 0;
	unsigned int tempnet = 0xffffffff << (32 - (originBits + bitNum));
	cout << tempnet << endl;
	cout << "IP net        Fyrsta nothæfa       Síðasta nothæfa        brodcast         Maski" << endl;
	cout << "|---------------------------------------------------------------------------------|" << endl;
	backToIp(newArray, whole(originArray, 0, magicNumber2));
	backToIp(newArray, whole(originArray, 0, magicNumber2) + 1);
	backToIp(newArray, whole(originArray, 0, magicNumber2) + magicNumber - 2);
	backToIp(newArray, whole(originArray, 0, magicNumber2) + magicNumber - 1);
	backToIp(newArray, tempnet);
	cout << endl;

	for (i; i < netNum - 1; i++){
		backToIp(newArray, whole(originArray, 1, magicNumber2));
		backToIp(newArray, whole(originArray, 1, magicNumber2) + 1);
		backToIp(newArray, whole(originArray, 1, magicNumber2) + magicNumber - 2);
		backToIp(newArray, whole(originArray, 1, magicNumber2) + magicNumber - 1);
		backToIp(newArray, tempnet);
		cout << endl;
		magicNumber2 += magicNumber;
	}

	return 0;
}

