#include <iostream>

namespace test
{
    class String
    {
        String();

        ~String();

        String(const String& rhs);

        String& operator=(const String& rhs);

    private:
        char* str_;
    };
}
