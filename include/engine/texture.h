#ifndef TEXTURE_H
#define TEXTURE_H
#include <string.h>
class Texture{
    public:
        Texture(std::string fileName);
        ~Texture();
        unsigned int GetID(){return id;}
        static void Enable(int id);
        static void SetActiveTexture(int n);
        unsigned int id;
        std::string type;
};

#endif //TEXTURE_H