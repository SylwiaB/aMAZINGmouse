/*
 * Mouse.h
 *
 *  Created on: 18 maj 2017
 *      Author: sylwia
 */
#include "Maze.h"
#include "Walls.h"

#ifndef MOUSE_H_
#define MOUSE_H_


namespace std {

class Mouse{
	int position;		// current mouse position on the map
	unsigned char orientation;	// where the mouse is directed to
	Maze *maze;
	void new_orientation(int direction);
public:
	Mouse(Maze *m);
	~Mouse();

	void step();
	void turn(int dir);
	void turn_mouse(Walls *w);
	void mapping();
	int get_position();
	bool is_finish();
	void LED(int ledno, int cnt, int light, int dark);
};
}


#endif /* MOUSE_H_ */
