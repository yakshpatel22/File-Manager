#include "FileManager.h"
/*
*Author    : Yaksh Patel
*Date      : 20/01/2022
*Purpose   : Creating  a C++ Windows console application that recursively backs up source files 
            (any file with the extensions .c, .cpp, .h or .hpp) into a backup folder.  Files that are copied 
            will be counted and their sizes totaled and reported.
*File Name  :FileManager.cpp
*Version    :1.0.0
*/

FileManager::FileManager() : FileManager(std::filesystem::current_path().string())
{
}

FileManager::FileManager(std::string sourceDirectory) : FileManager(sourceDirectory, "C:\\backup\\")
{
}

FileManager::FileManager(std::string sourceDirectory, std::string backupDirectory)
    : m_sourcePath(sourceDirectory), m_backupPath(backupDirectory)
{
    // Read the files in the source directory
    for (const auto& file : std::filesystem::directory_iterator(m_sourcePath))
    {
        // Only consider the regular files and those that have extensions ".cpp, .h, .c, .hpp"
        if (!file.is_regular_file())
            continue;
        
        // Get the file extension
        std::string ext = file.path().extension().string();
        
        // Filter the file extension
        if (ext != ".cpp" && ext != ".c" && ext != ".h" && ext != ".hpp")
            continue;

        // Add to the list
        m_files.push_back(file_pair(file, false));
    }

    // Create the back-up directory if it doesn't exist
    if (!std::filesystem::exists(m_backupPath))
    {
        std::filesystem::create_directory(m_backupPath);
    }
}

// Backup the files inside the source directory to the backup directory
void FileManager::backup()
{
    for (auto& file_entry : m_files)
    {
        // Check if the file is already in the back up folder
        std::filesystem::path filePath = m_backupPath;

        // Build the file path
        filePath.replace_filename(file_entry.first.path().filename());

        // Copy the file from the source directory if it does not exist
        if (!std::filesystem::exists(filePath))
        {
            // Copy the file
            std::filesystem::copy(file_entry.first.path(), filePath);

            // Update the back up flag
            file_entry.second = true;
        }
    }
}

// Report the back-up process status
void FileManager::report()
{
    std::cout << "Root Directory: " << m_sourcePath.string() << std::endl;
    std::cout << "Backup Directory: " << m_backupPath.string() << std::endl;

    // Get maximum file name length
    int width = 0;

    for (const auto& file_entry : m_files)
    {
        if (file_entry.first.path().filename().string().size() > width)
        {
            width = file_entry.first.path().filename().string().size();
        }
    }


    // Loop through all the files
    for (const auto& file_entry : m_files)
    {
        if (file_entry.second)
        {
            std::cout << "+";
        }
        else
        {
            std::cout << "-";
        }

        // Print the filename
        std::cout << std::right << std::setw(width) << file_entry.first.path().filename().string();

        // Print the file size
        std::cout << "              Size: " << std::fixed << file_entry.first.file_size() << std::endl;
    }
}