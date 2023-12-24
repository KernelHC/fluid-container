#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>

//******************************************** Defines and Macros ****************************************************//
#define ERROR_CODE      (1)
#define WINDOW_WIDTH    (800)
#define WINDOW_HEIGHT   (600)

//*********************************************** Declarations *******************************************************//
//Structs:
typedef struct button Button;
typedef struct toolbar Toolbar;
typedef struct container Container;
typedef struct container_part ContainerPart;
typedef struct particle Particle;
typedef struct fluid Fluid;
typedef struct pen Pen;

//Global variables:
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool game_is_running = true;
Toolbar* toolbar;
Container* container;

//******************************************** Struct Definitions ****************************************************//
struct button {
    SDL_Rect shape;
    char* text;
};

struct toolbar {
    SDL_Rect shape;
    Button* buttons;
};

struct container {

};

struct container_part {

};

struct particle {

};

struct fluid {

};

struct pen {

};

//******************************************* Function Declarations **************************************************//
int run();
int setup();
int process_input();
int update();
int render();
void quit();

void drawToolbar();
void drawButtons();
void drawContainer();
void drawFluid();

void updateFluid();

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
            "Fluid Container",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_OPENGL
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
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: {
            game_is_running = false;
        }
        case SDL_MOUSEBUTTONDOWN: {

            break;
        }
        default: {
            break;
        }
    }
}

int update() {
    updateFluid();
}

int render() {
    SDL_RenderClear(renderer);
    drawToolbar();
    drawButtons();
    drawContainer();
    drawFluid();
}

void quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void drawToolbar() {

}


void drawButtons() {

}


void drawContainer() {

}


void drawFluid() {

}


void updateFluid() {

}

//*************************************************** Main ***********************************************************//
int main(int argc, char* argv[]) {
    run();
    return 0;
}
