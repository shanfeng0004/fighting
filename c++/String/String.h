#include <iostream>

namespace test
{
    class String
    {
        String();
        ~String();

    private:
        String(const String&);
        String& operator=(const String&);

    };
}
