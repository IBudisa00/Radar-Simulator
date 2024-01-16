#include "radar.hh"
#include <cmath>

radar::radar(){
    angle_range = 120;
    range_radius = 6;
    left_range_boundary = 300;
    right_range_boundary = 60;
}

void radar::updateAngles(){
    left_range_boundary = left_range_boundary + 60;
    if(left_range_boundary > 240)
        right_range_boundary = angle_range - (360 - left_range_boundary);
    else
        right_range_boundary = left_range_boundary + 120;
}

bool radar::checkIfInRange(uint32_t x_cord, uint32_t y_cord){
    if(y_cord >= radar_y)
    {   //quadrant1 and quadrant4
        if((sqrt(pow(abs(x_cord-radar_x), 2) + pow(abs(y_cord-radar_y), 2)) <= range_radius)||(sqrt(pow(abs(x_cord-radar_x), 2) + pow(abs(y_cord-radar_y) - 1, 2)) <= range_radius))
            return true;
        else
            return false;
    }
    else
    {
        //quadrant2 and quadrant3
        if((sqrt(pow(abs(x_cord-radar_x), 2) + pow(abs(y_cord-radar_y), 2)) <= range_radius)||(sqrt(pow(abs(x_cord-radar_x), 2) + pow(abs(y_cord-radar_y) + 1, 2)) <= range_radius))
            return true;
        else
            return false;
    }
}

void radar::updateMap(area area[][AREA_SIZE]){
    for(uint32_t i = 0; i < AREA_SIZE; i++){
        for(uint32_t j = 0; j < AREA_SIZE; j++){
            if(checkIfInRange(i,j))
                std::cout << " O ";
            else
                std::cout << "  ";
        }
        std::cout<<"\n";
    }
}