#pragma once
#include "entity_array.h"



class System {

    public:
        EntityArray entities;

    public:
        virtual ~System() = default;
        virtual void update(float dt) = 0;
        virtual void draw() = 0;

};

class TransformSystem : public System {

    public:
        void update(float dt) override;        
        void draw() override;

};

