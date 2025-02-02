//
//  singleThread.cpp
//  CEC 470 HW 1
//
//  Created by Daniel Stone on 1/27/25.
//
//  Iteratively calculates the sum of integers 1 - 1,500,000 500 times and reports
//  total execution time and average execution time of each of the 500 iterations.
//

#include <iostream>
#include <chrono>


int main() {
    
    int sumTimers = 0;

    for(int i = 0; i < 500; i++) {
        int sum = 0;
        
        // Start the timer
        auto start = std::chrono::high_resolution_clock::now();
        
        for(int j = 1; j <= 1500000; j++) {
            sum += j;
        }
        
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

