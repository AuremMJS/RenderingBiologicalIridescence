#include "MathHelper.h"



MathHelper::MathHelper()
{
}


MathHelper::~MathHelper()
{
}

double MathHelper::IntegrateValues(std::vector<double> values)
{
	// Using trapezoidal rule
	int n = values.size();
	if (n <= 1)
		return 0.0;

	double del = 1;
	double sum = values[0];
	for (int i = 1; i < n - 1; i++)
	{
		sum += 0.5*values[i];
	}
	sum += values[n - 1];
	return sum;
}

//
//int n = values.size();
//if (n <= 1)
//return 0.0;
//
//double del = (values[n - 1] - values[0]) / n;
//if (del < 0)
//	del = -del;
//double sum = 0, sum2 = 0;
//if (values[0] > 0)
//sum = values[0];
//else
//sum2 = -values[0];
//
//for (int i = 1; i < n - 1; i++)
//{
//	if (values[i] > 0)
//		sum += 2 * values[i];
//	else
//		sum2 -= 2 * values[i];
//}
//if (values[n - 1] > 0)
//sum += values[n - 1];
//else
//sum2 -= values[n - 1];
//return ((del / 2.0) * (sum + sum2));