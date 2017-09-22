#include <iostream>

int main()
{
    // The following is a for-loop that reports the current loop number 10 times.
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        std::cout << "i = " << i << " and j = " << j << std::endl;
      }

      // We output a new line - just like hitting return on the keyboard.
      std::cout << std::endl;
    }

    return 0;
};

