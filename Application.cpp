#include <iostream>
#include "area.hh"
#include "radar.hh"

void updateProjectilePosition(area area[][AREA_SIZE], int x_cord, int y_cord, int trajectory);
void printArea(area area[][AREA_SIZE], radar radar, int trajectory);
void startSimulator(area area[][AREA_SIZE]);

int main(){
    area area[AREA_SIZE][AREA_SIZE];

    startSimulator(area);

    return 0;
}

void startSimulator(area area[][AREA_SIZE]){
    radar radar;
    int option;
    int running = 1;
    int coordinateX, coordinateY;
    int trajectory;

    area[7][7].setRadarLocation();

    std::cout << "Welcome to radar simulation. Pick option you want to procede with.\n";

    while(running)
    {
        std::cout <<" 1. Watch radar\n 2. Input object\n  3. Exit simulator\n";
        std::cin >> option;
        switch(option){
            case 1:
                //printingScannedArray
                printArea(area, radar, trajectory);
                //running = 0;
                break;
            case 2:
                //inputObject
                std::cout << "Coordinates must be in range [0-15]. Angle of trajectory must be in range [0-360]. Angle is in relation to azimuth." << std::endl;
                std::cout << "Enter X coordinate: ";
                std::cin >> coordinateX;
                std::cout << "\nEnter Y coordinate: ";
                std::cin >> coordinateY;
                std::cout << "\nEnter angle of trajectory: ";
                std::cin >> trajectory;

                area[coordinateX][coordinateY].setProjectilePresent(true);
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

void printArea(area area[][AREA_SIZE], radar radar, int trajectory){
    int n = 15;
    while(n)
    {
        radar.updateMap(area);
        radar.updateAngles();

        for(uint32_t i = 0; i < AREA_SIZE; i++){
            for(uint32_t j = 0; j < AREA_SIZE; j++){
                if(area[i][j].getProjectilePresentValue())
                {
                    updateProjectilePosition(area, i, j, trajectory);
                    break;
                }
            }
        }
        n--;
    }
}

void updateProjectilePosition(area area[][AREA_SIZE], int x_cord, int y_cord, int trajectory){
    int newPosition;
    newPosition = area[x_cord][y_cord].calcNewProjectilePosition(trajectory);

    if(area[x_cord][y_cord].getWeight() == 1)
        newPosition = area[x_cord][y_cord].getChangeDirectionTo();

    if(newPosition == north)
    {
        if(x_cord != 0)
        {
            area[x_cord-1][y_cord].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false); 
        }
        else
            area[x_cord][y_cord].updateArea(0, false); 
    }
    else if(newPosition == northEast)
    {
        if(x_cord != 0 || y_cord != AREA_SIZE - 1)
        {
            area[x_cord-1][y_cord+1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else if(newPosition == east)
    {
        if(y_cord != AREA_SIZE - 1)
        {
            area[x_cord][y_cord+1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else if(newPosition == southEast)
    {
        if(x_cord != AREA_SIZE - 1 || y_cord != AREA_SIZE - 1)
        {
            area[x_cord+1][y_cord+1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else if(newPosition == south)
    {
        if(x_cord != AREA_SIZE - 1)
        {
            area[x_cord+1][y_cord].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else if(newPosition == southWest)
    {
        if(x_cord != AREA_SIZE - 1 || y_cord != 0)
        {
            area[x_cord+1][y_cord-1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else if(newPosition == west)
    {
        if(y_cord != 0)
        {
            area[x_cord][y_cord-1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
    else
    {
        if(x_cord != 0 || y_cord != 0)
        {
            area[x_cord-1][y_cord-1].updateArea(area[x_cord][y_cord].getWeight() - 1, true);
            area[x_cord][y_cord].updateArea(0, false);
        }
        else
            area[x_cord][y_cord].updateArea(0, false);
    }
}