#include "area.hh"

area::area(){
    projectile_present = false;
    radarLocation = false;
    changeDirectionTo = noDirectionSet;
    weight = 0;
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
    if((trajectory <= 30 || trajectory >= 330) && trajectory != 0)
    {
        if(!weight)
        {
            if(trajectory <= 10)
            {
                setWeight(3);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory > 10 && trajectory <= 20)
            {
                setWeight(2);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory > 20)
            {
                setWeight(1);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory >= 350)
            {
                setWeight(3);
                setChangeDirectionTo(northWest);
            }
            else if(trajectory < 350 && trajectory >= 340)
            {
                setWeight(2);
                setChangeDirectionTo(northWest);
            }
            else
            {
                setWeight(1);
                setChangeDirectionTo(northWest);
            }
        }
        return north;
    }
    else if(trajectory > 30 && trajectory < 60)
    {
        if(!weight)
        {
            if(trajectory <= 40)
                setWeight(3);
            else if(trajectory > 40 && trajectory < 50)
                setWeight(2);
            else
                setWeight(1);

            setChangeDirectionTo(east);
        }
        return northEast;
    }
    else if((trajectory >= 60 && trajectory <= 120) && trajectory != 90)
    {
        if(!weight)
        {
            if(trajectory <= 70)
            {
                setWeight(1);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory > 70 && trajectory <= 80)
            {
                setWeight(2);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory > 80 && trajectory < 90)
            {
                setWeight(3);
                setChangeDirectionTo(northEast);
            }
            else if(trajectory > 90 && trajectory <= 100)
            {
                setWeight(3);
                setChangeDirectionTo(southEast);
            }
            else if(trajectory > 100 && trajectory <= 110)
            {
                setWeight(2);
                setChangeDirectionTo(southEast);
            }
            else
            {
                setWeight(1);
                setChangeDirectionTo(southEast);
            }
        }
        return east;
    }
    else if(trajectory > 120 && trajectory < 150)
    {
        if(!weight)
        {
            if(trajectory <= 130)
                setWeight(3);
            else if(trajectory > 130 && trajectory < 140)
                setWeight(2);
            else
                setWeight(1);

            setChangeDirectionTo(south);
        }
        return southEast;
    }
    else if((trajectory >= 150 && trajectory <= 210) && trajectory != 180)
    {
        if(!weight)
        {
            if(trajectory <= 160)
            {
                setWeight(1);
                setChangeDirectionTo(southEast);
            }
            else if(trajectory > 160 && trajectory <= 170)
            {
                setWeight(2);
                setChangeDirectionTo(southEast);
            }
            else if(trajectory > 170 && trajectory < 180)
            {
                setWeight(3);
                setChangeDirectionTo(southEast);
            }
            else if(trajectory > 180 && trajectory <= 190)
            {
                setWeight(3);
                setChangeDirectionTo(southWest);
            }
            else if(trajectory > 190 && trajectory <= 200)
            {
                setWeight(2);
                setChangeDirectionTo(southWest);
            }
            else
            {
                setWeight(1);
                setChangeDirectionTo(southWest);
            }
        }
        return south;
    }
    else if(trajectory > 210 && trajectory < 240)
    {
        if(!weight)
        {
            if(trajectory <= 220)
                setWeight(3);
            else if(trajectory > 220 && trajectory < 230)
                setWeight(2);
            else
                setWeight(1);

            setChangeDirectionTo(west);
        }
        return southWest;
    }
    else if((trajectory >= 240 && trajectory <= 300) && trajectory != 270)
    {
        if(!weight)
        {
            if(trajectory <= 250)
            {
                setWeight(1);
                setChangeDirectionTo(southWest);
            }
            else if(trajectory > 250 && trajectory <= 260)
            {
                setWeight(2);
                setChangeDirectionTo(southWest);
            }
            else if(trajectory > 260 && trajectory < 270)
            {
                setWeight(3);
                setChangeDirectionTo(southWest);
            }
            else if(trajectory > 270 && trajectory <= 280)
            {
                setWeight(3);
                setChangeDirectionTo(northWest);
            }
            else if(trajectory > 280 && trajectory <= 290)
            {
                setWeight(2);
                setChangeDirectionTo(northWest);
            }
            else
            {
                setWeight(1);
                setChangeDirectionTo(northWest);
            }
        }
        return west;
    }
    else if(trajectory > 300 && trajectory < 330)
    {
        if(!weight)
        {
            if(trajectory <= 310)
                setWeight(3);
            else if(trajectory > 310 && trajectory < 320)
                setWeight(2);
            else
                setWeight(1);

            setChangeDirectionTo(north);
        }
        return northWest;
    }
    else if(trajectory == 0)
        return north;
    else if(trajectory == 90)
        return east;
    else if(trajectory == 180)
        return south;
    else
        return west;
}

void area::setChangeDirectionTo(uint32_t value){
    changeDirectionTo = value;
}

uint32_t area::getChangeDirectionTo(){
    return changeDirectionTo;
}

void area::setWeight(uint32_t value){
    weight = value;
}

uint32_t area::getWeight(){
    return weight;
}

void area::updateArea(int weightValue, bool projectileValue, int newDirection){
    setWeight(weightValue);
    setProjectilePresent(projectileValue);
    setChangeDirectionTo(newDirection);
}

bool area::getRadarLocation(){
    return radarLocation;
}