#pragma once

#include <iostream>
#include <vector>

// Windows Headers
#include <Windows.h>

namespace FileIO
{
    class WindowsIO
    {
    public:
        explicit WindowsIO(std::string filePath)
        {
            m_fileHandle = ::CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, NULL);
        }

        virtual ~WindowsIO()
        {
            ::CloseHandle(m_fileHandle);
        }

        bool ReadWholeFile()
        {
            DWORD fileSize{};
            DWORD dataRead{};
            fileSize = ::GetFileSize(m_fileHandle, NULL);
            ::SetFilePointer(m_fileHandle, 0, NULL, FILE_BEGIN);
            std::vector<std::uint8_t> buffer(fileSize);

            if (!::ReadFile(m_fileHandle, buffer.data(), fileSize, &dataRead, NULL))
            {
                return false;
            }
            if (dataRead != fileSize)
            {
                std::cerr << "Read error: read " << dataRead << " bytes of " << fileSize << "\n";
                return false;
            }

            std::cout << "Read " << dataRead << " bytes\n";
            return true;
        }

    private:
        HANDLE m_fileHandle{};
    };
}