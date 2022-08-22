#ifndef _APPLE_WRAPPER_H__
#define _APPLE_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct cppAdd; // Warning: 不能使用 extern 修饰

extern struct cppAdd *GetInstance(void);
extern void ReleaseInstance(struct cppAdd **ppInstance);
extern float Sum(struct cppAdd *pADD, float a, float b);

#ifdef __cplusplus
};
#endif

#endif