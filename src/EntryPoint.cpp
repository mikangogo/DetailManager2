static void OnLibraryLoad(void* optionalArgument)
{
    
}

static void OnLibraryDispose()
{
    
}

#if defined(_MSC_VER)
#include <windows.h>

BOOL WINAPI DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD     fdwReason,
    _In_ LPVOID    lpvReserved
)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        OnLibraryLoad(hinstDLL);
        break;
    case DLL_PROCESS_DETACH:
        OnLibraryDispose();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
}
#else
void __attribute__((constructor)) lib_entry()
{
    OnLibraryLoad(0);
}
void __attribute__((destructor)) lib_exit()
{
    OnLibraryDispose();
}
#endif
