#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 690;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
TTF_Font* font = NULL;
SDL_Texture* texture[100] = {NULL};

class init_close
{
    public:
    bool initSDL()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        window = SDL_CreateWindow("SUDOKU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL)
        {
            std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }
        if (TTF_Init() < 0)
        {
            std::cout << "SDL_ttf could not initialize! Error: " << TTF_GetError() << std::endl;
            SDL_Quit();
            return 1;
        }
        font = TTF_OpenFont("Lato-Heavy.ttf", 48);
        if (font == NULL)
        {
            std::cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
            return false;
        }
        return true;
    }
    void closeSDL()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};
