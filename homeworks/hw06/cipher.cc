#include "cipher.h"

#define UPPER_CASE(r) ((r) - ('a' - 'A'))

struct Cipher::CipherCheshire {
    string cipherText;
};

Cipher::Cipher()
{
    smile = new CipherCheshire;
    smile->cipherText = "abcdefghijklmnopqrstuvwxyz ";
}
Cipher::Cipher(string in)
{
    smile = new CipherCheshire;
    smile->cipherText = in;
}
string Cipher::encrypt(string raw)
{
    string retStr;
    cout << "Encrypting..." << endl;
    for(unsigned int i = 0; i < raw.size(); i++) {
        unsigned int pos;
        bool upper = false;
        if(raw[i] == ' ') {
            pos = 26;
        } else if(raw[i] >= 'a') {
            pos = raw[i] - 'a';
        } else {
            pos = raw[i] - 'A';
            upper = 1;
        }
        if(upper) {
            retStr += UPPER_CASE(smile->cipherText[pos]);
        } else {
            retStr += smile->cipherText[pos];
        }
    }
    cout << "Done" << endl;

    return retStr;
}

string Cipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrpyting..." << endl;
    for(unsigned int i= 0; i < enc.size(); i++)
    {
      unsigned int pos;
      bool upper = false;
      if(enc[i] == ' '){
        pos = smile->cipherText.find(' ') + 'a'; //Get index of character in cipherText 0-26
        if (pos > 122)//not a letter replace with space
        {
          pos = 32;
        }
      } else if (enc[i] >= 'a') {
        pos = smile->cipherText.find(enc[i]) + 'a';
        if (pos > 122)//not a letter replace with space
        {
          pos = 32;
        }
      } else {
        pos = smile->cipherText.find(tolower(enc[i])) + 'A';
        upper = 1;
      }
      if(upper) {
        retStr += (char)pos;
      } else {
        retStr += (char)pos;
      }

    }

    cout << "Done" << endl;

    return retStr;
}




struct CaesarCipher::CaesarCipherCheshire : CipherCheshire {
     int rot;
};

CaesarCipher::CaesarCipher()
{
  smile = new CipherCheshire;
  smile->cipherText = "abcdefghijklmnopqrstuvwxyz ";
}

CaesarCipher::CaesarCipher(string in, int rot)
{
  smile = new CipherCheshire;
  if(rot >=  27|| rot <= -27){
    rot = rot % 27;
  }

  if(rot >= 0) //Rotates string
  {
    for (int i = 0; i < rot; i++)
    {
      for (unsigned int x = 1; x < in.size(); x++)
      {
        char y = in[x-1];
        in[x-1] = in[x];
        in[x] = y;
      }
    }
  }

  else //Rotates string the other way if rot is negative
  {
    rot = abs(rot);
    for (int i = 0; i < rot; i++)
    {
      for (unsigned int x = in.size()-1; x > 0; x--)
      {
        char y = in[x-1];
        in[x-1] = in[x];
        in[x] = y;
      }
    }
  }

  smile->cipherText = in;
}

string CaesarCipher::encrypt(string raw)
{
    string retStr;
    cout << "Encrypting..." << endl;
    for(unsigned int i = 0; i < raw.size(); i++) {
        unsigned int pos;
        bool upper = false;
        if(raw[i] == ' ') {
            pos = 26;
        } else if(raw[i] >= 'a') {
            pos = raw[i] - 'a';
        } else {
            pos = raw[i] - 'A';
            upper = 1;
        }
        if(upper) {
            retStr += UPPER_CASE(smile->cipherText[pos]);
        } else {
            retStr += smile->cipherText[pos];
        }
    }
    cout << "Done" << endl;

    return retStr;

}

string CaesarCipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrpyting..." << endl;
    for(unsigned int i= 0; i < enc.size(); i++)
    {
      unsigned int pos;
      bool upper = false;
      if(enc[i] == ' '){
        pos = smile->cipherText.find(' ') + 'a';
        if (pos > 122)
        {
          pos = 32;
        }
      } else if (enc[i] >= 'a') {
        pos = smile->cipherText.find(enc[i]) + 'a';
        if (pos > 122)
        {
          pos = 32;
        }
      } else {
        pos = smile->cipherText.find(tolower(enc[i])) + 'A';
        upper = 1;
      }
      if(upper) {
        retStr += (char)pos;
      } else {
        retStr += (char)pos;
      }
    }
    cout << "Done" << endl;

    return retStr;
}
