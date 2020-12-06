#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

vector<int> findSeatIDs(vector<string> &vect) {
    vector<int> seatIDs;
    for (int i = 0; i < vect.size(); i++)
    {
        replace(vect[i].begin(), vect[i].end(), 'F', '0');
        replace(vect[i].begin(), vect[i].end(), 'B', '1');
        replace(vect[i].begin(), vect[i].end(), 'L', '0');
        replace(vect[i].begin(), vect[i].end(), 'R', '1');

        int row = stoi(vect[i].substr(0, 7), nullptr, 2);
        int seat = stoi(vect[i].substr(7), nullptr, 2);

        int seatID = (row * 8) + seat;

        seatIDs.push_back(seatID); 
    }

    return seatIDs;
    
}

int findMissingSeat(vector<int> &seatIDs) {
    sort(seatIDs.begin(), seatIDs.end());

    for (int i = 0; i < seatIDs.size(); i++)
    {
        if (seatIDs[i + 1] != seatIDs[i] + 1)
        {   
            cout << seatIDs[i] << ", " << seatIDs[i+1] << endl;
            return seatIDs[i] + 1;
        }
        
    }
    return -1;
}

int main() 
{ 
    ifstream is("input.txt");
    vector<string> vect; 

    string x;
    while (std::getline(is, x)) {
      vect.push_back(x);
    }

     is.close();

    vector<int> seatIDs = findSeatIDs(vect);

    int ids = *max_element(seatIDs.begin(), seatIDs.end());
    int missingSeat = findMissingSeat(seatIDs);

    cout << ids << '\n';
    cout << missingSeat << '\n';
    
    return 0;
} 