#include "Object.hh"

Object::Object(const Vector3D &position, const Material *material) : _position(position), _material(material)
{}

Object::Object(const Object &o)
{
	_material = o._material;
	_position = o._position;
}

Object::Object(const Object &&o)
{
	_material = o._material;
	_position = o._position;
}

Object::~Object()
{}

Object &Object::operator=(const Object &o)
{
	_material = o._material;
	_position = o._position;

	return (*this);
}

void Object::setMaterial(const Material *material)
{
	_material = material;
}

const Material *Object::getMaterial() const
{
	return (_material);
}

void Object::setPosition(const Vector3D &position)
{
	_position = position;
}

Vector3D Object::getPosition() const
{
	return (_position);
}