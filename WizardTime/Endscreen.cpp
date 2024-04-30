#include "Endscreen.h"

Endscreen::Endscreen(SDL_Renderer* renderer)
{
	if (!renderer)
	{
		cout << "Can't find renderer\n";
		return;
	}

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	UI* End = new UI("TIME UP!", 640, 480, TTF_OpenFont("Assets/Font.ttf", 60));
	UI* spareText = new UI("Thanks for playing", 640, 600, TTF_OpenFont("Assets/Font.ttf", 20));

	End->renderer(renderer);
	spareText->renderer(renderer);

	SDL_RenderPresent(renderer);
}
