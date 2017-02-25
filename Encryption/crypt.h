#pragma once
#include <iostream>
using namespace std;

class Encrypt
{
public:

	int e;        //set to 19 as the global rule -Tom we have it set to read in public key from inline parameters
	void read(char A[]);  //read from a file
	void encrypt(int P, int Q); //encryption with P and Q, print to standard out
	void decrypt(); //decrypt method, print to standard out
	void print();
protected:

	vector<int> message; //the message
	int pubKey; //Public key
	int priKey; //Private key
};

