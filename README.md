# File-Manager
This C++ Windows console application, FileManager, is my solution to the need for a tool to automatically back up source files. It recursively identifies and backs up files with extensions .c, .cpp, .h, or .hpp from a specified source directory to a backup folder. As part of this process, the application also counts the files copied and calculates their total size, providing a comprehensive report of the backup operation.

Key Features:-
1. Automatic Source File Backup: The application automates the backup of source files, sparing you the manual effort of copying them to a backup location.
2. Recursive File Identification: It scans the source directory recursively, ensuring that files from subdirectories are also included in the backup process.
3. File Type Filtering: The tool is tailored to developers' needs, backing up only source files with extensions .c, .cpp, .h, or .hpp.
4. Backup Report: After each backup operation, the application generates a detailed report that summarizes which files were copied, their sizes, and the overall success of the backup process.

How to Use:-
The FileManager application is designed to be easy to use with straightforward command-line options:

1. Case 1: Default Mode
  Execute ./filebackup with no arguments to initiate the backup process from the current directory.
2. Case 2: Specify Source Directory
  Run ./filebackup [sourcedir] to specify a source directory for the backup operation.
3. Case 3: Define Source and Backup Directories
  For more control, use ./filebackup [sourcedir] [backupdir] to specify both the source and backup directories.

What I've Learned:-
During the development of this project, I've gained valuable insights and hands-on experience in various areas of software development, including:

1. Filesystem Operations: I've learned how to navigate and manipulate directories and files using C++'s Standard Library filesystem component.
2. Object-Oriented Programming (OOP): I've applied OOP principles to structure the code, creating a flexible and reusable FileManager class.
3. Working with Paths: The project involved working with file paths, a skill essential for any file-related operation.
4. Command-Line Argument Handling: I've learned how to interpret and process command-line arguments, making the application versatile and user-friendly.
5. Custom Data Types: By defining a custom data type (file_pair), I've managed to encapsulate both file entries and their backup status, improving code organization.
6. Error Handling: I've included error handling to provide meaningful messages when the user provides incorrect arguments.

Get Started
You can clone this repository, compile the code, and start using FileManager to simplify and automate your source file backup process. Enhance your file management capabilities with a tool that takes the hassle out of keeping your source code safe and organized.
