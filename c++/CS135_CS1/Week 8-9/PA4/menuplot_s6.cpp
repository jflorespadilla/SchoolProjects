//Header files
#include "formatted_console_io_v16.h"
#include <fstream>

using namespace std;

//Global constants
const string PLS_CONT = " Press any key to continue ";
const int DEFAULT_X = 25;
const int MENU_X = 44;
const int MENU_Y = 14;
const string MENU_PRMT = " " ;
const int ACQ_SCRN_X = 43;
const int ACQ_SCRN_Y = 8;
const string ACQ_SCRN_STRG = "" ;
const int BAD_ACQ_X = 25; 
const int BAD_ACQ_Y = 11; 
const string BAD_ACQ_STRG = " FILE ACCESS STATUS: File name is not valid";
const int GD_ACQ_X = 25;
const int GD_ACQ_Y = 11;
const string GD_ACQ_STRG = " FILE ACCESS STATUS: File name is valid";
const int PLS_X = 25;
const int PLS_Y = 13;
const string HIGH = "high";
const string LOW = "low";
const int PRECSN = 2;
const int X_COUNT = 50;
const int Y_COUNT = 7;
const int Y_AVE = 9;
const int Y_MAX = 11;
const int Y_MIN = 13; 


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
int getNumItems( const string &flName, ifstream &fin );

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
int getData( const string &flName, ifstream &fin, double low, double high);

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
    bool fileFlag = false;
    char selection;
    int counter = 0, varNum, gXPos = 13, gYPos = 18, numOf, highIntv = 5, lowIntv = 0,;
    double  average, max, min;

    // Start curses
       // Function: startCurses
       startCurses();

    // Post-test loop
       // Operation: do while loop
       do
          {
           // Clear screen & set color
           clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
           setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

       // Display Menu
          // Function: menuDisplay
            menuDisplay();

       // Get Input
          // Function: waitForInput
            selection = waitForInput( FIXED_WAIT );

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
                   setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

                // Function: prtAcquScreen
                   prtAcquScreen();

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
                                                            "LEFT" );
                // Function: printStringAt
                       printStringAt( PLS_X, PLS_Y, PLS_CONT, "LEFT" );
                // Hold screen for user
                   // waitForInput
                      waitForInput( FIXED_WAIT );

                     }

             // If bad, print bad-message
                   else
                     {
                // Function: printStringAt
                       printStringAt( BAD_ACQ_X, BAD_ACQ_Y, BAD_ACQ_STRG,
                                                            "LEFT" );
                // Function: printStringAt
                       printStringAt( PLS_X, PLS_Y, PLS_CONT, "LEFT" );

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
                      badMsg();
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
                      printIntAt( X_COUNT, Y_COUNT, numOf, "RIGHT" );

                // Find the average
                   // Function: getAverage
                      average = getAverage( fileName, fileIn );                   

                   // print average
                     // Function: printDoubleAt
                      printDoubleAt( X_COUNT, Y_AVE, average, PRECSN, "RIGHT" );

                // Find highest and lowest
                   // Function: getHighLow
                      max = getHighLow( fileName, fileIn, HIGH );
                      min = getHighLow( fileName, fileIn, LOW );
                   // print high
                      // Function: printDoubleAt
                      printDoubleAt( X_COUNT, Y_MAX, max, PRECSN, "RIGHT" );

                   // print low
                      // Function: printDoubleAt
                      printDoubleAt( X_COUNT, Y_MIN, min, PRECSN, "RIGHT" );                      

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
                   if( !fileFlag )
                      {
                // Function: badMsg
                       badMsg();
                // Hold screen for user
                   // Function: waitForInput
                       waitForInput( FIXED_WAIT );
                      }

             // if the file is good, preform graph
                   else
                      {
                // Print analysis graph
                   // Function: prtGraphScreen
                      clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
                      setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
                      prtGraphScreen();

                // Operation: while loop
                        while( counter < 8 )
                           {
                                        
                      // Function: getData    ( Function used for all variables)
                           varNum = getData( fileName, fileIn, lowIntv + counter * 5, highIntv + counter *5 );
                         // Function: printDataFor
                           printDataFor( varNum, gXPos, gYPos - counter * 2 );


                   // end loop
                            counter++;
                           }



                   // Hold screen for user
                       waitForInput( FIXED_WAIT );

                   // re-initialize values
                   counter = 0;


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
             
             // Clear screen & set color
                // Function: clearScreen, setColor
                 clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
                  setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

                 
             // Message to the user for incorret option
                // Function: inputErrorMsg
                inputErrorMsg();
             
             // Hold screen for user
                // Function: waitForInput
                  waitForInput( FIXED_WAIT );

                 break;
               }
    // End post-test loop
          }
       while( !done );

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
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // Print Header
       // Function: printStringAt  
       printStringAt( DEFAULT_X, 3, " DATA ANALYSIS PROGRAM", "LEFT" );
       printStringAt( DEFAULT_X, 7, " MENU SELECTIONS", "LEFT" ); 
       printStringAt( DEFAULT_X, 9, " 1. Get <F>ile name", "LEFT" );
       printStringAt( DEFAULT_X, 10, " 2. Display Stats <A>nalysis", "LEFT" );
       printStringAt( DEFAULT_X, 11, " 3. Display Analysis <G>raph", "LEFT" );
       
    // Print hard Line
       // Function: printStringAt
       printStringAt( DEFAULT_X, 4, " =====================", "LEFT" );
    // Print menu options
       // Function: printStringAt
       printStringAt( DEFAULT_X, 7, " MENU SELECTIONS", "LEFT" ); 
       printStringAt( DEFAULT_X, 9, " 1. Get <F>ile name", "LEFT" );
       printStringAt( DEFAULT_X, 10, " 2. Display Stats <A>nalysis", "LEFT" );
       printStringAt( DEFAULT_X, 11, " 3. Display Analysis <G>raph", "LEFT" );
       printStringAt( DEFAULT_X, 12, " 4. <Q>uit program", "LEFT" );

    // Print promt string
      // Function: printStringAt
      printStringAt( DEFAULT_X, 14, " Enter Selection: ", "LEFT" );      

      // move curser
         // Function: moveToXY
         moveToXY( MENU_X, 14 );

   }

void prtAcquScreen()
   {
    // Clear screen & set color
       // Functions: clearScreen, setColor
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // Print prompt message
       // Function: printStringAt
       printStringAt( DEFAULT_X, 4, " FILE NAME AQUSITION", "LEFT" );
       printStringAt( DEFAULT_X, 8, " Enter file name: ", "LEFT" );
   }

void badMsg()
   {
    // Clear screen & set color
       // Functions: clearScreen, set color
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // Print message
       // printStringAt
       printStringAt( DEFAULT_X, 4, "Error: File not found - Action Aborted",
                                                             "LEFT" );
   }

bool getFileData( string &flName, ifstream &fin )
   {
    // Open File
       // Functions: .clear, . open
       fin.clear();
       fin.open( flName.c_str() );

    // Check if good
       // Function: .good
       fin.good();

    // Close file
       // Function: .close
       fin.close();

    return fin.good();
   }

void printAnalyScreen()
   {
    // Clear screen & Set color
       // Functions: clearScreen, setColor
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
    
    // Print header & prompt lines
       // Function: printStringAt
       printStringAt( DEFAULT_X, 4, "DATA STATISTICAL ANALYSIS", "LEFT" );
       printStringAt( DEFAULT_X, 7, "Item Count:", "LEFT" );
       printStringAt( DEFAULT_X, 9, "Data Average:", "LEFT" );
       printStringAt( DEFAULT_X, 11, "Highest Data Item:", "LEFT" );
       printStringAt( DEFAULT_X, 13, "Lowest Data Item:", "LEFT" );
       printStringAt( 24, 16, PLS_CONT, "LEFT" );

   }

int getNumItems( const string &flName, ifstream &fin )
   {
    // Intitialize variables
    int count = -1;
    double num;
    

    // open File
       // Functions: .clear, .open
       fin.clear();
       fin.open( flName.c_str() );
    // Check for good file
       // Function: .good
       fin.good();

    // Loop
       //Operation: while loop
       while( fin.good() )
          {
           fin >> num;

           count++;
          }


    // Close file
       // Function: .close
       fin.close();


    return count; 
   }

double getAverage( const string &flName, ifstream &fin )
   {
    // Intitialize variables
    int count = -1;
    double num, ave, numSum = 0;
    

    // open File
       // Functions: .clear, .open
       fin.clear();
       fin.open( flName.c_str() );
    // Check for good file
       // Function: .good
       fin.good();

    // Loop
       //Operation: while loop
       while( fin.good() )
          {
           fin >> num;
           numSum = numSum + num;
           count++;
          }

       ave = numSum / count;

    // Close file
       // Function: .close
       fin.close();

    return ave;
   }

double getHighLow( const string &flName, ifstream &fin, const string &extrema )
   {
    // Intitialize variables
    double answer = 0, num;
        

    // open File
       // Functions: .clear, .open
       fin.clear();
       fin.open( flName.c_str() );


    // if High
    if( extrema == "high" )
       {
       // Loop
          //Operation: while loop
          while( fin.good() )
             {
              fin >> num;
              if( answer < num )
                 {
                  answer = num;
                 }

             }


        }
    // if low
    else
       {
        fin >> answer;
        // Loop
          //Operation: while loop
           while( fin.good() )
             {
              fin >> num;
              if( answer > num )
                 {
                  answer = num;
                 }

             }     

       }
    // Close file
       // Function: .close
       fin.close();
     
    return answer; 
   }

void prtGraphScreen()
   {
    //Clear screen and set color
       // Functions: clearScreen, setColor
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );


    // Print Hoizontal componets
       // Function: printStringAt
       printStringAt( DEFAULT_X, 1, "ANALYSIS GRAPH", "LEFT" );
       printStringAt( 11, 20, "-|----|----|----|----|----|----|----|----|----|----|----|",
                                                                              "LEFT" );
       printStringAt( 11, 21, " 0    5   10   15   20   25   30   35   40   45   50   55",
                                                                              "LEFT" );
       printStringAt( 40, 23, "FREQUENCY OF AMPLITUDES", "CENTER" );


    // Print Vertical compnents
       // Function: printStringVertical
       printStringVertical( 3, 6, "AMPLITUDES", "DOWN" );
       printStringVertical( 5, 4, "< < < < < < < <", "DOWN" );
       printStringVertical( 7, 4, "4 3 3 2 2 1 1  ", "DOWN" );
       printStringVertical( 8, 4, "0 5 0 5 0 5 0 5", "DOWN" );
       printStringVertical( 11, 1, "|||||||||||||||||||", "DOWN" );

    // Print bottom message
       // Functions: setColor, printStringAt
    setColor( COLOR_CYAN, COLOR_WHITE, SET_BRIGHT );
    printStringAt( 51, 23, PLS_CONT, "LEFT" );

   }

int getData( const string &flName, ifstream &fin, double Low, double High)
   {
    // Initialize variables
    double num;
    int count = 0;

    // Open File
       // functions: .clear, . open
       fin.clear();
       fin.open(flName.c_str() );

    // Loop
       // Operation: while loop
       while( fin.good() )
          {
           fin >> num;

           if( ( Low < num ) && ( High > num ) )
              {
               count++;
              }
          }

    // Close file
       // Function: .close
       fin.close();



      // ** high and low will be incremented when function is placed in looop **

   
    return count;
   }

void printDataFor( int dataVal, int xPos, int yPos )
   {    
    // Intinalize Variables
    int counter, xInt, yInt;
    xInt = xPos ;   
    yInt = yPos;
    counter = dataVal;

    // set color
       // Function: setColor
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );

    // While loop
    while( counter > 0)
    {
      printCharAt( xPos, yPos, 'H' );
      xPos++;
      counter --;
      
    }
    
   printIntAt( xPos + 2, yPos, dataVal, "LEFT" ); 


   }

void inputErrorMsg()
   {
    // Clear screen & set color
       // Functions: clearScreen, setColor
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );


    // print message
       // Functions: printStringAt
       printStringAt( 40, 3, "Please select an option from the menu", "CENTER" );
       printStringAt( 40, 5, "Try again", "CENTER" );
   }
