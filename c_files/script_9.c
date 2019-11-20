/* ----------------------------------------------

 This program is designed to have the user input
 4 separate name and grade pairs for students in a
 class.  The program writes these names and grades
 to a file.

 If a student named "Vader" is entered in by the user,
 his grade is automatically 100, no matter what the
 user enters in for his grade.

 That file is then read and the average score, the
 lowest score, and the highest score are recorded.
 For both the low and high scores, the name of the
 student is also recorded.

 The program prints out the average score, and the
 high and low scores with their respective recipients.

 ----------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                 // necessary for strcmp() and strcpy()

int i=0, n=0;
char lowname[15], highname[15], name[15];
double lowgrade=100.0, highgrade=0.0, decoy, grade, average, total;

FILE *grade_log, *read_grades;      // initialize files

int main(void)
{

    /* Writing to File Part */
    grade_log = fopen ("grade_log.txt","w");        // create file to write to

    printf(" Instructions: enter in student's name (15 characters max), and their score (0-100).\n\n");
    while (i < 4)
    {
        printf(" Enter student %d's name: ", i+1);  // enter in student name
        scanf(" %s", name);                         // is a string of characters
        fprintf(grade_log, "%s ", name);            // write to file this string

        printf(" Enter his/her grade: ");           // enter student grade
        if (strcmp(name, "Vader") == 0)             // if the name entered is the same as "Vader", grade is 100
        {
            grade = 100.0;                          // as per instructions, if Vader is named, grade = 100
            scanf(" %lf", &decoy);
            fprintf(grade_log, "%.1f\n", grade);    // write double value to file on same line as student name
        }
        else
        {
            scanf(" %lf", &grade);                  // else, any other name, enter in grade
            fprintf(grade_log, "%.1f\n", grade);
        }

        i += 1;                                     // advance i to next iteration
    }

    fclose(grade_log);                              // close out the file we're writing to: writing is done


    /* Reading from File Part */
    read_grades = fopen("grade_log.txt", "r");

    while (fscanf(read_grades, "%s %lf", &name, &grade) == 2) // while there is still more data in file...
    {
        total += grade;                 // continuously add up total (average calculated later by dividing by number of entries)

        if (grade < lowgrade)           // lowest grade is set at 100 to start.  if student's grade is lower then this, they are the new low grade
        {
            strcpy(lowname, name);      // store student's name as the low scorer unless overwritten in further iterations
            lowgrade = grade;           // store their grade as the low grade - but may also be overwritten in future
        }

        if (grade > highgrade)     // high grade is set at 0 to start with
        {                               // LOGIC: the first grade will always be highest to start, so set it there and compare rest of grades
            strcpy(highname, name);     // copy name as the high scorer
            highgrade = grade;          // save this student's grade as the (possibly temporary) high scorer
        }

    }

    fclose(read_grades);                // close out reading the file, reading is completed

    /* Print out average, highest grade + student, lowest grade + student */
    printf("\n Average grade: %.1f\n", total/4);   // had 4 students, so average is total over 4
    printf(" Highest grade by %s with a grade of: %.1f\n", highname, highgrade);
    printf(" Lowest grade by %s with a grade of: %.1f\n", lowname, lowgrade);

    return 0;

}
