
#ifdef WIN32
# define DLL_EXPORT __declspec(dllexport)
#else
# define DLL_EXPORT
#endif

int DLL_EXPORT add(int, int);
int DLL_EXPORT sub(int, int);