#pragma once
#include "area.hh"
#define RED "\033[31m"
#define GREEN "\033[42m"
#define RESET "\033[0m"

class radar{
    private:
        //range boundaries have values [0-360]
        uint32_t left_range_boundary;
        uint32_t right_range_boundary;
        uint32_t angle_range;
        uint32_t range_radius;
        uint32_t angleChange;
        uint32_t radar_x;
        uint32_t radar_y;
        bool transition;
    public:
    radar();
    void updateAngles();
    bool checkIfInRange(uint32_t x_cord, uint32_t y_cord);
    bool checkIfAngleSuits(uint32_t x_cord, uint32_t y_cord);
    void updateMap(area area[][AREA_SIZE]);
};