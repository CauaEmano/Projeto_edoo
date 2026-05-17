#include "../include/Camera.h"
#include "../include/Placar.h"
#include <iostream>
#include <thread>
#include <chrono>

Camera::Camera(int x, int y) : Coletavel(x, y, "📷"), ofuscada(false) {}

void Camera::aplicarEfeito(Placar& placar){
    placar.incrementarCameras();
    this->ofuscada = true;

    cout << "Flash da câmera!\n";
    cout << "████████████████████████████████\n";
    cout << "████████████████████████████████\n";
    cout << "████████████████████████████████\n";

    this_thread::sleep_for(chrono::seconds(1));

    this->ofuscada = false;
    cout << "Câmeras coletadas: " << placar.getCameras() << "/3\n";
}

std::string Camera::getTipo() const {return "Camera";}

bool Camera::estaOfuscada() const {return this->ofuscada;}
