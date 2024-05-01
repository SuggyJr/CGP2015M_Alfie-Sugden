#include "Splashscreen.h"

Splashscreen::Splashscreen(SDL_Renderer* renderer)
{
	if (!renderer)
	{
		cout << "Can't find renderer\n";
		return;
	}

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	UI* Title = new UI("WIZARD TIME", 640, 480, TTF_OpenFont("Assets/Font.ttf", 60));
	UI* InstructionMOVE = new UI("WASD: TO MOVE", 640, 600, TTF_OpenFont("Assets/Font.ttf", 20));
	UI* InstructionSPACE = new UI("SPACE: MAGIC", 640, 650, TTF_OpenFont("Assets/Font.ttf", 20));

	Title->renderer(renderer);
	InstructionMOVE->renderer(renderer);
	InstructionSPACE->renderer(renderer);

	SDL_RenderPresent(renderer);
}
