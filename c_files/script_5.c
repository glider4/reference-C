/* ----------------------------------------------

 This program is designed to calculate and display
 the interest earnings of a bank account which has
 a 2.5% interest for the first 5 years, then gets
 increased to 3.5% for the second 5 year period.

----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // initialize all variables
    int year = 1;
    double balance = 1000.00;
    double interest = 0.00;
    double interest_rate1 = 2.50;
    double interest_rate2 = 3.50;

    // print out formatting for top of table
    printf("Year\t Principal\t Interest\t Interest Rate\t Available End of Year\t\n");

    // interest rate is 2.5% for years 1 to 5
    for (year = 1; year < 6; year++)
    {
        balance = balance + interest;
        interest = balance * (interest_rate1/100);
        printf("%d\t $%.2f\t $%.2f\t\t %.1f%%\t\t $%.2f\t\n", year, balance, interest, interest_rate1, balance+interest);
    }

    // interest rate is 3.5% for years 6 to 10
    for (year = 6; year < 11; year++)
    {
        balance = balance + interest;
        interest = balance * (interest_rate2/100);
        printf("%d\t $%.2f\t $%.2f\t\t %.1f%%\t\t $%.2f\t\n", year, balance, interest, interest_rate2, balance+interest);
    }


}

