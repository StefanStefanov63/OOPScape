#include "NullCommand.h"
bool NullCommand::execute()
{
	setConsolColor(Color::Red);
	std::cout << "Incorect Input\n";
	setConsolColor(Color::None);
	return false;
}
