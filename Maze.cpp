/*
 * Maze.cpp
 *
 *  Created on: May 17, 2017
 *      Author: sylwia
 */

#include <string.h>
#include <stdio.h>
#include "Maze.h"
#include <hFramework.h>

#define  NORTH	1		// binary 00000001
#define  EAST	2		// binary 00000010
#define  SOUTH	4		// binary 00000100
#define  WEST	8		// binary 00001000
#define  SIZE_STEP	8	// extension steps for maze matrix

using namespace hFramework;

namespace std {

Maze::Maze(int temp_size, int temp_start, int temp_finish) {
	set_size(temp_size);
	maze = new unsigned char[mazeSize * mazeSize];
	set_start(temp_start);
	set_finish(temp_finish);
	init();
}

Maze::~Maze() {
}

void Maze::init() {

		unsigned char sample1[] = {	0,0,0,0,
                                    0,0,0,0,
                                    0,0,0,0,
                                    0,0,0,0};
// initialization the labirynth by "0"
  for (int j=0; j<mazeSize; j++) {
	  for (int i=0; i<mazeSize; i++) {
		  maze[i+j*mazeSize]=0;
	  }
  }

}

void Maze::save_walls(int position, unsigned char walls) {
	maze[position] = walls;
}

void Maze::set_size(int msize) {
	mazeSize=msize;
}
void Maze::set_start(int start){
	this->start=start;
}
void Maze::set_finish(int finish){
	this->finish = finish;
}

int Maze::get_size(){
	return mazeSize;
}

int Maze::get_start(){
	return start;
}

int Maze::get_finish() {
	return finish;
}

void Maze::print() {
	char tmp[6];                                        // temp value to save detected walls as "picture"
	for (int k=0; k<3*3*mazeSize; k++) tmp[k]='1';
  for (int j=0; j<mazeSize; j++) {
	  for (int k=0; k<3; k++) {
		  for (int i=0; i<mazeSize; i++) {
			  switch (maze[i+j*mazeSize]) {
				  case 0: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,"# # #"); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 1: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,". . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 2: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 3: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 4: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,". . ."); break;
				  	  	  	  case 2: strcpy(tmp,"#   #"); break;
				  	  	  }; break;
				  case 5: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,". . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 6: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 7: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . ."); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 8: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,". . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 9: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,". . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 10: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 11: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# . #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 12: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,". . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 13: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,". . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# # #"); break;
				  	  	  }; break;
				  case 14: switch(k) {
				  	  	  	  case 0: strcpy(tmp,"# # #"); break;
				  	  	  	  case 1: strcpy(tmp,"# . #"); break;
				  	  	  	  case 2: strcpy(tmp,"# . #"); break;
				  	  	  }; break;
				  case 15: switch(k) {
                              case 0: strcpy(tmp,"     "); break;
				  	  	  	  case 1: strcpy(tmp,"     "); break;
				  	  	  	  case 2: strcpy(tmp,"     "); break;
				  	  	  }; break;
			  }
			  Serial.printf("%s",tmp);
		  }
		  Serial.printf("\r\n");
	  }
  }
}
} // namespace std

