#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std; 

string removeDuplicates(string answers) {
    string noDuplicates = "";
    for (int i = 0; i < answers.length(); i++)
    {
        size_t found = noDuplicates.find(answers[i]);
        if (found == string::npos)
        {
            noDuplicates += answers[i];
        }
        
    }

    return noDuplicates;
    
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
            temp.append(vec[i]);
        }
    }
    accumulated.push_back(temp);
  
    vector<string> answers;
    for (int i = 0; i < accumulated.size(); i++)
    {
        answers.push_back(removeDuplicates(accumulated[i]));
    }

    int result = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        result += answers[i].length();  
    }
  
    return result;
}
 

int part2(vector<string> &vec) {
    vector<int> charOccurences(26,0);
    int indexOfLastGroup = 0;
    int result = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != "")
        {
            for (int j = 0; j < vec[i].length(); j++)
            {
                charOccurences[vec[i][j] - 'a'] += 1;
            }
        } else
        {
            for (int j = 0; j < charOccurences.size(); j++)
            {
                if (charOccurences[j] == i - indexOfLastGroup)
                {
                    result++;
                }
                
            }
            fill(charOccurences.begin(), charOccurences.end(), 0);
            indexOfLastGroup = i + 1;
            
        }
        
        
    }

    return result;
    
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
    vect.push_back("");
    int result2 = part2(vect);
    cout << result << '\n';
    cout << result2 << endl;
    
    is.close();
    
    return 0;
} 