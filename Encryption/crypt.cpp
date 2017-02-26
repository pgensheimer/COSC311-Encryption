#include "crypt.h"

Encrypt::Encrypt(void) {
	//we need to create all of the key information when the class is constructed
	//using 3 and 7 for testing right now
	p = 3;
	q = 7;
	modulus = p*q;
	totient = (p - 1)*(q - 1);
	//we need code here to get the private key
	// public key * private key = 1 mod totient like the example
	priKey = gcd(pubKey, totient);
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
	unsigned long long int calc = 0;
	for (int i = 0; i < fromFile.size(); ++i) {
		calc = pow(fromFile[i], pubKey);
		encryptedMessage.push_back(calc % modulus);
	}

}

void Encrypt::decrypt() {
	unsigned long long int calc = 0;
	for (int i = 0; i < fromFile.size(); ++i) {
		calc = pow(fromFile[i], priKey);
		decryptedMessage.push_back(calc % modulus);
	}

}

void Encrypt::printFileMessage() {
	for (int i = 0; i < fromFile.size(); ++i)
		cout << fromFile[i] << " ";
}

void Encrypt::printEncryptedMessage() {
	for (int i = 0; i < encryptedMessage.size(); ++i)
		cout << encryptedMessage[i] << " ";
	cout << endl;
	saveMessageToFile(encryptedMessage);
}

void Encrypt::printDecryptedMessage() {
	for (int i = 0; i < decryptedMessage.size(); ++i)
		cout << decryptedMessage[i] << " ";
	cout << endl;
	asciiMessage(decryptedMessage);
	//saveMessageToFile(decryptedMessage);
}

void Encrypt::saveMessageToFile(vector<int> saveMessage) {
	ofstream out;
	string filename;

	do{
		cout << "What file would you like to save to?" << endl;
		//cin.ignore();
		getline(cin, filename);
		out.open(filename.c_str());
	}while(!out.is_open());

	for (int i = 0; i < saveMessage.size(); ++i) {
		if (i == saveMessage.size() - 1)
			out << saveMessage[i];
		else
			out << saveMessage[i] << ",";

	}

	out.close();
}

void Encrypt::asciiMessage(vector<int> translateMessage) {
	for (int i = 0; i < translateMessage.size(); ++i)
		cout << (char)translateMessage[i];
	cout << endl;
}