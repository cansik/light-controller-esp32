//
// Created by Florian on 28.11.17.
//

#ifndef SILVA_BASESCENE_H
#define SILVA_BASESCENE_H

#include "../BaseController.h"

class BaseScene : public BaseController {
private:

protected:
    explicit BaseScene(const char *name);
    const char *name;

public:
    void setup() override;

    void loop() override;

    const char * getName() const;
};


#endif //SILVA_BASESCENE_H
