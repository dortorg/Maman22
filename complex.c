

#include "complex.h"

/*all functions in header file*/

void read_comp(complex *cp, double real, double img)
{
    (*cp).real = real;
    (*cp).img = img;
}


/* add complex number name to*/
void print_comp(complex *cp)
{
    printf("SYSTEM: Print complex Number : ");
    printf("%.2f + %.2fi\n", (*cp).real, (*cp).img);
}

/*calculate the sum between two complex numbers*/
void add_comp(complex *cpA, complex *cpB)
{
    complex temp;
    temp.real = (*cpA).real + (*cpB).real;
    temp.img = (*cpA).img + (*cpB).img;
    printf("The result of the addition:\n");
    print_comp(&temp);
}

/*calculate the subtract between two complex numbers
 *and print the sum
 */
void sub_comp(complex *cpA, complex *cpB)
{
    complex temp;
    temp.real = (*cpA).real - (*cpB).real;
    temp.img = (*cpA).img - (*cpB).img;

    printf("The result of the subtraction:\n");
    print_comp(&temp);
}

/*multiple complex number with scalar
 *argument and print the result*/
void mult_comp_real(complex *cp, double scalar)
{
    complex temp;
    temp.real = (*cp).real * scalar;
    temp.img = (*cp).img * scalar;

    printf("The result of the multiplication with scalar:\n");
    print_comp(&temp);

}


/*multiple complex number with img number scalar
 *argument and print the result*/
void mult_comp_img(complex *cp, double scalar)
{
    complex temp;
    temp.real = (*cp).real * scalar;
    temp.img = -(*cp).img * scalar;

    printf("The result of the multiplication with img scalar:\n");
    if (temp.real < 0)
        printf("%.2f + (%.2fi)\n", temp.img, temp.real);
    else
        printf("%.2f + %.2fi\n", temp.img, temp.real);
}


/*multiple complex number with complex number
 *argument and print the result*/
void mult_comp_comp(complex *cpA, complex *cpB)
{
    complex temp;
    temp.real = ((*cpA).real * (*cpB).real) - ((*cpA).img * (*cpB).img);
    temp.img = ((*cpA).real * (*cpB).img) + ((*cpA).img * (*cpB).real);

    printf("The result of the multiplication of two complex numbers:\n");
    print_comp(&temp);
}


/*return the absolute value of complex number*/
void abs_comp(complex *cp)
{
    double absolue = sqrt( (pow((*cp).real, 2)) + (pow((*cp).img, 2)) );
    printf("The Absolute value of your variable is: %.2f\n", absolue);
}


complex* create()
{
	complex *comp = (complex*)malloc(sizeof(complex));
	comp->real = 0;
	comp->img = 0;
	return comp;
}







