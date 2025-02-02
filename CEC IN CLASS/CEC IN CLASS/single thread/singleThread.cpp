#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

long avg = 0;
long sum = 0;
int times = 0;

int getRandom() {
    int result = rand() % 100;
    return result;
}

//search of a value
void my_thread1(vector<int> values1) {
    int n = values1.size();
    for(int i = 0; i < n; i++) {
        if(values1[i] == 20)
            times++;
    }
}

//average the values
void my_thread2(vector<int> values1) {
    int n = values1.size();
    for(int i = 0; i < n; i++) {
        sum += values1[i];
    }
}

int main() {

    vector<int> values1(1000000);
    generate(values1.begin(), values1.end(), getRandom);

    int n = values1.size();

    auto time1 = high_resolution_clock::now();

    /*
    thread t1(my_thread1, values1);
    thread t2(my_thread2, values1);

    t1.join();
    t2.join();
    */

    for(int i = 0; i < n; ++i) {
        sum += values1[i];
        if(values1[i] == 4)
            ++times;
    }
    
    avg = sum / n;

    auto time2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(time2 - time1);

    cout << "\nAverage is: " << avg << endl;
    
    if(times == 0)
        cout << "\nValue not found" << endl;
    else    
        cout << "\nValue found " << times << " times" << endl;

    cout << "\nTime to execute: " << duration.count() << " microseconds" << endl;

}
