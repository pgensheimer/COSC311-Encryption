#include <cstdio>
#include <iostream>
#include <string>
#include "crypt.h"


using namespace std;

int main(int argc, char** argv)
{

	if (argc < 4)  // take your filename.csv, action and public key
	{
		cout << "Useage:encryption filename E|D K" << endl;
		cout << "filename: This is a comma delimited file with the message in integers" << endl;
		cout << "E: Action to be performed:" << endl;
		cout << "	E - This will encrypt the file" << endl;
		cout << "	D - This will decrypt the file" << endl;
		cout << "K: Public key to be entered" << endl;
		exit(0);
	}

	int P = 1, Q = 1;
	char Type;
	string fileName;

	Type = *argv[2];
	fileName = argv[1];

	Encrypt E;
	E.e = atoi(argv[3]);
	E.read(fileName);  //read the CSV file
	
	E.printMessage();

	if (Type == 'E') {
		cout << "Encrypting..." << endl;
		E.encrypt(P, Q);  //encrpyt the message
	}
	else {
		cout << "Decrypting..." << endl;
		E.decrypt();  //decrypt the message
	}
}