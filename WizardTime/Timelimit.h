#ifndef TIMELIMIT_H
#define TIMELIMIT_H

#include <iostream>
#include <SDL.h>

using namespace std;

class Timelimit
{
public:
	Timelimit();
	
	void resetTicks();
	int getTicks() const;

private:
	int startTicks;
};

#endif // !TIMELIMIT_H
