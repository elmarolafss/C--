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

int print_ip(int ip)
{
	unsigned char bytes[4];
	bytes[0] = ip & 0xFF;
	bytes[1] = (ip >> 8) & 0xFF;
	bytes[2] = (ip >> 16) & 0xFF;
	bytes[3] = (ip >> 24) & 0xFF;
	printf("%d.%d.%d.%d\n", bytes[3], bytes[2], bytes[1], bytes[0]);
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

