#include "RabinCarp.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace System::Numerics;

RabinCarp::RabinCarp()
{
	d = 52;
}

int RabinCarp::simmilarity(System::String ^mainString, System::String ^substring)
{
	int mainStringLengh = mainString->Length;
	int substringLength = substring->Length;
	BigInteger calculatedConst = 0;

	BigInteger hashOfsubstring = getCircleHash(substring, substringLength, 0, &calculatedConst);
	BigInteger hashOfMainStringPiece = getCircleHash(mainString, substringLength, 0, &calculatedConst);

	for (int i = 0; i < mainStringLengh - substringLength; i++) {
		if (hashOfsubstring == hashOfMainStringPiece) {
			for (unsigned int j = 0; (j < substringLength) && (substring[j] == mainString[i + j]); j++) {
				if (j == (substringLength - 1)) {
					return i;
				}
			}
		}
		
		hashOfMainStringPiece = getCircleHash(mainString->Substring(i), substringLength, hashOfMainStringPiece, &calculatedConst);
	}
	return -1;
}

BigInteger RabinCarp::initConst(unsigned int strLength)
{

	BigInteger h = 1;
	for (unsigned int i = 1; i < strLength; i++) {
		h = (h * d) % simple;
	}

	return h;
}

System::Numerics::BigInteger RabinCarp::getCircleHash(System::String ^string, int stringLength, BigInteger prevHash, BigInteger* calculated)
{

	if (*calculated == (long long)0) {
		*calculated = initConst(stringLength);
	}

	if (prevHash == (long long)0) {
		BigInteger accomulator = 0;
		for (unsigned int i = 0; i < stringLength; i++) {
			//prevHash += (d * prevHash + (int)string[i]) % simple;
			
			BigInteger power = d.Pow(d, stringLength - (i + 1));
			accomulator = accomulator.Add(accomulator, (((int)string[i]) * power));
		}

		prevHash = accomulator % simple;

		if (prevHash < (long long)0) {
			prevHash = prevHash.Add(prevHash, simple);
		}

		return prevHash;
	}
	else {
		BigInteger minusPrev = (prevHash.Subtract(prevHash, (int)string[0] * *calculated)) * d;
		BigInteger hash = (minusPrev.Add(minusPrev, (int)string[stringLength])) % simple;
		//int hash = (d * (prevHash - (int)string[0] * (*calculated)) + (int)string[stringLength]) % simple;
		if (hash < (long long)0) {
			hash = hash.Add(hash, simple);
		}

		return hash;
	}
	return 1;
}
