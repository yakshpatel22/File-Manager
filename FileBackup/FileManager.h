#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <utility>
#include <iomanip>
/*
*Author     : Yaksh Patel
*Date       : 20/01/2022
*Purpose    : Creating  a C++ Windows console application that recursively backs up source files
             (any file with the extensions .c, .cpp, .h or .hpp) into a backup folder.  Files that are copied
             will be counted and their sizes totaled and reported.
*File Name  :FileManager.h
*Version    :1.0.0
*/

class FileManager
{
public:
    // FileManager Constructors
    FileManager();
    FileManager(std::string sourceDirectory);
    FileManager(std::string sourceDirectory, std::string backupDirectory);

    // Backup the files inside the source directory to the backup directory
    void backup();

    // Report the back-up process status
    void report();

    typedef std::pair<std::filesystem::directory_entry, bool> file_pair;

private:
    std::filesystem::path m_sourcePath, m_backupPath;
    std::vector<file_pair> m_files;
};

