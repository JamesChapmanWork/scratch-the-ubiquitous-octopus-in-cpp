#include <thread>
#include <vector>

constexpr int threadsToSpawn = 8;

int main()
{
    std::vector<std::thread> threadVector;

    auto calculatePrimes = []()
    {
        std::vector<int> primeNumbers;
        for (int i = 1; i < INT32_MAX; ++i)
        {
            for (int j = 1; j < i / 2; ++j)
            {
                if (j % 2 == 0)
                {
                    ++j;
                }
                if (i % j == 0)
                {
                    break;
                }
            }
            primeNumbers.push_back(i);
        }
    };

    // Start 10 threads with a named and better expressed lambda function.
    for (int i = 0; i < threadsToSpawn; i++)
    {
        threadVector.push_back(std::thread(calculatePrimes));
    }

    for (auto &thr : threadVector)
    {
        thr.join();
    }

    return 0;
}