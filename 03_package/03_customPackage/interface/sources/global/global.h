
#pragma once

#ifdef MyMath_STATIC

// 静态库
#   define MyMath_EXPORT

#else

# define MyMath_EXPORT __declspec(dllexport)

#endif