#ifndef complex_H_
#define complex_H_

/*#define ....*/

typedef struct complex{
    double real, img;
} complex;

/*extern global variables*/
extern complex a,b,c,d,e,f;

/* >>>>>>>>>>>>>>>>>>>>>>>>> FUNCTION DECLARTION >>>>>>>>>>>>>>>>>>>>>>>>> */

/*
 *set complex variable with
 *params: pointer to complex, double a, double b
 */
extern void read_comp(complex *cp, double a, double b);

/*
 *print complex variable
 *params: pointer to complex
 *example: (a+bi) ===> 2.31 + 4.05i
 */
extern void print_comp(complex *cp);

/*add two complex numbers
 *and print the sum of them
 */
extern void add_comp(complex *cpA, complex *cpB);

/*subtract two complex numbers
 *and print the sum of them
 */
extern void sub_comp(complex *cpA, complex *cpB);

/*multiple complex number with real number scalar
 *argument and print the result*/
extern void mult_comp_real(complex *cp, double real);

/*multiple complex number with img number scalar
 *argument and print the result*/
extern void mult_comp_img(complex *cp, double img);

/*multiple complex number with complex number
 *argument and print the result*/
extern void mult_comp_comp(complex *cpA, complex *cpB);


/*return the absolute value of complex number*/
extern void abs_comp(complex *cp);


#endif /* complex_H_ */
