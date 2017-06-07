/*
 * Maze.h
 *
 *  Created on: May 17, 2017
 *      Author: sylwia
 */

#ifndef MAZE_H_
#define MAZE_H_


namespace std {

class Maze {
	int mazeSize;
	unsigned char *maze;
	void init();
	int start;
	int finish;


public:
	Maze(int temp_size, int temp_start, int temp_finish);
	~Maze();
	void print();
	void save_walls(int position, unsigned char walls);
	void set_size(int msize);
	void set_start(int start);
	void set_finish(int finish);

	int get_size();
	int get_start();
	int get_finish();
};

} /* namespace std */

#endif /* MAZE_H_ */
