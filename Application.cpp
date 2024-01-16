#include <iostream>
#include "area.cpp"
#include "radar.cpp"

int main(){
    area area[AREA_SIZE][AREA_SIZE];

    startSimulator(area);

    return 0;
}

void startSimulator(area area[][AREA_SIZE]){
    radar radar;
    int option;
    int running = 1;

    std::cout << "Welcome to radar simulation. Pick option you want to procede with.\n";
    std::cout <<" 1. Watch radar\n 2. Input object\n  3. Exit simulator\n";
    std::cin >> option;

    while(running)
    {
        switch(option){
            case 1:
                //printingScannedArray
                printArea(area, radar);
                break;
            case 2:
                //inputObject
                //cordinates + angle in degrees
                break;
            case 3:
                running = 0;
                break;
            default:
                std::cout <<"Unknown option...\n";
                break;
        }
    }
}

void printArea(area area[][AREA_SIZE], radar radar){
    int n = 15;
    while(n)
    {
        radar.updateMap(area);
        n++;
    }
}