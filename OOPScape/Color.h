#pragma once
#include <windows.h>
enum class Color
{
	Red,
	Yellow,
	Green,
	Blue,
	None,
	White,
	LightRed
};

WORD toConsoleColor(Color color);
void setConsolColor(Color color);

