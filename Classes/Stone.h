/*
 * Stone.h
 *
 *  Created on: Apr 5, 2015
 *      Author: hiro
 */

#ifndef STONE_H_
#define STONE_H_

class Stone {
public:
    bool init() {
        return true;
    }

	int id;
	string name;

    CREATE_FUNC(Stone);

private:

};

#endif /* STONE_H_ */
