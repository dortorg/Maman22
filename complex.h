/*
 * complex.h
 *
 *  Created on: May 24, 2017
 *      Author: Dor
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct complex
{
	int sign;
	double imaginary;
	double real;
}complex;

/*errors*/
#define MISSING_HALT "Missing halt in the end of the file"


/*char* errors[] = {"Invalid complex variable", "Invalid command", "Missing comma", "Wrong parameter"};*/

#endif /* COMPLEX_H_ */

