#include <iostream>


const int MAX_LINE_LENGTH = 1024;
const char* COMMENT_SLINE = "//";
const char* COMMENT_MLINE = "/*";
const int COMMENT_MARKER_LENGTH = 2;


char* trim_leading(char* str)
{
    if (!str) return 0;

    char* ptr = str;

    while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
        ptr++;
    }
    return ptr;
}


int custom_strncmp(const char* s1, const char* s2, int n)
{
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }

        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}


int custom_strcmp(const char* s1, const char* s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}



void detect_comments()
{


    std::cout << "--- C++ (Minimal Library) Comment Detector ---" << std::endl;
    std::cout << "Enter a line to check (e.g., // my comment, or /* block), or 'exit' to quit." << std::endl;


    char input_line[MAX_LINE_LENGTH];


    while (true)
    {

        std::cout << "INPUT>> ";


        std::cin.getline(input_line, MAX_LINE_LENGTH);


        if (std::cin.fail() && !std::cin.eof())
        {
            std::cin.clear();
            std::cin.ignore(MAX_LINE_LENGTH, '\n');
            std::cout << "Input too long or error. Please try again." << std::endl;
            continue;
        }


        if (custom_strcmp(input_line, "exit") == 0) {
            break;
        }


        char* trimmed_ptr = trim_leading(input_line);


        if (*trimmed_ptr == '\0') {
            continue;
        }


        if (custom_strncmp(trimmed_ptr, COMMENT_SLINE, COMMENT_MARKER_LENGTH) == 0) {
            std::cout << "--> [DETECTED] Single-line Comment (//)!" << std::endl;
        }

        else if (custom_strncmp(trimmed_ptr, COMMENT_MLINE, COMMENT_MARKER_LENGTH) == 0) {
            std::cout << "--> [DETECTED] Multi-line Comment Start (/*) or complete single-line block!" << std::endl;
        }

        else {
            std::cout << "--> [NOT A COMMENT] This line appears to be executable code or text." << std::endl;
        }
    }
    std::cout << "\nProgram terminated." << std::endl;
}


int main() {
    detect_comments();

    return 0;
}
