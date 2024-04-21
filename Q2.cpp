#include<iostream>
using namespace std;

class Money
{
private:
	int dollars; // variable to store dollars
	int cents; // variable to store cents
public:
	void input(); // function to input dollars and cents from the user
	double compute(); // function to compute the total monetary amount
	void print(); // function to print the total monetary amount
};

int main()
{
	Money s1, s2; // create two Money objects
	s1.input(); // input dollars and cents for the first object
	s1.print(); // print the total monetary amount for the first object
	s2.input(); // input dollars and cents for the second object
	s2.print(); // print the total monetary amount for the second object
	return 0;
}

void Money::input()
{
	cout << "Please input how many dollars and cents you have." << endl; // prompt the user to input dollars and cents
	cout << "dollars:"; cin >> dollars; // input dollars
	cout << endl << "cents"; cin >> cents; // input cents
}

double Money::compute()
{
	double total = 0; // variable to store the total monetary amount
	if (cents >= 100) // if cents is greater than or equal to 100
	{
		dollars += cents / 100; // add the quotient of cents divided by 100 to dollars
		cents = cents % 100; // update cents to the remainder of cents divided by 100
		total = dollars + ((double)cents * 0.01); // calculate the total monetary amount
		return total; // return the total monetary amount
	}
	total = dollars + ((double)cents * 0.01); // calculate the total monetary amount
	return total; // return the total monetary amount
}

void Money::print()
{
	cout << "Money amonut" << compute() << endl; // print the total monetary amount
}
