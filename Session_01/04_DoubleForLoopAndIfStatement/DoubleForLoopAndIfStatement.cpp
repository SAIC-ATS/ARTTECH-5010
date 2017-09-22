#include <iostream>

int main()
{
    // The following is a for-loop that reports the current loop number 10 times.
    for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (j <= i)
        {
          // Only output the `#` characher if j is less than or equal to the i.
          std::cout << "#";
        }
      }

      // We output a new line - just like hitting return on the keyboard.
      std::cout << std::endl;
    }

    return 0;
};

