#include <stdio.h>
#include <limits.h>


int main()
{
        int a = INT_MAX;
        float b = __FLT_MAX__;
        double c = __DBL_MAX__;

        printf("max int: %d\nthe size: %lu\n\n", a, sizeof(a));
        printf("max float: %f\nthe size: %lu\n\n", b, sizeof(b));
        printf("max double: %f\nthe size: %lu\n\n", c, sizeof(c));

        return 0;
}
