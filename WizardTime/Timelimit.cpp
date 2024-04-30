#include "Timelimit.h"

Timelimit::Timelimit()
{
	this->startTicks = 0;
}

void Timelimit::resetTicks()
{
	startTicks = SDL_GetTicks();
}

int Timelimit::getTicks() const
{
	return (SDL_GetTicks() - startTicks);
}
