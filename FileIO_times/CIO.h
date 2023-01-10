#pragma once

#include <iostream>
#include <vector>

namespace FileIO
{
    class CIO
    {
    public:
        explicit CIO(std::string filePath)
        {
            m_fileHandle = ::fopen(filePath.c_str(), "rb");
        }

        virtual ~CIO()
        {
            ::fclose(m_fileHandle);
        }

        bool ReadWholeFile()
        {
            size_t fileSize{};
            size_t dataRead{};
            ::fseek(m_fileHandle, 0, SEEK_END);
            fileSize = ::ftell(m_fileHandle);
            ::fseek(m_fileHandle, 0, SEEK_SET);
            std::vector<std::uint8_t> buffer(fileSize);

            dataRead = ::fread(buffer.data(), 1, fileSize, m_fileHandle);

            if (dataRead != fileSize)
            {
                std::cerr << "Read error: read " << dataRead << " bytes of " << fileSize << "\n";
                return false;
            }
            std::cout << "Read " << dataRead << " bytes\n";
            return true;
        }

    private:
        FILE *m_fileHandle{};
    };
}