// Header Files
#include "formatted_cmdline_io_v06.h" // for I/O actions
    
using namespace std;

// Global Constant Definitions

const int DECIMAL_PRECISION = 2;
const int NO_BLOCK_SIZE = 0;

// Global Function Prototypes

   // none

// Main Program Definition
int main()
   {
    // initialize program

       // variable initialization
       int intVal;
       double doubleVal;
       int blockSize = 10;
       

    // prompt user for input
    intVal = promptForInt( "Enter an integer value: " );
    doubleVal = promptForDouble( "Enter a double value: " );

    // output the responses
    printString( "The integer value is: ", NO_BLOCK_SIZE, "LEFT" );
    printInt( intVal, NO_BLOCK_SIZE, "LEFT" );
    printEndLines(1);
    printString( "The double value is: ", 0, "LEFT" );
    printDouble( doubleVal, DECIMAL_PRECISION, 0, "LEFT" );
    printEndLines(2);

    // Close program

       // hold program
       system( "pause" );

       // return success
       return 0;
   }

// Supporting Function Implementation

   // none


