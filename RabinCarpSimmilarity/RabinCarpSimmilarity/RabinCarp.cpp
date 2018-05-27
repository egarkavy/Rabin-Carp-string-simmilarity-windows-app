#include "RabinCarp.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

RabinCarp::RabinCarp()
{
	
}

int RabinCarp::simmilarity(System::String ^mainString, System::String ^substring)
{
	int mainStringLengh = mainString->Length;
	int substringLength = substring->Length;
	int calculatedConst = 0;

	int hashOfsubstring = getCircleHash(substring, substringLength, 0, &calculatedConst);
	int hashOfMainStringPiece = getCircleHash(mainString, substringLength, 0, &calculatedConst);

	for (int i = 0; i < mainStringLengh - substringLength; i++) {
		if (hashOfsubstring == hashOfMainStringPiece) {
			for (unsigned int j = 0; (j < substringLength) && (substring[j] == mainString[i + j]); j++) {
				if (j == (substringLength - 1)) {
					return i;
				}
			}
		}
		hashOfMainStringPiece = getCircleHash(mainString[i].ToString(), substringLength, hashOfMainStringPiece, &calculatedConst);
	}
	return -1;
}

int RabinCarp::initConst(unsigned int strLength)
{

	int h = 1;
	for (unsigned int i = 1; i < strLength; i++) {
		h = (h * d) % simple;
	}

	return h;
}

int RabinCarp::getCircleHash(System::String ^string, int stringLength, int prevHash, int * calculated)
{

	if (*calculated == 0) {
		*calculated = initConst(stringLength);
	}

	if (prevHash == 0) {
		int accomulator = 0;
		for (unsigned int i = 0; i < stringLength; i++) {
			//prevHash += (d * prevHash + (int)string[i]) % simple;
			accomulator += ((int)string[i]) * pow(d, stringLength - (i + 1));
		}

		prevHash = accomulator % simple;

		if (prevHash < 0) {
			prevHash += simple;
		}

		return prevHash;
	}
	else {

		int hash = ((prevHash - (int)string[0] * *calculated) * d + (int)string[stringLength]) % simple;
		//int hash = (d * (prevHash - (int)string[0] * (*calculated)) + (int)string[stringLength]) % simple;
		if (hash < 0) {
			hash += simple;
		}

		return hash;
	}
	return 1;
}
