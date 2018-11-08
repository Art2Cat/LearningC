#include "sales.h"
#include <iostream>

namespace SALES {

	using namespace std;

	Sales::Sales() {
		for (int i = 0; i < QUARTERS; i++) {
			sales[i] = 0.0;
		}
		average = 0.0;
		max = 0.0;
		min = 0.0;
	}

	Sales::Sales(const double arr[], int n) {
		setSales(arr, n);
	}

	void Sales::init() {
		int idx = 1;
		double *tmp = new double [QUARTERS];
		cout << "Enter sales:" << endl;
		for (int i = 0; i < QUARTERS; i++) {
			cout << "sales[" << i << "]: ";

			cin >> tmp[i];
			idx++;
			if (cin.fail()) {
				tmp[i] = 0.0;
				break;
			}
		}

		setSales(tmp, idx - 1);
		delete [] tmp;
	}

	void Sales::setSales(const double * arr, int n) {
		auto total = 0.0;
		max = arr[0];
		min = arr[0];
		for (int i = 0; i < n ; i++) {
			total += arr[i];
			if (max < arr[i]) {
				max = arr[i];
			}
			if (min > arr[i]) {
				min = arr[i];
			}
			sales[i] = arr[i];
		}
		average = total / n;
	}

	void Sales::show() {
		cout << "Sales: { sales [";
		for (int i = 0; i < QUARTERS; i++) {
			cout << this->sales[i] << ",";
		}
		cout << "], average: " <<this->average << ", max: " << this->max
			<< ", min: " << this->min << "}." << endl;
	}
}  // namespace SALES
