/**
 * AJ Stein
 * Project 5
 * Data Structures
 * Description: 
 */ 
#include <climits>
#include <stack>
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

int main(int argc, char** argv){
//----------------------------------------------------------------------------
    // Declaration of input variables
    int numtest, numcity;
    // load test and city values:
    cin >> numtest; 
//----------------------------------------------------------------------------
    // Input:
    for(int j = 0; j < numtest; j++){
        cin >> numcity;
        vector<string> city;
        string inputcity;
        vector<vector<int> > tvec;
        string roads;
        int tmp;
        city.resize(numcity);
//----------------------------------------------------------------------------
    // Input for city:
        for(int i = 0; i < numcity; i++){
            while(cin.peek() == '\n' || cin.peek() == '\r') 
                cin.ignore();
            getline(cin, inputcity);
            city[i] = inputcity;
        }
//----------------------------------------------------------------------------
    // Input for roads:
        tvec.resize(numcity);
        for(int h = 0; h < numcity; h++){
            tvec[h].resize(numcity);
            getline(cin, roads);
            istringstream line(roads);
            int tmp43 = 0;
            while(line >> tmp){
                tvec[h][tmp43] = tmp;
                tmp43++;
            }       
        }
        shortestpath(tvec, city);
    }
//----------------------------------------------------------------------------
    return 0;
}

//----------------------------------------------------------------------------
void shortestpath(vector<vector<int> > &tvec, vector<string> &city){
    // Declarations: 
    vector<int> tbf(tvec.size()); // stores the vertices yet to be found
    vector<bool> tf(city.size(), false); // This keeps all the true/false stuff (talked about in rec), initiated with the size of city and all false
    vector<int> previous(city.size(), -1);  // Stores the previous location
//----------------------------------------------------------------------------
    // initializing tbf to max int, couldnt do it usual way becuase it brought a seg fault. 
    for(int i = 0; i < tvec.size(); i++){
        tbf[i] = INT_MAX;
    }
    tbf[0] = 0;
//----------------------------------------------------------------------------
    // Actual Algorithm part:
    for(int i = 0; i < tvec.size(); i++){
        int minWeight = INT_MAX;
        int v;
        for(int h = 0; h < tvec.size(); h++){
            if(!tf[h]){
                if(tbf[h] < minWeight){
                    v = h;
                    minWeight = tbf[h];
                }
            }
        }
        tf[v] = true;

        for(int j = 0; j < tvec.size(); j++){
            if(!tf[j] && tvec[v][j] && tbf[v] + tvec[v][j] < tbf[j]){
			    tbf[j] = tbf[v] + tvec[v][j];
                previous[j] = v;
            }
        }
    }
//----------------------------------------------------------------------------
    // Output
    int tmp = city.size() - 1;
    stack<int> store;
    store.push(tmp);
    while(tmp > -1){
        tmp = previous[tmp];
        store.push(tmp);
    }
    while(!store.empty()){
        cout << city[store.top()] << " ";
        store.pop();
    }
    cout << tbf[tbf.size() - 1] << endl;    

}
//----------------------------------------------------------------------------

