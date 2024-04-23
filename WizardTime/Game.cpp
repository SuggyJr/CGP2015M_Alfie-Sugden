#include "Game.h"
#include "Tilemap.h"

Tilemap* map;

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
	// Initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed: " << SDL_GetError() << endl;
		return;
	}

	// Create window
	window = SDL_CreateWindow("WIZARD TIME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window)
	{
		cout << "Window creation failed: " << SDL_GetError() << endl;
		return;
	}

	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		cout << "Renderer creation failed: " << SDL_GetError() << endl;
		return;
	}

	// Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		cout << "SDL_ttf initialization failed: " << TTF_GetError() << endl;
		return;
	}

	// Initialize SDL_image
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "SDL_image initialization failed: " << IMG_GetError() << endl;
		return;
	}

	map->loadMap("Assets/TestMap.txt");

	isFullscreen = false;
	isRunning = true;

	loop();
}

void Game::loop()
{
	renderSplashScreen();

	SDL_Delay(5000);

	while (isRunning)
	{
		input();
		update();
		render();
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::input()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
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

void Game::renderSplashScreen()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Color textColour = { 255, 255, 255 };
	TTF_Font* font = TTF_OpenFont("Assets/ChrustyRock-ORLA.ttf", 50);
	if (!font)
	{
		cout << "Failed to load font!\n";
		return;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, "WIZARD TIME", textColour);
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

	SDL_Rect textRect = { (640 - surface->w) / 2, (480 - surface->h) / 2, surface->w, surface->h };
	SDL_RenderCopy(renderer, texture, NULL, &textRect);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);

	SDL_RenderPresent(renderer);
}