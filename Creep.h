#ifndef CREEP_H
#define CREEP_H
#include "Animatable.h"
#include "Collidable.h"
#include "DrawableEntity.h"
#include "HealthBar.h"
#include "Mortal.h"
#include "Motile.h"
#include "Target.h"

class Creep : public virtual Motile, public virtual DrawableEntity, public virtual Animatable, public virtual Mortal, public virtual Collidable, public virtual Target {
	public:
		virtual ~Creep() {};
};
#endif
