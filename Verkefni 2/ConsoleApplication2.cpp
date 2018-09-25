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
unsigned int whole(int *originArray) {
	unsigned int ip_long = (originArray[0] << 24) | (originArray[1] << 16) | (originArray[2] << 8) | originArray[3];
	return ip_long;
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

	double bitNum = log2(netNum);
	int power = 32 - (originBits + bitNum);
	int magicNumber = pow(2, power);
	cout << print_ip(3232235776);
    return 0;
}

