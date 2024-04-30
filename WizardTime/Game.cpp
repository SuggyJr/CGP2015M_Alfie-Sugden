#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
Gameworld* gW = new Gameworld();
UI* countdown;
SDL_Event event;

Game::Game()
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
	SDL_Delay(2000);
	SDL_RenderClear(renderer);

	gW->init(renderer);

	seconds = 0;
	time = 60;
	countdown = new UI("00:00", 96, 48, TTF_OpenFont("Assets/Font.ttf", 30));

	loop();
}

void Game::loop()
{
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
			//cout << seconds << "\n";
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
	SDL_Rect rect{};
	rect.x = rect.y = 0;
	rect.w = 640;
	rect.h = 480;
	SDL_RenderFillRect(renderer, &rect);

	gW->render(renderer);

	countdown->renderer(renderer);

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