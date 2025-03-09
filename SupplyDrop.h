#ifndef SUPPLYDROP_H
#define SUPPLYDROP_H

#include "Payload.h"
#include "raylib.h"

// Ärvad klass
class SupplyDrop : public Payload {
    public:
        Texture2D texture;
        float rotation;
        SupplyDrop(float x,float y,float radius,float speedX, float speedY,const std::string& payloadName, const std::string& texturePath);
    
        void Update(float deltaTime, float windSpeed) override;
        void Draw() const override;
    
        ~SupplyDrop() override;
    
        };

#endif