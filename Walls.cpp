#include "Walls.h"
#include <hFramework.h>
#include <DistanceSensor.h>



#define NORTH 1
#define EAST  2
#define SOUTH  4
#define WEST  8

//value determined during tests depending on maze cell size and robot dimension and sensor placement
#define WALL_CHECK_DISTANCE 17

using namespace hModules;

Walls::Walls() {
}

Walls::~Walls() {
}

void Walls::LED(int ledno, int cnt, int light, int dark) {
    for (int i=0; i<cnt; i++) {
        switch(ledno) {
            case 1: LED1.on(); sys.delay(light); LED1.off(); sys.delay(dark); break;
            case 2: LED2.on(); sys.delay(light); LED2.off(); sys.delay(dark); break;
            case 3: LED3.on(); sys.delay(light); LED3.off(); sys.delay(dark); break;
        }
    }
}

bool Walls::is_wall_left()
{
    DistanceSensor LeftSens(hSens1);
    int reading1 = LeftSens.getDistance();
    sys.delay(10);
    int reading2 = LeftSens.getDistance();
    sys.delay(10);
    int reading3 = LeftSens.getDistance();
    sys.delay(10);
    int reading4 = LeftSens.getDistance();
    sys.delay(10);
    int reading5 = LeftSens.getDistance();

    int array[5] = {reading1,reading2, reading3, reading4, reading5};
    int temp1 = 0;
    int temp2= reading1;
    int leftdist=0;
    for(int i=0;i<5;i++)
    {
        if(array[i]>temp1)
        temp1=array[i];
    }
       for(int i=0;i<5;i++)
    {
        if(array[i]<temp2)
        temp2=array[i];
    }
    leftdist = (reading1+reading2+reading3+reading4+reading5-temp1-temp2)/3;
    Serial.printf ("Left distance: %d \r\n", leftdist);
    if(leftdist<= WALL_CHECK_DISTANCE)
        {
        Serial.printf("Left wall detected\r\n");
        return true;
        }
    else
        return false;
}


bool Walls::is_wall_right()
{

    DistanceSensor RightSens(hSens2);
    int reading1 = RightSens.getDistance();
    sys.delay(10);
    int reading2 = RightSens.getDistance();
    sys.delay(10);
    int reading3 = RightSens.getDistance();
    sys.delay(10);
    int reading4 = RightSens.getDistance();
    sys.delay(10);
    int reading5 = RightSens.getDistance();

    int array[5] = {reading1,reading2, reading3, reading4, reading5};
    int temp1 = 0;
    int temp2= reading1;
    int rightdist=0;
    for(int i=0;i<5;i++)
    {
        if(array[i]>temp1)
        temp1=array[i];
    }
       for(int i=0;i<5;i++)
    {
        if(array[i]<temp2)
        temp2=array[i];
    }
    rightdist = (reading1+reading2+reading3+reading4+reading5-temp1-temp2)/3;
        Serial.printf ("Right distance: %d \r\n", rightdist);
    if(rightdist<= WALL_CHECK_DISTANCE)
        {
        Serial.printf("Right wall detected \r\n");
        return true;
        }
    else
        return false;
}



bool Walls::is_wall_front()
{
    DistanceSensor FrontSens(hSens3);
    int reading1 = FrontSens.getDistance();
    sys.delay(10);
    int reading2 = FrontSens.getDistance();
    sys.delay(10);
    int reading3 = FrontSens.getDistance();
    sys.delay(10);
    int reading4 = FrontSens.getDistance();
    sys.delay(10);
    int reading5 = FrontSens.getDistance();

    int array[5] = {reading1,reading2, reading3, reading4, reading5};
    int temp1 = 0;
    int temp2= reading1;
    int frontdist=0;
    for(int i=0;i<5;i++)
    {
        if(array[i]>temp1)
        temp1=array[i];
    }
       for(int i=0;i<5;i++)
    {
        if(array[i]<temp2)
        temp2=array[i];
    }
    frontdist = (reading1+reading2+reading3+reading4+reading5-temp1-temp2)/3;
    Serial.printf ("Front distance: %d \r\n", frontdist);

    if(frontdist<= WALL_CHECK_DISTANCE)
    {
        Serial.printf("Front wall detected \r\n");
        return true;
    }
    else
        return false;
}

unsigned char Walls::detect_walls(unsigned char orientation)
{
    bool LeftWallExist = false;
    bool RightWallExist = false;
    bool FrontWallExist = false;
    LeftWallExist = is_wall_left();
    RightWallExist = is_wall_right();
    FrontWallExist = is_wall_front();

    unsigned char LeftWall=0;
    unsigned char RightWall=0;
    unsigned char FrontWall=0;

    LED(2, 2, 300, 500);

    if(orientation==NORTH)
    {   Serial.printf("Current orientation: NORTH \r\n");
        if (LeftWallExist)
            LeftWall = WEST;


        if (RightWallExist)
            RightWall = EAST;

        if (FrontWallExist)
            FrontWall = NORTH;
    }
    else if(orientation==EAST)
    {
        Serial.printf("Current orientation: EAST \r\n");
        if (LeftWallExist)
            LeftWall = NORTH;

        if (RightWallExist)
            RightWall = SOUTH;

        if (FrontWallExist)
            FrontWall = EAST;
    }
    else if(orientation==WEST)
    {
        Serial.printf("Current orientation: WEST \r\n");
        if (LeftWallExist)
            LeftWall = SOUTH;

        if (RightWallExist)
            RightWall = NORTH;

        if (FrontWallExist)
            FrontWall = WEST;
    }
    else if(orientation==SOUTH)
    {
        Serial.printf("Current orientation: SOUTH \r\n");
        if (LeftWallExist)
            LeftWall = EAST;

        if (RightWallExist)
            RightWall = WEST;

        if (FrontWallExist)
            FrontWall = SOUTH;
    }
    unsigned char    CellWalls = FrontWall+RightWall+LeftWall;
    Serial.printf("\r\n Cell walls: %u \r\n", (unsigned int)CellWalls);
    return CellWalls;
}
