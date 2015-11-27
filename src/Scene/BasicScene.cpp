#include "Scene/BasicScene.hh"

void BasicScene::addObject(const Object *object)
{
    _objects.push_back(object);
}

bool BasicScene::intersectRay(const Ray &r, Hit &h) const
{
    Hit         tempHit;
    bool        haveHit = false;

    for (unsigned int i = 0, len = _objects.size(); i < len; i++)
    {
        if (_objects[i]->intersectRay(r, tempHit, h.t))
        {
            if (tempHit.t < h.t)
            {
                haveHit = true;
                h = tempHit;
                h.material = _objects[i]->getMaterial();
            }
        }
    }

    return (haveHit);
}