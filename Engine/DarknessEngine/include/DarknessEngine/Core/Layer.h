#ifndef DE_LAYER_H
#define DE_LAYER_H

#include <string>

#include "Events/Event.hpp"

namespace DarknessEngine{
    class Layer{
    public:
        Layer(const std::string& name = "LAYER");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onImGuiDraw() {}
        virtual void onEvent(Event& event) {}
        
        inline const std::string& getName() const { return m_nameDBG; }
    protected:
        std::string m_nameDBG;   
    };
}

#endif