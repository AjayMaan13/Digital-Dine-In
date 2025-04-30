#include <iostream>
#include <string>
#include <limits>

using namespace std;
//using standard namespace 

#include "Utils.h" //including the header file "utils.h" here 



//this line defines the namespace seneca
namespace seneca {

    //starting the namespace block

    Utils ut;
    //this is a global utils object 

    //this is a debug mode flag 
    bool debug = false;









    //this is a memory block size for dynamic memory allocation  
    const size_t AllocationBlockSize = 128;


    //this gets an integer within the provided range 
    int Utils::getInt(int min, int max)const {
        int value;
        bool valid = false;
        //starting while 
        while (!valid) {
            value = getInt(); //this getsuser input 
            if (value < min || value > max) {
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
                continue;
            }
            valid = true;
        }
        return value;
    }


    //if the input is empty, this gets an integer using a default value
    int Utils::getint(int defaultValue) const {
        string input;




        cin >> ws; // this line skips the whitespace 
        getline(cin, input);

        if (input.empty()) {
            return defaultValue;
        }
        else {
            return stoi(input); // this line converts a sr=tring into an integer 
        }
    }
    //this gets an integer and ensures proper input handling 
    int Utils::getInt() const {
        int value;
        string input;
        bool valid = false;
    
        while (!valid) {
            getline(cin, input);
    
            if (input.empty()) {
                cout << "You must enter a value: ";
                continue;
            }
    
            try {
                size_t idx;
                value = stoi(input, &idx);
    
                if (idx != input.length()) {
                    cout << "Only an integer please: ";
                    continue;
                }
    
                if (value < 0 || value > 3) {
                    cout << "Invalid value: [0<= value <=3], try again: ";
                    continue;
                }
    
                valid = true;
            } catch (invalid_argument&) {
                cout << "Invalid integer: ";
            } catch (out_of_range&) {
                cout << "Invalid integer: ";
            }
        }
    
        return value;
    }


    //this allocates and copies a string 
    char* Utils::alocpy(const char* src) {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src){
        //this allocates and copies a string into a given destination 

        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }


    char* Utils::strcpy(char* des, const char* src)const { //this copies a string 
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0); //this line null terminates the string 
        return des;
    }


    //this copies a string with a specific length 
    char* Utils::strcpy(char* des, const char* src, int len)const {
        int i;
        for (i = 0; i < len && src[i]; i++) des[i] = src[i];
        des[i] = 0; // this is a null terminator
        return des;
    }


    //this copies a string with a specific length 
    //this is similar to strncpy
    char* Utils::strncpy(char* des, const char* src, int len)const {
        int i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i]; //null terminate 
        return des;
    }


    //this gets the string length 
    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    // this reads a string dynamically from the input 
    char* Utils::read(char*& toRet, istream& istr, char delimiter)const {
        bool done = false;

        //this allocates the initial memory 
        char* cstr = new char[AllocationBlockSize];
        toRet = cstr;
        int size = AllocationBlockSize;
        int nullindex = 1;


        do {
            cin.getline(cstr, AllocationBlockSize, delimiter);
            if (cin.fail()) {
                //if the input exceeds the allocated size , it automatically increases the memory 
                char* temp = new char[size + AllocationBlockSize];
                strcpy(temp, toRet);
                delete[] toRet;
                toRet = temp;
                cstr = &toRet[size - nullindex++];
                size += AllocationBlockSize;
                cin.clear();
            }
            else {
                done = true;
            }
        } while (!done);

        //this allocates just enough memory for the final string 
        char* temp = new char[strlen(toRet) + 1];
        strcpy(temp, toRet);
        delete[] toRet;
        toRet = temp;
        return toRet;
    }

    //this checks if character is a whitespace 
    bool Utils::isspace(char ch)const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r'; // r f v n t
    }


    //this checks if a string contains whitespace only 
    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    // function provided by module
    char* Utils::makeBillFileName(char* filename, size_t billNo)const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        // Calculate the number of digits
        do {
           cnt++;
           temp /= 10;
        } while (temp > 0);
        length = cnt;
        // Convert each digit to character from the end
        while (billNo > 0) {
           billFileName[--cnt] = (billNo % 10) + '0';
           billNo /= 10;
        }
        // Handle the case when billNo is 0
        if (billFileName[cnt - 1] == '\0') {
           billFileName[--cnt] = '0';
        }
        // Attach .txt to the end of the file name
        for (int i = 0; ".txt"[i]; i++) {
           billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
     }
    

}
//end of utils.cpp file 
