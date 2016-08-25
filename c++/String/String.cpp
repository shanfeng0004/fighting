#include <string.h>

#include "String.h"

namespace test
{
    String::String()
    {
        str_ = new char[1];
        str_[0] = '\0';
    }

    String::~String()
    {
        if (str_ != NULL) {
            delete[] str_;
            str_ = NULL;
        }
    }

    String::String(const String& rhs)
    {
        int len = strlen(rhs.str_);
        str_ = new char[len+1];
        
        strcpy(str_, rhs.str_);
    }

    String& String::operator=(const String& rhs)
    {
        if (this != &rhs) {
            int len = strlen(rhs.str_);
            str_ = new char[len+1];
            
            strcpy(str_, rhs.str_);
        }

        return *this;
    }
}
