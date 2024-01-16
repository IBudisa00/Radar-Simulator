#include <iostream>
#include <cstdint>
#define AREA_SIZE 15

class area{
    private:
        uint32_t x;
        uint32_t y;
        bool projectile_present;
        bool radarLocation;
    public:
        area(uint32_t x_cord, uint32_t y_cord);
        void setProjectilePresent(bool value);
        void setRadarLocation();
};