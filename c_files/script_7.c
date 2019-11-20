/* ----------------------------------------------

 This program is designed to do the following:
    1) Generate random values between 0-200 which
    are the number of items sold.
    2) General values between 1-1000 which are the
    prices of these items.
    3) Both 1 and 2 must be in arrays of 10 values.

After these are completed, it prints out a table which
displays the item number, the amount of those items sold,
their prices per each one, and the total amount of sale.  At
the end, the total sale of the store is also calculated.

If more than 100 items are sold of a single item type, the user
is notified to reorder the item.  This is done by a column of "Y"
or "N" characters to denote whether the item needs to be reordered
or not.

Functions were used to generate random integers AND random
double values depending on which array was being created.

----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));  // time seed value

	int a,b,i;
	int rand_int(int a, int b); // function prototype: random integer
	int items[10]; // array for number of each item
	char order[10]; // array Y or N to reorder item

	double rand_dub(double a, double b); // function prototype: random double
	double prices[10]; // array for price of each item
	double itemSale[10]; // item number * price = total $ sold of item
	double totalSale = 0.0;

    printf("\nItem\t Price/Unit\t Units Sold\t Total \t\t Reorder?"); // generate top of table
    printf("\n-------------------------------------------------------------------");

    for (i=0; i<10; i++) // put as many random variables as there are slots in array (10 in this case)
    {
        items[i] = rand_int(0, 200); // items sold between 0-200
        prices[i] = rand_dub(1.0, 1000.0); // prices between 1-1000
        itemSale[i] = (items[i] * prices[i]); // total $ made selling each item
        totalSale = totalSale + itemSale[i]; // total $ made over all sales

        if (items[i] > 100) // if more than 100 items sold, tell user to reorder item!
        {
            order[i] = 'Y';
        }
        else // if 100+ items not sold, no need to reorder
        {
            order[i] = 'N';
        }

        printf("\n%d \t $%.2f \t %d \t\t $%.2f \t %c", i+1, prices[i], items[i], itemSale[i], order[i]);
    }

    printf("\n-------------------------------------------------------------------");
    printf("\n\nTotal store sale: $%.2f", totalSale); // generate last calculation: total store sale
    printf("\n\n");
    fflush(stdin);
	return 0;
}

/* Define all functions below */

int rand_int(int a, int b) // function for random integer
{
	return rand()%(b-a+1) +a;
}

double rand_dub(double a, double b) // function for random double
{
	double dub = (double)rand() / RAND_MAX;
	return dub * (b-a+1) + a;
}

