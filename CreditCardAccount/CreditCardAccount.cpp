#include "pch.h"
#include "CreditCardAccount.h"
#using<mscorlib.dll>

using namespace System;

void CreditCardAccount::SetCreditLimit(double amount) {
	creditLimit = amount;
}
bool CreditCardAccount::MakePurchase(double amount) {
	if (currentBalance + amount > creditLimit)
	{
		return false;
	}
	else
	{
		currentBalance += amount;

		if (currentBalance >= creditLimit / 2)
		{
			if (scheme == nullptr)
			{
				scheme = gcnew LoyaltyScheme();
			}
			else
			{
				scheme->EarnPointsOnAmount(amount);
			}
		}
		return true;
	}
}

void CreditCardAccount::RedeemLoyaltyPoints()
{
	if (scheme == nullptr)
	{
		Console::WriteLine("Sorry, you dot not havea "
			"loyalty scheme yet");
	}
	else
	{
		Console::Write("Pints available: ");
		Console::Write(scheme->GetPoints());
		Console::Write(". How many points do you want "
			" to redeem? ");

		String^ input = Console::ReadLine();
		int points = Convert::ToInt32(input);

		scheme->RedeemPoints(points);

		Console::Write("Points remaning : ");
		Console::Write(scheme->GetPoints());
	}
}

void CreditCardAccount::MakeRepayment(double amount) {
	currentBalance -= amount;
}
void CreditCardAccount::PrintStatement() {
	Console::Write("Current balance: ");
	Console::WriteLine(currentBalance);
}
long CreditCardAccount::GetAccountNumber() {
	return accountNumber;
}
CreditCardAccount::CreditCardAccount()
{
	accountNumber = 1234;
	currentBalance = 0.0;
	creditLimit = 3000;
}
CreditCardAccount::CreditCardAccount(long number, double limit)
{
	accountNumber = number;
	creditLimit = limit;
	currentBalance = 0.0;

	numberOfAccounts++;

	scheme = nullptr;

	Console::Write("This is account number ");
	Console::WriteLine(numberOfAccounts);
}
/*
CreditCardAccount::CreditCardAccount(long number, double limit)

	: accountNumber(number), creditLimit(limit), currentBalance(0.0)
{
}
*/
int CreditCardAccount::GetNumberOfAccounts()
{
	return numberOfAccounts;
}
static CreditCardAccount::CreditCardAccount()
{
	interestRate = 45;
	Console::WriteLine("Static constrcutor called");
}