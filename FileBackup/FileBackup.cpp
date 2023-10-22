// FileBackup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
*Author    : Yaksh Patel
*Date      : 20/01/2022
*Purpose   : Creating  a C++ Windows console application that recursively backs up source files
            (any file with the extensions .c, .cpp, .h or .hpp) into a backup folder.  Files that are copied
            will be counted and their sizes totaled and reported.
*File Name :FileBackup.cpp
*Version   :1.0.0
*/

#include "FileManager.h"

int main(int argc, char **argv)
{
    // Case 1: ./filebackup
    if (argc == 1)
    {
        FileManager fmObj;

        fmObj.backup();
        fmObj.report();
    }
    // Case 2: ./filebackup path
    else if (argc == 2)
    {
        FileManager fmObj(argv[1]);

        fmObj.backup();
        fmObj.report();
    }
    // Case 3: ./filebackup path1 path2
    else if (argc == 3)
    {
        FileManager fmObj(argv[1], argv[2]);

        fmObj.backup();
        fmObj.report();
    }
    // Unknown
    else
    {
        std::cerr << "Usage: ./filebackup [sourcedir] [backupdir]" << std::endl;
        return 1;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
