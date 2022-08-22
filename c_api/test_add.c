#include "cppwarrper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
int main(void)
{
    struct cppAdd * cppAdd;
    cppAdd = GetInstance();
    float result = Sum(cppAdd,2.f,3.2f);

    printf("2 + 3.2 = %f\n", result);
    ReleaseInstance(&cppAdd);
    return 0;
}