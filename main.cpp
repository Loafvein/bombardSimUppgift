#include "raylib.h" 
#include "Payload.h"
#include "Aircraft.h"
#include "Dropdownmenu.h"
#include <vector>
#include <string>
#include "FatMan.h"
#include "SupplyDrop.h"

#include<iostream>
int main(){
    std::cout << "Current working directory: " << GetWorkingDirectory() << std::endl;

    InitWindow(800,600, "Bombardment Simulator");
    SetTargetFPS(60);

    Aircraft plane(-150,200,300.0f,"./assets/plane.png");
    
    // Knappens position och storlek
    Rectangle button = { 350, GetScreenHeight()-100.0f, 100, 50 };  // x, y, bredd, höjd :Bombard-Knappen
    Rectangle increaseButton = {GetScreenWidth()- 60.0f, 50, 70, 40};  // Knapp för att öka
    Rectangle decreaseButton = {GetScreenWidth()- 60.0f, 100, 70, 40}; // Knapp för att minska

    // Vindhastighet
    float windResistance = 0.0f;

    bool hasPayloadDropped = false;

    FatMan* fatMan = new FatMan(-100,-100,10.0f,0.0f,200.0f,"Fat_man","assets/fat_man.png");
    SupplyDrop* supplyDrop = new SupplyDrop(-100,-100,10.0f,0.0f,200.0f,"Supply_drop","assets/ammo.png");

    std::vector<Payload*> payloadOptions = {
        new Payload(-100,-100,10.0f,0.0f,200.0f,"Bomb"),
        new Payload(-100,-100,500.0f,0.0f,250.0f,"Rock"),
        new Payload(-100,-100,5.0f,0.0f,250.0f,"Apple"),
        fatMan,
        supplyDrop
        

    };

    DropdownMenu dropdownMenu(50,50,200,30,payloadOptions);
    //Payload selectedPayload(0, 0, 0, 0, 0, "");
    //Payload previousSelectedPayload(0, 0, 0, 0, 0, "");

    Payload* selectedPayload = nullptr;
    Payload* previousSelectedPayload = nullptr;

    bool payloadSelected = false;

    //Tha Loop
    while (!WindowShouldClose())
    {   
        //payloadSelected = false;
        // Kolla om musen är över knappen   
        Vector2 mousePoint = GetMousePosition();
        bool isMouseOver = CheckCollisionPointRec(mousePoint, button);
        bool isMouseOverIncreaseButton = CheckCollisionPointRec(mousePoint,increaseButton);
        bool isMouseOverDecreaseButton = CheckCollisionPointRec(mousePoint,decreaseButton);

        if(isMouseOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            plane.Start();
                TraceLog(LOG_INFO, "Bombard button pressed!");
                hasPayloadDropped = false;
        } 
        if(isMouseOverIncreaseButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            windResistance +=  9.99f;
            TraceLog(LOG_INFO,TextFormat("Wind resistance is increased to %0.2f",windResistance));
        }
        if(isMouseOverDecreaseButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            windResistance -=  9.99f;
            TraceLog(LOG_INFO,TextFormat("Wind resistance is decreased to %0.2f",windResistance));
        }

        plane.Update(GetFrameTime());
        //if(!selectedPayload.isActive && plane.position.x >=200 && !hasPayloadDropped && !selectedPayload.name.empty()){
        if (selectedPayload && !selectedPayload->isActive && plane.position.x >= 200 && !hasPayloadDropped && !selectedPayload->name.empty()) {
            //selectedPayload.Drop(plane.position.x + plane.texture.width /2, plane.position.y + plane.texture.height);
            selectedPayload->Drop(plane.position.x + plane.texture.width / 2, plane.position.y + plane.texture.height);
            hasPayloadDropped = true;
        }
        dropdownMenu.Update();

        if (dropdownMenu.IsItemSelected()) {
            Payload* newSelectedPayload = dropdownMenu.GetSelectedItem(); // Hämtar nytt val

            // Endast uppdatera om valet faktiskt har ändrats
            //if (newSelectedPayload.name != selectedPayload.name) {
             if (newSelectedPayload != selectedPayload) {
                selectedPayload = newSelectedPayload; // Byt till den nya payloaden
                //TraceLog(LOG_INFO, TextFormat("Selected Payload: %s", selectedPayload.name.c_str()));
                TraceLog(LOG_INFO, TextFormat("Selected Payload: %s", selectedPayload->name.c_str()));
                payloadSelected = true;
                hasPayloadDropped = false;  // Återställ så att ny payload kan släppas
                }
        }



        BeginDrawing();
        ClearBackground(RAYWHITE);

        //selectedPayload.Update(GetFrameTime(),windResistance);
        if (selectedPayload) {
            selectedPayload->Update(GetFrameTime(), windResistance); // Använd -> för pekare
            selectedPayload->Draw();                           // Använd -> för pekare
        }

        DrawRectangleRec(button,isMouseOver ? BLUE : RED );
        DrawText("Bombard", button.x + 10, button.y + 15, 20, WHITE);  

        DrawRectangleRec(increaseButton,isMouseOverIncreaseButton ? BLUE : GREEN);
        DrawText("+",increaseButton.x + 20,increaseButton.y + 15,20,BLACK);
        DrawRectangleRec(decreaseButton,isMouseOverDecreaseButton ? BLUE : YELLOW);
        DrawText("-",decreaseButton.x + 20,decreaseButton.y + 15,20,BLACK);

        // Rita vindhastigheten
        DrawText(TextFormat("Wind Resistance: %.2f", windResistance), GetScreenWidth() -300, 10, 20, BLACK);

        dropdownMenu.Draw();
        plane.Draw();
        //selectedPayload.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
    
}