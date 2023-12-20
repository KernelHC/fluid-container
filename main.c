#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//******************************************** Defines and Macros ****************************************************//
#define ERROR_CODE      (1)
#define WINDOW_WIDTH    (800)
#define WINDOW_HEIGHT   (600)

//*********************************************** Declarations *******************************************************//
//Global variables:
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event* event = NULL;
bool game_is_running = true;

//Structs:
typedef struct toolbar Toolbar;
typedef struct container Container;
typedef struct container_part ContainerPart;
typedef struct particle Particle;
typedef struct fluid Fluid;

//******************************************** Struct Definitions ****************************************************//
struct toolbar {

};

struct container {

};

struct container_part {

};

struct particle {

};

struct fluid {

};

//******************************************* Function Declarations **************************************************//
int run();
int setup();
int process_input();
int update();
int render();
void quit();

//******************************************* Function Definitions ***************************************************//
int run() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Failed to initialize SDL");
        exit(ERROR_CODE);
    }
    game_is_running = setup();
    while (game_is_running) {
        process_input();
        update();
        render();
    }
    quit();
}

int setup() {
    window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        fprintf(stderr, "Failed to create window");
        exit(ERROR_CODE);
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        exit(ERROR_CODE);
    }
    return true;
}

int process_input() {
    SDL_PollEvent(event);
}

int update() {

}

int render() {

}

void quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//*************************************************** Main ***********************************************************//
int main(int argc, char* argv[]) {
    run();
    return 0;
}
