#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "bigInt.h"

using namespace std;

class Encrypt{
public:
	vector<int> message; //the message
	int e;        //set to 19 as the global rule -Tom we have it set to read in public key from inline parameters
	void read(string fileName);  //read from a file
	void encrypt(int P, int Q); //encryption with P and Q, print to standard out
	void decrypt(); //decrypt method, print to standard out
	void printMessage();
protected:
	int pubKey; //Public key
	int priKey; //Private key
};