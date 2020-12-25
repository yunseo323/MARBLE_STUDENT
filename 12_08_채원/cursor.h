#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

COORD GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
void CursorView(char show);
void RemoveCursor(void);
