#include "camera.h"
#include "madd.h"
#include <glm/gtc/matrix_transform.hpp>
Camera::Camera(){
    cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)Madd::GetInstance().GetWidth() / Madd::GetInstance().GetHeight(), 0.1f, 100.0f);
}

Camera::~Camera(){

}

glm::mat4* Camera::GetView(){
    return &view;
}

glm::mat4* Camera::GetProjection(){
    return &projection;
}

void Camera::UpdateProjection(){
    projection = glm::perspective(glm::radians(45.0f), (float)Madd::GetInstance().GetWidth() / Madd::GetInstance().GetHeight(), 0.1f, 100.0f);
}

void Camera::LookAt(glm::vec3 pos){
    cameraFront = glm::normalize(pos);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::MovePosition(glm::vec3 movementVector){
    cameraPos += movementVector;
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    //cameraFront += movementVector*context->GetDeltaTime();
}

void Camera::SetPosition(glm::vec3 pos){

}

void Camera::SetPitchAndYaw(float pitch, float yaw){
    glm::vec3 front;
    front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    front.y = sin(glm::radians(pitch));
    front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    cameraFront = glm::normalize(front);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}