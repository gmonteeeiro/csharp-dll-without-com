#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){

    typedef void (*alloc)();
    typedef void (*free)();
    typedef TCHAR* (*getMsg)();

    HINSTANCE hDLL = LoadLibrary("csharp-dll-without-com.dll");
    if (hDLL != NULL)
    {
        ((alloc)GetProcAddress(hDLL, "alloc"))();

        auto obj = (getMsg) GetProcAddress(hDLL, "getMsg");
        if(obj){
            TCHAR* teste = obj();
        }

        ((free)GetProcAddress(hDLL, "free"))();
        FreeLibrary(hDLL);

    }   

    return 0;
}