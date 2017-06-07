/*
 * Mouse.cpp
 *
 *  Created on: 18 maj 2017
 *      Author: sylwia
 */
#include <string.h>
#include <hFramework.h>
#include "Mouse.h"
#include "Walls.h"

#define  NORTH	1		// binary 00000001
#define  EAST	2		// binary 00000010
#define  SOUTH	4		// binary 00000100
#define  WEST	8		// binary 00001000

#define LEFT 1
#define RIGHT 0

using namespace hFramework;

namespace std {
Mouse::Mouse(Maze *m) {
	maze=m;
	position = 0;
	orientation = NORTH;                                // initialization orientation of maze
}

// to manage LED diods on roboCORE
void Mouse::LED(int ledno, int cnt, int light, int dark) {
    int i;
        switch(ledno) {
            case 1:
                    for (i=0; i<cnt; i++) {
                        LED1.on(); sys.delay(light); LED1.off(); sys.delay(dark);}
                        break;
            case 2:
                    for (i=0; i<cnt; i++) {
                        LED2.on(); sys.delay(light); LED2.off(); sys.delay(dark);}
                        break;

            case 3:
                    for (i=0; i<cnt; i++) {
                        LED3.on(); sys.delay(light); LED3.off(); sys.delay(dark);}
                        break;
        }
}

int Mouse::get_position() {
	return position;
}

// checking if mouse reached the goal
 bool Mouse::is_finish() {
	bool answer;
	if (position == maze->get_finish())
		answer = true;
	else
		answer= false;

	return answer;
}
void Mouse::new_orientation(int direction){
	if (direction == RIGHT)
		if (orientation != WEST) orientation*= 2;
		else orientation = NORTH;
	if (direction == LEFT)
			if (orientation != NORTH) orientation/= 2;
			else orientation = WEST;
}

void Mouse::turn(int dir) {
    if(dir == RIGHT)
    {
    hMot3.rotRel(-840,500);              //Prawy
    hMot4.rotRel(840,557,1);             //Lewy
    sys.delay(1000);
    }
    if(dir == LEFT)
    {
     hMot4.rotRel(-840,557);              //Lewy
    hMot3.rotRel(840,500,1);              //Prawy
    sys.delay(1000);
    }
}

void Mouse::step(void) {
    LED(3,3,100,100);
    hMot3.rotRel(2000,500);
    hMot4.rotRel(2000,557,1);
    sys.delay(50);

    Serial.printf("Position1: %d\r\n", position);
    switch (orientation) {
        case NORTH: position += 4; break;
        case SOUTH: position -= 4; break;
        case WEST: position += 1; break;
        case EAST: position -=1; break;
    }

    Serial.printf("Position2: %d\r\n", position);

}

 void Mouse::turn_mouse(Walls *w) {
      if (!w->is_wall_right()){
		 turn(RIGHT);
		  sys.delay(100);
		 new_orientation(RIGHT);
	 }

	 else if (!w->is_wall_front()) {
	  sys.delay(100);	}	// do nothing

	 else if (!w->is_wall_left()){
		 turn(LEFT);
		 sys.delay(100);
	 	 new_orientation(LEFT);
	 }

	 else {									// U-turn
		 turn(RIGHT);
		 new_orientation(RIGHT);
		 sys.delay(100);
		 turn(RIGHT);
		 sys.delay(100);
		 new_orientation(RIGHT);
	 }
 }
void Mouse::mapping() {
    LED(3,2,500,500);
	int start = maze->get_start();
	int finish = maze->get_finish();
	int msize = maze->get_size();
	Walls *w = new Walls();
	unsigned char w_temp;				//temporary walls oriented to maze
	position = start;


	while (is_finish() != true) {

		w_temp = w->detect_walls(orientation);
		maze->save_walls(position, w_temp);
        turn_mouse(w);
		step();
	}
		w_temp = w->detect_walls(orientation);
		maze->save_walls(position, w_temp);
		turn_mouse(w);
		 hMot3.rotRel(2000,500);
        hMot4.rotRel(2000,557,1);
        sys.delay(50);


}

}


