//
//  doubleThread.cpp
//  CEC 470 HW 1
//
//  Created by Daniel Stone on 1/27/25.
//
//  Iteratively calculates the sum of integers 1 - 1,500,000 500 times and reports
//  total execution time and average execution time of each of the 500 iterations.
//  Half of the problem is done in another thread and results for time of execution
//  are compared.
//

#include <iostream>
#include <chrono>
#include <thread>

void sum_num(int start, int end, int &sum) {
    for(int i = start; i <= end; i++) {
        sum += i;
    }
}

int main() {
    
    int sumTimers = 0;

    for(int i = 0; i < 500; i++) {
        int sum1 = 0;
        int sum2 = 0;
        
        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();

        //Create thread to calculate first half of 1,500,000
        std::thread t1(sum_num, 1, 750000, std::ref(sum1));
        
        //Calculate second half
        for(int j = 750001; j <= 1500000; j++){
            sum2 += j;
        }

        //Join thread
        t1.join();
        
        //add sums together
        int totalSum = sum1 + sum2;

        //Stop the timer
        auto stop = std::chrono::high_resolution_clock::now();
        
        //Calculate duration
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        sumTimers += duration.count();
        std::cout << duration.count() << std::endl;
    }

    std::cout << "Average execution time: " << sumTimers / 500 << " microseconds" << std::endl;
    std::cout << "Total execution time: " << sumTimers << " microseconds" << std::endl;
 
 return 0;
}

