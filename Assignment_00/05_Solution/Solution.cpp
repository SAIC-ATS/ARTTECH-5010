#include <iostream>

int main()
{
    for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        if ((i + j) % 2 == 0)
        {
          std::cout << "\\";
        }
        else
        {
          std::cout << "/";
        }

      }
      std::cout << std::endl;
    }

    return 0;
};

