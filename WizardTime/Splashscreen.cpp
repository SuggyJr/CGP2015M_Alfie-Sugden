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
	UI* Inst1 = new UI("W: UP", 640, 600, TTF_OpenFont("Assets/Font.ttf", 20));
	UI* Inst2 = new UI("A: LEFT", 640, 650, TTF_OpenFont("Assets/Font.ttf", 20));
	UI* Inst3 = new UI("D: RIGHT", 640, 700, TTF_OpenFont("Assets/Font.ttf", 20));
	UI* Inst4 = new UI("SPACE: MAGIC", 640, 750, TTF_OpenFont("Assets/Font.ttf", 20));

	Title->renderer(renderer);
	Inst1->renderer(renderer);
	Inst2->renderer(renderer);
	Inst3->renderer(renderer);
	Inst4->renderer(renderer);

	SDL_RenderPresent(renderer);
}
