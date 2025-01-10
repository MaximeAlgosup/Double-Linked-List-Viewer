#include "csvFormatting.hpp"
#include <dirent.h>


int main() {
    cout << "Welcome to the CSV formatting tool!" << endl;
    cout << "This tool allows you to add the contents of one file to another, or remove a column from a CSV file." << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Add the contents of one file to another." << endl;
    cout << "2. Merge the contents of all files in a directory to another." << endl;
    cout << "3. Remove a column from a CSV file." << endl;
    cout << "4. Exit." << endl;

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        string source, destination;
        cout << "Enter the name of the source file: ";
        cin >> source;
        cout << "Enter the name of the destination file: ";
        cin >> destination;

        if (addFileToAnother(source, destination))
        {
            cout << "File " << source << " added to " << destination << " successfully." << endl;
        }
    }
    else if (choice == 2)
    {
        string directory, destination;
        cout << "Enter the name of the directory: ";
        cin >> directory;
        cout << "Enter the name of the destination file: ";
        cin >> destination;

        vector<string> fileNames = getFileNamesInDirectory(directory);
        for (const string& fileName : fileNames)
        {
            if (fileName != "." && fileName != "..")
            {
                string source = directory + "/" + fileName;
                if (addFileToAnother(source, destination))
                {
                    cout << "File " << source << " added to " << destination << " successfully." << endl;
                }
            }
        }
    }
    else if (choice == 3)
    {
        string source, destination;
        int column;
        cout << "Enter the name of the source file: ";
        cin >> source;
        cout << "Enter the name of the destination file: ";
        cin >> destination;
        cout << "Enter the column to remove: ";
        cin >> column;

        if (removeColumn(source, destination, column))
        {
            cout << "Column " << column << " removed from " << source << " successfully." << endl;
        }
    }
    else if (choice == 4)
    {
        cout << "Exiting..." << endl;
    }
    else
    {
        cout << "Invalid choice. Exiting..." << endl;
    }

}

bool isFileExists(const string& filename)
{
    FILE* file = fopen(filename.c_str(), "r");
    if (file)
    {
        fclose(file);
        return true;
    }
    return false;
}

vector<string> getFileNamesInDirectory(const string& directory){
    vector<string> fileNames;
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(directory.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            fileNames.push_back(ent->d_name);
        }
        closedir(dir);
    }
    return fileNames;
}


bool addFileToAnother(const string& source, const string& destination)
{
    if (!isFileExists(source))
    {
        cerr << "Error: File " << source << " does not exist." << endl;
        return false;
    }

    if (!isFileExists(destination))
    {
        cerr << "Error: File " << destination << " does not exist." << endl;
        return false;
    }

    FILE* sourceFile = fopen(source.c_str(), "r");
    FILE* destinationFile = fopen(destination.c_str(), "a");

    if (!sourceFile || !destinationFile)
    {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    char c;
    while ((c = fgetc(sourceFile)) != EOF)
    {
        fputc(c, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return true;
}


bool removeColumn(const string& source, const string& destination, int column)
{
    if (!isFileExists(source))
    {
        cerr << "Error: File " << source << " does not exist." << endl;
        return false;
    }

    FILE* sourceFile = fopen(source.c_str(), "r");
    FILE* destinationFile = fopen(destination.c_str(), "w");

    if (!sourceFile || !destinationFile)
    {
        cerr << "Error: Could not open file." << endl;
        return false;
    }

    char c;
    int currentColumn = 1;
    bool inQuotes = false;
    while ((c = fgetc(sourceFile)) != EOF)
    {
        if (c == '"')
        {
            inQuotes = !inQuotes;
        }

        if (c == ',' && !inQuotes)
        {
            currentColumn++;
        }

        if (currentColumn != column)
        {
            fputc(c, destinationFile);
        }

        if (c == '\n')
        {
            currentColumn = 1;
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return true;
}

int getColumnCount(const string& source)
{
    if (!isFileExists(source))
    {
        cerr << "Error: File " << source << " does not exist." << endl;
        return -1;
    }

    FILE* file = fopen(source.c_str(), "r");

    if (!file)
    {
        cerr << "Error: Could not open file." << endl;
        return -1;
    }

    char c;
    int columnCount = 1;
    bool inQuotes = false;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '"')
        {
            inQuotes = !inQuotes;
        }

        if (c == ',' && !inQuotes)
        {
            columnCount++;
        }

        if (c == '\n')
        {
            break;
        }
    }

    fclose(file);

    return columnCount;
}