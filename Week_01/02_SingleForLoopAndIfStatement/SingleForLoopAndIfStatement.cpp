#include <iostream>

int main()
{
    // The following is a for-loop that reports the current loop number 10 times.
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            std::cout << "Yep, this is index 5!" << std::endl;
        }
        else if (i == 7)
        {
            std::cout << "This is index 7!" << std::endl;
        }
        else
        {
            std::cout << "This is not 5 or 7, but rather: " << i << std::endl;
        }
    }

    return 0;
};

