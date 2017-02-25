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
	Encrypt();
	vector<int> fromFile; //the message
	vector<int> decryptedMessage;
	vector<int> encryptedMessage;
	int e;        //set to 19 as the global rule -Tom we have it set to read in public key from inline parameters
	void read(string fileName);  //read from a file
	void encrypt(); //encryption with P and Q, print to standard out
	void decrypt(); //decrypt method, print to standard out
	void printFileMessage();
	void printEncryptedMessage();
	void printDecryptedMessage();
protected:
	int pubKey; //Public key
	int priKey; //Private key
private:
	int p, q; // we need to set these here to our two three digit primes
	int modulus;
	int totient;
	int gcd(int a, int b); // with help from http://codereview.stackexchange.com/questions/66711/greatest-common-divisor
};