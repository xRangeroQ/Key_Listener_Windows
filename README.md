# ⌨️ Windows Low-Level Keyboard Hook (C language)

A simple C application that demonstrates how to intercept and log system-wide keyboard events using the **Windows API**.

## 📝 Description
This program uses a **Low-Level Keyboard Hook** (`WH_KEYBOARD_LL`) to monitor keyboard input globally across the Windows operating system. Unlike standard input methods, this hook captures key presses even when the console window is not in focus. 🎯

## ✨ Features
* 🔍 **System-wide capture:** Tracks key down events (`WM_KEYDOWN` and `WM_SYSKEYDOWN`).
* 🔢 **Virtual-Key Codes:** Displays the unique `vkCode` for every key pressed.
* 🔄 **Active Monitoring:** Uses a Windows Message Loop to keep the hook alive and responsive.

## ⚙️ How It Works
1. **SetWindowsHookEx** ⚓: Registers a callback function into the Windows hook chain.
2. **KeyboardHandler** 📞: A callback function that triggers every time a key is pressed. It extracts the `vkCode` from the `KBDLLHOOKSTRUCT`.
3. **Message Loop** 🔄: A `while` loop using `GetMessage` keeps the application running and processing system signals.
4. **UnhookWindowsHookEx** 🔌: Properly releases the hook resource before the application terminates (essential for system stability).

## ⚠️ Disclaimer
This project is for educational purposes only. 🛑 Unauthorized use of keyboard hooking (keylogging) on systems you do not own or have explicit permission for is illegal and unethical. Use responsibly!
