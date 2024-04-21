#include<iostream>
using namespace std;

class Weight
{
private:
	double Weight; // variable to store weight
public:
	double setWeightPounds(double n) // function to set weight in pounds
	{
		Weight = n; // assign input weight to the member variable
		return n; // return the input weight
	}

	double setWeightKilograms(double n) // function to set weight in kilograms
	{
		Weight = n / 2.21; // convert input weight to pounds and assign to the member variable
		return (n / 2.21); // return the input weight in pounds
	}

	double setWeightOunces(double n) // function to set weight in ounces
	{
		Weight = n * 16; // convert input weight to pounds and assign to the member variable
		return (n * 16); // return the input weight in pounds
	}
};

int main()
{
	Weight s1; // create an object of class Weight
	int scale; // variable to store the chosen scale
	double weight; // variable to store the weight

	// Prompt the user to input the scale
	cout << "Input your scale (pound=1, kilograms=2, ounce=3): ";
	cin >> scale;
	cout << endl;

	// Prompt the user to input the weight in the specified scale
	cout << "Input the number in the specified scale: ";
	cin >> weight;
	cout << endl;

	// Determine the chosen scale and display the weight in pounds accordingly
	if (scale == 1)
	{
		cout << "It's: " << s1.setWeightPounds(weight) << " pounds" << endl;
	}
	else if (scale == 2)
	{
		cout << "It's: " << s1.setWeightKilograms(weight) << " pounds" << endl;
	}
	else if (scale == 3)
	{
		cout << "It's: " << s1.setWeightOunces(weight) << " pounds" << endl;
	}
	return 0;
}
