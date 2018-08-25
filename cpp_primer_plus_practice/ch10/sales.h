#ifndef __SALES_H__
#define __SALES_H__

namespace SALES {
	const int QUARTERS = 4;
	class Sales {
		private:
			double sales[QUARTERS];
			double average;
			double max;
			double min;

		public:
			Sales();

			Sales(const double arr[], int n);

			void init();

			void setSales(const double *, int);

			void show();

	};
} // namespace SALES
#endif
