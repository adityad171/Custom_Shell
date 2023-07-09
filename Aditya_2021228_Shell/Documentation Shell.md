# Aditya_2021228_Shell

My shell can handle the following commands:
1. cd : change directory
        .. - previous directory
        "dir name" - enter the directory

        Error - less than required arguments (segmentation fault)
              - no such file or directory

2. pwd : show working directory
        -P - shows current/working directory

3. echo : print to stdout
        -n - print without newline character

4. ls : view files in directory
        -a - print all files including hidden directories and files
        -A - print all files including hidden directories and files without . and ..

        Errors - wrong flag

5. rm : removes files
        -i : prompt before deleting
        -f : ignore if file not present

        Errors - no file mentioned 
               - no such file

6. cat - view files
        -n : print with line numbers
        -s : skip repeated new lines

        Errors - no file mentioned
               - no such file exists

7. mkdir - create new directory
        -v : prompt after creating
        -p : create parent directory also

        Error - asks for directory name if no file mentioned

8. date - print date
        -u : print time in UTC
        -r file : print last modified time of file

        Errors - Illegal option (wrong flag)