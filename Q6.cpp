#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	int histogram[11] = { 0 };//histogram initialize
	vector<int> grades;
	cout << "Enter score(0 to 10, enter -1 to quit):" << endl;
	int score;

	while (true) {
		cin >> score;
		//stop when user entered -1
		if (score == -1) {
			break;
		}
		//check range
		if (score < 0 || score>10) {
			cout << "Out of range." << endl;
			continue;
		}
		grades.push_back(score);
	}
	//count and record in histogram
	for (int i = 0; i < grades.size(); i++) {
		histogram[grades[i]]++;
	}
	//outpot histogram
	for (int i = 0; i <= 10; i++) {
		cout << histogram[i] << " grade(s) of " << i << endl;
	}

	return 0;
}