#include "../include/Camera.h"
#include "../include/Placar.h"
#include <iostream>
#include <thread>
#include <chrono>

Camera::Camera(int x, int y) : Coletavel(x, y, "📷"), ofuscada(false) {}

/*void Camera::aplicarEfeito(Placar& placar){
    Para futuro
}*/

std::string Camera::getTipo() const {return "Camera";}

bool Camera::estaOfuscada() const {return this->ofuscada;}
