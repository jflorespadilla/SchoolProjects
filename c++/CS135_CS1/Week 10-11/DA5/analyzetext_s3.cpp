//Header files
#include <fstream>
#include "formatted_console_io_v16.h"

using namespace std;

//Global constants

//Function Prototypes

/*
Name: mainScrn
Processing: Displays the main screen of the program
Input: None
Output/Display: The first menu seen in the program
Dependencies: Console io tools
*/
void mainScrn();

/*
Name: fileNameScrn
Processing: Displays the file name prompt screen
Input: None
Output/Display: The screen seen for every menu selection for opening a file
Dependencies: Console io tools
*/
void fileNameScrn();

/*
Name: dataDisplayScrn
Processing: Displays the data analysis screen
Input: None
Output/Display: The analysis screen (Only when a vaid file name is open)
Dependencies: console io tools
*/
void dataDisplayScrn();

/*
Name: invalidFileScrn
Processing: Displays an error message to the user
Input: None
Output/return: Indicates a failure to open a file
Dependencies: console io tools
*/
void invalidFileScrn();

/*
Name: upperGraphScrn
Processing: Displays the graph for upper case graphing
Input: None
Output/display: Displays the X and Y axis, and other supporting information.
Dependencies: Console io tools
*/
void upperGraphScrn();

/*
Name: lowerGraphScrn
Processing: Displays the graph for lower case graphing
Input: None
Output/Display:Displays the X and Y axis, and other supporting information.
Dependencies: console io tools
*/
void lowerGraphScrn();

/*
Name: calcWordNum
Processing: Calculates the number of words in a string found in a file
Input: ifstream variable
Output/return: Integer representing the number of words found.
Dependencies: ifstream, supporting function isLetter.
*/
int calcWordNum( ifstream &fin );

/*
Name: getShotLong
Processing: gets either the shorest or longest word in file
Input: ifstream variable, Char indicating what to retreive ( LONG or SHORT )
Output/return: c-style string.
Dependencies: ifstream, supporting function isLetter.
*/
void getShortLong( ifstream &fin, char indicator, char array[] );

/*
Name: calcWordAve
Processing: Calculates the average word length in a given string
Input:  ifstream variable
Output/return: Double representing the average word length.
Dependencies: ifstream, supporting function isLetter
*/
double calcWordAve( ifstream &fin );


/*
Name: prntUpperCaseData
Processing: prints the amount of chars representing the unit amount of 
            Capital letters on to a graph.
Input: int representing a capital letter count, an x and y position.
Output/return: A char unit
Dependencies: console io tools, getUpperCaseData
*/
void prntUpperCaseData( int letterCount, int XPos, int YPos, char array[] );


/*
Name: prntLowerCaseData
Processing: prints the amount of chars representing the unit amount of 
            lower case letters on to a graph.
Input: int representing a lower case letter count, an x and y position.
Output/return: A char unit.
Dependencies: console io tools, getLowerCaseData
*/
void prntLowerCaseData( int letterCount, int XPos, int YPos, char array[] );

/*
Name: countLetters
Processing: Counts the number of letters in a given file and stores each letter
            counted in an array.
Input: ifstream, c-style string
Output/return: none
Dependencies: ifstream
*/
void countLetters( ifstream &fin, char array[] );

/*
Name: writeFile
Processing: Writes a file with some given information
Input: ofstream variable, an int, c-style string for long, c-style string for
       short, and a double value.
Output/return: Creates a text file called datafile.txt
Dependencies: ofstream
*/
void writeFile( ofstream &fout, int letNum, char longest[], char shortest[],
                                                           double average );

/*
Name: isLetter
Processing: Analyzes an index of an array and either returns true or false
Input: An array index, and three boolean switches
Output/return: It will either return true or fals ( what retun varies on the
               switches and what is desired )
Dependencies: To be used in a function that involves analyzing texts.
*/
bool isLetter( char array[], bool capital, bool lowerCase, bool weird );



//Main function

int main()
   {
    //Initialize variables

    // Post test loop
      // Operation: do while       

       // Clear screen
          // Functions: clear sreeen & set color (x2)

       // Display Main screen
          // Function: mainScrn

       // Get Input
          // Function: Typecast for char return for waitForInput

       // Switch statement
       // Operation: Switch
          // Case '1', 'S', 's'
             // Get file name screen
                //fileNameScrn

             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)

             // clear screen
                // Functions: clear sreeen & set color

             // if statement
                // Open File
                   // Functions: .clear, .open
                
                // Valid file screen if good
                   // Function: dataDispScrn

                   // Calculate number of words
                      // Function: calcWordNum
                   // Determain Longest & shortest word
                      // Function: getShortLong
                   // Calculate average word length
                      // Function: calcWordAve
                   // Display Data
                      // Functions: printIntAt, printDoubleAt, printCharAt
                      

                   // Write file
                      // functions: writeFile
                   

             // Hold screen for user
                // Function: waitForInput
             // Close file
                // Function: .close

             // End If statement

               // error message screen else bad
                 // Funcction: invalidFileScrn
               // Hold screen for user
                  //Function: waitForInput

          // Case '2', 'U', 'u'
             // Clear screen
                // Functions: clearScreen, setColor
             // Get file name screen
                // Function: fileNameScrn
             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)
             // clear screen
                // Functions: clearScreen, setColor
             // If statement
             // Open file
                //Functions: .clear, .open
                // Graphing screen if valid file
                  // clear screen
                     // Functions: clearScreen, setColor, upperGraphScrn
                  // Get Upper case data
                     // Function: countLetters
                  // Graph Upper case data
                     // Functions: prntUpperCaseData
                // Hold screen for user
                   // Function: waitForInput
                // Close file
                   // Functions: .close

             // End If statement



                // Error message else bad
                // clear screen
                   // Functions: clearScreen, setColor
                // Hold Screen for user
                   // Function: waitForInput

          // Case '3', 'L', 'l'
             // Clear sceen
                // Functions: clearScreen, setColor
             // Get file name screen
                // Function: fileNameScrn
             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)
             // clear screen
                //Functions: clearScreen, setColor
             // If statement
                // Graphing screen if valid file
                   // Open file
                     // Functions: .clear, .open
                   // clear screen
                      // Functions: clearScreen, setColor, lowerGraphScrn
                   // Get Lower case data
                      // Function: countLetters
                   // Graph Lower case data
                      // prntLowerCaseData
                 // Hold screen for user
                    // Function: waitForInput
                 // Close file
                    // Function: .close

             // End If statement



                // Error message else bad
                // clear screen
                   // Functions: clearScreen, setColor
                // Hold Screen for user
                   // Function: waitForInput
    

          // Case '4', 'Q','q'
             // set flag to true to end program
          
    // End post test loop


    return 0;

   }

//Function Implementations

void mainScrn()
   {
    // Stub
   }

void fileNameScrn()
   {
    // Stub
   }

void dataDisplayScrn()
   {
    // Stub
   }

void invalidFileScrn()
   {
    // Stub
   }

void upperGraphScrn()
   {
    // Stub
   }

void lowerGraphScrn()
   {
    // Stub 
   }

int calcWordNum( ifstream &fin )
    {
     return 0; // Stub return
    }

void getShortLong( ifstream &fin, char indicator, char array[] )
   {
    // Stub return
   }

double calcWordAve( ifstream &fin )
   {
    return 0; //
   }

void prntUpperCaseData( int letterCount, int XPos, int YPos, char array[] )
   {
    // Stub
   }

void prntLowerCaseData( int letterCount, int XPos, int YPos, char array[] )
   {
    // Stub
   }

void countLetters( ifstream &fin, char array[] )
   {
    // Stub
   }

void writeFile( ofstream &fout, int letNum, char longest[], char shortest[],
                                                           double average )
   {
    // Stub
   }

bool isLetter( char array[], bool capital, bool lowerCase, bool weird )
   {
    return false; // Stub
   }
