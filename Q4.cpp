#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

class BoxOFProduce
{
private:
    string box_bundles[3]; // Array to store the bundles of produce in the box
public:
    string getbundle(); // Function to get a random bundle of produce from a file
    void input_bundle(int index, const string bundle); // Function to input a bundle into the box
    void print_box(); // Function to print the contents of the box
    void switch_bundle(int index); // Function to allow the user to switch a bundle in the box
};

int main()
{
    srand(time(NULL)); // Seed the random number generator

    BoxOFProduce box; // Create an instance of the BoxOFProduce class

    // Input three random bundles into the box
    for (int j = 0; j < 3; j++)
    {
        box.input_bundle(j, box.getbundle());
    }

    // Print the contents of the box
    box.print_box();

    // Allow the user to switch a bundle in the box
    for (int j = 0; j < 3; j++)
    {
        box.switch_bundle(j);
    }
}

// Function to print the contents of the box
void BoxOFProduce::print_box()
{
    cout << "Box Contents: ";
    for (int i = 0; i < 3; i++)
    {
        cout << box_bundles[i] << " ";
    }
    cout << endl;
}

// Function to get a random bundle of produce from a file
string BoxOFProduce::getbundle()
{
    ifstream inputfile("input.txt");
    if (inputfile.is_open())
    {
        string item;
        int random = rand() % 6 + 1; // Generate a random number between 1 and 6
        int count = 0;
        do {
            getline(inputfile, item); // Read a line from the file
            count++;
        } while (count <= random); // Repeat until we reach the random line
        return item; // Return the random bundle
    }
}

// Function to allow the user to switch a bundle in the box
void BoxOFProduce::switch_bundle(int index)
{
    int will;
    cout << "Do you want to substitute the bundle at index " << index << " (0 for yes, 1 for no)?" << endl;
    cin >> will;
    if (will == 0)
    {
        int choice;
        cout << "You can substitute your fruit or vegetable with (1: Broccoli, 2: Tomato, 3: Kiwi, 4: Kale, 5: Tomatillo)" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            box_bundles[index] = "Broccoli";
            break;
        case 2:
            box_bundles[index] = "Tomato";
            break;
        case 3:
            box_bundles[index] = "Kiwi";
            break;
        case 4:
            box_bundles[index] = "Kale";
            break;
        case 5:
            box_bundles[index] = "Tomatillo";
            break;
        }
    }
}
