//
// Created by aleksandr on 05.05.22.
//

#ifndef __PROJECT_BOX2D_H
#define __PROJECT_BOX2D_H

#include "game_object.h"

struct Box2dComponent : Component {
    float hardness = 2;
    b2PolygonShape shape;
    b2BodyDef bodyDef;
    b2Body *body;

    Box2dComponent(float x, float y, float widthShape, float heightShape, const std::string& name, bool isDynamic) {
        shape.SetAsBox(widthShape / SCALE, heightShape / SCALE); //создаем выпуклую оболочку
        if (isDynamic) {
            bodyDef.type = b2_dynamicBody;
        }

        bindingToShape(name, x, y);
    }

    void bindingToShape([[maybe_unused]] const std::string& name, float x, float y) {
        bodyDef.position.Set(x / SCALE, y / SCALE);
        body = World.CreateBody(&bodyDef);
        body->CreateFixture(&shape, hardness);
//        body->SetUserData((void *) name.c_str());
    }

};

#endif //__PROJECT_BOX2D_H
