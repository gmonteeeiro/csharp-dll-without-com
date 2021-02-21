#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void SumTwoNumbers(HINSTANCE hDLL){
    typedef void (*AllocTwoNumbers)(int number1, int number2);
    typedef void (*GetSum)(int *result);

    ((AllocTwoNumbers)GetProcAddress(hDLL, "AllocTwoNumbers"))(14, 7);

    int result;
    ((GetSum)GetProcAddress(hDLL, "GetSum"))(&result);

    printf("%d", result);
}

void SendAndReturnString(HINSTANCE hDLL, char* string){
    typedef void (*AllocText)(char *string);
    typedef void (*GetText)(char **string);

    ((AllocText)GetProcAddress(hDLL, "AllocText"))(string);

    char* stringReturn;
    ((GetText)GetProcAddress(hDLL, "GetText"))(&stringReturn);

    printf("%s", stringReturn);
}

void GetCSharpString(HINSTANCE hDLL){
    typedef void (*GetString)(char **string);

    char* stringReturn;
    ((GetString)GetProcAddress(hDLL, "GetString"))(&stringReturn);

    printf("%s", stringReturn);
}

void ShowError(HINSTANCE hDLL, char* error){
    typedef void (*ShowError)(char *string);
    ((ShowError)GetProcAddress(hDLL, "ShowError"))(error);
}

int main(){
    HINSTANCE hDLL = LoadLibrary("csharp-dll-without-com.dll");

    if (hDLL != NULL)
    {
        // SumTwoNumbers(hDLL);
        // SendAndReturnString(hDLL, "Texto enviado pelo C");
        GetCSharpString(hDLL);
        // ShowError(hDLL, "Teste de erro");

        FreeLibrary(hDLL);
    }   

    return 0;
}
