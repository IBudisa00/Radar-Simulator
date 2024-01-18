#include "area.hh"

area::area(uint32_t x_cord, uint32_t y_cord){
    x = x_cord;
    y = y_cord;
    projectile_present = false;
    radarLocation = false;
}

void area::setProjectilePresent(bool value){
    projectile_present = value;
}

void area::setRadarLocation(){
    radarLocation = true;
}

bool area::getProjectilePresentValue(){
    return projectile_present;
}

int area::calcNewProjectilePosition(int trajectory){
    if(trajectory <= 30 || trajectory >= 330)
    {
        setProjectilePresent(false);
        return north;
    }
    else if(trajectory > 30 && trajectory < 60)
        return northEast;
    else if(trajectory >= 60 && trajectory <= 120)
        return east;
    else if(trajectory > 120 && trajectory < 150)
        return southEast;
    else if(trajectory >= 150 && trajectory <= 210)
        return south;
    else if(trajectory > 210 && trajectory < 240)
        return southWest;
    else if(trajectory >= 240 && trajectory <= 300)
        return west;
    else if(trajectory > 300 && trajectory < 330)
        return northWest;
}

uint32_t area::getXcord(){
    return x;
}

uint32_t area::getYcord(){
    return y;
}
