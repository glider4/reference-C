/* -----------------------------------------------

 This code is designed to calculate the geometric area of
 different shapes with user-inputted dimensions, including a triangle,
 rectangle, and circle, and sphere.

 ----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Used for raising radius to 2nd power in circle area calculation

int main(void)
{
    // First step, defining variables for future reference in equations

    // Part 1: Triangle with base and height inputted in inches.
    double tri_area = 0.0;
    double tri_height = 0.0;
    double tri_base = 0.0;

    // Part 2: Rectangle with length and width inputted in inches.
    double rect_area = 0.0;
    double rect_length = 0.0;
    double rect_width = 0.0;

    // Part 3: Circle with radius inputted in inches.
    double circ_area = 0.0;
    double circ_rad = 0.0;

    // Part 4: Sphere with radius inputted in inches.
    double sphere_vol = 0.0;
    double sphere_rad = 0.0;

    // Now, ask for user to input values to fill these variables:
    // Triangle base and height
    printf("Enter triangle base (use double value, in inches): ");
    scanf("%lf", &tri_base);

    printf("Enter triangle height (use double value, in inches): ");
    scanf("%lf", &tri_height);

    // Rectangle length and width
    printf("Enter rectangle length (use double value, in inches): ");
    scanf("%lf", &rect_length);

    printf("Enter rectangle width (use double value, in inches): ");
    scanf("%lf", &rect_width);

    // Circle radius
    printf("Enter circle radius (use double value, in inches): ");
    scanf("%lf", &circ_rad);

    // Sphere radius
    printf("Enter sphere radius (use double value, in inches): ");
    scanf("%lf", &sphere_rad);

    // Now, use defined variables for calculations.
    // Calculations for areas of shapes with dimensions already defined above.
    tri_area = ((tri_base*tri_height) / 2);
    rect_area = (rect_length * rect_width);
    circ_area = (M_PI * pow(circ_rad, 2));
    sphere_vol = ((4/3) * (M_PI) * pow(sphere_rad, 3));

    // Print out calculated values formatted to be read and understood easily.
    printf("Area of triangle with base %.2f in. and height %.2f in.  =  %.2f square inches \n", tri_base, tri_height, tri_area);
    printf("Area of rectangle with length %.2f in. and width %.2f in.  =  %.2f square inches \n", rect_length, rect_width, rect_area);
    printf("Area of circle with radius of %.2f in. =  %.2f square inches \n", circ_rad, circ_area);
    printf("Volume of a sphere with radius of %.2f in. =  %.2f cubic inches \n", sphere_rad, sphere_vol);

}
