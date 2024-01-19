#include <iostream>
#include <cstdint>
#define AREA_SIZE 15

enum nextProjectilePosition{
    noDirectionSet,
    north,
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
        uint32_t changeDirectionTo;
        uint32_t weight;
    public:
        area();
        void setProjectilePresent(bool value);
        void setRadarLocation();
        bool getProjectilePresentValue();
        int calcNewProjectilePosition(int trajectory);
        void setChangeDirectionTo(uint32_t value);
        uint32_t getChangeDirectionTo();
        void setWeight(uint32_t value);
        uint32_t getWeight();
        void updateArea(int weightValue, bool projectileValue);
};