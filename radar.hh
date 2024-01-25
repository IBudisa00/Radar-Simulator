#pragma once
#include "area.hh"
#define RED "\033[41m"
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
        int radar_x;
        int radar_y;
        bool transition;
    public:
    radar();
    void updateAngles();
    bool checkIfInRange(int x_cord, int y_cord);
    bool checkIfAngleSuits(int x_cord, int y_cord);
    void updateMap(area area[][AREA_SIZE]);
    void setRadarCoords(int x_cord, int y_cord);
};