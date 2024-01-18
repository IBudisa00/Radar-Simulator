#include "radar.hh"
#include <cmath>

radar::radar(){
    angle_range = 120;
    range_radius = 6;
    left_range_boundary = 300;
    right_range_boundary = 60;
    transition = true;
}

void radar::updateAngles(){
    if(left_range_boundary + 60 > 360)
    {
        left_range_boundary = left_range_boundary + 60 - 360;
        right_range_boundary = left_range_boundary + 120;
    }
    else if(left_range_boundary + 60 == 360)
    {
        left_range_boundary = 0;
        right_range_boundary = left_range_boundary + 120;
    }
    else
    {
        left_range_boundary = left_range_boundary + 60;
        if(right_range_boundary + 120 > 360)
            right_range_boundary = angle_range - (360 - left_range_boundary);
        else if(right_range_boundary + 120 == 360)
            right_range_boundary = 0;
        else
            right_range_boundary = left_range_boundary + 120;
    }
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

bool radar::checkIfAngleSuits(uint32_t x_cord, uint32_t y_cord){
    //check quadrant
    double hypotenuse;
    int adjacent;
    int opposite;
    double calc_angle;

    //quadrant2
    if(radar_x > x_cord && radar_y > y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        hypotenuse = calcHypotenuse(opposite, adjacent);
        calc_angle = 270.0 + 1/cos(adjacent/hypotenuse);
    }
    //quadrant1
    else if(radar_x > x_cord && radar_y < y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        hypotenuse = calcHypotenuse(opposite, adjacent);
        calc_angle = 90.0 - 1/cos(adjacent/hypotenuse);
    }
    //quadrant4
    else if(radar_x < x_cord && radar_y < y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        hypotenuse = calcHypotenuse(opposite, adjacent);
        calc_angle = 90.0 + 1/cos(adjacent/hypotenuse);
    }
    //quadrant3
    else if(radar_x < x_cord && radar_y > y_cord)
    {
        opposite = abs(x_cord-radar_x);
        adjacent = abs(y_cord-radar_y);
        hypotenuse = calcHypotenuse(opposite, adjacent);
        calc_angle = 270.0 - 1/cos(adjacent/hypotenuse);
    }
    else if(radar_x == x_cord)
    {
        if(y_cord > radar_y)
            calc_angle = 90;
        else
            calc_angle = 270;
    }
    else if(radar_y == y_cord)
    {
        if(x_cord > radar_x)
            calc_angle = 180;
        else
            calc_angle = 0;
    }
    //right above radar
    else
        return true;

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
                        std::cout << " O ";
                    else
                        std::cout << "  ";
                }
            }
            else
                std::cout << "  ";
        }
        std::cout<<"\n";
    }
}

double radar::calcHypotenuse(int opposite, int adjacent){
    return sqrt(pow(adjacent, 2) + pow(opposite, 2));
}
