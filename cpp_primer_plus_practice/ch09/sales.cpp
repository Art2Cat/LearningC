#include "sales.h"
#include <iostream>

using namespace std;
namespace SALES {

	void setSales(Sales &s, const double arr[], int n) {
		double total = 0.0;
		double max = arr[0];
		double min = arr[0];
		for (int i = 0; i < n; i++) {
			total += arr[i];
			s.sales[i] = arr[i];
			if (max < arr[i]) {
				max = arr[i];
			}
			if (min > arr[i]) {
				min = arr[i];
			}
		}
		s.average = total / n;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales &s) {
		int n = 1;
		cout << "Enter sales:" << endl;
		for (int i = 0; i < QUARTERS; i++) {
			cout << "sales[" << i << "]: ";

			cin >> s.sales[i];
			n++;
			if (cin.fail()) {
				s.sales[i] = 0.0;
				break;
			}
		}

		double total = 0.0;
		double max = s.sales[0];
		double min = s.sales[0];

		for (int i = 0; i < n - 1; i++) {
			total += s.sales[i];
			if (max < s.sales[i]) {
				max = s.sales[i];
			}
			if (min > s.sales[i]) {
				min = s.sales[i];
			}
		}
		s.average = total / n;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales &s) {
		cout << "Sales: { sales [";
		for (int i = 0; i < QUARTERS; i++) {
			cout << s.sales[i] << ",";
		}
		cout << "], average: " << s.average << ", max: " << s.max
			<< ", min: " << s.min << "}." << endl;
	}
}  // namespace SALES
