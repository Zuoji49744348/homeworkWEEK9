#include<iostream>
using namespace std;

class ZipCode {
public:
	ZipCode(int code) : zipcode(code) {
		TransferToBarCode();
	}
	ZipCode(const string bar) : BarCode(bar) {
		TransferToZipCode();
	}
	ZipCode() {}
	int getZipCode() const {
		return zipcode;
	}
	string getBarCode() const { return BarCode; }
private:
	string BarCode;
	int zipcode;
	//zip code -> bar code
	void TransferToBarCode() {
		BarCode = "1";
		int value[5] = { 7,4,2,1,0 };
		int temp;
		for (int j = 4; j >= 0; j--) {
			temp = int(zipcode / pow(10, j)) % 10;//digit of zip code
			if (temp == 0) {
				BarCode = BarCode + "11000";
			}
			else {
				int count = 0;//number of '1'
				for (int i = 0; i < 5; i++) {
					if (temp >= value[i] && count < 2) {
						BarCode = BarCode + "1";
						temp = temp - value[i];
						count++;
					}
					else {
						BarCode = BarCode + "0";
					}
				}
			}
		}
		BarCode = BarCode + "1";
	}
	//bar code -> zip code
	void TransferToZipCode() {
		zipcode = 0;
		int value[5] = { 7,4,2,1,0 };
		for (int i = 0; i < 5; i++) {
			int temp = 0;
			for (int j = 0; j < 5; j++) {
				if (BarCode[i * 5 + j + 1] == '1') {
					temp += value[j];
				}
			}
			if (temp == 11) {
				temp = 0;
			}
			zipcode += (temp * pow(10, 4 - i));
		}
	}
};

int main(void) {
	ZipCode zip1("110100101000101011000010011");
	ZipCode zip2(99504);

	cout << "Zip 1:" << endl
		<< "Zip code: " << zip1.getZipCode() << endl
		<< "Bar code: " << zip1.getBarCode() << endl;
	cout << "Zip 2:" << endl
		<< "Zip code: " << zip2.getZipCode() << endl
		<< "Bar code: " << zip2.getBarCode() << endl;

	return 0;
}