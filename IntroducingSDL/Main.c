#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
/*
  For visual studio if you want to avoid the console
  window showing up do the following:

  right click on properties on the project:
  1) Go to Linker > System > set subsystem to WINDOW
  2) Go to Linker > Advanced and set entry point to mainCRTStartup
*/
typedef struct
{
  int x, y;
  short life;
  char *name;
} Man;

int ProcessEvents(SDL_Window *window, Man *man)
{
  SDL_Event event;
  int done = 0;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_WINDOWEVENT_CLOSE:
      {
        if (window)
        {
          SDL_DestroyWindow(window);
          window = NULL;
          done = 1;
          break;
        }
      }
      break;
      case SDL_KEYDOWN:
      {
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            done = 1;
            break;
        }
      }
      break;
      case SDL_QUIT:
        //quit out of the game
        done = 1;
        break;
    }
  }

  //This also allows you move diagonally and make circular type motions if you switch holding up/right and left/down for example
  //Scan code is likely better for movement while SDLK is better for entering names etc - see https://stackoverflow.com/questions/31941446/what-is-the-difference-between-an-sdl-physical-key-code-and-an-sdl-virtual-key-c

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_LEFT])
  {
   man->x-=10;
  }
  if (state[SDL_SCANCODE_RIGHT])
  {
    man->x+=10;
  }
  if (state[SDL_SCANCODE_UP])
  {
    man->y-=10;
  }
  if (state[SDL_SCANCODE_DOWN])
  {
    man->y+=10;
  }
  return done;
}

void RenderWindow(SDL_Renderer *renderer, Man *man)
{

  //set the drawing color to blue
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

  //Clear the screen to blue
  SDL_RenderClear(renderer);

  //set the drawing color to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_Rect rect = { man->x, man->y, 200, 200 };
  SDL_RenderFillRect(renderer, &rect);

  //We are done drawing, "present" or show to the screen what we've drawn
  SDL_RenderPresent(renderer);
}


int main(int argc, char *args[])
{
  SDL_Window *window; //declare a window
  SDL_Renderer *renderer; //declare a renderer

  SDL_Init(SDL_INIT_VIDEO); //Initialize SDL2

  Man man;
  man.x = 220;
  man.y = 140;

  //Create an application window with settings
  window = SDL_CreateWindow("Game Window", //window title
                            SDL_WINDOWPOS_UNDEFINED,               //intial x pos
                            SDL_WINDOWPOS_UNDEFINED,               //intial y pos
                            640,                                   //width in pixels
                            480,                                  //height in pixels
                            0                                     //flags
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  //The window is open: enter program loop (see SDL_PollEvent)
  int done = 0;

  //Event loop
  while (!done)
  {
    //Check for events
    done = ProcessEvents(window, &man);
    //Render Display
    RenderWindow(renderer, &man);
    //don't burn up the CPU
    SDL_Delay(16.67);
  }

  //Close and destroy the window
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  //Clean up
  SDL_Quit();
  return 0;
}
