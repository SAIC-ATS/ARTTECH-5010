# Basic C++
## Write, Compile, Run

To write, compile and run a basic C++ program you must complete the following steps:

1. _Write_ an empty file in a plain-text editor such as `nano` (on the command line) or [Atom](https://atom.io/). Example contents can be found in the examples in this directory. This text file is contains your _source code_. Simple source code files, such as those in this example, usually end with `.cpp`.
2. Open a Terminal and change directories to the location of your _source code_ file.
_Compile_ your _source code_ on the terminal using the following command:
```shell
g++ HelloWorld.cpp -o HelloWorld
```
3. Check for errors and _debug_ if you encounter errors. Debugging is the process of _reading_ the errors returned by the compiler and fixing the errors in your code before compiling again.
4. Once your _source code_ compiles with no errors, then you can run your executable program with the following command:
```shell
./HelloWorld
```
The `./` tells the terminal to run the program with the given name from the local directory.
