/**
 * AJ Stein
 * Project 5
 * Data Structures
 * Description: [TBA]
 */ 
#include <sstream>
#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int vertex, weight;
};

// Functions:
void shortestpath(vector<vector<int> > &tvec, vector<string> &city);
int distance(vector<bool> tf, vector<int> tbf);

int main(int argc, char** argv){
//----------------------------------------------------------------------------
    // Declaration of input variables
    int numtest, numcity;
    // load test and city values:
    cin >> numtest >> numcity; 
//----------------------------------------------------------------------------
    // Test that the above works:
    cout << "The number of test: " << numtest << ", The number of cities: " << numcity << endl;
//----------------------------------------------------------------------------
    // Declaration of needed city container and input string
    vector<string> city;
    string inputcity;
//----------------------------------------------------------------------------
    // Standard input for vector
    for(int j = 0; j < numtest; j++){
        for(int i = 0; i < numcity; i++){
            while(cin.peek() == '\n' || cin.peek() == '\r') // Not 100% sure what this does but 2400 always had us doing this
                cin.ignore();
            getline(cin, inputcity);
            city.push_back(inputcity);
        }
    }
//----------------------------------------------------------------------------
    // Test that the vector loaded properly:
    cout << "These are the input cities: ";
    for(int i = 0; i < city.size(); i++)
        cout << city[i] << " ";
//----------------------------------------------------------------------------
    // Declaration of Road vector and input variable. Along with resizing the vector
    vector<vector<int> > tvec;
    string roads;
    int tmp;
//----------------------------------------------------------------------------
    // Note:
    // Hunter and I talked about this method because we both found the same link online
    // I attempted doing it some other ways but they all had a few problems here and there
    for(int i = 0; i < numtest; i++){
        tvec.resize(numcity);
        for(int j = 0; j < numcity; j++){
            getline(cin, roads);
            istringstream line(roads);
            while(line >> tmp)
                tvec[j].push_back(tmp);
        }
    }
//----------------------------------------------------------------------------
    // Test for the vector load:
    cout << endl;
    for(int i = 0; i < tvec.size(); i++){
        for (size_t k = 0; k < tvec[i].size(); k++){
            cout << tvec[i][k] << " ";
        }
        cout << endl;
    }
//----------------------------------------------------------------------------
    shortestpath(tvec, city);




    cout << endl;
    return 0;
}

/**
 * Note:
 * V: stores vertex that have the shortest path (its a bool)
 * P: Stores the previous
 * 3 Containers: VS, V, P
 */ 
//----------------------------------------------------------------------------
void shortestpath(vector<vector<int> > &tvec, vector<string> &city){
    // Declarations: 
    vector<int> tbf(tvec.size(), INT_MAX); // stores the vertices yet to be found
    vector<bool> tf(city.size() - 1, false); // This keeps all the true/false stuff (talked about in rec), initiated with the size of city and all false
    vector<int> previous(city.size() - 1, -1);  // Stores the previous location
    int vertex = tvec[0][0];
    
    tbf[0] = 0;
    tf[0] = true; // Keep in mind the vector is storing 0 and 1 for true and false not actually true and false
    for(int i = 0; i < tvec.size(); i++){
        //int d = distance(tf, tbf);
        //cout << d;
        //tf[d] = true;
        for(int j = 0; j < tvec.size(); j++){
            if(!tf[j] && tvec[i][j] && tbf[i] != INT_MAX && tbf[i] + tvec[i][j] < tbf[j])
			    tbf[j]=tbf[i]+tvec[i][j];

        }
    }

    for (int i = 0; i < city.size() - 1; i++){ // print out last digit
        cout << city[i] << "  ";
    }
    
   cout << tbf[city.size() - 1];

}
//----------------------------------------------------------------------------
int distance(vector<bool> tf, vector<int> tbf){
    int max = INT_MAX, index;
    for(int i = 0; i < tf.size(); i++){
        for(int j = 0; j < tf.size(); j++){
            if(tf[j] == false && tbf[j] <= max){
                max = tbf[j];
                index = j;
            }
        }
    }
    return index;
 }
//----------------------------------------------------------------------------
