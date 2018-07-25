#ifndef MESH_H
#define MESH_H
#include "vertex.h"
#include "texture.h"
#include <vector>
class Mesh{
    public:
        Mesh(std::vector<Vertex> vertices,
             std::vector<unsigned int> indices,
             std::vector<Texture> textures);
        ~Mesh();
    void Draw();
    private:
        unsigned int VAO, VBO, EBO;
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
};

#endif //MESH_H