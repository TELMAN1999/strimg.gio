#include "string.h"
#include <iostream>
#include <cstring>
#include <string>

int main()
{
        String a, b;

        a = "hello ";
        b = "world";

        std::cout << "a = " << a << ", b = " << b << '\n';

        std::cout << "a + b = " << a + b << '\n';

        a.swap(b);

        std::cout << "After swap: a = " << a << ", b = " << b << '\n';

        a.append(b);

        std::cout << "After appending: a = " << a << ", b = " << b << '\n';

        int index = a.find_first_of("llo");

        std::cout << "First index of 'llo' in a is: " << index << '\n';
	
	a = "adsfadsfasdfadsddf";
	b = "asdfadfadsfffvczxv";

	std::cout << "std::strcmp a < b = " << std::strcmp(a,b) << std::endl;
	std::cout << "my_strcmp a < b = " << String::strcmp(a,b) << std::endl;
        return 0;
}
