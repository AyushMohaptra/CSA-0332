#include <stdio.h>

void check(const char *str) {
    if (str && str[0] != '\0') {
        printf("Valid string \n");
    } else {
        printf("Invalid string.\n");
    }
}

int main() {
    const char *str1 = "Hello";
    const char *str2 = "";
    const char *str3 = NULL;

    check(str1);
    check(str2);
    check(str3);

    return 0;
}
