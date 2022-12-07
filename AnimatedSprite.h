#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "Animatable.h"
#include "DrawableEntity.h"
#include "Placeable.h"
#include "Collidable.h"

class AnimatedSprite : public virtual Animatable, public virtual DrawableEntity, public virtual Placeable, public virtual Collidable { };
#endif
