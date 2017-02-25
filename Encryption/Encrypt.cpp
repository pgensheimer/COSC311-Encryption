#include <cstdio>
#include <iostream>
#include <vector>
#include "crypt.h"
#include <fstream> // open files

using namespace std;

int main(int argc, char** argv)
{

	if (argc < 5)  // take your filename.csv, action and public key
	{
		cout << "Useage:encryption filename E|D K" << endl;
		cout << "filename: This is a comma delimited file with the message in integers" << endl;
		cout << "E: Action to be performed:" << endl;
		cout << "	E - This will encrypt the file" << endl;
		cout << "	D - This will decrypt the file" << endl;
		cout << "K: Public key to be entered" << endl;
		exit(0);
	}

	int P, Q, public_key;
	char Type;
	string fileName;
	ifstream cvsFile;

	Type = *argv[2];
	//sscanf(argv[3], "%d", &P);
	public_key = atoi(argv[3]);


	Encrypt E;
	E.e = public_key;
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