#include <cstdio>
#include <iostream>
#include <vector>
#include "bigInt.h"

using namespace std;

class Encrypt
{
public:

	int e;        //set to 19 as the global rule
	void read(char A[]);  //read from a file
	void encrypt(int P, int Q); //encryption with P and Q, print to standard out
	void decrypt(); //decrypt method, print to standard out
	void print();
protected:

	vector<char> message; //the message
	int pubKey; //Public key
	int priKey; //Private key
};

int main(int argc, char** argv)
{

	if (argc < 5)  // take your filename.csv, type, P, and Q
	{
		if (argc[1] = "help") {
			cerr << "Type encryption"
		}
		else
		{
			cerr << "Bad Useage: Encrypt_ filename E|D P Q" << endl << "Or type encryption help for more information." << endl;
		}
		exit(0);
	}
	int P, Q;
	char Type;

	Type = *argv[2];
	sscanf(argv[3], "%d", &P);
	sscanf(argv[4], "%d", &Q);

	Encrypt E;
	E.e = 19;
	E.read(argv[1]);  //read the CSV file
	if (Type == 'E')
	{
		printf("Encrypting...\n");
		E.encrypt(P, Q);  //encrpyt the message
	}
	else
	{
		printf("Decrypting...\n");
		E.decrypt();  //decrypt the message
	}
}


void Encrypt::read(char A[])
{
	printf("%s\n", A);
	return;
}

void Encrypt::encrypt(int P, int Q)
{
	printf("%d %d\n", P, Q);
	return;
}

void Encrypt::decrypt()
{
	return;
}