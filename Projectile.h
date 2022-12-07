#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <iostream>
#include "Collidable.h"
#include "Damager.h"
#include "DrawableEntity.h"
#include "Mortal.h"
#include "Motile.h"

class Projectile : public virtual DrawableEntity, public virtual Motile, public virtual Collidable, public virtual Damager, public virtual Mortal {
	public:
		virtual ~Projectile() { }
};
#endif
