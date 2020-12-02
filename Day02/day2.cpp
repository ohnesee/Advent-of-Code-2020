#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 

bool oldPolicy( string instr, string pw) {
  int min = std::stoi(instr.substr(0, instr.find("-")));
  int max =  std::stoi(instr.substr(instr.find("-")+1, instr.find(" ")));
  char c = instr[instr.size()-1];
  
  int count = std::count(pw.begin(), pw.end(), c);
  
  if (count >= min && count <= max )
  {
    return true;
  }
              
  return false;
}

bool newPolicy( string instr, string pw) {
  int pos1 = std::stoi(instr.substr(0, instr.find("-")));
  int pos2 =  std::stoi(instr.substr(instr.find("-")+1, instr.find(" ")));
  char c = instr[instr.size()-1];
  
  if (pw[pos1] == c && !(pw[pos2] == c))
  {
    return true;
  } else if (!(pw[pos1] == c) && (pw[pos2] == c))
  {
    return true;
  } else
  {
    return false;
  }

  return false;
}

int checkPasswords(vector<string> &vec) {
  int count = 0;

  for (int i = 0; i < vec.size(); i++)
  {
    string instruction = vec[i].substr(0, vec[i].find(":"));
    string password = vec[i].substr(vec[i].find(": ")+1 , vec.size()-1);
    if (newPolicy(instruction, password))
    {
      count = count + 1;
    }
    
    
  }
  
  return count;
}

int main() 
{ 
    ifstream is("input.txt");
    // read into vector
    vector<string> vect; 

    string x;
    while (std::getline(is, x)) {
      vect.push_back(x);
    }

    int result = checkPasswords(vect);
    cout << result << '\n';
    
    is.close();
    
    return 0;
} 