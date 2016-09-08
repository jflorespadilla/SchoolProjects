//Header files
#include <fstream>
#include "formatted_console_io_v16.h"

using namespace std;

//Global constants
const char fileWrite[] = "datafile.txt";
const char SHORTEST = 'l';
const char LONGEST = 'H';
const int GREEN_MIN_X = 10;
const int GREEN_MIN_Y = 5;
const int GREEN_MAX_X = 69;
const int GREEN_MAX_Y = 19;
const int FLN_PMT_X = 47;
const int FLN_PMT_Y = 9;
const bool CAP_FALSE = false;
const bool CAP_TRUE = true;
const bool LOWER_FALSE = false;
const bool LOWER_TRUE = true;
const bool WEIRD_FALSE = false;
const bool WEIRD_TRUE = true;


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
Name: fileNameScrn2
Processing: Displays the file name prompt screen
Input: None
Output/Display: The screen seen for every menu selection for opening a file
Dependencies: Console io tools
*/
void fileNameScrn2();

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
       an array to retrieve value.
Output/return: c-style string.
Dependencies: ifstream, supporting function isLetter.
*/
void getShortLong( ifstream &fin, char indicator, char array[], char fileName[] );

/*
Name: calcWordAve
Processing: Calculates the average word length in a given string
Input:  ifstream variable
Output/return: Double representing the average word length.
Dependencies: ifstream, supporting function isLetter
*/
double calcWordAve( ifstream &fin, int numOfWords, char fileName[] );


/*
Name: prntUpperCaseData
Processing: prints the amount of chars representing the unit amount of 
            Capital letters on to a graph.
Input: int representing a capital letter count, an x and y position.
Output/return: A char unit
Dependencies: console io tools, getUpperCaseData
*/
void prntUpperCaseData( int letterCount[], int XPos, int YPos );


/*
Name: prntLowerCaseData
Processing: prints the amount of chars representing the unit amount of 
            lower case letters on to a graph.
Input: int representing a lower case letter count, an x and y position.
Output/return: A char unit.
Dependencies: console io tools, getLowerCaseData
*/
void prntLowerCaseData( int letterCount[], int XPos, int YPos );

/*
Name: countLetters
Processing: Counts the number of letters in a given file and stores each letter
            counted in an array.
Input: ifstream, c-style string
Output/return: none
Dependencies: ifstream
*/
void countLetters( ifstream &fin, bool isCap, int array[] );

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
bool isLetter( char val, bool capital, bool lowerCase, bool weird );



//Main function

int main()
   {
    //Initialize variables
    bool done = false;
    char selection;
    char flName[30]; 
    char lWord[200];
    char sWord[200];
    ifstream inFile;
    ofstream outFile;
    int numOfWords;
    int letterCount[27];
    int letterStop = 0;
    double average;

    // Function: Start curses
    startCurses();

    // Post test loop
      // Operation: do while  
    do
       {     

       // Intitialize letterCount
       while( letterStop < 26 )
          {
           letterCount[letterStop] = 0;
           letterStop++;
          } 


       // Display Main screen
          // Function: mainScrn
          mainScrn();          

       // Get Input
          // Function: Typecast for char return for waitForInput
          selection = char( waitForInput( FIXED_WAIT ) );

       // Switch statement
       // Operation: Switch
           switch( selection )
              {
          // Case '1', 'S', 's'
                case '1':
                case 'S':
                case 's':
             // Get file name screen
                //fileNameScrn
                  fileNameScrn();

             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)
                promptForStringAt( FLN_PMT_X, FLN_PMT_Y, " ", flName );
 

             // Open File
                // Functions: .clear, .open
                inFile.clear();                
                inFile.open ( flName );

             // if statement
                if( inFile.good() )
                   {
                
                // Valid file screen if good
                   // Function: dataDispScrn
                     dataDisplayScrn();

                   // Calculate number of words
                      // Function: calcWordNum
                      numOfWords = calcWordNum( inFile );
                     
                   // Determain Longest & shortest word
                      // Function: getShortLong
                      getShortLong( inFile, SHORTEST, sWord, flName );
                      getShortLong( inFile, LONGEST, lWord, flName );

                   // Calculate average word length
                      // Function: calcWordAve
                      average = calcWordAve( inFile, numOfWords, flName );
                   // Display Data
                      // Functions: printIntAt, printDoubleAt, printStringAt
                      printIntAt( 49, 9, numOfWords, "LEFT" );
                      printStringAt( 49, 10, lWord, "LEFT");
                      printStringAt( 49, 11, sWord, "LEFT" );
                      printDoubleAt( 49, 12, average, 2, "LEFT" );
                   // Write file
                      // functions: writeFile
                      writeFile( outFile, numOfWords, lWord, sWord, average );

             // Hold screen for user
                // Function: waitForInput
                      waitForInput( FIXED_WAIT );
             // Close file
                // Function: .close
                      inFile.close();

             // End If statement
                   }

                else
                   {
               // error message screen else bad
                 // Funcction: invalidFileScrn
                      invalidFileScrn();

               // Hold screen for user
                  //Function: waitForInput
                      waitForInput( FIXED_WAIT );
                   }

                break;

          // Case '2', 'U', 'u'
                case '2':
                case 'U':
                case 'u':
             // Clear screen
                // Functions: clearScreen, setColor
             // Get file name screen
                // Function: fileNameScrn
                  fileNameScrn2();

             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)
                  promptForStringAt( FLN_PMT_X, FLN_PMT_Y, " ", flName );


             // Open File
                // Functions: .clear, .open
                  inFile.clear();                
                  inFile.open ( flName );

             // If statement
                  if( inFile.good() )
                     {
                // Graphing screen if valid file
                  // clear screen
                     // Functions: upperGraphScrn
                     upperGraphScrn();

                  // Get Upper case data
                     // Function: countLetters
                      countLetters( inFile, CAP_TRUE,  letterCount );

                  // Graph Upper case data
                     // Functions: prntUpperCaseData
                      prntUpperCaseData( letterCount, 17, 20 );

                // Hold screen for user
                   // Function: waitForInput
                      waitForInput( FIXED_WAIT );

                // Close file
                   // Functions: .close
                      inFile.close();

             // End If statement
                     }

                  else
                     {
                // Error message else bad
                      invalidFileScrn();

                // Hold Screen for user
                   // Function: waitForInput
                      waitForInput( FIXED_WAIT );
                     }
                break;

          // Case '3', 'L', 'l'
                case '3':
                case 'L':
                case 'l':

             // Clear sceen
                // Functions: clearScreen, setColor
             // Get file name screen
                // Function: fileNameScrn
                  fileNameScrn2();

             // prompt for c-style string to get file name
                // Function: promptForStringAt (void version)
                  promptForStringAt( FLN_PMT_X, FLN_PMT_Y, " ", flName );

             // Open File
                // Functions: .clear, .open
                  inFile.clear();                
                  inFile.open ( flName );

             // If statement
                   if ( inFile.good() )
                      {
                // Graphing screen if valid file
                      // Functions: lowerGraphScrn
                       lowerGraphScrn();

                   // Get Lower case data
                      // Function: countLetters
                       countLetters( inFile, CAP_FALSE, letterCount );                  

                   // Graph Lower case data
                      // prntLowerCaseData
                       prntLowerCaseData( letterCount, 17, 20 );

                 // Hold screen for user
                    // Function: waitForInput
                       waitForInput( FIXED_WAIT );

                 // Close file
                    // Function: .close
                       inFile.close();

             // End If statement
                      }

                   else
                      {
                // Error message else bad
                       invalidFileScrn();

                // Hold Screen for user
                   // Function: waitForInput
                       waitForInput( FIXED_WAIT );
                      }

                break;
                
          // Case '4', 'Q','q'
                case '4':
                case 'Q':
                case 'q':
             // set flag to true to end program
                  done = true;
                break;

              }
    // End post test loop
       }
    while( !done );

    // Function: endCurses
    endCurses();

    return 0;

   }

//Function Implementations

void mainScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( GREEN_MIN_X, GREEN_MIN_Y, GREEN_MAX_X, GREEN_MAX_Y );  


    // Print text
       // Function: printStringAt
       printStringAt( 12, 6, "Text Analysis Program", "LEFT" );
       printStringAt( 12, 7, "=====================", "LEFT" );
       printStringAt( 12, 9, "Analysis Menu", "LEFT" );
       printStringAt( 12, 10, "-------------", "LEFT" );
       printStringAt( 12, 12, "1. <S>how brief analysis description", "LEFT" );
       printStringAt( 12, 13, "2. Plot <U>pper case letter frequency", "LEFT" );
       printStringAt( 12, 14, "3. Plot <L>ower case letter frequency", "LEFT" );
       printStringAt( 12, 15, "4. <Q>uit", "LEFT" );

   }

void fileNameScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( GREEN_MIN_X, GREEN_MIN_Y, GREEN_MAX_X, GREEN_MAX_Y );  


    // Print text
       // Function: printStringAt
       printStringAt( 12, 6, "Breif Analysis Description", "LEFT" );
       printStringAt( 12, 7, "--------------------------", "LEFT" );
       printStringAt( 12, 9, "Enter file name of analysis file  : ", "LEFT" );

   }

void fileNameScrn2()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( GREEN_MIN_X, GREEN_MIN_Y, GREEN_MAX_X, GREEN_MAX_Y );  


    // Print text
       // Function: printStringAt
       printStringAt( 12, 6, "File Open Moduel - Graph", "LEFT" );
       printStringAt( 12, 7, "--------------------------", "LEFT" );
       printStringAt( 12, 9, "Enter file name of analysis file  : ", "LEFT" );

   }


void dataDisplayScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( GREEN_MIN_X, GREEN_MIN_Y, GREEN_MAX_X, GREEN_MAX_Y );  

    // Print text
       // Function: printStringAt
       printStringAt( 12, 6, "Breif Analysis Description", "LEFT" );
       printStringAt( 12, 7, "--------------------------", "LEFT" );
       printStringAt( 12, 9, "Number of words                   :", "LEFT" );
       printStringAt( 12, 10, "Largest word                      :", "LEFT" );
       printStringAt( 12, 11, "Shortest word                     :", "LEFT" );
       printStringAt( 12, 12, "Average word length               :", "LEFT" );
       printStringAt( 12, 14, "Analysis complete", "LEFT" );
       printStringAt( 12, 16, "Press any key to continue...", "LEFT" );
   }

void invalidFileScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
       setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
       clearScreen( GREEN_MIN_X, GREEN_MIN_Y, GREEN_MAX_X, GREEN_MAX_Y );  

    // Print text
       // Function: printStringAt
       printStringAt( 12, 6, "Error Message Module", "LEFT" );
       printStringAt( 12, 7, "--------------------------", "LEFT" );
       printStringAt( 16, 12, "Invalid file name - Module aborted", "LEFT" );
       printStringAt( 12, 16, "Press any key to continue...", "LEFT" );

   }

void upperGraphScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // Print text
       // Function: printStringAt
       printStringAt( 2, 3, "1 mark = 2", "LEFT" );
       printStringAt( 40, 2, "UPPER CASE FREQUENCIES", "CENTER" );
       printStringAt( 12, 6, "30", "LEFT" );
       printStringAt( 12, 11, "20", "LEFT" );
       printStringAt( 12, 16, "10", "LEFT" );
       printStringAt( 3, 22, "LETTERS", "LEFT" );
       printStringAt( 15, 21, "|-----------------------------------------------------|", "LEFT" );
       printStringAt( 15, 22, "| A B C D E F G H I J K L M N O P Q R S T U V W X Y Z |", "LEFT" );

    // Print Vertical text
       // printStringVertical
       printStringVertical( 7, 7, "FREQUENCIES", "DOWN" );
       printStringVertical( 15, 20, "||||-||||-||||-||", "UP" );
    
    // End instruction
       // Function setColor, printStringAt
       setColor( COLOR_CYAN, COLOR_WHITE, SET_BRIGHT );
       printStringAt( 50, 23, "Press any key to continue...", "LEFT" );

   }

void lowerGraphScrn()
   {
    // Set the color and clear the screen
       // Function: clearScreen, setColor
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // Print text
       // Function: printStringAt
       printStringAt( 2, 3, "1 mark = 40", "LEFT" );
       printStringAt( 40, 2, "LOWER CASE FREQUENCIES", "CENTER" );
       printStringAt( 11, 6, "600", "LEFT" );
       printStringAt( 11, 11, "400", "LEFT" );
       printStringAt( 11, 16, "200", "LEFT" );
       printStringAt( 3, 22, "LETTERS", "LEFT" );
       printStringAt( 15, 21, "|-----------------------------------------------------|", "LEFT" );
       printStringAt( 15, 22, "| A B C D E F G H I J K L M N O P Q R S T U V W X Y Z |", "LEFT" );

    // Print Vertical text
       // printStringVertical
       printStringVertical( 7, 7, "FREQUENCIES", "DOWN" );
       printStringVertical( 15, 20, "||||-||||-||||-||", "UP" );
    
    // End instruction
       // Function setColor, printStringAt
       setColor( COLOR_CYAN, COLOR_WHITE, SET_BRIGHT );
       printStringAt( 50, 23, "Press any key to continue...", "LEFT" );

   }

int calcWordNum( ifstream &fin )
    {
     // initialize variables
     char val[200];
     int wordCount = 0;
     
     // Prime Loop
     fin >> val;
     
     while( fin.good() )
        {
         if (charInString( '-', val ) )
            {
             wordCount++;
            }
         wordCount++;
         fin >> val;
        }  
     // Function: .close to reset processing of the file for next function
     fin.close();

     return wordCount;
    }

void getShortLong( ifstream &fin, char indicator, char array[], char fileName[] )
   {
    // initialize variables
    int aIndex = 0;
    int bIndex = 0;
    int aCounter = 0;
    int bCounter = 0;
    char dummy[200];

    // Open File
    fin.clear();
    fin.open( fileName );

    // Switch statement
    switch( indicator )
       {
        // case 'l':
        case SHORTEST:
          // Prim loop
          fin >> array;
          fin >> dummy;
          
          // Check for loop skipping characaters
          if( !(isLetter( array[aIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE)) )
            {
             aIndex++;
            }          

          // pre-test loop with .good contiton
          while( fin.good() )
             {
              // pre-test loop with isLetter condition
              while( isLetter( array[aIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE) )
                 {
                  // increment counter
                  aCounter++;
                  aIndex++;
                 }

          // Check for loop skipping characters
          if( !(isLetter( dummy[bIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE)) )
            {
             bIndex++;
            }          


              // pre-test loop with isLetter condition
              while( isLetter( dummy[bIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE) )
                 {
                  // increment secondary counter
                  bCounter++;
                  bIndex++;
                 }
 
              // if statement
              // if counter < secondary counter
              if( aCounter <= bCounter )
                 {
                  // fin new value for secondary array value
                  fin >> dummy;
                  // reset counter values
                  aIndex = 0;
                  bIndex = 0;
                  aCounter = 0;
                  bCounter = 0;
                 }
 
              // else counter > seccondary counter
              else
                 {
                  // copy srn to array, fin new value for secondary array
                  strcpy( array, dummy);
                  // reset counter values
                  aIndex = 0;
                  bIndex = 0;
                  aCounter = 0;
                  bCounter = 0;
 
                 }
 
             }
        break;
 
        // case 'h':
        case LONGEST: 
        // Prim loop
          fin >> array;
          fin >> dummy;
 
          // pre-test loop with .good contiton
          while( fin.good() )
             {
              // pre-test loop with isLetter condition
              while( isLetter( array[aIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE) )
                 {
                  // increment counter
                  aCounter++;
                  aIndex++;
                 }
 
              // pre-test loop with isLetter condition
              while( isLetter( dummy[bIndex], CAP_TRUE, LOWER_TRUE, WEIRD_TRUE) )
                 {
                  // increment secondary counter
                  bCounter++;
                  bIndex++;
                 }
 
              // if statement
              // if counter > secondary counter
              if( aCounter >= bCounter )
                 {
                  // fin new value for secondary array value
                  fin >> dummy;
                  // reset counter values
                  aIndex = 0;
                  bIndex = 0;
                  aCounter = 0;
                  bCounter = 0;
                 }
 
              // else counter < seccondary counter
              else
                 {
                  // copy srn to array, fin new value for secondary array
                  strcpy( array, dummy);
                  // reset counter values
                  aIndex = 0;
                  bIndex = 0;
                  aCounter = 0;
                  bCounter = 0;
 
                 }
 
             }
        break;
       }
    // Close file
    fin.close();

   }

double calcWordAve( ifstream &fin, int numOfWords, char fileName[] )
   {
    // initialize variables
    double letterCount = 0;
    double ave;
    char letter;
    
    // Open the file
    fin.clear();
    fin.open( fileName );
    
    // Prime loop
    fin >> letter;
    while( fin.good() )
       {
        
        if(isLetter( letter, CAP_TRUE, LOWER_TRUE, WEIRD_TRUE) )
           {
            letterCount++;
           }

        fin >> letter;

       }
    
    // Calcualate the average
    ave = (letterCount / numOfWords);

    // .close to reset file processing for the next function
    fin.close();
    return ave; 
   }

void prntUpperCaseData( int letterCount[], int XPos, int YPos )
   {
    // initialize variables
    int printCounter = 0;

    // set color
       // Function: setColor
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );

    // pre-test loop for A
    while( printCounter < letterCount[0]/2 )
       {
        printCharAt( XPos, YPos, 'A' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 19;

    // pre-test loop for B
    while( printCounter < letterCount[1]/2 )
       {
        printCharAt( XPos, YPos, 'B' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 21;

    // pre-test loop for C
    while( printCounter < letterCount[2]/2 )
       {
        printCharAt( XPos, YPos, 'C' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 23;

    // pre-test loop for D
    while( printCounter < letterCount[3]/2 )
       {
        printCharAt( XPos, YPos, 'D' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 25;

    // pre-test loop for E
    while( printCounter < letterCount[4]/2 )
       {
        printCharAt( XPos, YPos, 'E' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 27;

    // pre-test loop for F
    while( printCounter < letterCount[5]/2 )
       {
        printCharAt( XPos, YPos, 'F' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 29;

    // pre-test loop for G
    while( printCounter < letterCount[6]/2 )
       {
        printCharAt( XPos, YPos, 'G' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 31;

    // pre-test loop for H
    while( printCounter < letterCount[7]/2 )
       {
        printCharAt( XPos, YPos, 'H' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 33;

    // pre-test loop for I
    while( printCounter < letterCount[8]/2 )
       {
        printCharAt( XPos, YPos, 'I' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 35;

    // pre-test loop for J
    while( printCounter < letterCount[9]/2 )
       {
        printCharAt( XPos, YPos, 'J' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 37;

    // pre-test loop for K
    while( printCounter < letterCount[10]/2 )
       {
        printCharAt( XPos, YPos, 'K' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 39;

    // pre-test loop for L
    while( printCounter < letterCount[11]/2 )
       {
        printCharAt( XPos, YPos, 'L' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 41;

    // pre-test loop for M
    while( printCounter < letterCount[12]/2 )
       {
        printCharAt( XPos, YPos, 'M' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 43;

    // pre-test loop for N
    while( printCounter < letterCount[13]/2 )
       {
        printCharAt( XPos, YPos, 'N' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 45;

    // pre-test loop for O
    while( printCounter < letterCount[14]/2 )
       {
        printCharAt( XPos, YPos, 'O' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 47;

    // pre-test loop for P
    while( printCounter < letterCount[15]/2 )
       {
        printCharAt( XPos, YPos, 'P' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 49;

    // pre-test loop for Q
    while( printCounter < letterCount[16]/2 )
       {
        printCharAt( XPos, YPos, 'Q' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 51;

    // pre-test loop for R
    while( printCounter < letterCount[17]/2 )
       {
        printCharAt( XPos, YPos, 'R' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 53;

    // pre-test loop for S
    while( printCounter < letterCount[18]/2 )
       {
        printCharAt( XPos, YPos, 'S' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 55;

    // pre-test loop for T
    while( printCounter < letterCount[19]/2 )
       {
        printCharAt( XPos, YPos, 'T' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 57;

    // pre-test loop for U
    while( printCounter < letterCount[20]/2 )
       {
        printCharAt( XPos, YPos, 'U' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 59;

    // pre-test loop for V
    while( printCounter < letterCount[21]/2 )
       {
        printCharAt( XPos, YPos, 'V' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 61;

    // pre-test loop for W
    while( printCounter < letterCount[22]/2 )
       {
        printCharAt( XPos, YPos, 'W' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 63;

    // pre-test loop for X
    while( printCounter < letterCount[23]/2 )
       {
        printCharAt( XPos, YPos, 'X' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 65;

    // pre-test loop for Y
    while( printCounter < letterCount[24]/2 )
       {
        printCharAt( XPos, YPos, 'Y' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 67;

    // pre-test loop for Z
    while( printCounter < letterCount[25]/2 )
       {
        printCharAt( XPos, YPos, 'Z' );
        printCounter++;
        YPos--;
       }

   }

void prntLowerCaseData( int letterCount[], int XPos, int YPos )
   {
    // initialize variables
    int printCounter = 0;

    // set color
       // Function: setColor
       setColor( COLOR_BLUE, COLOR_WHITE, SET_BRIGHT );

    // pre-test loop for a
    while( printCounter < letterCount[0]/40 )
       {
        printCharAt( XPos, YPos, 'a' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 19;

    // pre-test loop for b
    while( printCounter < letterCount[1]/40 )
       {
        printCharAt( XPos, YPos, 'b' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 21;

    // pre-test loop for c
    while( printCounter < letterCount[2]/40 )
       {
        printCharAt( XPos, YPos, 'c' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 23;

    // pre-test loop for d
    while( printCounter < letterCount[3]/40 )
       {
        printCharAt( XPos, YPos, 'd' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 25;

    // pre-test loop for e
    while( printCounter < letterCount[4]/40 )
       {
        printCharAt( XPos, YPos, 'e' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 27;

    // pre-test loop for f
    while( printCounter < letterCount[5]/40 )
       {
        printCharAt( XPos, YPos, 'f' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 29;

    // pre-test loop for g
    while( printCounter < letterCount[6]/40 )
       {
        printCharAt( XPos, YPos, 'g' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 31;

    // pre-test loop for h
    while( printCounter < letterCount[7]/40 )
       {
        printCharAt( XPos, YPos, 'h' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 33;

    // pre-test loop for i
    while( printCounter < letterCount[8]/40 )
       {
        printCharAt( XPos, YPos, 'i' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 35;

    // pre-test loop for j
    while( printCounter < letterCount[9]/40 )
       {
        printCharAt( XPos, YPos, 'j' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 37;

    // pre-test loop for k
    while( printCounter < letterCount[10]/40 )
       {
        printCharAt( XPos, YPos, 'k' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 39;

    // pre-test loop for l
    while( printCounter < letterCount[11]/40 )
       {
        printCharAt( XPos, YPos, 'l' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 41;

    // pre-test loop for m
    while( printCounter < letterCount[12]/40 )
       {
        printCharAt( XPos, YPos, 'm' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 43;

    // pre-test loop for n
    while( printCounter < letterCount[13]/40 )
       {
        printCharAt( XPos, YPos, 'n' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 45;

    // pre-test loop for o
    while( printCounter < letterCount[14]/40 )
       {
        printCharAt( XPos, YPos, 'o' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 47;

    // pre-test loop for p
    while( printCounter < letterCount[15]/40 )
       {
        printCharAt( XPos, YPos, 'p' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 49;

    // pre-test loop for q
    while( printCounter < letterCount[16]/40 )
       {
        printCharAt( XPos, YPos, 'q' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 51;

    // pre-test loop for r
    while( printCounter < letterCount[17]/40 )
       {
        printCharAt( XPos, YPos, 'r' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 53;

    // pre-test loop for s
    while( printCounter < letterCount[18]/40 )
       {
        printCharAt( XPos, YPos, 's' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 55;

    // pre-test loop for t
    while( printCounter < letterCount[19]/40 )
       {
        printCharAt( XPos, YPos, 't' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 57;

    // pre-test loop for u
    while( printCounter < letterCount[20]/40 )
       {
        printCharAt( XPos, YPos, 'u' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 59;

    // pre-test loop for v
    while( printCounter < letterCount[21]/40 )
       {
        printCharAt( XPos, YPos, 'v' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 61;

    // pre-test loop for w
    while( printCounter < letterCount[22]/40 )
       {
        printCharAt( XPos, YPos, 'w' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 63;

    // pre-test loop for x
    while( printCounter < letterCount[23]/40 )
       {
        printCharAt( XPos, YPos, 'x' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 65;

    // pre-test loop for y
    while( printCounter < letterCount[24]/40 )
       {
        printCharAt( XPos, YPos, 'y' );
        printCounter++;
        YPos--;
       }
    // Reset values
    printCounter = 0;
    YPos = 20;
    XPos = 67;

    // pre-test loop for z
    while( printCounter < letterCount[25]/40 )
       {
        printCharAt( XPos, YPos, 'z' );
        printCounter++;
        YPos--;
       }

   }

void countLetters( ifstream &fin, bool isCap, int array[] )
   {
    // initialize variables
    int subtractor;
    char value;
    bool cap, low;    

    // if statement
    if( isCap )
       {
        // Capital A ASKII value
        subtractor = 65;
        cap = true;
        low = false;
       }
       
    else
       {
       // Lower case A ASKII value
        subtractor = 97;
        cap = false;
        low = true;
       }

    
    // Pre-test loop
    while( fin. good() )
       {
        fin >> value;
        if( isLetter( value, cap, low, WEIRD_FALSE) )
           {
            array[ value - subtractor ]++;
           }

       }
    
   }

void writeFile( ofstream &fout, int letNum, char longest[], char shortest[],
                                                           double average )
   {
    // initialize variables

    // Open and write file
    fout.open( fileWrite );


    // Write title
       // Function: fout
       fout << "TEXT FILE STATISTICS" << endl;
       fout << "--------------------" << endl << endl << endl;

    // Write out number of letter
       // Function: fout
       fout << "Number of words: " << letNum << endl;

    // Write out Longest and shortest word
       // Function: fout
       fout << "Longest word: " << longest << endl;
       fout << "Shortest word: " << shortest << endl;

    // Write out the average
       // Function: fout
       fout << "Average word length: " << average << endl << endl << endl;
       fout << "====================" << endl;

    // Close file
    fout.close();

   }

bool isLetter( char val, bool capital, bool lowerCase, bool weird )
   {

    // If capital true
    if( capital )
       {
        // If char within chraracter range
        if( val >= 'A' && val <= 'Z' )
           {
            // return true
            return true;
           }
       }

    // If lowerCase true
    if( lowerCase )
       {
        // If char within chraracter range
        if( val >= 'a' && val <= 'z' )
           {
            // return true
            return true;
           }
       }

    // If weird true
    if( weird )
       {
        // If char within chraracter range
        if( val == char( 39 ) )
           {
            // return true
            return true;
           }
       }

    return false; 
   }
