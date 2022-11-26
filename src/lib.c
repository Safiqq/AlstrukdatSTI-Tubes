#include "lib.h"

int stringLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

boolean isEqualStr(char *str1, char *str2)
{
    int i = 0;
    boolean checker = (stringLength(str1) == stringLength(str2));
    while (str1[i] != '\0' && str2[i] != '\0' && checker)
    {
        if (str1[i] != str2[i])
            checker = false;
        i++;
    }
    return checker;
}