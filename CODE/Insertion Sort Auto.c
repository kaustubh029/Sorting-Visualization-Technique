#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int position[] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900};
int height[19], i, j, key;
double time, ltime;
double speed = 0.100000;

static int init();
static int sort();
static int end();
static int cluch();

int main()
{
    InitWindow(950, 950, "Insertion__Sort__");
    SetWindowState(FLAG_VSYNC_HINT);                       // VSYNC syncs refresh rate and frame rate(fps)
    init();
    sort();
    end();
    CloseWindow();
    return 0;
}

int init()
{

    for (int i = 0; i < 19; i++)
        height[i] = (rand() % 890) + 20;

    while (!IsKeyDown(KEY_ENTER))
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 19; i++)
            DrawRectangle(position[i], 950 - height[i], 50, height[i], BLACK);

        EndDrawing();
        if (WindowShouldClose())
            exit(0);
    }
    return 0;
}

int sort()
{
    for (i = 1; i < 19; i++)
    {
        key = height[i];
        j = i - 1;

        while (j >= 0 && height[j] > key)
        {
            if (j == i - 1) // remove card
            {
                cluch();
                height[j + 1] = 0;
            }
            cluch();
            height[j + 1] = height[j]; // slide card
            height[j] = 0;
            j = j - 1;
        }
        cluch();
        height[j + 1] = key; // insert card
        cluch();
    }
    return 0;
}

int cluch()
{
    ltime = GetTime();
    while (time <= ltime + speed)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText(TextFormat("SPEED : %f", speed), 10, 10, 20, BLACK);
        for (int k = 0; k < 19; k++)
            if (k == j + 1)
                DrawRectangle(position[k], 950 - height[k], 50, height[k], RED);
            else if (k < i + 1)
                DrawRectangle(position[k], 950 - height[k], 50, height[k], SKYBLUE);
            else
                DrawRectangle(position[k], 950 - height[k], 50, height[k], BLACK);
        EndDrawing();

        time = GetTime();

        // change in speed
        if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && speed >= 0.005001)
            speed -= 0.005;
        if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && speed <= 1.00000)
            speed += 0.005;

        if (WindowShouldClose())
            exit(0);
    }
    return 0;
}

int end()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < 19; i++)
            DrawRectangle(position[i], 950 - height[i], 50, height[i], BLACK);

        EndDrawing();
    }
    return 0;
}