//  Header Files

#include <iostream>
   
using namespace std;

//  Global Constant Definitions

    // none

//  Global Function Prototypes
bool isInTwentiethCentury( int aYear );
bool isBeforeMidCentury( int aYear );
bool isAfterMidCentury( int aYear );

//  Main Program Definition
int main()
   {
    // initialize program

       // variable initialization
       int someYear;
 
    // prompt user for a year, using cout, cin
    cout << "Enter a Year: ";
    cin >> someYear ;

    // test and report before mid century
    if( isBeforeMidCentury( someYear ) )
       {
        // report that it is before mid century
        cout << endl << endl;
        cout << "The year " << someYear
             << " is before mid twentieth century." << endl << endl;
       }
    else
       {
        // report that it is not before mid century
        cout << endl << endl;
        cout << "The year " << someYear
             << " is NOT before mid twentieth century." << endl << endl;
       }

    // test and report after mid century
    if( isAfterMidCentury( someYear ) )
       {
        // report that it is after mid century
        cout << endl << endl;
        cout << "The year " << someYear
             << " is after mid twentieth century." << endl << endl;
       }
    else
       {
        // report that it is not after mid century
        cout << endl << endl;
        cout << "The year " << someYear
             << " is NOT after mid twentieth century." << endl << endl;
       }
      
    // Close program
       // hold program
       system( "pause" );

       // return success
       return 0;
   }

//  Supporting Function Implementation

bool isInTwentiethCentury( int aYear )
   {
    if( aYear >= 1901 && aYear <= 2000 )
       {
        return true;
       }  

    return false;
   }

bool isBeforeMidCentury( int aYear )
   {
    if( aYear >= 1901 && aYear <= 1950 )
       {
        return true;
       }
    return false;
   }

bool isAfterMidCentury( int aYear )
   {
    if( isInTwentiethCentury( aYear ) )
       {
        if( !isBeforeMidCentury( aYear ) )
           {
            return true;
           }
         return false;
       }
    
    return false;
   }
