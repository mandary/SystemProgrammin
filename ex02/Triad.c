#include "Triad.h"

//Yufang Sun
//1334960
//mandary@uw.edu

//Takes 2 triads and return T/F if they are equal
int triad_equal(Triad x, Triad y) {
	return x.first == y.first && x.second == y.second && x.third == y.third;
}

//Takes a triad and sort its component
//and then return it
Triad triad_sort(Triad x) {
	//find the maximum and minimum
	int max = max(max(x.first, x.second), x.third);
	int min = min(min(x.first, x.second), x.third);
	//find the middle number
	if (x.first > min && x.first < max) {
		x.second = x.first;
	} else if (x.third > min && x.third < max) {
		x.second = x.third;
	} 
	x.first = min;
	x.third = max;
	return x;
}
