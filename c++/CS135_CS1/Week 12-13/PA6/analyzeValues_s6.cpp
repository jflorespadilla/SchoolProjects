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
void getFileName( bool &fileGood, ifstream &fin );

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
void readFileData( int arr[][MAX_COL], int &fileRow, int &fileCol, ifstream &fin );

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
Name: displayError
Processing: displays error for an input out of range or with incorrect letter
Input: None
Output/Return: Display the error message
Dependencies: formatted command line tools
*/
void displayError2();

/*
Name: printArray
Processing: Prints out the values stored in each index of the array
Input: integer array with values stored.
Output/Return: display of each value stored
Dependencies: readFileData, formatted command line tools
*/
void printArray( int arr[][MAX_COL],  int &fileRow, int &fileCol );

/*
Name: calcAverage
Processing: calculates the average of a given column or row
Input: Integer array with values stored, char letter, index number
Output/Return: double value found in the calculations
Dependencies: cmath, readFileData, getRowCol
*/
double caclAverage( int arr[][MAX_COL], char &RowOrCol, int &index, int &fileRow, int &fileCol );

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
void printData( double ave, double standardD, char &RowOrCol, int &index );

//Main function

int main()
   {
    // Initialize variables
    bool done = false;
    bool fileGood;//Temporary value
    bool letterTest;
    bool indexTest;
    int fileMatrix[MAX_ROW][MAX_COL];
    int fRow, fCol, inputIndex;
    char inputChar, loopChar;
    double aver, stanD;
    ifstream fileIn;

    do
    {
    //prompt ( file Name )
       // Function: getFileName
       getFileName( fileGood, fileIn );

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
          readFileData( fileMatrix, fRow, fCol, fileIn );

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
                   displayError2();
               }
          
             //good: continue
             else
                { 
                 //didsplay ( array )
                    // function: printArray
                    printArray( fileMatrix, fRow, fCol );

                 //calculate ( avarage )
                    // Function: calcAverage
                    aver = caclAverage( fileMatrix, inputChar, inputIndex, fRow, fCol );

                 //calclulate ( SD )
                    // Function: calcSD
                    stanD = calcSD( fileMatrix, inputChar, inputIndex, fRow, fCol, aver );

                 //display data
                    // Function: printData
                    printData( aver, stanD, inputChar, inputIndex );
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

void getFileName( bool &fileGood, ifstream &fin )
   {
    // initialize variables
    char fileName[MAX_F_NAME];

    // Display title screen
       // Function: printString
       printString("ARRAY ANALYSIS PROGRAM", 0, "LEFT" );
       printEndLines(1);
       printString( "======================", 0, "LEFT" );
       printEndLines(2);

    // prompt for a string name
       // Function: promtForString
       promptForString( "Enter file name: ", fileName );

    // Open and test file
       // Function: fin
       fin.clear();
       fin.open( fileName );

       if( fin.good() )
          {
           fileGood = true;
          }

       else
          {
           fileGood = false;
          }

       printEndLines(3);

   }

void displayErrorMsg()
   {
    // display message
       // Function: printString
       printString( "ERROR: File not found, processing aborted.", 0, "LEFT");
       printEndLines(2);
   }

void readFileData( int arr[][MAX_COL], int &fileRow, int &fileCol, ifstream &fin )
   {
    // initialize variables
    int tempCol, tempRow;
    int row = 0, col = 0;
    char dummy;

    // Obtain values
       // Function: fin
       fin.ignore( 20, ':') >> fileRow;
       fin.ignore( 20, ':') >> fileCol;


    // store values in array
       // for loop
       for( tempRow = fileRow ; tempRow > 0; tempRow-- )
          {
           col = 0;
           fin >> arr[row][col];
           col = 1;

           // for loop
           for( tempCol = fileCol; tempCol > 1; tempCol-- )
              {
               fin >> dummy;
               fin >> arr[row][col];
               col++;
              }
           row++;
          }

      fin.close();
      
   }

void getRowCol( char &RowOrCol, int &index )
   {
    // prompt for a character
       // Function: promptForChar
       RowOrCol = promptForChar("Enter Desired <R>ow or <C>olumn and Index (e.g., R5, C7, etc.): ");

    // promt for an integer
       // Function: promptForInt
       index = promptForInt("");
   }

bool checkLetter( char &RowOrCol )
   {

    // if statement
    if( (RowOrCol == 'r') || (RowOrCol == 'R') || (RowOrCol == 'c') || (RowOrCol == 'C') )
       {
        return true;
       }

    return false; 
   }

bool checkNum( int &fileRow, int &fileCol, char &RowOrCol, int &index )
   {
    // if statement (row range)
    if( (RowOrCol == 'r') || (RowOrCol == 'R') )
       {
        // if statement
        if( (index > 0) && (index <= fileRow) )
           {
            return true;
           }

        // else statement
        else
           {
            return false;
           }

       }

    // if statment (col range)
    if( (RowOrCol == 'c') || (RowOrCol == 'C') )
       {
        // if statement
        if( (index > 0) && (index <= fileCol) )
           {
            return true;
           }

        // else statement
        else
           {
            return false;
           }

       }

    return false;
   }

void displayError()
   {
    // Display message
       // Function: printString, printEndLines
       printEndLines(2);
       printString("Row/Column indicator letter incorrect, processing aborted.", 0, "LEFT" );
       printEndLines(2);
   }

void displayError2()
   {
    // Display message
       // Function: printString, printEndLines
       printEndLines(2);
       printString("Row or column number incorrect, processing aborted.", 0, "LEFT" );
       printEndLines(2);
   }

void printArray( int arr[][MAX_COL], int &fileRow, int &fileCol )
   {
    // initialize variables
    int row, col;

    // print message
    printEndLines(3);
    printString("Array Display", 0, "LEFT");
    printEndLines(1);
    
    // print individual indexes
       // for loop
       for( row = 0 ; row < fileRow ; row++)
          {
           printChars(8, ' ');
           // for loop
           for( col = 0 ; col < fileCol ; col++)
              {
               // Functions: printInt, printEndLines
                printChar(' ');
                printInt( arr[row][col], 1, "LEFT");           
              }
           printEndLines(1);
          }
    printEndLines(2);
   }

double caclAverage( int arr[][MAX_COL], char &RowOrCol, int &index, int &fileRow, int &fileCol )
   {
    // initialize variables
    double ave;
    int count = 0;
    double num = 0;
    int temprow = index;
    int tempcol = index;

    // set to equivelent array index values
    temprow -= 1;
    tempcol -= 1;

    // add values in row or col
       // if row
       if( (RowOrCol == 'r') || (RowOrCol == 'R') )
          {
           // for loop
           for( tempcol = 0 ; tempcol < fileCol ; tempcol++)
              {
               num += arr[temprow][tempcol];
               count++; 
              }
          }

       // else
       else
          {
           // for loop
           for( temprow = 0 ; temprow < fileRow ; temprow++)
              {
               num += arr[temprow][tempcol];
               count++; 
              }
          }

   // calcualate average
   ave = double(num / count);

    return ave;
   }

double calcSD( int arr[][MAX_COL], char &RowOrCol, int &index, int &fileRow,
               int &fileCol, double ave )
   {
    // initialize variables
    double denom;
    double sumDenom = 0;
    double devDenom;
    double SD;
    int row, col;

    // give input values
    row = index;
    col = index;

    row -= 1;
    col -=1;

    // add values in row or col
       // if row
       if( (RowOrCol == 'r') || (RowOrCol == 'R') )
          {
           for( col = 0; col < fileCol ; col++)
              {
               denom = double(arr[row][col]) - ave;
               denom *= denom;
               sumDenom += denom;              
              }
           
           devDenom = sumDenom / fileCol;

          }

       // else
       else
          {
           for( row = 0; row < fileRow ; row++)
              {
               denom = double(arr[row][col]) - ave;
               denom *= denom;
               sumDenom += denom;   
              }

           devDenom = sumDenom / fileRow;
         
          }
   // calcualate Standard deviation
   SD = sqrt( devDenom);

    return SD; 
   }

void printData( double ave, double standardD, char &RowOrCol, int &index )
   {
    // printMessage
       // if row
       if( (RowOrCol == 'r') || (RowOrCol == 'R') )
          {
           // functions: printString, printInt
           printString("calculated data for row: ", 0, "LEFT");
           printInt( index, 0, "LEFT");
          }

       // else
       else
          {
           // functions: printString, printInt
           printString("calculated data for column: ", 0, "LEFT");
           printInt( index, 0, "LEFT");

          }

    printEndLines(1);
    printChars(8, ' ');

    // Print average
       // Function: printString, printDouble
       printString("Average: ", 0, "LEFT");
       printDouble( ave, 2, 0, "LEFT");
       printEndLines(1);
       printChars(8, ' ');

    // Prind Standard deviation
       // Function: printString, printDouble
       printString("Standard Deviation: ", 0, "LEFT");
       printDouble( standardD, 2, 0, "LEFT");
       printEndLines(2);


   }
