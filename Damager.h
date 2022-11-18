#ifndef DAMAGER_H
#define DAMAGER_H
#include "Mortal.h"

class Damager {
	public:
		virtual void damage(Mortal&) = 0;
};
#endif
