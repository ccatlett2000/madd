#ifndef MADD_H
#define MADD_H

#include <vector>
#include <chrono>
/** Type Definition for chrono clock shorthand */
typedef std::chrono::high_resolution_clock Clock;
/** Type Definition for chrono time_point shorthand */
typedef Clock::time_point Time;


class GameObject;
class Renderer;
class Camera;
class EventHandler;
class ShaderProgram;
struct GLFWwindow;
class Madd {
public:
    Madd(int width, int height, const char *title);
    ~Madd();
    void Tick();
    void AddObject(GameObject* obj);
    bool StayOpen(){return !close;}
    void Close(){close = true;}
    void SetMainCamera(Camera* cameraObj);
    Camera* GetMainCamera();
    EventHandler* GetEventHandler();
    float GetTime();
    float GetDeltaTime();
    int GetWidth();
    int GetHeight();
    GLFWwindow* GetWindow();
    ShaderProgram* GetGlobalShader();
    void ProcessInput(int key, int action);
private:
    Renderer* render;
    std::vector<GameObject*> objs;
    Camera* mainCamera;
    EventHandler* event;
    void ReloadShader();
    void UpdateDeltaTime();
    void LoadShader();
    std::chrono::duration<float> dTime;
    bool close;
    int width;
    int height;
    float timeScale;
    Time lastFrame;
    ShaderProgram* globalShader;
};

#endif // MADD_H