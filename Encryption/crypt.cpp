#include "crypt.h"

Encrypt::Encrypt(void) {
	//we need to create all of the key information when the class is constructed
	p = 3;
	q = 7;
	modulus = p*q;
	totient = (p - 1)*(q - 1);
	//we need code here to get the private key
	// public key * private key = 1 mod totient like the example
	priKey= gcd(pubKey, totient);
}

int Encrypt::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void Encrypt::read(string fileName) {
	ifstream csvFile;
	csvFile.open(fileName.c_str());

	//validate if the file exists
	while (!csvFile.is_open()) {
		cout << "Problem with file name. Please check that the file exists and re-enter file name: " << endl;
		getline(cin, fileName);
		csvFile.open(fileName.c_str());
	}

	string x;
	//read data into vector
	while (getline(csvFile, x)) {
		stringstream ss(x);
		string pass;
		while (getline(ss, pass, ',')) {
			fromFile.push_back(stoi(pass));
		}
	}
}

void Encrypt::encrypt() {
	for (int i = 0; i < fromFile.size(); ++i) 
		encryptedMessage.push_back((fromFile[i] ^ pubKey) % modulus);
}

void Encrypt::decrypt() {
	for (int i = 0; i < fromFile.size(); ++i)
		decryptedMessage.push_back((fromFile[i] ^ priKey) % modulus);
}

void Encrypt::printFileMessage() {
	for (int i = 0; i < fromFile.size(); ++i)
		cout << fromFile[i] << " ";
}

void Encrypt::printEncryptedMessage() {
	for (int i = 0; i < encryptedMessage.size(); ++i)
		cout << encryptedMessage[i] << " ";
}

void Encrypt::printDecryptedMessage() {
	for (int i = 0; i < decryptedMessage.size(); ++i)
		cout << decryptedMessage[i] << " ";
}