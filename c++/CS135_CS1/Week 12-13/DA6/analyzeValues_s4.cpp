//Header files
#include <fstream>
#include "formatted_cmdline_io_v06.h"
#include <cmath>

using namespace std;

//Global constants
const int MAX_ROW = 9;
const int MAX_COL = 9;
const int MAX_F_NAME = 40;

//Function Prototypes
/*
Name: getFileName
Processing: prompts for a file name and attempts to open the file. boolean value
            will be given a value.
Input: A boolean variable
Output/Return: Give the boolean variable a value
Dependencies: formatted command line tools
*/
void getFileName( bool fileGood );

/*
Name: displayErrorMsg
Processing: displays error message when the wrong input is used
Input: None
Output/Return: Error message display
Dependencies: formatted command line tools
*/
void displayErrorMsg();

/*
Name: readFileData
Processing: reads the file and determains the size of the matrix and gives the 
            array the values found in the file.
Input: An integer arry for storing values, and two integer variables for 
       determaining the size of the matrix.
Output/Return: integer arry stores values. Integer variables store maximum row
               anc col size.
Dependencies: fstream
*/
void readFileData( int arr[][MAX_COL], int &fileRow, int &fileCol );

/*
Name: getRowCol
Processing: prompts user for letter and number input.
Input: user letter and user integer.
Output/Return: values stored in variables
Dependencies: formatted command line tools
*/
void getRowCol( char &RowOrCol, int &index );

/*
Name: checkLetter
Processing: checks if the letter input is a valid input.
Input: Char called by reference
Output/Return: True or false
Dependencies: getRowCol for char
*/
bool checkLetter( char &RowOrCol );

/*
Name: checkNum
Processing: checks if the number input is within range of the matrix size
Input: Maximum row and col size by reference, integer input, letter input
Output/Return: True or false
Dependencies: getRowCol for char and integer input, readFileData for Maxes
*/
bool checkNum( int &fileRow, int &fileCol, char &RowOrCol, int &index );

/*
Name: displayError
Processing: displays error for an input out of range or with incorrect letter
Input: None
Output/Return: Display the error message
Dependencies: formatted command line tools
*/
void displayError();

/*
Name: printArray
Processing: Prints out the values stored in each index of the array
Input: integer array with values stored.
Output/Return: display of each value stored
Dependencies: readFileData, formatted command line tools
*/
void printArray( int arr[][MAX_COL] );

/*
Name: calcAverage
Processing: calculates the average of a given column or row
Input: Integer array with values stored, char letter, index number
Output/Return: double value found in the calculations
Dependencies: cmath, readFileData, getRowCol
*/
double caclAverage( int arr[][MAX_COL], char &RowOrCol, int &index );

/*
Name: calcSD
Processing: calculates the standard deviation of a given column or row
Input: Integer array with values stored char letter, index number, and max file
       row and col, average
Output/Return: Double value representing standard deviation.
Dependencies:cmath, readFileData, getRowCol
*/
double calcSD( int arr[][MAX_COL], char &RowOrCol, int &index, int &fileRow,
               int &fileCol, double ave );

/*
Name: printData
Processing: Displays data of average and the data of standard deviation
Input: Average  and Standard deviation
Output/Return: Printed informations
Dependencies: calcAverage, calcSD, formatted command line tools
*/
void printData( double ave, double standardD );

//Main function

int main()
   {
    // Initialize variables
    bool done = false;
    bool fileGood = false; //Temporary value
    bool letterTest;
    bool indexTest;
    int fileMatrix[MAX_ROW][MAX_COL];
    int fRow, fCol, inputIndex;
    char inputChar, loopChar;
    double aver, stanD;

    do
    {
    //prompt ( file Name )
       // Function: getFileName
       getFileName( fileGood );

       //test bad
       if(!fileGood)       
          {
           //display error
              // Function: displayErrorMsg
              displayErrorMsg();
          }

       //test good
       else
          {
          //continue
          // Function: readFileData
          readFileData( fileMatrix, fRow, fCol );

          //prompt ( row/col )
             // function: getRowCol
             getRowCol( inputChar, inputIndex);

          //test ( letter )
            // Function: checkLetter
            letterTest = checkLetter( inputChar );            

          if( !letterTest )
             {
              //bad: display error
                 // Function: displayError
                 displayError();
             }

         //good: continue
         else
            {
             //test ( num )
             // function: CheckNum
             indexTest = checkNum( fRow, fCol, inputChar, inputIndex );

             if( !indexTest )
               {
                //bad: display error
                   // Function: displayError
                   displayError();
               }
          
             //good: continue
             else
                { 
                 //didsplay ( array )
                    // function: printArray
                    printArray( fileMatrix );

                 //calculate ( avarage )
                    // Function: calcAverage
                    aver = caclAverage( fileMatrix, inputChar, inputIndex );

                 //calclulate ( SD )
                    // Function: calcSD
                    stanD = calcSD( fileMatrix, inputChar, inputIndex, fRow, fCol, aver );

                 //display data
                    // Function: printData
                    printData( aver, stanD );
                 }
            }
          }

    //prompt ( Quit ) loop 
       // Function: promptForChar
       loopChar = promptForChar( "Press <Q>uit, or any other key <and ENTER> to continue: " );
       // if q or Q end the loop
       if( (loopChar == 'q') || (loopChar == 'Q') )
          {
           done = true;
          }

       // else clear screen
       else
          {
           // Function: system ( "cls" )
           system( "cls" );
          }
    }
    while( !done );


    return 0;
   }

//Function Implementations

void getFileName( bool fileGood )
   {
    // stub
   }

void displayErrorMsg()
   {
    // stub
   }

void readFileData( int arr[][MAX_COL], int &fileRow, int &fileCol )
   {
    // stub
   }

void getRowCol( char &RowOrCol, int &index )
   {
    // stub
   }

bool checkLetter( char &RowOrCol )
   {
    return false; // stub return
   }

bool checkNum( int &fileRow, int &fileCol, char &RowOrCol, int &index )
   {
    return false; // stub return
   }

void displayError()
   {
    // stub
   }

void printArray( int arr[][MAX_COL] )
   {
    // Stub
   }

double caclAverage( int arr[][MAX_COL], char &RowOrCol, int &index )
   {
    return 0.00; //Stub return
   }

double calcSD( int arr[][MAX_COL], char &RowOrCol, int &index, int &fileRow,
               int &fileCol, double ave )
   {
    return 0.00; // Stub return
   }

void printData( double ave, double standardD )
   {
    // stub
   }
