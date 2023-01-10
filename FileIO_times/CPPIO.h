#pragma once

#include <fstream>
#include <iostream>
#include <vector>

namespace FileIO
{
    class CPPIO
    {
    public:
        explicit CPPIO(std::string filePath)
        {
            m_fileHandle.open(filePath.c_str(), std::ifstream::binary);
        }

        virtual ~CPPIO()
        {
            m_fileHandle.close();
        }

        bool ReadWholeFile()
        {
            size_t fileSize{};
            m_fileHandle.seekg(0, m_fileHandle.end);
            fileSize = m_fileHandle.tellg();
            m_fileHandle.seekg(0, m_fileHandle.beg);
            std::vector<std::uint8_t> buffer(fileSize);

            m_fileHandle.read(reinterpret_cast<char *>(buffer.data()), fileSize);

            if (!m_fileHandle)
            {
                std::cerr << "Read error: read " << m_fileHandle.gcount() << " bytes of " << fileSize << "\n";
                return false;
            }
            std::cout << "Read " << m_fileHandle.gcount() << "bytes\n";
            return true;
        }

    private:
        std::ifstream m_fileHandle{};
    };
}