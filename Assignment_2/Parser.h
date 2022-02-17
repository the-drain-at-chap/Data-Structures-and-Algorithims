#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Parser{
  public:
    Parser();                     //Default constructor
    Parser(string s);             //Overloaded constructor
    ~Parser();                    // Destructor
    void ParseString(){                     //iterates through user input's string and uses a switch statement to get number of all alphabets and non-alphabets in string.
      for (int i = 0; i < userInput.size(); i++){
        switch(userInput[i]){
          case 'a':
            a++;
            break;
          case 'A':
            a++;
            break;
          case 'b':
            b++;
            break;
          case 'B':
            b++;
            break;
          case 'c':
            c++;
            break;
          case 'C':
            c++;
            break;
          case 'd':
            d++;
            break;
          case 'D':
            d++;
            break;
          case 'e':
            e++;
            break;
          case 'E':
            e++;
            break;
          case 'f':
            f++;
            break;
          case 'F':
            f++;
            break;
          case 'g':
            g++;
            break;
          case 'G':
            g++;
            break;
          case 'h':
            h++;
            break;
          case 'H':
            h++;
            break;
          case 'i':
            i++;
            break;
          case 'I':
            i++;
            break;
          case 'j':
            j++;
            break;
          case 'J':
            j++;
            break;
          case 'k':
            k++;
            break;
          case 'K':
            k++;
            break;
          case 'l':
            l++;
            break;
          case 'L':
            l++;
            break;
          case 'm':
            m++;
            break;
          case 'M':
            m++;
            break;
          case 'n':
            n++;
            break;
          case 'N':
            n++;
            break;
          case 'o':
            o++;
            break;
          case 'O':
            o++;
            break;
          case 'p':
            p++;
            break;
          case 'P':
            p++;
            break;
          case 'q':
            q++;
            break;
          case 'Q':
            q++;
            break;
          case 'r':
            r++;
            break;
          case 'R':
            r++;
            break;
          case 's':
            s++;
            break;
          case 'S':
            s++;
            break;
          case 't':
            t++;
            break;
          case 'T':
            t++;
            break;
          case 'u':
            u++;
            break;
          case 'U':
            u++;
            break;
          case 'v':
            v++;
            break;
          case 'V':
            v++;
            break;
          case 'w':
            w++;
            break;
          case 'W':
            w++;
            break;
          case 'x':
            x++;
            break;
          case 'X':
            x++;
            break;
          case 'y':
            y++;
            break;
          case 'Y':
            y++;
            break;
          case 'z':
            z++;
            break;
          case 'Z':
            z++;
            break;
          default:
            nonalpha++;
            break;
        }
      }
    }
    int GetAlphabetTotal(){                   //adds all alphabet private variables together and returns total number of alphabet that was in string
      int total;
      total = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + x + y + z;
      return total;
    }
    int GetNonAlphabetTotal(){               //returns nonalpha private variable
      return nonalpha;
    }
    double GetAlphabetAverage(){            //adds all private variables together and divides by 26.0 to return the average number of alphabet in string
      double average;
      double total = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t + u + v + w + x + y + z;
      average = total / 26.0;
      return average;
    }
    int GetNumPairs(){                    //finds number of pairs of string by comparing i with the next index to see if they are the same, stops before the final index
      int numPairs = 0;
      for (int i = 0; i < userInput.size() - 1; i++){
        if(userInput[i] == userInput[i + 1]){
            numPairs++;
        }
      }
      return numPairs;
    }
    void CreateOutputFile(){            //creates output file in the format required in the assignment requirements
      ofstream outputfile;
      outputfile.open("outputfile.txt", ios_base::app);
      outputfile << "a:" << a << endl;
      outputfile << "b:" << b << endl;
      outputfile << "c:" << c << endl;
      outputfile << "d:" << d << endl;
      outputfile << "e:" << e << endl;
      outputfile << "f:" << f << endl;
      outputfile << "g:" << g << endl;
      outputfile << "h:" << h << endl;
      outputfile << "i:" << i << endl;
      outputfile << "j:" << j << endl;
      outputfile << "k:" << k << endl;
      outputfile << "l:" << l << endl;
      outputfile << "m:" << m << endl;
      outputfile << "n:" << n << endl;
      outputfile << "o:" << o << endl;
      outputfile << "p:" << p << endl;
      outputfile << "q:" << q << endl;
      outputfile << "r:" << r << endl;
      outputfile << "s:" << s << endl;
      outputfile << "t:" << t << endl;
      outputfile << "u:" << u << endl;
      outputfile << "v:" << v << endl;
      outputfile << "w:" << w << endl;
      outputfile << "x:" << x << endl;
      outputfile << "y:" << y << endl;
      outputfile << "z:" << z << endl;
      outputfile << "alphabets:" << GetAlphabetTotal() << endl;
      outputfile << "non-alphabets:" << GetNonAlphabetTotal() << endl;
      outputfile << "average:" << GetAlphabetAverage() << endl;
      outputfile << "pairs:" << GetNumPairs() << endl;
      outputfile.close();
    }

  private:                        //private variables include the string, the number of all the alphabets, and the number of all the nonalphabets
    string userInput;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int nonalpha = 0;
};

Parser::Parser(){           //default constructor has string be blank by default if there is no user input
  userInput = "";
}

Parser::Parser(string s){           //overloaded constructor sets string to whatever user inputs
  userInput = s;
}

Parser::~Parser(){                  //destructor prints bye bye to indicate object successfully being deleted
  cout << "bye bye" << endl;
}
