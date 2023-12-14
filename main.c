#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//******************************************** Defines and Macros ****************************************************//

//*********************************************** Declarations *******************************************************//
//Global variables:
bool game_not_closed = true;

//

//******************************************** Struct Definitions ****************************************************//


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
