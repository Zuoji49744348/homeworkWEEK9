#include <iostream>
#include <string>

using namespace std;

class Pizza {
private:
    int type_size[2]; // Array to store the selected pizza type and size by the user
    string type[3] = { "deep_dish","hand_tossed","pan" }; // Array to store the strings representing pizza types
    string size[3] = { "small","mediun","large" }; // Array to store the strings representing pizza sizes
    int numToppings; // Integer variable to store the number of toppings
public:
    void input(); // Function to receive user input for pizza type, size, and toppings
    int computePrice(); // Function to compute the price of the pizza based on its size and toppings
    void outputDescription(); // Function to output the description of the pizza including type, size, toppings, and price
};

int main()
{
    Pizza s1; // Create an object of class Pizza
    s1.input(); // Call the input() function to receive user input
    s1.outputDescription(); // Output the description of the pizza
    return 0;
}

void Pizza::input()
{
    cout << "Please input your pizza type(if deep dish enter 1,hand_tossed enter2 ,pan enter 3)" << endl; // Prompt the user to input the pizza type
    cin >> type_size[0]; // Receive the user input for pizza type and store it in the first element of the array
    cout << "Please input your pizza size(if small enter 1,mediun enter 2 ,large enter 3)" << endl; // Prompt the user to input the pizza size
    cin >> type_size[1]; // Receive the user input for pizza size and store it in the second element of the array
    cout << "Please input the number of pepperoni or cheese toppings" << endl; // Prompt the user to input the number of toppings
    cin >> numToppings; // Receive the user input for the number of toppings
}

int Pizza::computePrice()
{
    // Compute the price of the pizza based on its size and toppings
    if (type_size[1] == 1) // If the pizza size is small
    {
        return (10 + 2 * numToppings); // Return the price of the pizza (Small pizza price is $10 plus $2 per topping)
    }
    else if (type_size[1] == 2) // If the pizza size is medium
    {
        return (14 + 2 * numToppings); // Return the price of the pizza (Medium pizza price is $14 plus $2 per topping)
    }
    else if (type_size[1] == 3) // If the pizza size is large
    {
        return (17 + 2 * numToppings); // Return the price of the pizza (Large pizza price is $17 plus $2 per topping)
    }
}

void Pizza::outputDescription()
{
    // Output the description of the pizza including type, size, toppings, and price
    cout << "The pizza's type is " << type[type_size[0]] << "." << endl; // Output the pizza type
    cout << "The pizza's size is " << size[type_size[1]] << "." << endl; // Output the pizza size
    cout << "The pizza have " << numToppings << " toppings on it" << endl; // Output the number of toppings on the pizza
    cout << "The pizza's price is " << computePrice() << " dollars." << endl; // Output the price of the pizza
}
