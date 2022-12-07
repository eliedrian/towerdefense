#ifndef TOWER_H
#define TOWER_H
#include "Placeable.h"
#include "DrawableEntity.h"
#include "Shooter.h"

class Tower : public virtual Placeable, public virtual DrawableEntity, public virtual Shooter {
	public:
		virtual ~Tower() {}
};
#endif
