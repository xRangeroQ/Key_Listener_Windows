// Include Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Keyboard Handler Function
LRESULT CALLBACK KeyboardHandler(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT *Information = (KBDLLHOOKSTRUCT*)lParam;
        printf("Key Pressed Code: %d\n", Information->vkCode);
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Main Function
int main(int argc, char* argv[])
{
    HHOOK KeyboardHandlerHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHandler, NULL, 0);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(KeyboardHandlerHook);
    return 0;
}
