/* ----------------------------------------------

 The goal of this program is to calculate the
 sum of numbers in a row of a matrix, for all the
 rows in that matrix.  Also, the diagonal sum is
 calculated.  The matrix itself was given in the
 assignment and is formatted into C by a 4x4 double
 array (2 dimensional).

 In terms of printing, this program prints out each row
 of the matrix itself, one after another, to display
 before the average and sum are shown directly to the right
 of the row.  The diagonal sums are printed directly after
 the sum of all the components in the matrix is displayed.

 The function avg_rowfunc is designed to take a single
 dimensional (1D) array and calculate the average of the
 entries in that array.  This was useful for calculating
 the average of the elements per row.

 As for the diagonals, top L to bottom R was easy because
 each entry has the same indices (0,0 and 1,1 etc).  But,
 for the opposite direction (top R to bottom L), the column
 identifier had to be subtracted by 1 each time.

 ----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int row = 0, column = 0, n = 0, k = 3;
    double totalsum = 0.0, rowsum = 0.0, rowavg = 0.0, diag1 = 0.0, diag2 = 0.0;
    double onerow[4];
    double avg_rowfunc(double matrix[]);

    // define matrix itself as 4x4 with all values from assignment
    double m[4][4] = {
                    {66.2, 10.1, 35.6, 19.9},
                    {65.1, 11.9, 88.3, 17.1},
                    {1.1, 2.7, 3.8, 4.2},
                    {5.9, 6.6, 9.9, 77.7},
                    };

    // begin by print out name and top of table format
    printf(" Matrix\t\t\t\t\t Row Sum \t Row Average\n");
    printf(" ====================================================================\n\n");

    for( row = 0; row < 4; row++ )
        {
        rowsum = 0.0;  // reset sum so iterations don't compile together

        for( column = 0; column < 4; column++ )
            {
            onerow[column] = m[row][column];   // put each row into it's own array and pass to avg. function
            rowsum = rowsum + m[row][column];  // sum of row is addition of it's elements
            }

        for ( n = 0; n < 4; n++)
            {
            printf(" %.2f\t", onerow[n]); // print out each row in the matrix for display
            }
        rowavg = avg_rowfunc(onerow);  // call function to calculate average of row
        totalsum = totalsum + rowsum;  // the total sum continuously updates - does not reset to 0 after iteration
        printf("\t %.2f  \t %.2f\n", rowsum, rowavg ); // now print out sum of row and average to display next to row of matrix
        }

    printf("\n Total sum of all matrix components: %.2f\n", totalsum);

    // diagonal sums section: top table format print out
    printf("\n ====================================================================\n\n");
    printf("               Diagonal Sums of Matrix                   \n\n");
    printf(" Top Left to Bot Right \t\t Top Right to Bot Left \n");

    for( n = 0; n < 4; n++ ) // n is used because it'll be specifying both rows and columns in diag1
        {
        diag1 = diag1 + m[n][n];  // top L to bot R is just 0,0 then 1,1 then 2,2 then 3,3
        diag2 = diag2 + m[n][k];  // top R to bot L is 0,3 then 1,2 then 2,1 then 3,0
        k = k - 1;  // advance rows backwards from 3 for top R to bot L
        }

    printf("\n \t %.2f \t\t\t %.2f \n", diag1, diag2); // print out diagonal results and end table format
    printf("\n ======================================================\n\n");

}

double avg_rowfunc(double mat[]) // function to calculate average of any given array inputted
{
    int i = 0;
    int n = sizeof(mat);
    double total = 0.0;

    for( i = 0; i < 4; i++ ) // indice increases by one in array to sum up each element
        {
        total = total + mat[i]; // sum of the array is sum plus the current matrix indice
        }

    return (total / n); // average is just the total sum over the size of the array
}
