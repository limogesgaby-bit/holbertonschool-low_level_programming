#include "main.h"
#include <stdio.h>

int main(void)
{
    printf("%c: %d\n", (char)48, _isdigit(48));
    printf("%c: %d\n", (char)97, _isdigit(97));
    return (0);
}
