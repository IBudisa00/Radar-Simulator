#include "radar.hh"

#define _USE_MATH_DEFINES
#include <cmath>

radar::radar(){
    angle_range = 120;
    range_radius = 12;
    left_range_boundary = 300;
    right_range_boundary = 60;
    angleChange = 30;
    transition = true;
}

void radar::updateAngles(){
    int newLeftRange = (left_range_boundary + angleChange) % 360;
    int newRightRange = (newLeftRange + angle_range) % 360;

    if(newLeftRange < left_range_boundary)
        transition = false;
    left_range_boundary = newLeftRange;
    if(newRightRange < right_range_boundary)
        transition = true;
    right_range_boundary = newRightRange;
}

bool radar::checkIfInRange(int x_cord, int y_cord){
    if(sqrt(pow(abs(x_cord-radar_x), 2) + pow(abs(y_cord-radar_y), 2)) <= range_radius)
        return true;
    else
        return false;
}

bool radar::checkIfAngleSuits(int x_cord, int y_cord){
    double adjacent;
    double opposite;
    double calc_angle;

    //quadrant2
    if(radar_x > x_cord && radar_y > y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        calc_angle = 270.0 + atan(opposite/adjacent)*180/M_PI;
    }
    //quadrant1
    else if(radar_x > x_cord && radar_y < y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        calc_angle = 90.0 - atan(opposite/adjacent)*180/M_PI;
    }
    //quadrant4
    else if(radar_x < x_cord && radar_y < y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        calc_angle = 90.0 + atan(opposite/adjacent)*180/M_PI;
    }
    //quadrant3
    else if(radar_x < x_cord && radar_y > y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        calc_angle = 270.0 - atan(opposite/adjacent)*180/M_PI;
    }
    else if(radar_x == x_cord)
    {
        if(y_cord > radar_y)
            calc_angle = 90;
        else if(y_cord < radar_y)
            calc_angle = 270;
        else
            return true;
    }
    else if(radar_y == y_cord)
    {
        if(x_cord > radar_x)
            calc_angle = 180;
        else
            calc_angle = 0;
    }

    if(transition)
    {
        if(calc_angle < left_range_boundary && calc_angle > right_range_boundary)
        {
            return false;
        }
        else
            return true;
    }
    else
    {
        if((calc_angle > left_range_boundary && calc_angle > right_range_boundary)||(calc_angle < left_range_boundary && calc_angle < right_range_boundary))
        {
            return false;
        }
        else
            return true;
    }
}

void radar::updateMap(area area[][AREA_SIZE]){
    for(uint32_t i = 0; i < AREA_SIZE; i++){
        for(uint32_t j = 0; j < AREA_SIZE; j++){
            if(checkIfAngleSuits(i,j))
            {
                if(checkIfInRange(i,j))
                {
                    if(area[i][j].getProjectilePresentValue())
                        std::cout << RED << " O " << RESET;
                    else if(area[i][j].getRadarLocation())
                        std::cout << GREEN << " R " << RESET;
                    else
                        std::cout << GREEN << " + " << RESET;
                }
                else
                    std::cout << " + ";
            }
            else
                std::cout << " + ";
        }
        std::cout<<"\n";
    }
}

void radar::setRadarCoords(int x_cord, int y_cord){
    radar_x = x_cord;
    radar_y = y_cord;
}
