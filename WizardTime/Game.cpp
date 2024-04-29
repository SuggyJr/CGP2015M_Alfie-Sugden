#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;
Gameworld* gW = new Gameworld();

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

	loop();
}

void Game::loop()
{
	const int  fps = 24;
	const int frameDelay = 1000 / fps;

	SDL_Delay(5000);

	while (isRunning)
	{
		Startframe = SDL_GetTicks();
		input();
		update();
		render();
		frameTime = SDL_GetTicks() - Startframe;
		fpsCount = 1000 / (SDL_GetTicks() - Startframe);
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
}

void Game::update()
{
	gW->update();
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

	gW->render(renderer);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);

	SDL_RenderPresent(renderer);
}

void Game::input()
{
	while (SDL_PollEvent(&event))
	{
		gW->input(Game::event);

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