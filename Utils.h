#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

//including the iostrem library here ->
#include <iostream>
using namespace std; 
//using standard namespace 

//this line defines the namespace seneca
namespace seneca {

    //starting the namespace block

    //this is a utility class that would provide helper functions for input, string manipulation and formatting
    class Utils {


    public:
        // this makes sure that all the members below this line are accessible outside this class as well


        int getint(int defaultValue)const;
        //this reads an integer from the user , returning a default value if there is no any input provided 

        //this reads an integer from the user without any age restrictions 
        int getInt()const;

        //this read an integer from the user , ensuring that it is within a specified range i.e. from min to max
        int getInt(int min, int max)const;

        char* alocpy(const char* src); // this dynamically allocates memory and copies the provided string , retuening the new string 

        char* alocpy(char*& des, const char* src);
        // this allocates memory for destination string and copies the source string into it

        char* strcpy(char* des, const char* src)const; //this copies a string from 'src' to 'des'

        //this copies exactly 'len' characters from 'src' to des'
        char* strncpy(char* des, const char* src, int len)const;

        //this copies up to 'len; characters from 'src' to 'des'
        char* strcpy(char* des, const char* src, int len)const;

        int strlen(const char* str)const;
        //this returns the length of the given string 


        //this checks if an entire C-string consists of only whitespace characters 
        bool isspace(const char* cstring)const;

        bool isspace(char ch)const;
        //this checks if any given character is a whitespace character 

        //This reads input from an input stream i.e. 'istr' until it reaches a given delimite , the default is a newline 
        char* read(char*& toRet, std::istream& istr, char delimiter = '\n')const;
        //this dynamicaaly allocates memory for the result

        //this prints a string to an output stream ostr'
        
        std::ostream& print(std::ostream& ostr, const char* cstring, size_t maxlen)const;

        char* makeBillFileName(char* filename, size_t billNo)const;

    };


    extern Utils ut;//this is teh global utils object for an easy access to helper functions 


    extern bool debug;
    //this is a global flag to turn on or turn off the debugging 
}

#endif // !SENECA_UTILS_H
//end of header file

