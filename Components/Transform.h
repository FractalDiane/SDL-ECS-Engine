#ifndef __TRANSFORM_H
#define __TRANSFORM_H

#include "Component.h"
#include "Vector2.h"

class Transform : public Component {
private:
	Vector2 position;
	float rotation;
	Vector2 scale;

public:
	Transform();
	~Transform();

	Vector2 get_position() const;
	float get_rotation() const;
	Vector2 get_scale() const;

	void set_position(const Vector2& value);
	void set_rotation(const float& value);
	void set_scale(const Vector2& value);
};

#endif
