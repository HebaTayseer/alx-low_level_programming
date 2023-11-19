#include "main.h"

int main(void) {
    const char *message = "\"At the end of the day, my goal was to be the best hacker\"\n\t- Kevin Mitnick";
    
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        _putchar(message[i]);
    }

    return (0);
}

