#ifndef MORTAL_H
#define MORTAL_H
class Mortal {
	public:
		virtual int hitpoints() = 0;
		virtual void receiveHit(int) = 0;
		virtual void die() = 0;
};
#endif
