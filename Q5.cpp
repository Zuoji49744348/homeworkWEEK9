#include <iostream>

using namespace std;

class HotDogStand {
private:
    int stand_ID;
    int sold;
    static int totalsold;
public:
    HotDogStand(int ID, int sold) : stand_ID(ID), sold(sold) {}
    void Just_Sold() { sold++; totalsold++; }
    int getSold() { return sold; };
    static int getTotalSold() { return totalsold; }
};

int HotDogStand::totalsold = 0;

int main() {
    HotDogStand stand1(1, 10);
    HotDogStand stand2(2, 15);
    HotDogStand stand3(3, 20);

    stand1.Just_Sold();
    stand2.Just_Sold();
    stand2.Just_Sold();
    stand3.Just_Sold();
    stand3.Just_Sold();
    stand3.Just_Sold();

    cout << "Hot Dogs Sold by Stand 1: " << stand1.getSold() << std::endl;
    cout << "Hot Dogs Sold by Stand 2: " << stand2.getSold() << std::endl;
    cout << "Hot Dogs Sold by Stand 3: " << stand3.getSold() << std::endl;
    cout << "Total Hot Dogs Sold by All Stands: " << HotDogStand::getTotalSold() << endl;

    return 0;
}