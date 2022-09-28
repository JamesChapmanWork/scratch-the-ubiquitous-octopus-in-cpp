#include <iostream>
#include <thread>
#include <vector>

int main()
{
    const auto processorCount = std::thread::hardware_concurrency();
    std::cout << processorCount << " CPU cores detected\n\n";

    std::vector<std::thread> threadVector;

    auto calculatePrimes = []()
    {
        bool isPrime{ false };
        std::vector<int> primeNumbers;
        for (int i = 3; i < INT32_MAX; ++i)
        {
            isPrime = true;
            for (int j = 3; j < i / 2; ++j)
            {
                if (i % 2 == 0)
                {
                    isPrime = false;
                    continue;
                }
                if (i % j == 0)
                {
                    isPrime = false;
                    continue;
                }
            }
            if (isPrime)
            {
                primeNumbers.push_back(i);
            }
        }
    };

    // Start 10 threads with a named and better expressed lambda function.
    for (int t = 0; t < processorCount; t++)
    {
        std::cout << "Spawning thread " << t + 1 << "...\n";
        threadVector.push_back(std::thread(calculatePrimes));
    }

    for (auto &thr : threadVector)
    {
        thr.join();
    }

    return 0;
}