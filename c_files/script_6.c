/* ----------------------------------------------

 This program is designed to calculate and display
 the trajectory of a cannon ball; the user inputs
 the initial velocity and trajectory angle, and then
 selects what they want calculated: the max height
 obtained by the cannon ball, it's time of flight,
 or the range that it was fired.

 Input restrictions: initial velocity between 20 to
 800 m/s, angle from 5 to 80 degrees.

----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

// define functions and their types
double max_height(double, double);
double time(double, double);
double range(double, double);
int choice();

int main(void)
{
    int choice = 1;
    while (choice != 5) // if choice == 5, program exits
    {
        choice = select();
    }

return 0;
}

// define selection function for what users inputs and wants to calculate
int select(void)
{
    int choice;
    double velocity, angle, maxheight, tot_time, tot_range, timetomax;

    // get initial velocity input from user: must be between 20-800 m/s
    while (velocity > 800 || velocity < 20)
    {
        printf(" Enter initial velocity of cannon ball between 20-800 m/s: ");
        scanf("%lf", &velocity);
    }

    // get initial firing angle from user: must be between 5-80 degrees
    while (angle > 80 || angle < 5)
    {
        printf(" Enter angle of fired cannon ball between 5-80 degrees: ");
        scanf("%lf", &angle);
    }

    // prompt user to select what they want to calculate
    printf("\n Choose calculation: \n 1 - Maximum height achieved \n 2 - Time of flight \n 3 - Horizontal range of flight \n 4 - Calculate all of the above \n 5 - Exit this program \n\n");
    scanf("%d", &choice);

    // canon ball trajectory is a parabola, so maximum height is achieved in 1/2 time of entire flight
    timetomax = ( time(velocity, angle) / 2 );

    if (choice == 1)
    {
        maxheight = max_height(velocity, angle);
        printf("\n The maximum height achieved was %.2f meters \n", maxheight);
        printf(" The time to reach max height was %.2f seconds \n", timetomax);
    }
    else if (choice == 2)
    {
        tot_time = time(velocity, angle);
        printf("\n The time of the flight was %.2f seconds \n", tot_time);
        printf(" The time to reach max height was %.2f seconds \n", timetomax);
    }
    else if (choice == 3)
    {
        tot_range = range(velocity, angle);
        printf("\n The horizontal range of the flight was %.2f meters \n", tot_range);
        printf(" The time to reach max height was %.2f seconds \n", timetomax);
    }
    else if (choice == 4)
    {
        maxheight = max_height(velocity, angle);
        tot_time = time(velocity, angle);
        tot_range = range(velocity, angle);

        printf("\n The maximum height achieved was %.2f meters", maxheight);
        printf("\n The time of the flight was %.2f seconds", tot_time);
        printf("\n The horizontal range of the flight was %.2f meters \n", tot_range);
        printf(" The time to reach max height was %.2f seconds \n", timetomax);
    }
    else if (choice == 5)
    {
        printf("\n Program exit, come back soon! \n");
    }
    else
    {
        printf("\n Choice must be in list \n");
    }

    return (choice);
}

// peak height function
double max_height(double v, double a)
{
    double maxheight;
    maxheight = ( pow(v,2) * pow(sin( (a*PI / 180)), 2 ) ) / (2*9.8);
    return (maxheight);
}

// time of flight function
double time(double v, double a)
{
    double tot_time;
    tot_time = ( (2*v) * sin((a*PI / 180)) ) / 9.8;
    return (tot_time);
}

// horizontal range function
double range(double v, double a)
{
    double tot_range;
    tot_range = ( pow(v,2) * sin(2* (a*PI / 180) ) ) / 9.8;
    return (tot_range);
}
