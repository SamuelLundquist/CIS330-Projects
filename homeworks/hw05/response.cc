//
// Implementation of methods for classes Response, AngryResponse, HappyResponse
//
#include <iostream>
#include <string>
#include <algorithm>

#include "response.hh"

using namespace std;

//
// Implementation of Word methods
//
// Don't worry too hard about these implementations.
// If you'd like to learn more about STL see: https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
//
string Word::upper()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

string Word::lower()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

//
// Implementation of Response methods
//
bool Response::checkAndRespond(const string &inWord, ostream &toWhere)
{
  // TODO:
  // This method should check if its object's keyword is in the inWord message.
  // If it is, the method should call the  `respond` method passing the toWhere stream and return true.
  // If it isn't, the method should return false.
}

void Response::respond(ostream &toWhere)
{
  // TODO:
  // This method should insert its object's response into the given stream.
}


//
// Implementation of AngryReponse methods
//

// TODO:
// Implement the `respond` method for the AngryResponse class so that some angry expression (e.g. ":(")
// is included in the output.

//
// Implementation of HappyResponse methods
//

// TODO:
// Implement the method(s) for the HappyResponse class.
// Unlike the AngryResponse class, the HappyResponse class should include some happy expression (e.g. ":)")
// in its output.
