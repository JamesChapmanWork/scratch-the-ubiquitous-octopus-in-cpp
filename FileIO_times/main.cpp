#include "CIO.h"
#include "CPPIO.h"
#include "WindowsIO.h"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    std::string argv1(argv[1]);

    try
    {
        FileIO::CIO reader(argv1);
        auto t1 = std::chrono::steady_clock::now();
        reader.ReadWholeFile();
        auto t2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = t2 - t1;
        std::cout << "C IO time: " << diff.count() << "\n";
    }
    catch (...)
    {
        std::cerr << "Exception\n";
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(1s);

    try
    {
        FileIO::CPPIO reader(argv1);
        auto t1 = std::chrono::steady_clock::now();
        reader.ReadWholeFile();
        auto t2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = t2 - t1;
        std::cout << "C++ IO time: " << diff.count() << "\n";
    }
    catch (...)
    {
        std::cerr << "Exception\n";
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(1s);

    try
    {
        FileIO::WindowsIO reader(argv1);
        auto t1 = std::chrono::steady_clock::now();
        reader.ReadWholeFile();
        auto t2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = t2 - t1;
        std::cout << "Windows IO time: " << diff.count() << "\n";
    }
    catch (...)
    {
        std::cerr << "Exception\n";
    }

    std::cout << std::endl;

    return 0;
}