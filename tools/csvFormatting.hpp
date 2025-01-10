/*!
    \file csvFormatting.hpp
    \brief Small utility functions for CSV file formatting.
    \author Maxime CARON
    \date 01-10-2025
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

/*!
    \brief Check if a file exists.
    \param filename The name of the file to check.
    \return True if the file exists, false otherwise.
*/
bool isFileExists(const string& filename);


/*!
    \brief Get all file names in a directory.
    \param directory The name of the directory to get the file names from.
    \return A vector containing all the file names in the directory.
*/
vector<string> getFileNamesInDirectory(const string& directory);


/*!
    \brief Add the contents of one file to another.
    \param source The name of the file to add.
    \param destination The name of the file to add to.
    \return True if the operation was successful, false otherwise.
*/
bool addFileToAnother(const string& source, const string& destination);


/*!
    \brief Remove a column from a CSV file.
    \param source The name of the file to remove the column from.
    \param destination The name of the file to write the result to.
    \param column The column to remove.
    \return True if the operation was successful, false otherwise.
*/
bool removeColumn(const string& source, const string& destination, int column);


/*!
    \brief Get the number of columns in a CSV file.
    \param source The name of the file to get the number of columns from.
    \return The number of columns in the file.
*/
int getColumnCount(const string& source);