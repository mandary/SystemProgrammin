#include <iostream>
#include <sstream>
#include <string>

#include <cstdlib>

#include "Example.h"

using namespace std;

Example sub(Example ex) {
  return ex;
}

//--------------------------------------------------------------------
// The mainline/app. All it does is show when constructors and
// destructors are invoked.
//--------------------------------------------------------------------

int main(int argc, char* argv[]) {

  const char * prompt = "\n===> ";

  //--------------------------------------------------------------------
  // local variable...
  // Here's a local object.  It will be deleted when we leave
  // this scope.
  //--------------------------------------------------------------------
  cout << prompt << "Local object:" << endl;
  Example local("local");

  //--------------------------------------------------------------------
  // new...
  // Here we new up an object.  To delete it, we use 'delete'.
  //--------------------------------------------------------------------
  cout << prompt << "new'ed object:" << endl;
  Example *scalarEx = new Example("new'ed");
  delete scalarEx;

  //--------------------------------------------------------------------
  // Arrays...
  // We'd like to new up an array of objects.
  // (Note: These don't work, and there's no simple way to make them work.)
  //Example arrayEx[5];
  //Example *ptrArrayEx = new Example[5];
  //--------------------------------------------------------------------

  // This is one (awkward) way around the problem.
  cout << prompt << "Array of objects:" << endl;
  Example **arrayEx = new Example*[5];
  for ( int i=0; i<5; i++ ) {
    arrayEx[i] = new Example( string( to_string(i) ).c_str() );
  }
  for ( int i=0; i<5; i++ ) {
    delete arrayEx[i];
  }
  delete [] arrayEx;

  //--------------------------------------------------------------------
  // (Very) local scope...
  // Here are automatic variables: created in a local scope and
  // destroyed on exit from that scope.
  //--------------------------------------------------------------------
  {
    cout << prompt << "Short-lived local:" << endl;
    Example localEx("short-lived local");
  }

  //--------------------------------------------------------------------
  // Function call / assignment...
  // Here's the most complicated example, and one that's surprisingly
  // hard to get right.
  //--------------------------------------------------------------------
  cout << prompt << "Function call, return, assign:" << endl;
  Example returnedVal = sub(local);

  return 0;
}
