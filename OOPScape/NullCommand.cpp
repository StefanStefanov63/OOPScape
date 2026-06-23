#include "NullCommand.h"
void NullCommand::execute()
{
	setConsolColor(Color::Red);
	std::cout << "Incorect Input\n";
	setConsolColor(Color::None);
}
