#include <hFramework.h>
#include <stdio.h>
#include "Maze.h"
#include "Mouse.h"

using namespace hFramework;
using namespace std;

int hMain(void)
{
 	int temp_size=4;
	int temp_start=0;
	int temp_finish=14;

	Maze *m = new Maze(temp_size, temp_start, temp_finish);
	Mouse *rat = new Mouse(m);

	rat->mapping();
	m->print();
    return 0;
}


