#pragma once
public ref class RabinCarp
{
public:
	RabinCarp();

	int simmilarity(System::String ^mainString, System::String ^substring);
	//just a simle digit
	int simple = 65713;
	//digit < simple
	System::Numerics::BigInteger d;
private:
	System::Numerics::BigInteger initConst(unsigned int strLength);

	//Algorithm suggested by Rabin and Karp 
	System::Numerics::BigInteger getCircleHash(System::String ^string, int stringLength, System::Numerics::BigInteger prevHash, System::Numerics::BigInteger* calculated);
};

