// Rnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include <thread>
#include <future>
#include <time.h>
#include <list>

int randomize(int valueToCheck)
{   
    int maxValue = 0;
    int curValue = 0;

    for (int i = 0; i < valueToCheck; i++)
    {
        curValue = 0;
        for (int j = 0; j < 231; j++)
        {
            if ((rand() % 4) + 1 == 1)
            {
                curValue++;
            }
        }
        if (curValue > maxValue) { maxValue = curValue; }
    }

    return maxValue;
}

void printfcomma(int n) {
    if (n < 1000) {
        printf("%d", n);
        return;
    }
    printfcomma(n / 1000);
    printf(",%03d", n % 1000);
}

int main()
{
    int valueToCheck = 1000000000;
    char strStart[26];
    char strEnd[26];
    std::list<int> values;
    time_t start = time(0);
    ctime_s(strStart, sizeof strStart, &start);
    std::cout << "Started at " << strStart;

    srand((unsigned)start);
    std::future<int> ret1 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret2 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret3 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret4 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret5 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret6 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret7 = std::async(&randomize, valueToCheck / 8);
    std::future<int> ret8 = std::async(&randomize, valueToCheck / 8);
    values.push_back(ret1.get());
    values.push_back(ret2.get());
    values.push_back(ret3.get());
    values.push_back(ret4.get());
    values.push_back(ret5.get());
    values.push_back(ret6.get());
    values.push_back(ret7.get());
    values.push_back(ret8.get());
    int maxValue = *max_element(values.begin(), values.end());
                
    time_t end = time(0);
    ctime_s(strEnd, sizeof strEnd, &end);
    
    std::cout << "Finished at " << strEnd << 
        "Duration: " << difftime(end, start) << "s" << std::endl <<
        "Max value rolled = " << maxValue << " from ";
    printfcomma(valueToCheck);
    std::cout << " rolls." << std::endl;
    std::string nothin;
    std::cin >> nothin;
}