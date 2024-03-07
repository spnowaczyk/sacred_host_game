//
// Created by s.nowaczyk on 07.03.2024.
//

#ifndef SACRED_HOST_MOUSECONTROLLER_H
#define SACRED_HOST_MOUSECONTROLLER_H


class MouseController {
public:
    static void MousePositionQuery(int *mouseX, int *mouseY);
    static void MouseClickQuery(bool *mouseClickFlag);
};


#endif //SACRED_HOST_MOUSECONTROLLER_H
