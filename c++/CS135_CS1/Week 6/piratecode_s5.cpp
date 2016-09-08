//Header files
# include "formatted_cmdline_io_v06.h"
# include <iostream>

using namespace std;

//Global constants
string HORIZONTAL_LINE = "----------------------------------------------------------------------------";
int TITLE_SPCE = 76;
int ALT_SPCE = 71;
//Function Prototypes

/*
Name: displayTable
Processing: Displays the table showing the phrase options
Input: none
Output/display: Table
Dependacies: formatted command line
*/
void displayTable();

/*
Name: displayInstr
Processing: Displays the bottom instructions
Input: none
Output/display: Instructions
Dependacies: formatted command line
*/
void displayInstr();

/*
Name: isGoodInput
Processing: Checks for acceptable input
Input: A letter character from the row, and integer from the column
Output/return: Boolean value
Dependacies: iostream
*/
bool isGoodInput( char row , int col );

/*
Name: translate
Processing: Translates user input to pirate speech
Input: A letter character from the row, integer from the column, and 
       a '-' or ',' to indicate continuation or not
Output/return: String pirate phrase
Dependacies: Formatted command line
*/
string translate( char row, int col, char sign );

/*
Name: isCont
Processing: checks if the user wants to continue or stop the phrase
Input: Character
Output/return: A boolean value
Dependacies: iostream
*/
bool isCont( char sign );

/*
Name: errorMessageForWrongInput
Processing: displays an error message to the user of incorrect input
Input: none
Output/display: error message
Dependacies: Formatted command line
*/
void errorMessageForWrongInput();

/*
Name: errorMessageForTooMany
Processing: displays an error message to the user of too many inputs
Input: none
Output/display: error message
Dependacies: Formatted command line
*/
void errorMessageForTooMany();


//Main function

int main()
   {
    // Initinalize variables
    char letter, punctuation;
    int number;
    string pirateTalk, pirateTalk2, pirateTalk3, pirateTalk4, pirateTalk5;
    string pirateTalk6, pirateTalk7, pirateTalk8, pirateTalk9, pirateTalk10;
    string finalPhrase;

    // Display table
       // Function: displayTable
       displayTable();

    // Display instruction
       // Function: displayInstr
       displayInstr();

    // Get user input
       // get row
          // Operator >>
       // get col
          // Operator >>
       // get next
          // Operator >>
          cin >> letter >> number >> punctuation;
       
        
    // Test input
       // Function: isGoodInput
       isGoodInput( letter, number );

       
    // Translate
       // Function: translate
       pirateTalk = translate( letter, number, punctuation );

    // Check for continue (Proper logic will hold the 9 other possible inputs )
       // Function: isCont
       isCont( punctuation );

       // if statements ( continues or ends the program )  
       if( isCont( punctuation ) )
          {
           // Repeat cin, cout and up to check isCont 8 more times
          }

       if( !(isCont( punctuation ) ) )
          {
           // get finalPhrase ( errorMessageForTooMany after tenth )
           /// finalPhrase = pirateTalk + pirateTalk2 + priateTalk3 + ... (etc).
          }


    // Display result
       // Function: printString
       printString( finalPhrase, 0, "LEFT" );

     // Hold sytem for user
     system( "pause" );
     return 0;

   }

//Function Implementations
void displayTable()
   {
    // Top line
       // Function: printString
       // Function: printchar
       printChar( '|' );
       printString( HORIZONTAL_LINE, 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);
       
    // Title
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( "PIRATE TRANSLATOR", TITLE_SPCE, "CENTER");
       printChar( '|' );
       printEndLines(1);
    // First row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( HORIZONTAL_LINE, 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // second row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
        printChar( '|' );
        printString( " A: | 1-Hello  2-Pardon me  3-Excuse me", 0, "LEFT" );
        printString( "                                     ", 0, "LEFT" );
        printChar( '|' );
        printEndLines(1);

    // Third row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Fourth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " B: | 1-Sir  2-Madam  3-Miss  4-Stranger  5-Officer", 0,
                                                                       "LEFT" );
       printString( "                         ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);
       
    // Fifth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Sixth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " C: | 1-Where is  2-Can you help me find  3-Is that  ", 0,
                                                                     "LEFT" );
       printString( "4-How far is it to     ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Seventh row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Eight row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " D: | 1-The  2-A  3-Any  4-Nearby 5-My  ", 0, "LEFT" );
       printString( "6-Your                              ", 0 , "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Ninth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Tenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " E: | 1-Old  2-Attractive  3-Happy", 0, "LEFT" );
       printString( "                                          ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Eleventh row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Twelveth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " F: | 1-Restroom  2-Restaurant  3-Hotel  ", 0, "LEFT" );
       printString( "4-Mall  5-Pub  6-Bank              ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Thirteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " ", TITLE_SPCE, "CENTER" );
       printChar( '|' );
       printEndLines(1);

    // Fourtheenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( "    | 1-I would like to  2-I desire  ", 0, "LEFT" );
       printString( "3-I wish I knew how to                 ", 0, "LEFT" );
       printChar( '|' );
       printEndLines(1);

    // Fifteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine
       printChar( '|' );
       printString( " G: |", 0, "LEFT" );
       printString( " ", ALT_SPCE, "CENTER");
       printChar( '|' );
       printEndLines(1);

    // Sixteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine

    // Seventeenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine

    // Eighteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine

    // Ninteenth row
       // Function: printChar
       // Function: printString
       // Function: printEndLine

    // Bottom row
       // Function: printChar
       // Function: printString
       // Function: printEndLine



   }

void displayInstr()
   {
    // Function: printString
    // Function: pringEndLine
   }

bool isGoodInput( char row , int col )
   {
    // Operation: switch
    // function: errorMessageForWrongInput  

    return 0; // stub return
   }

string translate( char row, int col, char sign )
   {
    // Operation: switch

    return "z";// stub
   }

bool isCont( char sign )
   {
    // Operation: if
    
    return 0; // stub
   }

void errorMessageForWrongInput()
   {
    //Function: printString
   }

void errorMessageForTooMany()
   {
    // Function: printString
   }
