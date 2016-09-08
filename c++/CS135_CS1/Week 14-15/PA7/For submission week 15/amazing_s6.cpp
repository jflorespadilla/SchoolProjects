//Header files
#include <fstream>
#include <time.h>
#include "formatted_console_io_v16.h"

using namespace std;

//Global constants
const int MAX_COL = 70;
const int MAX_ROW = 20;
const int MAX_CHAR_NAME = 25;
const int MAX_SCORE_SLOTS = 11;
const char MASTER_FILE[] = "mazenames.txt";
const char SCORE_FILE[] = "scores.txt";

//Function Prototypes

/*
Name: welcomeScreen
Processing: Displays the first splash screen
Input: None
Output/Return: Splash Screen display
Dependencies: formatted console io
Developer: Jeremy Miera
*/
void welcomeScreen();


/*
Name: instructionScreen
Processing: Displas the instructions for the game
Input: None
Output/Return: Instructions display
Dependencies: formatted console io
Developer: Jeremy Miera
*/
void instructionScreen();

/*
Name: playGame
Processing: Runs gameplay loop until game ends (Acts as a second driver)
Input: None
Output/Return: Runs the game
Dependencies: formatted console io, fstream, and other supporting functions
Developer: Jesus Flores-Padilla
*/
void playGame();

/*
Name: displayTops
Processing: Displays the top ten scores of the game with names, error message if 
            the score file is not found
Input: None
Output/Return: Displays the scores or an error message
Dependencies: formatted console io and ifstream
Developer: Jesus Flores-Padilla
*/
void displayTops();

/*
Name: displayMaze
Processing: Looks through a file containing a maze and prints out the maze on  
            screen.
Input: ifstream variable
Output/Return: printing the maze on to the screen
Dependencies: formatted console io, ifstream
Developer: Jesus Flores-Padilla
*/
void displayMaze( char arr[][MAX_COL] );

/*
Name: fileFailureMessage
Processing: Displays an error message to the user notifying a failure in opening
            a file.
Input: None
Output/Return: An error message display
Dependencies: ifstream, formatted consol io
Developer: Jeremy Miera
*/
void fileFailureMessage();

/*
Name: printStatBar
Processing: Prints the status bar seen below the gameplay screen.
Input: None
Output/Return: Status screen display
Dependencies: formatted console io
Developer: Jesus Flores-Padilla
*/
void printStatBar();

/*
Name: collisionDectction
Processing: Tells whether or not the space that the user indicated to go to is a
            wall (Number that decrements the score)
Input: cursor location indicating where the user has moved to.
Output/Return: True or false statement
Dependencies: formatted console io
Developer: Jesus Flores-Padilla
*/
bool collisionDetection( int xLoc, int yLoc, char arr[][MAX_COL] );

/*
Name: scoreFailureMessage
Processing: Displays message to indicate that no scores file was found.
Input: None
Output/Return: Error message display
Dependencies: formetted console io
Developer: Jeremy Miera
*/
void scoreFailureMessage();

/*
Name: goodbyeScreen
Processing: Displays a goodbye message for the user
Input: None
Output/Return: Goodbye message display
Dependencies: formetted console io
Developer: Jeremy Miera
*/
void goodbyeScreen();

/*
Name: printMainMenu
Processing: Displays the game's main menu
Input: None
Output/Return: Diplay main menu
Dependencies: formetted console io
Developer: Jeremy Miera
*/
void printMainMenu();

/*
Name: addNumbsToMaze
Processing: Adds numbs to maze
Input: Two dementional array
Output/Return: adds numbers to the arry
Dependencies: formetted console io
Developer: Jesus Flores-Padilla
*/
void addNumbsToMaze(char arr[][MAX_COL]);

/*
Name: randomNumber
Processing: Generates a random number
Input: none
Output/Return: Generates a random number for screen use
Dependencies: formetted console io
Developer: Jeremy Miera
*/
int randomNumber();

/*
Name: randomNumber
Processing: Generates a random number
Input: Number array, list of Names, and an indicator of the size
Output/Return: Sorts out numbers and names attributed with the numbers in order
               frome greatest to least.
Dependencies: none
Developer: Jesus Flores-Padilla
*/
void bubbleSort(int numVal[], char nameListVal[][MAX_CHAR_NAME], int size );

//Main function

int main()
   {
    // Initialize variables
    bool done = false;
    char menuSelection;

     startCurses();

    // Display splash
       // Function: welcomeScreen
       welcomeScreen();

    // Instruction screen
       // Function: instructionScreen
       instructionScreen();

    //Loop//
    do
       {
        // Menu
        // function: printMainMenu
         printMainMenu();
         menuSelection = char(waitForInput( FIXED_WAIT ));

          // Begin case statement
          switch( menuSelection)
             {
              case 'p':
              case 'P':
              case '1':
              // Play game ( As a second driver )
                 // Function: playGame (Other functions within this function)
                 playGame();               

              break;


              case 's':
              case 'S':
              case '2':
              // Display top scores
                 // Function: displayTops
                 displayTops();

              break;


              case 'q':
              case 'Q':
              case '3':
              // Quit
              done = true;

             }
             // End case statement
       
       // End Loop//
       }
    while(!done);

    // Display good-bye screen (After loop has ended)
       // Function: goodbyeScreen
       goodbyeScreen();

    endCurses();

    return 0;
   }

//Function Implementations

void welcomeScreen()
   {
   int random, key;
   bool done= false;
     
     
    setColor( COLOR_RED, COLOR_CYAN, SET_BRIGHT);
    clearScreen( 0, 0, 79, 24 );


     while( done == false )
               {
               random = randomNumber();    


               if(random>=0 && random<=5)
                     {
                     setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT);
                     clearScreen( 0, 0, 79, 24 );
                     
                     printStringAt( 22, 2, "TTTTTTTTTT   HH     HH   EEEEEEEE", "LEFT" );
                     printStringAt( 22, 3, "TTTTTTTTTT   HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 4, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 5, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 6, "    TT       HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 7, "    TT       HH     HH   EEEEEEEE", "LEFT" );

                     printStringAt( 4, 10, "  AAAA     MMM    MMM     AAAA     ZZZZZZZ   IIII   NNN     NN    GGGGGG ", "LEFT" );
                     printStringAt( 4, 11, " AA  AA    MM M  M MM    AA  AA        ZZZ    II    NN N    NN   GG    GG", "LEFT" );
                     printStringAt( 4, 12, "AA    AA   MM  MM  MM   AA    AA      ZZZ     II    NN  N   NN   GG      ", "LEFT" );
                     printStringAt( 4, 13, "AAAAAAAA   MM      MM   AAAAAAAA     ZZZ      II    NN   N  NN   GG  GGGG", "LEFT" );
                     printStringAt( 4, 14, "AA    AA   MM      MM   AA    AA    ZZZ       II    NN    N NN   GG    GG", "LEFT" );
                     printStringAt( 4, 15, "AA    AA   MM      MM   AA    AA   ZZZZZZZ   IIII   NN     NNN    GGGGGG ", "LEFT" );

                     printStringAt( 19, 18, " GGGGGG      AAAA     MMM    MMM   EEEEEEEE", "LEFT" );
                     printStringAt( 19, 19, "GG    GG    AA  AA    MM M  M MM   EE     E", "LEFT" );
                     printStringAt( 19, 20, "GG         AA    AA   MM  MM  MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 21, "GG  GGGG   AAAAAAAA   MM      MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 22, "GG    GG   AA    AA   MM      MM   EE     E", "LEFT" );
                     printStringAt( 19, 23, " GGGGGG    AA    AA   MM      MM   EEEEEEEE", "LEFT" );
                     }

              else if(random>=6)
                     {     
                    setColor( COLOR_CYAN, COLOR_GREEN, SET_BRIGHT);
                     clearScreen( 0, 0, 79, 24 );
                     printStringAt( 22, 2, "TTTTTTTTTT   HH     HH   EEEEEEEE", "LEFT" );
                     printStringAt( 22, 3, "TTTTTTTTTT   HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 4, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 5, "    TT       HHHHHHHHH   EEEE    ", "LEFT" );
                     printStringAt( 22, 6, "    TT       HH     HH   EE     E", "LEFT" );
                     printStringAt( 22, 7, "    TT       HH     HH   EEEEEEEE", "LEFT" );

                     printStringAt( 4, 10, "  AAAA     MMM    MMM     AAAA     ZZZZZZZ   IIII   NNN     NN    GGGGGG ", "LEFT" );
                     printStringAt( 4, 11, " AA  AA    MM M  M MM    AA  AA        ZZZ    II    NN N    NN   GG    GG", "LEFT" );
                     printStringAt( 4, 12, "AA    AA   MM  MM  MM   AA    AA      ZZZ     II    NN  N   NN   GG      ", "LEFT" );
                     printStringAt( 4, 13, "AAAAAAAA   MM      MM   AAAAAAAA     ZZZ      II    NN   N  NN   GG  GGGG", "LEFT" );
                     printStringAt( 4, 14, "AA    AA   MM      MM   AA    AA    ZZZ       II    NN    N NN   GG    GG", "LEFT" );
                     printStringAt( 4, 15, "AA    AA   MM      MM   AA    AA   ZZZZZZZ   IIII   NN     NNN    GGGGGG ", "LEFT" );

                     printStringAt( 19, 18, " GGGGGG      AAAA     MMM    MMM   EEEEEEEE", "LEFT" );
                     printStringAt( 19, 19, "GG    GG    AA  AA    MM M  M MM   EE     E", "LEFT" );
                     printStringAt( 19, 20, "GG         AA    AA   MM  MM  MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 21, "GG  GGGG   AAAAAAAA   MM      MM   EEEE    ", "LEFT" );
                     printStringAt( 19, 22, "GG    GG   AA    AA   MM      MM   EE     E", "LEFT" );
                     printStringAt( 19, 23, " GGGGGG    AA    AA   MM      MM   EEEEEEEE", "LEFT" );

                     }
             key = waitForInput( 1 );
             if ( key >=0 )
                {
                done = true;

                }

              }

        
   
   }

void instructionScreen()
   {
    setColor( COLOR_BLUE, COLOR_CYAN, SET_BRIGHT );
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
    setColor( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );
    clearScreen( 10, 4, 69, 19 );

    printStringAt( 26, 5, "Amazing Game Instructions", "LEFT" );
    printStringAt( 26, 6, "=========================", "LEFT" );

    printStringAt( 20, 8, "Get through the maze as fast as you can", "LEFT" );

    printStringAt( 14, 10, "Hitting maze edge reduces score by the value hit", "LEFT" );
    printStringAt( 25, 11, "or by the passage of time", "LEFT" );

    printStringAt(23, 13, "Each level starts with more points", "LEFT" );

    printStringAt(19, 15, "If the score reaches zero in any level,", "LEFT" );
    printStringAt(30, 16, "the game is ended", "LEFT" );

    printStringAt(23, 18, "Pressing <Q> also ends the game", "LEFT" );
    
    waitForInput( FIXED_WAIT );

   }

void playGame()
   {
     // Intialize variables
     char nameOfPlayer[MAX_CHAR_NAME];
     char fileNameOfLevel[MAX_CHAR_NAME];
     char mazeGrid[MAX_ROW][MAX_COL];
     char topTenScoreNames[MAX_SCORE_SLOTS][MAX_CHAR_NAME];
     char dummy;
     ifstream masterFin;
     ifstream mazeFin;
     ifstream scoresFin;
     ofstream storeFout;
     bool endGame = false;
     bool endLevel = false;
     int topTenScores[MAX_SCORE_SLOTS];
     int scoreSlot = 0;
     int scoreWrite = 0;
     int buffer = 0;
     int userInput;
     int levelCount = 1;
     int secondsCounter = 0;
     int seconds = 0;
     int score = 50;
     int subtract;     
     int xVal1;
     int yVal1;
     int xVal2;
     int yVal2;
     int mazeRow;
     int mazeCol;
     int printedXPos;
     int printedYPos;
     int endXPos;
     int endYPos;
     int rollStart;
     int gridRow = 0;

     startCurses();
     
     // Get Name
        // Functions: clearScreen, setColor
        setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
        clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
        
        // Function: promptForStringAt
        promptForStringAt( 30, 12, "Enter your name: ", nameOfPlayer);

     // Display maze
            // Open master file
            masterFin.clear();
            masterFin.open( MASTER_FILE );

            // Start loop
            while( (!endGame) && (score > 0) )
               {

               // Error if failed open
               if( !masterFin.good())
                  {
                   fileFailureMessage();
                   endGame = true;
                   endLevel = true;
                  }

               else
                  {
                   // Take in file name as a c-style string
                   masterFin >> fileNameOfLevel;

                      // Open Maze file
                      mazeFin.clear();
                      mazeFin.open( fileNameOfLevel );


                      // Error if failed open
                      if( !mazeFin.good())
                         {                      
                          // Function: fileFailureMessage
                          fileFailureMessage();
                          endGame = true;
                          endLevel = true;
                         }

                      else
                         {
                          endLevel = false;

                         // Store in values
                         mazeFin.ignore(20, ':');
                         mazeFin.ignore(20, ':');
                         mazeFin >> yVal1;
                         mazeFin >> dummy;
                         mazeFin. ignore  ( 20, ':') >> xVal1;

                         mazeFin.ignore(20, ':');
                         mazeFin.ignore(20, ':');
                         mazeFin >> yVal2;
                         mazeFin >> dummy;
                         mazeFin.ignore( 20, ':') >> xVal2;
                         mazeFin.ignore(2, '\n');
                         
                         while( gridRow < MAX_ROW )
                            {
                             mazeFin.getline( mazeGrid[gridRow], 100 );
                             gridRow++;
                            }  
                            gridRow = 0;                          

                            // add numbers to maze
                            //Function: addNumbsToMaze
                            addNumbsToMaze( mazeGrid );

                         // Display maze
                            //Function:displayMaze
                            displayMaze( mazeGrid ); 

                            

                         // Display Stats bar 
                            // Function: printStatBar
                            printStatBar();                            
                                  


                         // Navigate

                         // Initialize begining values and end values
                         srand( time(NULL) );
                         rollStart = rand() % 5 + 1 ;
                         
                         if( rollStart % 2 == 0 )
                            {
                             mazeRow = yVal1 - 1;
                             mazeCol = xVal1 - 1;
                             printedXPos = xVal1 + 4;
                             printedYPos = yVal1 - 1;
                             endXPos = xVal2 + 4;
                             endYPos = yVal2 - 1; 
                             
                            }
                         else
                            {
                             mazeRow = yVal2 - 1;
                             mazeCol = xVal2 - 1;
                             printedXPos = xVal2 + 4;
                             printedYPos = yVal2 - 1;
                             endXPos = xVal1 + 4;
                             endYPos = yVal1 - 1; 

                            }


                         // Start inner loop
                         while( (!endLevel)  && (score > 0) )
                            {
                             setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
                             printCharAt( printedXPos, printedYPos, '#' );

                             setColor( COLOR_RED, COLOR_BLUE, SET_BRIGHT );
                             clearScreen(65, 22, 67, 22);
                             printIntAt( 65, 22, seconds, "LEFT" );
                             clearScreen(65, 23, 67, 23);
                             printIntAt( 65, 23, score, "LEFT" );
                            // Get Input
                               // function: waitForInput
                               userInput = waitForInput( DEFAULT_WAIT );
                               secondsCounter++;

                            // If counter is = 10
                            if( secondsCounter == 10 )
                               {
                                // Count Time
                                seconds++;
                                // Decrement score
                                score--;
                                //initialize counter to 0
                                secondsCounter = 0;
                            // End if statement
                               }

                             // If Q
                             if( (userInput == int('q')) || (userInput == int('Q')) )
                                {
                                 // Pause and quit
                                 setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
                                 printStringAt( 7, 23, "End game - Press any key to continue", "LEFT" );
                                 waitForInput(FIXED_WAIT);

                                 endLevel = true;
                                 endGame = true;
                                }
                             // End if statemnt

                             // If up arrow
                             if( userInput == KB_UP_ARROW )
                                {
                                 // Move
                                 mazeRow--;

                                 //Keep player in bounds
                                 if( mazeRow < 0 )
                                    {
                                     mazeRow++;
                                     printedYPos += 1;
                                    }                                 

                                 
                                   // Detecting collision
                                   // Function: collisionDectction
                                   if( collisionDetection( mazeCol, mazeRow, mazeGrid ) )
                                      {
                                       subtract = int(mazeGrid[mazeRow][mazeCol]) - int('0');
                                       score = score - subtract;
                                       setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
                                       printCharAt( printedXPos, printedYPos - 1, mazeGrid[mazeRow][mazeCol]);
                                       mazeRow++;
                                    
                                      }
                                   else
                                      {
                                       printedYPos--;
                                      }
                             //  End if statement
                                }


                             if( userInput == KB_DOWN_ARROW )
                                {
                                 // Move
                                 mazeRow++;

                                 // Keep player in bounds
                                 if( mazeRow > 19 )
                                    {
                                     mazeRow--;
                                     printedYPos -= 1;
                                    }                                 

                                 
                                   // Detecting collision
                                   // Function: collisionDectction
                                   if( collisionDetection( mazeCol, mazeRow, mazeGrid ) )
                                      {
                                       subtract = int(mazeGrid[mazeRow][mazeCol]) - int('0');
                                       score = score - subtract;
                                       setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
                                       printCharAt( printedXPos, printedYPos + 1, mazeGrid[mazeRow][mazeCol]);
                                       mazeRow--;
                                    
                                      }
                                   else
                                      {
                                       printedYPos++;
                                      }
                             //  End if statement


                                }


                             if( userInput == KB_LEFT_ARROW )
                                {
                                 // Move
                                 mazeCol--;

                                 // Keep player in bounds
                                 if( mazeCol < 0 )
                                    {
                                     mazeCol++;
                                     printedXPos += 1;
                                    }                                 

                                 
                                   // Detecting collision
                                   // Function: collisionDectction
                                   if( collisionDetection( mazeCol, mazeRow, mazeGrid ) )
                                      {
                                       subtract = int(mazeGrid[mazeRow][mazeCol]) - int('0');
                                       score = score - subtract;
                                       setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
                                       printCharAt( printedXPos - 1, printedYPos, mazeGrid[mazeRow][mazeCol]);
                                       mazeCol++;
                                    
                                      }
                                   else
                                      {
                                       printedXPos--;
                                      }
                             //  End if statement
                                }


                             if( userInput == KB_RIGHT_ARROW )
                                {
                                 // Move
                                 mazeCol++;

                                 // Keep player in bounds                                 
                                 if( mazeCol > 69 )
                                    {
                                     mazeCol--;
                                     printedXPos -= 1;
                                    }                                 

                                   // Detecting collision
                                   // Function: collisionDectction
                                   if( collisionDetection( mazeCol, mazeRow, mazeGrid ) )
                                      {
                                       subtract = int(mazeGrid[mazeRow][mazeCol]) - int('0');
                                       score = score - subtract;
                                       setColor( COLOR_RED, COLOR_GREEN, SET_BRIGHT );
                                       printCharAt( printedXPos + 1, printedYPos, mazeGrid[mazeRow][mazeCol]);
                                       mazeCol--;
                                    
                                      }
                                   else
                                      {
                                       printedXPos++;
                                      }
                             //  End if statement
                                }


                             // If spacebar
                             if( userInput == int(' ') )
                                {
                                 // Pause
                                 waitForInput( FIXED_WAIT );
                                }
                             // End if statement

                             // If the end is reached
                             if( (printedXPos == endXPos) && (printedYPos == endYPos) )
                                {
                                 endLevel = true;
                                }
                             // End if statement

                             // Update time and score again to keep accurate
                             clearScreen(65, 22, 67, 22);
                             printIntAt( 65, 22, seconds, "LEFT" );
                             clearScreen(65, 23, 67, 23);
                             printIntAt( 65, 23, score, "LEFT" );

                    // End inner loop
                            }
                    // Close maze file
                     mazeFin.close();

                    // count levels
                    levelCount++;

                    // Update score
                    if (score <= 0)
                       {
                        // Give a real score
                        score = 0;
                        
                        // printOut the final time and score
                        setColor( COLOR_RED, COLOR_BLUE, SET_BRIGHT );
                        clearScreen(65, 22, 67, 22);
                        printIntAt( 65, 22, seconds, "LEFT" );
                        clearScreen(65, 23, 67, 23);
                        printIntAt( 65, 23, score, "LEFT" );

                        // Print the end game message
                        setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
                        printStringAt( 6, 23, "End Game - Press Any Key To Continue", "LEFT" );
                        waitForInput( FIXED_WAIT );
                       }

                    if ( (score > 0) && (levelCount == 2) )
                       {
                        score += 100;
                       }

                    if( (score > 0) && (levelCount == 3 ) )
                       {
                        score += 150;
                       }
                    if( levelCount > 3 )
                       {
                        endGame = true;

                        setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
                        printStringAt( 6, 23, "You WIN!!! - Press Any Key To Continue", "LEFT" );
                        waitForInput( FIXED_WAIT );
                       }

               // End loop
                         }
                  }
               }
        
     // Store score into file
     // close master file    
     masterFin.close();

     // Write and update score file 
     scoresFin.clear();
     scoresFin.open( SCORE_FILE );
     
     if( scoresFin.good() )
        {
         while(scoresFin.good() )
            {
             scoresFin >> topTenScores[scoreSlot];
             scoresFin >> dummy;
             scoresFin.getline(topTenScoreNames[scoreSlot], 30);


             scoreSlot++;
            }
         scoresFin.close();

         topTenScores[scoreSlot - 1] = score;
         strcpy( topTenScoreNames[scoreSlot - 1], nameOfPlayer);


         bubbleSort( topTenScores, topTenScoreNames, scoreSlot );
         
         storeFout.open( SCORE_FILE );

         if( scoreSlot - 1 > 9 )
            {
             while( buffer < scoreSlot - 1 )
                {
                 storeFout << topTenScores[scoreWrite];
                 storeFout << ',';
                 storeFout << topTenScoreNames[scoreWrite];
                 storeFout << endl; 
             
                 scoreWrite++;
                 buffer++;
                }
            }

          else
             {
             while( buffer < scoreSlot )
                {
                 storeFout << topTenScores[scoreWrite];
                 storeFout << ',';
                 storeFout << topTenScoreNames[scoreWrite];
                 storeFout << endl; 
             
                 scoreWrite++;
                 buffer++;
                }

             }
         storeFout.close();

        }

     else
        {
         storeFout.open( SCORE_FILE );
         storeFout << score;
         storeFout << ',';
         storeFout << nameOfPlayer;
         storeFout << endl; 
         storeFout.close();
        }

     endCurses();

   }

void displayTops()
   {
    // Initialize variables
    ifstream fin;
    int number[10];
    char dummy;
    char list[10][MAX_CHAR_NAME];
    int indexScoreRead = 0;
    int indexScorePrint = 0;
    int yPos = 7;
    // Read file
    fin.clear();
    fin.open( SCORE_FILE );
    
    // if file good display scores
    if(fin.good())
       {
        setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
        clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

        // Display menu headers
        printStringAt(40, 2, "TOP TEN WINNERS", "CENTER");
        printStringAt(40, 3, "===============", "CENTER");
        printStringAt(25, 4, "NAMES", "LEFT");
        printStringAt(25, 5, "=====", "LEFT");
        printStringAt(50, 4, "SCORES", "LEFT");
        printStringAt(50, 5, "======", "LEFT");

        // Get and print name and scores
        while( fin.good() )
           {
            fin >> number[indexScoreRead];
            fin >> dummy;
            fin.getline(list[indexScoreRead], 30);

            indexScoreRead++;
           }
        fin.close();

        while( indexScorePrint < indexScoreRead - 1 )
           {
            // Functions: ifstream variable, printStringAt, printIntAt
            printStringAt( 25, yPos, list[indexScorePrint], "LEFT");
            printIntAt( 50, yPos, number[indexScorePrint], "LEFT");

            yPos++;
            indexScorePrint++;

           }
        setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT );
        printStringAt( 25, 23, "Press any key to continue...", "LEFT" );

        waitForInput( FIXED_WAIT );
       }
    // End if statement
    
    // else false display error message
    else
       {
       // Function: scoreFailureMessage
       scoreFailureMessage();
    // End if statement
       }

    // Stub
   }

void displayMaze( char arr[][MAX_COL] )
   {
    // Initialize variables
    int row;
    int col;
    int xPos = 5;
    int yPos = 0;
    
    
    //Clear Screen
    setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
    setColor( COLOR_YELLOW, COLOR_GREEN, SET_BRIGHT );
    clearScreen( 5, 0, 65, 19 );

    // Start loop
    for( row = 0 ; row < MAX_ROW ; row++ )
       {
        // Start inner loop
        for( col = 0 ; col < MAX_COL ; col++ )
           {
            // Print element
            //Funtion: printCharAt
            if( (arr[row][col] > '0') && (arr[row][col] <= '5') )
               {
                setColor( COLOR_BLUE, COLOR_GREEN, SET_BRIGHT );
                printCharAt( xPos, yPos, arr[row][col] );
               }

            else
               {
                setColor( COLOR_YELLOW, COLOR_GREEN, SET_BRIGHT );
                printCharAt( xPos, yPos, arr[row][col] );
               }
                xPos++;
               
            // End inner loop
           }
        
        xPos = 5;
        yPos++;
        
    // End loop
       }
    // Stub
   }

void fileFailureMessage()
   {
    setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    printStringAt( 20, 11, "Game file not found - No mazes availiable", "LEFT" );

    waitForInput( FIXED_WAIT );
   }

void printStatBar()
   {
    // initialize variables

    // Clear Screen section
       // Functions: clearScreen, setColor
       setColor( COLOR_RED, COLOR_BLUE, SET_BRIGHT );
       clearScreen( 0, 20, 79, 24 );

    // Print Dotted lines and in game instructions and status names
       // Function: printStringAt
       printStringAt( 0, 20, "================================================================================", "LEFT" ); 
       printStringAt( 6, 22, "Press Up, Down, Left, or Right Arrows to Move", "LEFT" );
       printStringAt( 7, 23, "Press Spacebar to Pause", "LEFT" );
       printStringAt( 60, 22, "Time:", "LEFT" );
       printStringAt( 59, 23, "Score:", "LEFT" );

   }

bool collisionDetection( int xLoc, int yLoc, char arr[][MAX_COL])
   {
    // Initialize variables

    // check the position in the array
    // if position is a number
    if( (arr[yLoc][xLoc] >= '1') && (arr[yLoc][xLoc] <= '5') )
       {
        return true;
       }
    
       // return true
    
    return false;
   }

void scoreFailureMessage()
   {
   setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

   printStringAt( 20, 11, "Score file not found - No scores availiable", "LEFT" );
    
    waitForInput( FIXED_WAIT );
   }

void goodbyeScreen()
   {
   setColor( COLOR_RED, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

   printStringAt( 30, 8, "THAN YOU FOR PLAYING", "LEFT" );

   printStringAt( 33, 10, "THE AMAZING GAME", "LEFT" );

   printStringAt( 28, 13, "Press Any Key to Continue", "LEFT" );
      
    waitForInput( FIXED_WAIT );
   }

void printMainMenu()
   {
   setColor( COLOR_WHITE, COLOR_CYAN, SET_BRIGHT );
   clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );   

   printStringAt( 30, 8, "MENU SELECTIONS", "LEFT" );
   printStringAt( 30, 9, "---------------", "LEFT" );

   printStringAt( 30, 11, "1. <P>lay Game", "LEFT" );
   printStringAt( 30, 12, "2. <S>how Top Scores", "LEFT" );
   printStringAt( 30, 13, "3. <Q>uit Program", "LEFT" );

  

   }

void addNumbsToMaze( char arr[][MAX_COL])
   {
    // Initialize variables
    int row;
    int col;
    int randomValue;
        
    srand(time( NULL ));

    // search through array
      // outer loop
      for( row = 0 ; row < MAX_ROW ; row++ )
         {
          // inner loop
          for( col = 0 ; col < MAX_COL ; col++)
             {

              // if current spot is a space
              if( arr[row][col] == ' ' )
                 {
                  randomValue = rand() % 5 + 1;
                  // if spot before was an x
                  if( arr[row][col -1] == 'X' )
                    {
                     // change to random number
                     arr[row][col - 1] = '0' + randomValue  ;
                    }

                  // if spot after is an x
                  if( arr[row][col + 1] == 'X')
                     {
                      // change to random number
                     arr[row][col + 1] = '0' + randomValue ;
                     }

                  // if spot above is an x
                  if( arr[row - 1][col] == 'X' )
                     {
                      // change to random numbe
                     arr[row - 1][col] = '0' + randomValue ;
                     }

                  // if spot below is an x
                  if( arr[row + 1][col] == 'X' )
                     {
                      // change to random number
                     arr[row + 1][col] = '0' + randomValue ;
                     }
            
               //End if statement 
                  }
              // end inner loop
             }
          // End outer loop
         }
    // Stub
   }

int randomNumber()
        {             
    srand(time(NULL));
    int random; 
    random = rand()%10;    

    //printIntAt( 5,5, random, "LEFT");
    return (random);
    }

void bubbleSort(int numVal[], char nameListVal[][MAX_CHAR_NAME], int size )
   {
    int slot;
    int tempInt;
    char tempArr[MAX_CHAR_NAME];
    bool sort = true;
    
    while(sort)
       {
        sort = false;
        for( slot = 0 ; slot < size - 1 ; slot++ )
           {
            if( numVal[slot] < numVal[slot + 1] )
               {
                tempInt = numVal[slot];
                numVal[slot] = numVal[slot + 1];
                numVal[slot + 1] = tempInt;
 
                strcpy( tempArr, nameListVal[slot] );
                strcpy( nameListVal[slot], nameListVal[slot + 1] );
                strcpy( nameListVal[slot + 1], tempArr );
                
                sort = true;
               }
         
           }
       }

    
   }
