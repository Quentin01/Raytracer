#include "Scene/BasicScene.hh"

void BasicScene::addObject(const Object *object)
{
	_objects.push_back(object);
}

Hit::Type BasicScene::intersectRay(const Ray &r, Hit &h) const
{
	Hit			tempHit;
	Hit::Type	returnValue = Hit::NONE;
	Hit::Type	tempValue = Hit::NONE;

	for (unsigned int i = 0, len = _objects.size(); i < len; i++)
	{
		if ((tempValue = _objects[i]->intersectRay(r, tempHit, h.dist)) != Hit::NONE)
		{
			if (tempHit.dist < h.dist)
			{
				returnValue = tempValue;
				h = tempHit;
				h.material = _objects[i]->getMaterial();
			}
		}
	}

	return (returnValue);
}