#pragma once
#include <iostream>
#include <string>
using namespace std;
class HashEntidad {
private:
	int key;
	string value;
public:
	HashEntidad(int key, string value) {
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	string getValue() { return value; }
};
