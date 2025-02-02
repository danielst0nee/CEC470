//
//  main.cpp
//  CEC IN CLASS
//
//  Created by Daniel Stone on 1/29/25.
//

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace std::chrono;

//generate a random number between 0 and 99
int getRandom() {
    int result = rand() % 100;
    return result;
}

/*
void my_thread1_fun(vector<int> values1) {
    sort(values1.begin(), values1.end());
}
 */

// measure execution for sorting vector of 2 million values
int main() {
    
    //starting time
    auto time1 = high_resolution_clock::now();
    
    //initialize vectors
    vector<int> values1(1000000);
    vector<int> values2(1000000);
    
    //fill up vectors with random numbers
    generate(values1.begin(), values1.end(), getRandom);
    generate(values2.begin(), values2.end(), getRandom);

    //ending time
    auto time2 = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(time2 - time1);
    
    cout << "The time to create random vectors was: " << duration.count() << " milliseconds" << endl;
    
    //get sorting start time
    time1 = high_resolution_clock::now();
    
    //sort vectors
    sort(values1.begin(), values1.end());
    sort(values2.begin(), values2.end());
    
    //get sorting end time
    time2 = high_resolution_clock::now();
    
    
    duration = duration_cast<milliseconds>(time2 - time1);
    
    cout << "The time to sort the vectors was: " << duration.count() << " milliseconds" << endl;
    
    return 0;
}

