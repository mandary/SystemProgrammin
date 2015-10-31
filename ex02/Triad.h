
#ifndef TRIAD_H_
#define TRIAD_H_

//function to find min and max
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))
#define max(X, Y)  ((X) > (Y) ? (X) : (Y))

//Triad data struct
typedef struct Triad{
	int first;
	int second;
	int third;
}Triad;

//Takes 2 triads and return T/F if they 
//are equal
int triad_equal(Triad x, Triad y);

//Takes a triad and sort its component
//and then return it
Triad triad_sort(Triad x);


#endif // TRIAD_H_