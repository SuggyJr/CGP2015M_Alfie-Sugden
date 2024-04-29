#include "Timelimit.h"

Timelimit::Timelimit()
{
	this->startTicks = 0;
}

void Timelimit::resetTicks()
{
	startTicks = SDL_GetTicks();
}

const int Timelimit::getTicks()
{
	return (SDL_GetTicks() - startTicks);
}
