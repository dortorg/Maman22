/*
 * =========================================================================================
 * name        : mmn_22/main.c
 * author      : Ariel Mashraki, ID 301......
 * email       : ariel@.....
 * description : description....
 * =========================================================================================
 */

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
extern void mult_comp_real(complex *cp, double scalar);

/*multiple complex number with img number scalar
 *argument and print the result*/
extern void mult_comp_img(complex *cp, double scalar);

/*multiple complex number with complex number
 *argument and print the result*/
extern void mult_comp_comp(complex *cpA, complex *cpB);


/*return the absolute value of complex number*/
extern void abs_comp(complex *cp);

static const struct
{
	void (*abs_comp)(complex *cp);
	void (*mult_comp_comp)(complex *cpA, complex *cpB);
	void (*mult_comp_img)(complex *cp, double scalar);
	void (*mult_comp_real)(complex *cp, double scalar);
	void (*sub_comp)(complex *cpA, complex *cpB);
	void (*add_comp)(complex *cpA, complex *cpB);
	void (*print_comp)(complex *cp);

}COMPLEX = {
		abs_comp,
		mult_comp_comp,
		mult_comp_img,
		mult_comp_real,
		sub_comp,
		add_comp,
		print_comp
};


#endif /* complex_H_ */
