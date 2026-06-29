#include <stdio.h>
#include <stdlib.h>

void sec_15_1();
void sec_15_2();


int main(int argc, char *argv[]) {
  printf("Chapter 15: Writing Large Programs\n"
         "----------------------------------\n\n");

  sec_15_1();
  sec_15_2();
  return EXIT_SUCCESS;
}

void sec_15_1(){
    char *note = 
        "  Programs are commonly made of many files. Source files (usually \n"
        "end in .c) that contain code, function defs, variables, etc, and \n" 
        "Header files (usually end in .h) that contain constant \n" 
        "definitions, function prototypes, and other shared information.\n\n"

        "  For the RPN calculator example, you might put all parsing functions \n"
        "in `token.c` and stack-related functions like `push()`, `pop()`, \n"
        "`is_empty()` in a different file called `stack.c`. The `main()` function\n"
        "would go into another file, `calc.c`\n\n"

        "Some Advantages:\n"
        "----------------\n"
        " * Grouping related functions and variables to clarify program structure\n"
        " * {Each source file can compile separately which might save time in large \n"
        "   programs\n"
        " * Functions are more easily reused in other programs when grouped in\n"
        "   separate source files.\n";

    printf("%s", note);
}

void sec_15_2(){
    char *note = 
        "  With many source files, how can a function in one file call a \n"
        "function in another file? How can it access an external variable?\n"
        "The answer is with #include.\n\n"

        "  The #include directive tells the preprocessor to open a file and\n"
        "insert its contents into the current file. We use #include in two \n"
        "forms:\n"
        "  #include <filename> // for headers that belong to C's libraries\n"
        "  #include \"filename\" // for all other header files, including \n"
        "                           ones we write.\n\n"

        "Header Locations:\n"
        "-----------------\n"
        " * <filename> searches the system header folders, commonly in /usr/include\n"
        "              on UNIX systems\n"
        " * \"filename\" searches the current directory, then the system header\n" 
        "              folders.\n"
        "Header paths can be added by a command line option like -Ipath\n"

        "Conditional Includes:\n"
        "---------------------\n\n"
        "#if defined(APPLE_SILICON)\n"
        "   #define CPU_FILE \"arm64i.h\"\n"
        "#endif\n"
        "\n"
        "#include CPU_FILE\n";

    printf("\n\n%s", note);
}
