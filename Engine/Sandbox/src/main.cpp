#define DE_LOG_ENABLED

#include <DarknessEngine.h>

class Sandbox : public DarknessEngine::Application{
public:
    Sandbox(){

    }

    ~Sandbox(){

    }
};

DarknessEngine::Application* DarknessEngine::CreateApplication(){
    return new Sandbox();
}