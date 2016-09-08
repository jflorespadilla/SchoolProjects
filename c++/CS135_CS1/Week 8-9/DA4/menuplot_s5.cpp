//Header files
#include "formatted_console_io_v16.h"
#include <fstream>

using namespace std;

//Global constants
const string PLS_CONT = "Press any key to continue ";
const int MENU_X = 1; // temporary constant
const int MENU_Y = 1; // temporary constant
const string MENU_PRMT = " " ;// temorary constant
const int ACQ_SCRN_X = 1; // temporary constant
const int ACQ_SCRN_Y = 1; // temporary constant
const string ACQ_SCRN_STRG = " " ;// temporary constant
const int BAD_ACQ_X = 1; // temporary constant
const int BAD_ACQ_Y = 1; // temporary constant
const string BAD_ACQ_STRG = " "; // temporary constant
const int GD_ACQ_X = 1;// temporary constant
const int GD_ACQ_Y = 1; // temporary constant
const string GD_ACQ_STRG = " "; // temporary constant
const int PLS_X = 1; // temporary constant
const int PLS_Y = 1; // temporary constant
const string HIGH = "high";
const string LOW = "low";
const int PRECSN = 2; // temporary constant
const int X_COUNT = 1; // temporary constant
const int Y_COUNT = 1; // temporary constant
const int X_AVE = 1; // temporary constant
const int Y_AVE = 1; // temporary constant
const int X_MAX = 1; // temporary constant
const int Y_MAX = 1; // temporary constant
const int X_MIN = 1; // temporary constant
const int Y_MIN = 1; // temporary constant


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
int getData( const string &flName, ifstream &fin, double &low, double &high);

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
    ifstream fileIn;
    string fileName;
    bool done = false;
    bool fileFlag;
    char selection;
    int counter, varNum, gXPos, gYPos;
    double highIntv, lowIntv, numOf, average, max, min;

    // Start curses
       // Function: startCurses
       startCurses();

    // Post-test loop
       // Operation: do while loop
       do
          {

       // Display Menu
          // Function: menuDisplay
            menuDisplay();

       // Get Input
          // Function: promptForCharAt
            selection = promptForCharAt( MENU_X, MENU_Y, MENU_PRMT );

       // switch (selection, quit)
            switch( selection )
               {
          // Case 'F', 'f', '1'
                 case 'F':
                 case 'f':
                 case '1':
             // Clear screen & print title acquisition screen
                // Function: clearScreen
                   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X,
                                                           SCRN_MAX_Y );
                // Function: prtAcquScreen
                   void prtAcquScreen();

             // prompt user for file, check if good & open
                // Function: promptForStringAt
                   fileName = promptForStringAt( ACQ_SCRN_X, ACQ_SCRN_Y,
                                                              ACQ_SCRN_STRG );
                // Function: getFileData
                   fileFlag = getFileData( fileName, fileIn );
             // If good, print good message
                // Operation: if
                   if( fileFlag )
                     {
                // Function: printStringAt
                       printStringAt( GD_ACQ_X, GD_ACQ_Y, GD_ACQ_STRG,
                                                            "CENTER" );
                // Function: printStringAt
                       printStringAt( PLS_X, PLS_Y, PLS_CONT, "CENTER" );
                // Hold screen for user
                   // waitForInput
                      waitForInput( FIXED_WAIT );

                     }

             // If bad, print bad-message
                   else
                     {
                // Function: printStringAt
                       printStringAt( BAD_ACQ_X, BAD_ACQ_Y, BAD_ACQ_STRG,
                                                            "CENTER" );
                // Function: printStringAt
                       printStringAt( PLS_X, PLS_Y, PLS_CONT, "CENTER" );

                // Hold screen for user
                   // waitForInput
                      waitForInput( FIXED_WAIT );

                     }
                 break;

          // Case 'A', 'a', '2'
                 case 'A':
                 case 'a':
                 case '2':

             // if the file is bad, print message
                   if( !fileFlag )
                     {
                // Function: badMsg
                      void badMsg();
                // Hold screen for user
                   // Fucntion: waitForInput
                      waitForInput( FIXED_WAIT );

                     }

             //if the file is good, preform analysis
                   else
                     {
                // print data stat analysis
                   // Function: printAnalyScreen
                      printAnalyScreen();

                // Count the number of items
                   // Function: getNumItems
                      numOf = getNumItems( fileName, fileIn );

                   // print count
                      // Function: printDoubleAt
                      printDoubleAt( X_COUNT, Y_COUNT, numOf, PRECSN, "" );

                // Find the average
                   // Function: getAverage
                      average = getAverage( fileName, fileIn );                   

                   // print average
                     // Function: printDoubleAt
                      printDoubleAt( X_AVE, Y_AVE, average, PRECSN, "" );

                // Find highest and lowest
                   // Function: getHighLow
                      max = getHighLow( fileName, fileIn, HIGH );
                      min = getHighLow( fileName, fileIn, LOW );
                   // print high
                      // Function: printDoubleAt
                      printDoubleAt( X_MAX, Y_MAX, max, PRECSN, "" );

                   // print low
                      // Function: printDoubleAt
                      printDoubleAt( X_MIN, Y_MIN, min, PRECSN, "" );                      

                // Hold screen for user
                   // Function: waitForInput
                       waitForInput( FIXED_WAIT );

                      }
                 break;

          // Case 'G', 'g', '3'
                 case 'G':
                 case 'g':
                 case '3':
             // if the file is bad, print message
                   if( fileFlag )
                      {
                // Function: badMsg
                       void badMsg();
                // Hold screen for user
                   // Function: waitForInput
                       waitForInput( FIXED_WAIT );
                      }

             // if the file is good, preform graph
                   else
                      {
                // Print analysis graph
                   // Function: prtGraphScreen

                // Operation: while loop
                        while( counter <= 8 )
                           {
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
                           varNum = getData( fileName, fileIn, lowIntv, 
                                                                  highIntv);
                         // Function: printDataFor
                           printDataFor( varNum, gXPos, gYPos );


                   // end loop
                            counter++;
                           }

                   // Hold screen for user
                       waitForInput( FIXED_WAIT );
                      }

                 break;

          // Case 'Q', 'q', '4' (!Quit loops)
                 case 'Q':
                 case 'q':
                 case '4':
             // End loop, set flag to true
                  done = true;
                 break;

          //Default case
                 default:
                 
             // Message to the user for incorret option
                // Function: inputErrorMsg
             
             // Hold screen for user
                // Function: waitForInput
                  waitForInput( FIXED_WAIT );

                 break;
               }
    // End post-test loop
          }
       while( done );

    // End curses
       // Function: endCurses
       endCurses();

    return 0;

   }


//Function Implementations
void menuDisplay()
   {
    // Set screen color
       // Function: setColor

    // Print Header
       // Function: printStringAt    

    // Print hard Line
       // Function: printStringAt
    // Print menu options
       // Function: printStringAt

    // Print promt string
      // Function: printStringAt
      // move curser
         // Function: moveToXY
   }

void prtAcquScreen()
   {
    // Clear screen & set color
       // Functions: clearScreen, setColor

    // Print prompt message
       // Function: printStringAt
   }

void badMsg()
   {
    // Clear screen & set color
       // Functions: clearScreen, set color

    // Print message
       // printStringAt
   }

bool getFileData( string &flName, ifstream &fin )
   {
    // Open File
       // Functions: .clear, . open

    // Check if good
       // Function: .good

    // Close file
       // Function: .close

    return false; // Stub return
   }

void printAnalyScreen()
   {
    // Clear screen & Set color
       // Functions: clearScreen, setColor
    
    // Print header & prompt lines
       // Function: printStringAt
   }

double getNumItems( const string &flName, ifstream &fin )
   {
    // Intitialize variables

    // open File
       // Functions: .clear, .open

    // Check for good file
       // Function: .good

    // Close file
       // Function: .close

    // Loop
       //Operation: while loop

    return 0.00; // Stub return
   }

double getAverage( const string &flName, ifstream &fin )
   {
    // Intitialize variables

    // open File
       // Functions: .clear, .open

    // Check for good file
       // Function: .good

    // Close file
       // Function: .close

    // Loop
       //Operation: while loop

    // Calculate average
       // Operation: math

    return 0.00; // Stub return
   }

double getHighLow( const string &flName, ifstream &fin, const string &extrema )
   {
    // Intitialize variables

    // open File
       // Functions: .clear, .open

    // Check for good file
       // Function: .good

    // Close file
       // Function: .close

    // if High

       // Loop
          //Operation: while loop

    // if low

       // Loop
          //Operation: while loop

     
    return 0.00; // Stub return
   }

void prtGraphScreen()
   {
    // Print Hoizontal componets
       // Function: printStringAt

    // Print Vertical compnents
       // Function: printStringVerticalAt
    // Stub
   }

int getData( const string &flName, ifstream &fin, double &Low, double &High)
   {
    // Initialize variables

    // Open File
       // functions: .clear, . open

    // Check for good file
       // Function: .good

    // Close file
       // Function: .close


    // Loop
      // Operation: while loop

      // ** high and low will be incremented when function is placed in looop **

   
    return 0; // Stub return
   }

void printDataFor( int dataVal, int xPos, int yPos )
   {    
    // Intitialize Variables

    // If statemnts
      // Operation: if
      // If dataVal < 5
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 10
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 15
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 20
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 25
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 30
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 35
         // "H's for Histogram
            // Function: printStringAt

      // If dataVal < 40
         // "H's for Histogram
            // Function: printStringAt

   }

void inputErrorMsg()
   {
    // Clear screen & set color
       // Functions: clearScreen, setColor

    // print message
       // Functions: printStringAt
   }
