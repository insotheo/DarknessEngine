#ifndef DE_APPLICATION_H
#define DE_APPLICATION_H

namespace DarknessEngine{
    class Application{
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application* CreateApplication(); // on client
}

#endif