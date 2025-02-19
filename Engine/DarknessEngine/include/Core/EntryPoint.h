#ifndef DE_ENTRY_POINT_H
#define DE_ENTRY_POINT_H

#include "Kernel.h"

extern DarknessEngine::Application* DarknessEngine::CreateApplication();

int main(int argc, char** argv){
    auto app = DarknessEngine::CreateApplication();
    app->run();
    delete app;
    return 0;
}

#endif