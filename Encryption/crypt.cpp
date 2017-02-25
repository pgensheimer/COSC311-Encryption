#include "crypt.h"

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
			message.push_back(stoi(pass));
		}
	}
}

void Encrypt::encrypt(int P, int Q) {
	//printf("%d %d\n", P, Q);

}

void Encrypt::decrypt() {

}

void Encrypt::printMessage() {
	for (int i = 0; i < message.size(); ++i)
		cout << message[i] << " ";
}