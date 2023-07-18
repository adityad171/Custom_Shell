# Linux Shell Implementation
The shell can handle the following commands:
1. cd : change directory
        ~ - change to home directory
        / - change to root directory

        Error - too many arguments
              - less than required arguments 
              - no such directory

2. pwd : show working directory
        -L - show environment variable
        -P - show working directory

        Error - too many arguments
              - wrong flag

3. echo : print to stdout
        -n - print without newline character
        -E - print without interpreting escape character

        Errors - too many arguments

4. ls : view files in directory 
        -a - print all files including hidden directories and files
        -A - print all files including hidden directories and files without . and ..

        Errors - too many arguments
               - wrong flag

5. rm : remove files
        -i : prompt before deleting
        -f : ignore if not present

        Errors - no file mentioned 
               - no such file

6. cat - view files
        -n : print with line numbers
        -s : skip repeated new lines

        Errors - no file mentioned
               - no such file

7. mkdir - create new directory
        -v : prompt after creating
        -p : create parent directory also

        Error - no file mentioned 
              - too many arguments

8. date - print date
        -u : print time in GMT
        -r file : print last modified time of file

        Errors - wrong flag
               - too many flags
