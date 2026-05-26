#include "../include/Camera.h"
#include "../include/Placar.h"
#include <iostream>
#include <thread>
#include <chrono>

Camera::Camera(int x, int y) : Coletavel(x, y, "📷"), ofuscada(false) {}

void Camera::aplicarEfeito(Placar& placar){
    placar.incrementarCameras();
    this->ofuscada = true;

    std::cout << "Flash da câmera!\n";
    std::cout << "████████████████████████████████\n";
    std::cout << "████████████████████████████████\n";
    std::cout << "████████████████████████████████\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));   // Pausa a execução da thread atual por 1 segundo

    this->ofuscada = false;
    std::cout << simbolo << " Câmeras coletadas: " << placar.getCameras() << "/3\n";
}

bool Camera::estaOfuscada() const { return this->ofuscada; }
