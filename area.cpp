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