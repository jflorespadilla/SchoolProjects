//Header files
#include "formatted_console_io_v16.h"
#include <fstream>

using namespace std;

//Global constants

//Function Prototypes

/*
Name: menuDisplay
Processing: Displays the main menu to the user
Input: None
Output/Display: Displays the main menu
Dependencies: formatted console io
*/
void menuDisplay();

/*
Name: prtAcquScreen
Processing: Prints the acqusition screen ( when option 1 is pressed)
Input: none
Output/Return: The acqusition screen
Dependencies: formatted console io
*/
void prtAcquScreen();

/*
Name: badMsg
Processing: prints out an error message to the user ( if no file is found to 
            perform the desired operation )
Input: none
Output/Return: Error message
Dependencies: formatted console io
*/
void badMsg();

/*
Name: getFileData
Processing: Returns a true or false on file opening.
Input: A string varable for a file nave and an ifstream variable
Output/Return: A true or false indication
Dependencies: fstream
*/
bool getFileData( string &flName, ifstream &fin );

/*
Name: printAnalyScreen
Processing: Displays the data analysis screen ( Second option from main menu)
Input: None
Output/Return: Display the data analysis screen
Dependencies: fstream
*/
void printAnalyScreen();

/*
Name: getNumItems
Processing: Opens file and counts the amount of number values that are given in
            the file.
Input: String of the file name, ifstream variable
Output/Return: Double giving the amount of counted items
Dependencies: ifstream
*/
double getNumItems( const string &flName, ifstream &fin );

/*
Name: getAverage
Processing: opens file and calculates the average found in the file.
Input: Srting of the file name, ifstream variable
Output/Return: Double giving the average amount
Dependencies: ifstream
*/
double getAverage( const string &flName, ifstream &fin );

/*
Name: getHighLow
Processing: opens file and recives either Maximum or Minimum depending on 
            extrema.
Input: Sring of file name, ifstream variable, Either constant string 
       HIGH or LOW
Output/Return: Double representing the Maxinmum or the Minimum
Dependencies: ifstream
*/
double getHighLow( const string &flName, ifstream &fin, const string &extrema );

/*
Name: prtGraphScreen
Processing: Displays the graphing screen (third option on main menu)
Input: None
Output/Display: Displays the graph (Not the information)
Dependencies: formatted console io
*/
void prtGraphScreen();

/*
Name: getData
Processing: Gets data from file, counts how many number exist in that interval
            and returns that integer
Input: Name of file string, ifstream variable, Low and High reference value
Output/Return: Number of double values that fit in the specified interval
Dependencies: ifstream
*/
int getData( const string &flName, ifstream &fin, double Low, double High);

/*
Name: printDataFor
Processing: Prints out the number of "H's" for the histogram and the amount of
            units said to be found as represented by an integer
Input: Data value, int for X and y positon
Output/Display: Prints "H's" for histogram and integer
Dependencies: formatted io stream
*/
void printDataFor( int dataVal, int xPos, int yPos );

/*
Name: inputErrorMsg
Processing: It is the default message telling the user that the input was not
            an option.
Input: None
Output/Return: Message displayed
Dependencies: fromatted console io
*/
void inputErrorMsg();


//Main function

int main()
   {
    // Initinalize Variables

    // Start curses
       // Function: startCurses

    // Post-test loop
       // Operation: do while loop

       // Display Menu
          // Function: menuDisplay

       // Get Input
          // Function: promptForCharAt

       // switch (selection, quit)
          // Case 'F', 'f', '1'
             // Clear screen & print title acquisition screen
                // Function: clearScreen
                // Function: prtAcquScreen

             // prompt user for file, check if good & open
                // Function: promptForIntAt
                // Function: getFileData

             // If good, print good message
                // Operation: if
                // Function: printStringAt
                // Function: printStringAt

                // Hold screen for user
                   // waitForInput

             // If bad, print bad-message
                // Function: printStringAt
                // Function: printStringAt

                // Hold screen for user
                   // waitForInput

          // Case 'A', 'a', '2'
             // if the file is bad, print message
                // Function: badMsg

                // Hold screen for user
                   // Fucntion: waitForInput

             //if the file is good, preform analysis
                // print data stat analysis
                   // Function: printAnalyScreen
                   

                // Count the number of items
                   // Function: getNumItems

                   // print count
                      // Function: printDoubleAt

                // Find the average
                   // Function: getAverage

                   // print average
                     // Function: printDoubleAt

                // Find highest and lowest
                   // Function: getHighLow

                   // print high
                      // Function: printDoubleAt

                   // print low
                      // Function: printDoubleAt

                // Hold screen for user
                   // Function: waitForInput

          // Case 'G', 'g', '3'
             // if the file is bad, print message
                // Function: badMsg

                // Hold screen for user
                   // Function: waitForInput

             // if the file is good, preform graph
                // Print analysis graph
                   // Function: prtGraphScreen

                // Operation: while loop
                   // Collect Data for  Variable < 5
                      //print data for < 5
                   // Collect Data for  Variable < 10
                      //print data for < 10
                   // Collect Data for  Variable < 15
                      //print data for < 15
                   // Collect Data for  Variable < 20
                      //print data for < 20
                   // Collect Data for  Variable < 25
                      //print data for < 25
                   // Collect Data for  Variable < 30
                      //print data for < 30
                   // Collect Data for  Variable < 35
                      //print data for < 35
                   // Collect Data for  Variable < 40
                      //print data for < 40
                      
                      // Function: getData    ( Function used for all variables)
                         // Function: printDataFor


                   // end loop


                   // Hold screen for user
                   

          // Case 'Q', 'q', '4' (!Quit loops)
             // End loop, set flag to true

          //Default case
             // Message to the user for incorret option
                // Function: inputErrorMsg
             
             // Hold screen for user
                // Function: waitForInput

    // End post-test loop

    // End curses
       // Function: endCurses


    return 0;
   }

//Function Implementations
void menuDisplay()
   {
    // Stub
   }

void prtAcquScreen()
   {
    // Stub
   }

void badMsg()
   {
    // Stub
   }

bool getFileData( string &flName, ifstream &fin )
   {
    return false; // Stub return
   }

void printAnalyScreen()
   {
    // Stub
   }

double getNumItems( const string &flName, ifstream &fin )
   {
    return 0.00; // Stub return
   }

double getAverage( const string &flName, ifstream &fin )
   {
    return 0.00; // Stub return
   }

double getHighLow( const string &flName, ifstream &fin, const string &extrema )
   {
    return 0.00; // Stub return
   }

void prtGraphScreen()
   {
    // Stub
   }

int getData( const string &flName, ifstream &fin, double Low, double High)
   {
    return 0; // Stub return
   }

void printDataFor( int dataVal, int xPos, int yPos )
   {
    // stub
   }

void inputErrorMsg()
   {
    // stub
   }
