#pragma once
public ref class RabinCarp
{
public:
	RabinCarp();

	int simmilarity(System::String ^mainString, System::String ^substring);
	//just a simle digit
	int simple = 65713;
	//digit < simple
	int d = 52;
private:
	int initConst(unsigned int strLength);

	//Algorithm suggested by Rabin and Karp 
	int getCircleHash(System::String ^string, int stringLength, int prevHash, int *calculated);
};

