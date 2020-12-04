#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 

bool validPassport(string &passport) {
  string checks [7] = {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
  for (int i = 0; i < 7; i++)
  {
    size_t found = passport.find(checks[i]);
    if (found == string::npos)
    {
      return false;
    }
  }
  return true;
}

int part1(vector<string> &vec) {
  vector<string> accumulated;
  string temp = "";
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == "")
    {
      accumulated.push_back(temp);
      temp = "";
    } else
    {
      temp.append(" ");
      temp.append(vec[i]);
    }
  }
  accumulated.push_back(temp);

  int count = 0;
  for (int i = 0; i < accumulated.size(); i++)
  {

    string passport = accumulated[i];
    if (validPassport(passport)) {
      count++;
    }

  }
  
  return count;
}

int main() 
{ 
    ifstream is("input.txt");
    vector<string> vect; 

    string x;
    while (getline(is, x)) {
      vect.push_back(x);
    } 

    int result = part1(vect);
    cout << result << '\n';
    
    is.close();
    
    return 0;
} 