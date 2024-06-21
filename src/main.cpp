#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../../raygui.h"
#include <iostream>

const int screenHeight = 300;
const int screenWidth = 300;

char OutputChar[256] = "0";

int RangeMin = 0;
int RangeMax = 0;

char RangeMinText[10] = "0"; // Temporary storage for RangeMin
char RangeMaxText[10] = "0"; // Temporary storage for RangeMax

bool RangeMinClicked = false;
bool RangeMaxClicked = false;

void DrawGenerator();
void UpdateGenerator();

int main(){
    InitWindow(screenWidth, screenHeight, "little number generator");
    while(!WindowShouldClose()){
        UpdateGenerator();
        DrawGenerator();
    }
    CloseWindow();
    return 0;
}

void DrawGenerator()
{
    BeginDrawing();
        ClearBackground(WHITE);
        DrawText("MIN VALUE", 30, 184, 10, BLACK);
        DrawText("MAX VALUE", 170, 184, 10, BLACK);
        DrawText("OUTPUT", 100, 15, 10, BLACK);
    EndDrawing();
}

void UpdateGenerator()
{

    Rectangle RangeMinRec = {30, 200, 100, 30};
    Rectangle RangeMaxRec = {170, 200, 100, 30};

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        if(CheckCollisionPointRec(GetMousePosition(), RangeMinRec)) {
            RangeMinClicked = true;
            RangeMaxClicked = false;
        }

        if(CheckCollisionPointRec(GetMousePosition(), RangeMaxRec)) {
            RangeMaxClicked = true;
            RangeMinClicked = false;
        }
    }

    GuiTextBox(RangeMinRec, RangeMinText, 10, RangeMinClicked);
    
    GuiTextBox(RangeMaxRec, RangeMaxText, 10, RangeMaxClicked);

    RangeMin = atoi(RangeMinText);
    RangeMax = atoi(RangeMaxText);

    Rectangle OutputRec = {100, 30, 100, 30};
    GuiTextBox(OutputRec, OutputChar, 256, false);

    Rectangle GenerateRec = {100, 90, 100, 30};
    if(GuiButton(GenerateRec, "Generate")){
        if(RangeMin < RangeMax){
            sprintf(OutputChar, "%d", GetRandomValue(RangeMin, RangeMax));
        }
    }
}
