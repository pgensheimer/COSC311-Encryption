#include "crypt.h"

Encrypt::Encrypt(void) {
	//we need to create all of the key information when the class is constructed
	//using 3 and 7 for testing right now
	p = 313;
	q = 733;
	modulus = p*q;
	totient = (p - 1)*(q - 1);
	//we need code here to get the private key
	// public key * private key = 1 mod totient like the example
	priKey = gcdExtended(pubKey, totient, &x, &y);
}

// C function for extended Euclidean Algorithm
//http://www.geeksforgeeks.org/basic-and-extended-euclidean-algorithms/
int Encrypt::gcdExtended(int a, int b, int *x, int *y)
{
	// Base Case
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b%a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
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

void Encrypt::printDecMessage(vector<int> passedMessage) {
	for (int i = 0; i < passedMessage.size(); ++i)
		cout << passedMessage[i] << " ";
	cout << endl;
}

void Encrypt::printASCIIMessage(vector<int> passedMessage) {
	for (int i = 0; i < passedMessage.size(); ++i)
		cout << (char)passedMessage[i];
	cout << endl;
}

void Encrypt::saveMessageToFile(vector<int> saveMessage) {
	ofstream out;
	string filename;

	do {
		cout << "What file would you like to save to?" << endl;
		//cin.ignore();
		getline(cin, filename);
		out.open(filename.c_str());
	} while (!out.is_open());

	for (int i = 0; i < saveMessage.size(); ++i) {
		if (i == saveMessage.size() - 1)
			out << saveMessage[i];
		else
			out << saveMessage[i] << ",";
	}
	out.close();
}