//this is a getCWD() reimplementation

#include "./headder_files/default.h"
#include <filesystem>
#include <iostream>
#include<algorithm>

string getCWD(char* argv[])
{
    ostringstream argvo;
    argvo << argv[0];
    string argvs = argvo.str();
    size_t pos = std::string::npos;
    string toErase = "main.o";
    // Search for the substring in string in a loop untill nothing is found
    while ((pos  = argvs.find(toErase) )!= std::string::npos)
    {
        // If found then erase it from string
        argvs.erase(pos, toErase.length());
    }
    cout << argvs <<endl;
    return argvs;
}

std::string GetDirectory(const std::string& path)
{
    size_t found = path.find_last_of("/\\");
    return(path.substr(0, found));
}
