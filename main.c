#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

//******************************************** Defines and Macros ****************************************************//
#define ERROR_CODE      (1)
#define WINDOW_WIDTH    (800)
#define WINDOW_HEIGHT   (600)
#define CONTAINER_SIZE  (1000)

//*********************************************** Declarations *******************************************************//
//Structs:
typedef struct coord Coord;
typedef struct button Button;
typedef struct toolbar Toolbar;
typedef struct container Container;
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
struct coord {
    int x;
    int y;
};

struct button {
    SDL_Rect shape;
    char* text;
};


struct toolbar {
    SDL_Rect shape;
    Button* buttons;
};

struct container {
    Coord shape[CONTAINER_SIZE];
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

void processMouseDown(int pos_x, int pos_y);
bool clickToolbar(int pos_x, int pos_y);
bool clickCanvas(int pos_x, int pos_y);
bool clickStartSim(int pos_x, int pos_y);

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
    int x,y;
    SDL_GetMouseState(&x, &y);
    switch (event.type) {
        case SDL_QUIT: {
            game_is_running = false;
        }
        case SDL_MOUSEBUTTONDOWN: {
            processMouseDown(x,y);
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


void processMouseDown(int x, int y) {
    clickToolbar(x, y);
    clickCanvas(x, y);
    clickStartSim(x, y);
}


bool clickToolbar(int x, int y) {
    return true;
}


bool clickCanvas(int x, int y) {
    return true;
}


bool clickStartSim(int x, int y) {
    return true;
}

//*************************************************** Main ***********************************************************//
int main(int argc, char* argv[]) {
    run();
    return 0;
}
