#include <core/emulator.h>

int main(int argc, char *argv[])
{
	platform::core::Emulator& emulator = platform::core::Emulator::Instance();

	emulator.Run();

	return 0;
}