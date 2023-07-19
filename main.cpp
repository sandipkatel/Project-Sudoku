//g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
#include <iostream>
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_ttf.h"

#include "frontend.h"


int main(int argc, char* args[])
{
    init_close ic;
    frontend fe;
    if (!ic.initSDL())
    {
        return 1;
    }

    fe.drawFrame();

    bool quit = false;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    ic.closeSDL();
    return 0;
}
