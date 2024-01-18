#include <iostream>
#include <cstdint>
#define AREA_SIZE 15

enum nextProjectilePosition{
    north = 1,
    northEast,
    east,
    southEast,
    south,
    southWest,
    west,
    northWest
};

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
        bool getProjectilePresentValue();
        int calcNewProjectilePosition(int trajectory);
        uint32_t getXcord();
        uint32_t getYcord();
};