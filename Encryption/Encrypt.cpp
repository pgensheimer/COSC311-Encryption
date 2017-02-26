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
	char Type;
	string fileName;

	Type = *argv[2];
	fileName = argv[1];

	Encrypt E;
	E.pubKey= atoi(argv[3]); //get the parameter to encrypt or decrypt
	E.read(fileName);  //read the CSV file
	cout << "Private key for testing " << E.priKey << endl;
	cout << "Public key for testing " << E.pubKey << endl;
	

	if (Type == 'E') {
		cout << "Encrypting the following message..." << endl;
		E.printASCIIMessage(E.fromFile);
		E.encrypt();  //encrpyt the message
		E.printDecMessage(E.encryptedMessage);
		E.saveMessageToFile(E.encryptedMessage);
	}
	if (Type =='D') {
		cout << "Decrypting the following code..." << endl;
		E.printDecMessage(E.fromFile);
		E.decrypt();  //decrypt the message
		E.printDecMessage(E.decryptedMessage);
		E.printASCIIMessage(E.decryptedMessage);
	}
}