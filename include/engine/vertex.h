#ifndef VERTEX_H
#define VERTEX_H
#include <glm/glm.hpp>
struct Vertex{
    Vertex(glm::vec3 Position,
           glm::vec3 Normal,
           glm::vec2 TexCoords):
           Position(Position),
           Normal(Normal),
           TexCoords(TexCoords){}
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};
#endif //VERTEX_H
