#include "pch.h"

using namespace System;

ref class Animal
{
public:
	int legs;

	void SetName(String^ nm)
	{
		name = nm;
	}
	String^ GetName() { return name; }
private:
	String^ name;
};

int main(array<System::String^>^ args)
{
	Animal cat, dog;
	cat.SetName("Cat");
	cat.legs = 4;
	dog.SetName("Dog");
	dog.legs = 4;

	Console::WriteLine("Animal  1 - name: {0}, legs: {1}", cat.GetName(), cat.legs);
	Console::WriteLine("Animal  2 - name: {0}, legs: {1}", dog.GetName(), dog.legs);
	Console::WriteLine();
	return 0;
}
