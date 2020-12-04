#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 

int part1(vector<int> &vec) {
  std::sort(vec.begin(), vec.end());
  int left = 0;
  int right = vec.size()-1;
  while (left < right) {
    int sum = (vec[left] + vec[right]);
    if (sum == 2020)
    {
      return vec[left] * vec[right];
    }
    else if (sum < 2020)
    {
      left++;
    } 
    else
    {
      right--;
    }
  }

  return -1;
}

int main() 
{ 
    ifstream is("input.txt");
    // read into vector
    vector<int> vect; 

    int x;
    while (is >> x) {
      vect.push_back(x);
    }

    int result = part1(vect);
    cout << result << '\n';
    
    is.close();
    
    return 0;
} 