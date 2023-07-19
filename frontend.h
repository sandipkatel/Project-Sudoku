#pragma once 

#include "initClose.h"

class Texture
{
    public:
        Texture(){}
        void loadTexture(SDL_Texture*&, const char*, SDL_Color&);
        void preloadTextures();
        void displayTexture(SDL_Texture*&, int, int, int, int);
        void RightBar();
};

class frontend
{ 
    public:
    Texture Text;
    void drawFrame()
    {
        // Clear the renderer with white color
        SDL_SetRenderDrawColor(renderer, 153, 209, 213, 255);
        SDL_RenderClear(renderer);

        
        int RGB[][3] = {{123, 180, 0},{228, 255, 0}, {255, 240, 0}, {255, 133, 0}, {255, 38, 0}, {51, 172, 221},{0, 182, 114}};
        int a=0;

        int initialx = 30;
        int initialy = 8;
        int length = 75;

        //draw background of sudoku board  white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect rect = { initialx-2, initialy-2, length * 9, length * 9 };
        SDL_RenderFillRect(renderer, &rect);

        //draw frame for rectangle above
        for(int i = 0;i<9;i++)
        {   
            for(int j = 0; j<9; j++)
                {
                    a = (i+j)%7;
                    SDL_SetRenderDrawColor(renderer, RGB[a][0], RGB[a][1], RGB[a][2], 128);
                    SDL_Rect borderRect1 = { initialx + 2, initialy + 2, length-4, length-4};
                    SDL_RenderFillRect(renderer, &borderRect1);
                    initialx+=length;
                }
            initialx=30;
            initialy+=length;
        }

        //Draw a thick border 
        initialx = 30;
        initialy =8;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        for(int i= 0; i<5;i++)
        {
            SDL_Rect rect = { initialx+i-2, initialy+i-2, length * 9, length * 9 };
            SDL_RenderDrawRect(renderer, &rect);
            //these are all ziczac verticle lines
            SDL_RenderDrawLine(renderer, initialx + length*3+i-2, initialy, initialx +length*3+i-2,initialy + length*2);
            SDL_RenderDrawLine(renderer, initialx + length*4+i-2, initialy, initialx +length*4+i-2,initialy + length*1);
            SDL_RenderDrawLine(renderer, initialx + length*6+i-2, initialy + length*1, initialx +length*6+i-2,initialy + length*2);
            SDL_RenderDrawLine(renderer, initialx + length*1+i-2, initialy + length*2, initialx +length*1+i-2,initialy + length*3);
            SDL_RenderDrawLine(renderer, initialx + length*5+i-2, initialy + length*2, initialx +length*5+i-2,initialy + length*3);
            SDL_RenderDrawLine(renderer, initialx + length*8+i-2, initialy + length*2, initialx +length*8+i-2,initialy + length*3);
            SDL_RenderDrawLine(renderer, initialx + length*2+i-2, initialy + length*3, initialx +length*2+i-2,initialy + length*4);
            SDL_RenderDrawLine(renderer, initialx + length*3+i-2, initialy + length*3, initialx +length*3+i-2,initialy + length*4);
            SDL_RenderDrawLine(renderer, initialx + length*7+i-2, initialy + length*3, initialx +length*7+i-2,initialy + length*4);
            SDL_RenderDrawLine(renderer, initialx + length*4+i-2, initialy + length*4, initialx +length*4+i-2,initialy + length*5);
            SDL_RenderDrawLine(renderer, initialx + length*5+i-2, initialy + length*4, initialx +length*5+i-2,initialy + length*5);
            SDL_RenderDrawLine(renderer, initialx + length*2+i-2, initialy + length*5, initialx +length*2+i-2,initialy + length*6);  
            SDL_RenderDrawLine(renderer, initialx + length*6+i-2, initialy + length*5, initialx +length*6+i-2,initialy + length*6);
            SDL_RenderDrawLine(renderer, initialx + length*7+i-2, initialy + length*5, initialx +length*7+i-2,initialy + length*6);
            SDL_RenderDrawLine(renderer, initialx + length*1+i-2, initialy + length*6, initialx +length*1+i-2,initialy + length*7);  
            SDL_RenderDrawLine(renderer, initialx + length*4+i-2, initialy + length*6, initialx +length*4+i-2,initialy + length*7); 
            SDL_RenderDrawLine(renderer, initialx + length*8+i-2, initialy + length*6, initialx +length*8+i-2,initialy + length*7);
            SDL_RenderDrawLine(renderer, initialx + length*3+i-2, initialy + length*7, initialx +length*3+i-2,initialy + length*8);
            SDL_RenderDrawLine(renderer, initialx + length*6+i-2, initialy + length*7, initialx +length*6+i-2,initialy + length*9);
            SDL_RenderDrawLine(renderer, initialx + length*5+i-2, initialy + length*8, initialx +length*5+i-2,initialy + length*9);
            //these are all ziczac horizontal lines
            SDL_RenderDrawLine(renderer, initialx + length*4, initialy + length*1+i-2, initialx +length*6,initialy + length*1+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*1, initialy + length*2+i-2, initialx +length*5,initialy + length*2+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*6, initialy + length*2+i-2, initialx +length*8,initialy + length*2+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*1, initialy + length*3+i-2, initialx +length*2,initialy + length*3+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*3, initialy + length*3+i-2, initialx +length*7,initialy + length*3+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*8, initialy + length*3+i-2, initialx +length*9,initialy + length*3+i-2);
            SDL_RenderDrawLine(renderer, initialx, initialy + length*4+i-2, initialx +length*2,initialy + length*4+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*3, initialy + length*4+i-2, initialx +length*4,initialy + length*4+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*5, initialy + length*4+i-2, initialx +length*9,initialy + length*4+i-2);
            SDL_RenderDrawLine(renderer, initialx, initialy + length*5+i-2, initialx +length*4,initialy + length*5+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*5, initialy + length*5+i-2, initialx +length*6,initialy + length*5+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*7, initialy + length*5+i-2, initialx +length*9,initialy + length*5+i-2);
            SDL_RenderDrawLine(renderer, initialx, initialy + length*6+i-2, initialx +length*1,initialy + length*6+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*2, initialy + length*6+i-2, initialx +length*6,initialy + length*6+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*7, initialy + length*6+i-2, initialx +length*8,initialy + length*6+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*1, initialy + length*7+i-2, initialx +length*3,initialy + length*7+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*4, initialy + length*7+i-2, initialx +length*8,initialy + length*7+i-2);
            SDL_RenderDrawLine(renderer, initialx + length*3, initialy + length*8+i-2, initialx +length*5,initialy + length*8+i-2);
        }
        /*
        
        //Draw a verticle lines for sudoku cell
        for(int i= 0; i<8;i++)
        {   
            initialx +=length;
            SDL_RenderDrawLine(renderer, initialx, initialy, initialx, initialy +length*9);
        }
        initialx = 30;
        //Draw horizontal lines
        for(int i= 0; i<8;i++)
        {   
            initialy +=length;
            SDL_RenderDrawLine(renderer, initialx, initialy, initialx + length*9, initialy);
        }
        */

        //Draw thick verticle line to seperate
        initialx=initialx+length*10;
        initialy = 15;
        for(int i= 0; i<8;i++)
        { 
            initialx+=1;
            SDL_RenderDrawLine(renderer, initialx, initialy, initialx, length*9);
        }

        Text.RightBar();
        // Render the changes
        SDL_RenderPresent(renderer);
    }
};



void Texture::loadTexture(SDL_Texture*& texture, const char* text, SDL_Color& fontColour)
{
    // Create text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, fontColour);
    // Create texture from surface pixels
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
}
void Texture::preloadTextures()
{
    // Choose colour of font to black
    SDL_Color fontColour = { 0, 0, 0, SDL_ALPHA_OPAQUE };

    loadTexture(texture[0], " ", fontColour);
    char temp[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 1; i < 10; i++)
    {   
        char tmp[2] = {temp[i-1], '\0'};
        loadTexture(texture[i],tmp, fontColour);
    }
    loadTexture(texture[10], "SUDOKU", fontColour);
    loadTexture(texture[11], "username : ............", fontColour);
    loadTexture(texture[12], "Time Elapshed 00:01:59", fontColour);
    loadTexture(texture[13], "Best Score 00:22:22", fontColour);
    loadTexture(texture[14], "By : hemprashad", fontColour);
    loadTexture(texture[15], "Exit", fontColour);
    loadTexture(texture[16], "Hint", fontColour);
}

void Texture::displayTexture(SDL_Texture*& texture, int x, int y, int textureWidth, int  textureHeight)
{
    SDL_Rect destRect1 = { x, y, textureWidth, textureHeight};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect1);
}

void Texture:: RightBar()
{
    int length = 75;
    int thick_line_x = 10 + 75*10;
    int textureWidth = 0, textureHeight = 0;
    preloadTextures();
    //Disply Sudoku
    SDL_QueryTexture(texture[10], nullptr, nullptr, &textureWidth, &textureHeight);
    int x = thick_line_x + (SCREEN_WIDTH - thick_line_x-textureWidth)/2;
    int y = 10;
    displayTexture(texture[10], x, y, textureWidth, textureHeight);

    x += textureWidth + length;
    y = 15;
    SDL_Rect Rect = { x, y, 50, 20 };
    SDL_RenderDrawRect(renderer, &Rect);
    SDL_QueryTexture(texture[15], nullptr, nullptr, &textureWidth, &textureHeight);
    textureWidth/=2.5;
    textureHeight/=2.5;
    displayTexture(texture[15], x+(50-textureWidth)/2, y + (20-textureHeight)/2, textureWidth, textureHeight);

    //Display User name

    x = thick_line_x + length;
    y =10 + length;
    SDL_QueryTexture(texture[11], nullptr, nullptr, &textureWidth, &textureHeight);
    displayTexture(texture[11], x, y, textureWidth/1.5, textureHeight/1.5);

    //Display time elapshed
    x = thick_line_x + length;
    y += length/2;
    SDL_QueryTexture(texture[12], nullptr, nullptr, &textureWidth, &textureHeight);
    displayTexture(texture[12], x, y, textureWidth/1.5, textureHeight/1.5);

    //display best score
    x = thick_line_x + length*3;
    y += length/2;
    SDL_QueryTexture(texture[13], nullptr, nullptr, &textureWidth, &textureHeight);
    displayTexture(texture[13], x, y, textureWidth/2, textureHeight/2);

    //display the high scorer
    x = thick_line_x + length*5;
    y += length/2.5;
    SDL_QueryTexture(texture[14], nullptr, nullptr, &textureWidth, &textureHeight);
    displayTexture(texture[14], x, y, textureWidth/2.5, textureHeight/2.4);


    for(int i = 0; i<3; i++)
    {
        SDL_Rect Rect = { thick_line_x + length * 3 -1 +i, int(y+ length/1.5-1 +i), int(length*1.5), int(length/1.25) };
        SDL_RenderDrawRect(renderer, &Rect);
    }

    x = thick_line_x + length * 3 + 10;
    y += length/1.5;
    SDL_QueryTexture(texture[16], nullptr, nullptr, &textureWidth, &textureHeight);
    displayTexture(texture[16], x, y, textureWidth, textureHeight);

    int initx = length * 12;
    int inity = 350;
    int height = length * 4/3;

    SDL_QueryTexture(texture[0], nullptr, nullptr, &textureWidth, &textureHeight);
    textureWidth*=2;
    textureHeight*=2;
    int k = 1;
    for(int i = 0; i <3;i++)
    {
        for(int j = 0; j<3; j++)
        {   
            x = initx + (height - textureWidth)/2;
            y = inity + (height - textureHeight)/2;
            SDL_Rect Rect = { initx, inity, height, height };
            SDL_RenderDrawRect(renderer, &Rect);
            displayTexture(texture[k], x, y, textureWidth, textureHeight);
            initx +=height;
            k++;
        }
        initx = 12 *length;
        inity +=height;
    }
    SDL_RenderPresent(renderer);
}