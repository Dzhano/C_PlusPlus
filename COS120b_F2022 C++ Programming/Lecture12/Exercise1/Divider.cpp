#include "Divider.h"

Divider::Divider(int n, int d) {
	numerator = n;
	if (d != 0) denominator = d;
	else denominator = 1;
}

double Divider::result() {
	return numerator / denominator;
}