#include "Color.h"
WORD toConsoleColor(Color color)
{
	switch (color)
	{
	case Color::Red:    return 12;
	case Color::Yellow: return 14;
	case Color::Green:  return 10;
	case Color::Blue:   return 9;
	case Color::White:  return 15;
	case Color::None:   return 7;
	}

	return 7;
}

void setConsolColor(Color color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, toConsoleColor(color));
}
