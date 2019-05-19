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
  string key = keyword.upper();
  if(inWord.find(key) != string::npos)
  {
    respond(toWhere);
    return true;
  }
  return false;
}

void Response::respond(ostream &toWhere)
{
  toWhere << keyword.normal() << endl;
}

//
// Implementation of AngryReponse methods
//
void HappyResponse::respond(ostream &toWhere)
{
  toWhere << keyword.normal() << " :)" << endl;
} 

//
// Implementation of HappyResponse methods
//
void AngryResponse::respond(ostream &toWhere)
{
  toWhere << keyword.normal() << " :(" << endl;
}