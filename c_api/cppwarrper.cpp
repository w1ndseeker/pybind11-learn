#include "cppwarrper.h"
#include "cppadd.h"
 
#ifdef __cplusplus
extern "C" {
#endif

struct cppAdd
{
    ws::cppadd cppadd;
};

struct cppAdd *GetInstance(void)
{
    return new struct cppAdd;
}

void ReleaseInstance(struct cppAdd **ppInstance)
{
    delete *ppInstance;
    *ppInstance = 0;
}

float Sum(struct cppAdd *pADD, float a, float b)
{
    return pADD->cppadd.sum(a,b);
}

#ifdef __cplusplus
};
#endif