#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
Gameworld* gW = new Gameworld();
UI* countdown;
SDL_Event event;

Game::Game() : fpsCount(0)
{
	init();
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed: " << SDL_GetError() << endl;
		return;
	}

	window = SDL_CreateWindow("WIZARD TIME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window)
	{
		cout << "Window creation failed: " << SDL_GetError() << endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		cout << "Renderer creation failed: " << SDL_GetError() << endl;
		return;
	}

	if (TTF_Init() == -1)
	{
		cout << "SDL_ttf initialization failed: " << TTF_GetError() << endl;
		return;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "SDL_image initialization failed: " << IMG_GetError() << endl;
		return;
	}

	isFullscreen = false;
	isRunning = true;

	Splashscreen ss(renderer);
	gW->init(renderer);

	seconds = 60;
	time = 60;
	countdown = new UI("00:00", 640, 480, TTF_OpenFont("Assets/Font.ttf", 100));

	loop();
}

void Game::loop()
{
	SDL_Delay(2000);

	while (isRunning)
	{
		timelimit.resetTicks();
		
		input();
		update();
		render();
		
		if (timelimit.getTicks() < D_TIME)
		{
			SDL_Delay(D_TIME - timelimit.getTicks());
			seconds--;
			cout << seconds << "\n";
			if (seconds <= 0)
			{
				time--;
				seconds = 60;
			}
		}
	}
	return;
}

void Game::update()
{
	gW->update();
	string timeStr = "00:" + to_string(time);
	const char* timeChar = timeStr.c_str();
	countdown->update(timeChar);
	//cout << time << "\n";
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Color textColor = { 255, 255, 255 };
	TTF_Font* font = TTF_OpenFont("Assets/Font.ttf", 10);
	if (!font)
	{
		cout << "Failed to load font!\n";
		return;
	}

	gW->render(renderer);

	string fpsText = "FPS: " + to_string(fpsCount);
	SDL_Surface* surface = TTF_RenderText_Solid(font, fpsText.c_str(), textColor);
	if (!surface)
	{
		cout << "Failed to create surface!\n" << SDL_GetError() << "\n";
		TTF_CloseFont(font);
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (!texture)
	{
		cout << "Failed to create texture!\n";
		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		return;
	}

	SDL_Rect textRect = { 10, 10, surface->w, surface->h }; 
	SDL_RenderCopy(renderer, texture, NULL, &textRect);

	countdown->renderer(renderer);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);

	SDL_RenderPresent(renderer);
}

void Game::input()
{
	while (SDL_PollEvent(&event))
	{
		gW->input(event);

		if (event.type == SDL_QUIT)
		{
			isRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
		}
	}
}