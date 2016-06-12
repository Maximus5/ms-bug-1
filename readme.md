# Windows 10 console bug

Reported originally in Maximus5/ConEmu#718 for Windows 10 Insider build 14361.

## Description

The call of `SetConsoleScreenBufferSize`, increasing console buffer by one column introduces two bugs:

1. `GetConsoleCursorInfo` returns **zero** cursor height (even MSDN promises only values 1..100);
2. The cursor position unexpectedly jumps to unexpected position. Sometimes user may see **two** cursors: one non-blinking at the ‘correct’ position, and second blinking at wrong, but actual position.

Actually, you may even resize (increase console window width) by dragging window frame.
Regardless the fact the cursor is blinking in the console window, `GetConsoleCursorInfo` returns zero cursor height.

![Animated description](https://github.com/Maximus5/ms-bug-1/blob/master/inc-width2.gif)


