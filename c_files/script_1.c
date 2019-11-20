/* -----------------------------------------------

 This code is designed to calculate the geometric area of
 different shapes with set dimensions, including a triangle,
 rectangle, and circle.

 Instructions were given as:
 1-   Area of a triangle with base of 13 inch and height of 29 inch.
 2-   Area of a rectangle with length of 10.2 inch and width of 6.5 inch.
 3-   Area of a circle with radius of 2.6 inches.

----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Used for raising radius to 2nd power in circle area calculation

int main(void)
{
    // First step, defining variables for future reference in equations

    // Part 1: Triangle with base 13 in. and height 29 in.
    double tri_area = 0.0;
    double tri_height = 29.0;
    double tri_base = 13.0;

    // Part 2: Rectangle with length 10.2 in. and width 6.5 in.
    double rect_area = 0.0;
    double rect_length = 10.2;
    double rect_width = 6.5;

    // Part 3: Circle with radius 2.6 inches.
    double circ_area = 0.0;
    double circ_rad = 2.6;

    // Now, use defined variables for calculations.
    // Calculations for areas of shapes with dimensions already defined above.
    tri_area = ((tri_base*tri_height) / 2);
    rect_area = (rect_length * rect_width);
    circ_area = (M_PI * pow(circ_rad, 2));

    // Print out calculated values formatted to be read and understood easily.
    printf("Area of triangle with base %.0f in. and height %.0f in.  =  %.2f square inches \n", tri_base, tri_height, tri_area);
    printf("Area of rectangle with length %.2f in. and width %.2f in.  =  %.2f square inches \n", rect_length, rect_width, rect_area);
    printf("Area of circle with radius of %.2f in. =  %.2f square inches \n", circ_rad, circ_area);

}
