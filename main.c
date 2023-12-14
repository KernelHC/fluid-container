#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//******************************************** Defines and Macros ****************************************************//

//*********************************************** Declarations *******************************************************//
//Global variables:
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event* event;
bool game_not_closed = true;

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
void run();
void setup();
void process_input();
void update();
void render();

//******************************************* Function Definitions ***************************************************//
void run() {
    SDL_Init(SDL_INIT_EVERYTHING);
    setup();
    while (game_not_closed) {
        process_input();
        update();
        render();
    }
    SDL_Quit();
}

void setup() {

}

void process_input() {

}

void update() {

}

void render() {

}

//*************************************************** Main ***********************************************************//
int main(int argc, char* argv[]) {
    run();
    return 0;
}
