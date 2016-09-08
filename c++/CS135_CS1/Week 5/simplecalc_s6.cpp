//Header files
#include "formatted_console_io_v16.h"
#include <cmath>
using namespace std;

//Global constants

//Function Prototypes
   /*
   Name:helloGoodbye
   Processing: Display Welcome and good-bye screen
   inputs: 1 for hello screen, 2 for goodbye screen
   output/display: Welcome good-bye screen
   Dependencies: formatted console i/o
   */
   void helloGoodbye(int value);

   /*
   Name: calcScreen
   Processing: Display the calculator screen
   inputs: none
   output/display: Calculator screen
   Dependencies: formatted console i/o
   */
   void calcScreen();

   /*
   Name: inputNumbers
   Processing: prompt user for integer input
   inputs: Character and user input integer, 'a' for first entry, 'b' for second
   output/return: Integers
   Dependencies: formatted console i/o
   */
   int inputNumbers( int posX, int posY, int value );

   /*
   Name: inputOperator
   Processing: prompt user for operator
   inputs: mathematical operations
   output/return: none
   Dependencies: formatted console i/o
   */
   char inputOperator( char anOperatort );

   /*
   Name: errorCheck
   Processing: Protects from over flow, checks for corret operator input,
               checks for proper integer input 
   inputs: character, integer. Character '*' means no character value
   inputs: integer 0 means no integer input
   inputs: 1 for message (entry too large), 2 for message (result too large),
   3 for message (incorrect operator)
   output/return: Error message
   Dependencies: formatted console i/o
   */
   bool errorCheck( char charValue, double value, int messageType );

   /*
   Name: calcAnswer
   Processing: Calculates the answers for user
   inputs: integers and operator from user
   output/return: integer
   Dependencies: formatted console i/o
   */
   double calcAnswer( int number1, char mathOperator, int number2 );

   /*
   Name: displayAnswer 
   Processing: Displays answer from calculation
   inputs: double
   output/display: answer
   Dependencies: formatted console i/o
   */
   void displayAnswer( double answer );

////////////////////////////////////////////////////////////////////////////////
//Main function

int main()
   {
   // initinialize variables
   int input1;
   int input2;
   double result;
   char mathSymbol;

   
   
      //start curses
      startCurses();

   // Welcome Screen
     // Use Welcome and good-bye screen function
     // funtion: helloGoodbye
     helloGoodbye(1);

   // Create Calculator screen
     // Use Calculator screen function
     // function: calcScreen
     calcScreen();

   // Get user input and Calculate
     // Get user input 1
     // function: inputNumbers
     input1 = inputNumbers( 40, 7, input1 );

        // Check for input error
        // function: errorCheck
        if ( !errorCheck('*', input1, 1 ) )
          {
          
           waitForInput( FIXED_WAIT );
           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye(2);
           waitForInput( FIXED_WAIT );
           

          }


     // Get user input 2
     // function: inputNumbers
     input2 = inputNumbers( 40, 10, input2 );

        // Check for input error
        // function: errorCheck
        if ( !errorCheck( '*', input2, 1 ) )
           {
            waitForInput( FIXED_WAIT );
            // Display goodbye screen
            // function: helloGoodbye
            helloGoodbye(2);
            waitForInput( FIXED_WAIT );
           

           }

     // Get operator
     // function: inputOperator
     mathSymbol = inputOperator( mathSymbol );

       // Check for input error
       // function: errorCheck
       if ( !errorCheck( mathSymbol, 0, 3 ) )
          {
           waitForInput( FIXED_WAIT );
           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye(2);
           waitForInput( FIXED_WAIT );
          

           }

    // Calculate answer
    // function: calcAnswer
    result = calcAnswer( input1, mathSymbol, input2);

       // Check for error
       // function: errorCheck
       if ( !errorCheck('*', result, 2 ) )
          {
           waitForInput( FIXED_WAIT );
           // Display goodbye screen
           // function: helloGoodbye
           helloGoodbye(2);
           waitForInput( FIXED_WAIT );
           
           }

    // Display answer
    // function: displayAnswer
    displayAnswer( result );

   // Good-bye screen
     // Use welcome and good-bye screen fucntion
     // function: helloGoodbye
     helloGoodbye(2);

   // hold system for user
   waitForInput( FIXED_WAIT );

     // end curses
     endCurses();

     return 0;

   }

//Function Implementations
void helloGoodbye(int value)
   {
    // Go to Hello screen (Step 6)
    // function: bool
    if( value == 1 )
       {
        setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
        clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
        printStringAt( 40, 9, "WELCOME", "CENTER" );
        printStringAt( 40, 12, "TO", "CENTER" );
        printStringAt( 40, 15, "THE SIMPLE CALCULATOR", "CENTER" );
        printStringAt( 40, 24, "Press any key to continue...", "CENTER" );
        moveToXY( 55, 24 );
        waitForInput( FIXED_WAIT );
        
       }
  
    // Go to Goodbye screen (step 6)
    // function: bool
    else if( value == 2 )
       {
        setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
        clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
        printStringAt( 40, 9, "GOODBYE", "CENTER" );
        printStringAt( 40, 12, "THANK YOU FOR USING", "CENTER" );
        printStringAt( 40, 15, "THE SIMPLE CALCULATOR", "CENTER" );
        printStringAt( 40, 24, "Press any key to continue...", "CENTER" );
        moveToXY( 55, 24 );
       }

       
   }

void calcScreen()
   {
    // Show calcScreen
    // function: setColor
    setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
    
    // Inner Screen
    setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
    clearScreen( 20, 3, 61, 21 );


       //Show inner screen

          // print first line
          // function: printStringAt
          printStringAt( 40, 3, "------------------------------------------",
                                                                 "CENTER" );          

          // print left vertical line
          // function: printStringVertical
          printStringVertical( 20, 4, "||||||||||||||||||", "DOWN" );


          // print title
          // function printStringAt
          printStringAt( 40, 4, "The Simple Calculator", "CENTER" );

          // print right vertical line
          // function: printStringVertical
          printStringVertical( 61, 4, "||||||||||||||||||", "DOWN" );

          // print middle line
          // function: printStringAt
          printStringAt( 40, 5, "----------------------------------------",
                                                                 "CENTER" );          

          // print bottom line
          // function: printStringAt
          printStringAt( 40, 21, "------------------------------------------",
                                                                 "CENTER" );   
          
          // Value entry message (step 6)
             // First
             printStringAt( 21, 7, " Enter Value 1 : ", "LEFT" );

             // First Entry box
             setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT );
             clearScreen( 40, 7, 47, 7 );
             


             // Second
             setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
             clearScreen( 21, 10, 37, 10);
             printStringAt( 21, 10, " Enter Value 2 : ", "LEFT" );

             // Second Entry box
             setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT );
             clearScreen( 40, 10, 47, 10 );
             
             

             // Operator
             setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
             clearScreen( 21, 13, 37, 13);
             printStringAt( 21, 13, " Enter Operator: ", "LEFT" );

             // Operator Entry box
             setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT );
             clearScreen( 40, 13, 47, 13 );
             
                

             // Result
             setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
             clearScreen( 21, 16, 37, 16);
             printStringAt( 21, 16, " Result        : ", "LEFT" );

             // Result Entry box
             setColor( COLOR_RED, COLOR_WHITE, SET_BRIGHT );
             clearScreen( 40, 16, 47, 16 );
            

   }

int inputNumbers( int posX, int posY, int value )
   {
    
    value = promptForIntAt( posX, posY, " " );

    
    return value;
   }

char inputOperator( char anOperator )
   {
    // What to return
    anOperator = promptForCharAt( 40, 13, " " );

    return anOperator;
   }

bool errorCheck( char charValue, double value, int messageType )
   {
    // Check for proper input
    // function: if
    if( (value <- 999999) || (value > 999999) )
       {
        // Improper input error screen
        // function: setColor, printStringAt
        setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
        clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
        setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
        clearScreen( 20, 3, 61, 21 );
         
        printStringAt( 40, 3, "------------------------------------------",
                                                                "CENTER" );
        printStringVertical( 20, 4, "||||||||||||||||||", "DOWN" );
        printStringVertical( 61, 4, "||||||||||||||||||", "DOWN" );
        printStringAt( 40, 21, "------------------------------------------",
                                                                 "CENTER" );    

        if( messageType == 1 )
           {
            // Entry over flow screen (step 6)
            printStringAt( 40, 12, "Entry value too large", "CENTER" );
            printStringAt( 40, 20, "Press any key to Continue", "CENTER" );

           }

           // Result over flow screen (step 6)
        if( messageType == 2 )
           {
            printStringAt( 40, 12, "Result value too large", "CENTER");
            printStringAt( 40, 20, "Press any key to Continue", "CENTER" );
           }

       return false;

       }

    // Proper Operator input (step 6)
    if( charValue !=  '+' || charValue != '-' || charValue != '*'
         || charValue != '/' || charValue != '%'  )
      {
       if ( messageType == 3)
          {
           setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );
           clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
           setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );
           clearScreen( 20, 3, 61, 21 );
           printStringAt( 40, 3, "------------------------------------------",
                                                                  "CENTER" );
           printStringVertical( 20, 4, "||||||||||||||||||", "DOWN" );
           printStringVertical( 61, 4, "||||||||||||||||||", "DOWN" );
           printStringAt( 40, 21, "------------------------------------------",
                                                                   "CENTER" );    
           printStringAt( 40, 12, "Incorrect operator used", "CENTER");
           printStringAt( 40, 20, "Press any key to Continue", "CENTER" );
          }
      return true;
      }

   return false;
   }

double calcAnswer( int number1, char mathOperator, int number2 )
   {
    double result;
    
    // Addition
    if( mathOperator == '+' )
       {
        result = double( number1 + number2 );
        
        return result;
       }

    // Subtraction
    if( mathOperator == '-' )
       {
        result = double( number1 - number2 );
        
        return result;
       }


    // Multiplication
    if( mathOperator == '*' )
       {
        result = double( number1 * number2 );

        return result;
       }

    
    // Division
    if( mathOperator == '/' )
       {
        result = double( number1 / number2 );

        return result;
       }


    // Modulo
    if( mathOperator == '%' )
       {
        result = double( number1 % number2 );
       
       return result;
       }
       
    
    return result; 
   }

void displayAnswer( double answer )
   {
    // Display the answer
    // function: printDoubleAt
    printDoubleAt( 40, 16, answer, 2, "CENTER" );
                                         
   }
