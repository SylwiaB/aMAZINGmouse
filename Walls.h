/*
 * Walls.h
 *
 *  Created on: 19 maj 2017
 *      Author: sylwia
 */

#ifndef WALLS_H_
#define WALLS_H_

class Walls {
public:
	Walls();
	virtual ~Walls();

	bool is_wall_left();
	bool is_wall_front();
	bool is_wall_right();

	unsigned char detect_walls(unsigned char orientation);
	void LED(int ledno, int cnt, int light, int dark);
};

#endif /* WALLS_H_ */
