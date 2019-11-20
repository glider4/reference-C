/* ----------------------------------------------

 This program is designed to ask the user for their
 ID number, credit limit, and current balance for a
 finance company who is undergoing changes and reducing
 each user's credit limit by 50%.

 The program checks the user's inputs in the following ways:
    1) Their ID must be four digits: instructions state range 1111 to 9999.
    2) Their current credit limit must be between $1,000 and $20,000.

*** THIS PROGRAM IS SPECIFICALLY DESIGNED TO CHECK THE USER'S INPUT ***
    --> If the input is incorrect, the program will not proceed.

If either of these conditions are not met when the user
is asked to input these numbers, the program will alert
the user of his/her mistake and then prompt the user to
re-enter the value.  Until the user enters in a correct value,
the program will not stop asking for a re-entry from the user.

Once these are entered in within their proper bounds,
a new credit limit is calculated which is 1/2 of the credit
limit that the user had, as per the new rules at the finance
company.  This value is then checked with the current balance which
was given by the user, to make sure that they are NOT over their
new credit limit.  If they are, a warning is displayed to tell
them that they are over the limit and should contact customer
service to get the issue resolved.

----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    // initialize all variables to be used later on in code
    int flag = 0; // "flag" is used for while loop to check user's inputs
    int id_num = 0;
    double credit_lim = 0.0;
    double current_bal = 0.0;
    double new_credit_lim = 0.0;
    double over_limit;  // do not make equal to a number as this is calculated later on

    // Get ID number: must be four digits
    while (flag == 0)  // use while loop to keep asking for user to input correctly, while input is not in proper bounds
    {
        printf("\nEnter ID number: ");
        scanf("%d", &id_num);

        if (id_num > 9999 || id_num < 1111)
        {
            printf("ID number must be 4 digits between 1111-9999, retry\n");
        }
        else
        {
            flag = 1; // stop while loop and accept user's input because it's within correct range
        }
    }


    // Get credit limit from user, must be between $1,000 and $20,000
    while (flag == 1) // flag changes when input is within proper bounds
    {
        printf("\nEnter credit limit (no commas): $");
        scanf("%lf", &credit_lim);

        if (credit_lim > 20000 || credit_lim < 1000)
        {
            printf("Credit limit must be between $1,000 and $20,000, retry\n");
        }
        else
        {
            flag = 2; // this stops while loop and accepts user's input as OK
        }

    }

    // Now ask for current balance from user: MUST BE LESS THAN OR EQUAL TO $20,000
    while (flag == 2)
    {
        printf("\nEnter current balance (no commas): $");
        scanf("%lf", &current_bal);

        if (current_bal > 20000)
        {
            printf("Current balance must be less than or equal to $20,000, retry\n");
        }
        else
        {
            flag = 3;
        }
    }

    // Now that correct values have been validated by program, program outputs below.

    // Calculate new credit limit for customer as 1/2 of their current credit limit
    new_credit_lim = ((credit_lim) / 2);

    // Print out this new credit limit along with the customer's ID
    printf("\nCustomer %d: Your new credit limit is $%.2f.\n", id_num, new_credit_lim);

    // Check to make sure that customer's current balance is NOT above the new credit limit
    // If it is, display a warning message to alert the user.
    if (current_bal > new_credit_lim)
    {
        over_limit = (current_bal - new_credit_lim);
        printf("\nWarning!  Current balance is $%.2f over new credit limit, call customer service!\n", over_limit);
    }

}
