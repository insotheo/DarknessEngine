#ifndef DE_LAYER_STACK_H
#define DE_LAYER_STACK_H

#include <vector>

#include "Core/Layer.h"

namespace DarknessEngine{
    class LayerStack{
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* overlay);
        void popLayer(Layer* layer);
        void popOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_layers.end(); }
    private:
        std::vector<Layer*> m_layers;
        unsigned int m_insIndx = 0; //stands for insert index
    };
}

#endif