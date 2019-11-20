/* ----------------------------------------------

 This program is designed to calculate and display the
 distances from a spaceship to an asteroid.  It is set up so
 that the user has to input a correct user name and password,
 which are given in the "ident.txt" document.  If the user
 enters in a correct user/password combo, the program runs.

 First, a set of asteroids (amount is controlled by "n" in main)
 are given a name, X, Y, and Z coordinates as random integers (in km) between
 1 and 1000.  These are then written to a file, "asteroids.txt".  The name
 of each asteroid is a single letter from the alphabet.

 This file, "asteroids.txt", is read and the distances to each asteroid
 are calculated based on the simple formula D = sqrt(X^2 + Y^2 + Z^2).  Each
 asteroid's distance is then written to a file with it's name, X, Y, and Z
 coordinates.  This file is called "distances.txt".

 The new file "distances.txt" is then read.  If the distance to an
 asteroid, any asteroid, is <750 kilometers away, a warning is displayed to the
 user about it.  A chart is also printed on the screen to display relatively,
 how close each asteroid is in a standard horizontal bar-chart format.

 After this, the last step of the program sorts the asteroids by distance
 and prints them out for the user to see.  The program the terminates.

---------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ====================================================================
// Functions utilized in this program

int security(void);                 // User name and password entrance into program
int make_asteroids(int n);          // Define asteroid name and X, Y, Z positions, write to file (n is number of asteroids)
int rand_int(int a, int b);         // To generate random integer value between a and b
int read_asteroids(void);           // Read file of names/positions, calculate distance, write to file
int display_warnings(void);         // Display warnings for closest asteroid and those <750km away
int make_graph(void);               // Displays chart of distances of asteroids to spaceship
int find_ranks(int n);              // Creates ranking system for asteroid distances

// ====================================================================


// ====================================================================
// Structures defined for program

struct ident                // Define structure for user name / password data
{
    char name[10];
    int pass;

};

struct asteroid_logs        // Define structure for asteroid data
{
  char name[1];
  int X;
  int Y;
  int Z;
  double dist;
};
// ====================================================================


// ====================================================================
// Begin main

int main(void)
{
    int n = 10;                 // number of asteroids
    int t = 3;                  // number of tries granted to user

    while (t > 0)               // While user still has tries left
    {
        if (security() == 0)    // if user and password are CORRECT, security() returns "0"
        {
            t = 0;              // stop WHILE loop to cease further iterations asking for user/pass
            printf("\n Unlocked --> Entering program \n\n");     // unlock program and run
            make_asteroids(n);
            read_asteroids();
            display_warnings();
            make_graph();
            find_ranks(n);
        }

        else                    // if security() does NOT return "0", user/pass were INCORRECT
        {
            t -= 1;          // remove one attempt from user

            if (t == 0)         // if no attempts left, exit program!
            {
                printf("\n\n Tries left: 0 --> Exiting Program \n\n");
            }
            else                // if t still greater than 0 (more tries available), tell user how many tries left
            {
                printf("\n Incorrect user and/or password, try again.  Tries left: %d \n", t);
            }
        }
    }

    return 0;
}

// ====================================================================



// ====================================================================
// Have user enter user name and password
// Allow three tries before exiting

int security(void)
{
    FILE *ident;
    ident = fopen("ident.txt","r");     // open the file for reading that has user/name pairs

    struct ident id;
    char name[10];
    int pass, flag=1;

    printf(" Enter user name:  ");      // have user enter user name and scan it into program
    scanf("%s", &name);

    printf(" Enter password:  ");       // have user enter password, scan into program
    scanf("%d", &pass);


    while ((fscanf(ident, "%s %d", id.name, &id.pass) == 2) && (flag == 1)) // if there is still data in the file
            {
                if ((strcmp(name, id.name) == 0) && (pass == id.pass))      // if both the name and password match in the file
                {
                    flag = 0;        // flag here is just used to stop the while loop once a match is found
                }
            }

    fclose(ident);  // close out the file
    return flag;    // if flag = 0, name/password was good; if not, name/password was NOT accepted

}

// ====================================================================


// ====================================================================
// Define asteroid names and their X, Y, Z positions using MATRIX
// "n" is how many asteroids I want to create

int make_asteroids(int n)
{
    FILE *asteroids;
    asteroids = fopen("asteroids.txt","w");

    int i, m[n][3];
    char ast_name, names[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // I set this up so that each asteroid got its own single-letter character from the alphabet

    for (i=0; i<n; i++)
    {
        m[i][1] = rand_int(1, 1000);        // define matrix entries as random integers using rand_int() function
        m[i][2] = rand_int(1, 1000);
        m[i][3] = rand_int(1, 1000);

        fprintf(asteroids, "%c %d %d %d\n", names[i], m[i][1], m[i][2], m[i][3]);       // write to asteroids file the name, X, Y, Z coordinates
    }

    fclose(asteroids);
    return 0;
}

// Function to return random integer
int rand_int(int a, int b)
{
    return rand()%(b-a+1) +a;
}

// ====================================================================


// ====================================================================
// Read file with asteroid position data in it
// Calculate distance to each asteroid, write new file with distances

int read_asteroids(void)
{
    FILE *asteroids, *distance;
    asteroids = fopen("asteroids.txt","r");     // open asteroids to read (name and X, Y, Z coordinates)
    distance = fopen("distance.txt", "w");      // open distance to write it --> need to add on distance to asteroid along with data from asteroids.txt

    struct asteroid_logs al;        // use this structure which has the preset variables for all data in the file

    if (asteroids == NULL)
    {
     printf("Error: Asteroids File Not Found!\n");
    }

    else
    {
        while (fscanf(asteroids, "%s %d %d %d", al.name, &al.X, &al.Y, &al.Z) == 4)     // as long as there's info in file
            {
                al.dist = sqrt(pow(al.X,2) + pow(al.Y,2) + pow(al.Z,2));                // calculate distance using sqrt() and pow() (equation was given)
                fprintf(distance, "%s %d %d %d %.2lf\n", al.name, al.X, al.Y, al.Z, al.dist);       // write this distance along with all other info to new distance.txt file
            }
    }

    fclose(asteroids);
    fclose(distance);
    return 0;

}
// ====================================================================


// ====================================================================
// Read file with distance to asteroids
// Display warning if closer than 750 km

int display_warnings(void)
{
    FILE *distance;
    distance = fopen("distance.txt", "r");      // open file to read
    char close_ast[1];
    double time, close_dist = 10000.0;
    struct asteroid_logs al;

    if (distance == NULL)
    {
        printf("Error: Distance File Not Found!\n");
    }

    else
    {
        while (fscanf(distance, "%s %d %d %d %lf", al.name, &al.X, &al.Y, &al.Z, &al.dist) == 5)    // as long as there's data in file
            {
                if (al.dist < close_dist)           // find closest (lowest) distance
                {
                    close_dist = al.dist;           // rename to call back later and print
                }

                if (al.dist <= 750)
                {
                    time = (al.dist / 25);   // these asteroids are traveling at 25 km/s, so divide our distance [km] by 25 to get time in seconds to impact
                    printf(" Warning!  Asteroid %s is %.2f km away!  Time to impact: %.2f seconds!\n", al.name, al.dist, time);
                }
            }

            printf("\n Closest asteroid is only %.2f km away!  Prepare to dodge! \n\n", close_dist);
    }

    fclose(distance);
    return 0;

}

// ====================================================================


// ====================================================================
// Read file with distance to asteroids
// Create and display graph of nearest asteroids

int make_graph(void)
{
    FILE *distance;
    distance = fopen("distance.txt", "r");  // open file to read, am not changing or writing anything to it

    int i, proportion;
    struct asteroid_logs al;  // use structure so that I don't have to re-define name, X, Y, Z variables over again


if (distance == NULL)
    {
        printf("Error: Distance File Not Found!\n");
    }

    else
    {
        while (fscanf(distance, "%s %d %d %d %lf", al.name, &al.X, &al.Y, &al.Z, &al.dist) == 5)  // read each filled in row of file
            {
                proportion = round(al.dist / 40);           // this proportion was based on the max distance of 3200 km away sqrt(1000^3)
                printf(" %s |", al.name);               // design chart using vertical bars

                for (i=0; i<proportion; i++)
                {
                    printf("-");            // design horizontal bars as dashes to represent distance to spaceship
                }

            printf("\n");

            }

        printf(" __|___________________|___________________|______________________________________| \n");
        printf("    0               800 km                1600 km                          3200 km\n");

    }

    fclose(distance);
    return 0;

}


// ====================================================================
// Read file with distance to asteroids
// Find ranks of asteroid distances, order, display

int find_ranks(int n)
{
    FILE *distance;
    distance = fopen("distance.txt", "r");  // read distance file

    int i, j;
    double  m[n], place;
    char names[n], plc;
    struct asteroid_logs al;


    if (distance == NULL)
    {
        printf("Error: Distance File Not Found!\n");
    }

    else
    {
        i = 0;
        while (fscanf(distance, "%s %d %d %d %lf", al.name, &al.X, &al.Y, &al.Z, &al.dist) == 5)
        {
            m[i] = al.dist;
            //strcpy(names[i], al.name);
            i += 1;
        }

        for (i=0; i<n; i++)
        {
            for (j=i+1; j<n; j++)
            {
                if (m[i] > m[j])
                {
                    place =  m[i];
                    //plc = names[i];

                    m[i] = m[j];
                    //names[i] = names[j];

                    m[j] = place;
                    //names[j] = plc;
                }
            }
        }
    }



    printf("\n\n Asteroid distances in order \n\n");
    for (i=0; i<n; i++)
    {
        printf(" %.2f\n", m[i]);
    }


    fclose(distance);
    return 0;
}

// ====================================================================
