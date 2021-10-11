#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

bool initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Error initializing SDL2: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		SDL_version version;
		SDL_VERSION(&version);
		std::cout << "SDL " << (int32_t)version.major << "." << (int32_t)version.minor << "." << (int32_t)version.patch << std::endl;
	}
	return true;
}

void shutdown()
{
	SDL_Quit();
}

int main()
{
	std::cout << "Hello world, GioBoyAdvance!" << std::endl;

#ifdef GIO_PLATFORM_WINDOWS
	std::cout << "Platform: Windows" << std::endl;
#endif

	initialize();
	shutdown();

	std::cout << "Press any key to continue...";
	std::cin.ignore();

	return 0;
}