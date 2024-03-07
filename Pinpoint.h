//
// Created by Admin on 07.03.2024.
//

#ifndef SACRED_HOST_PINPOINT_H
#define SACRED_HOST_PINPOINT_H

#include "VisualEffect.h"


class Pinpoint : public VisualEffect{
public:
    Pinpoint(int tileX, int tileY);
    ~Pinpoint();

    void Update() override;
    void Render() override;



};


#endif //SACRED_HOST_PINPOINT_H
