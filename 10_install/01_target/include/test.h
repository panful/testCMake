
#ifdef WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

class DLL_EXPORT Test
{
public:
    void Func() const;
};