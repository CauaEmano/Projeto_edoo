# Gisele Bündchen VS As Forças do Mal — C++

Reescrita em C++ orientado a objetos do jogo original desenvolvido em Python.
Sem GUI, sem persistência — interface 100% por linha de comando.

---

## Estrutura do projeto

```
gisele_cpp/
├── include/
│   ├── Coletavel.hpp   # Classe abstrata base
│   ├── Banana.hpp
│   ├── Camera.hpp
│   ├── Rosa.hpp
│   ├── Placar.hpp
│   ├── Gisele.hpp
│   ├── Fase.hpp
│   └── Jogo.hpp
├── src/
│   ├── Coletavel.cpp
│   ├── Banana.cpp
│   ├── Camera.cpp
│   ├── Rosa.cpp
│   ├── Placar.cpp
│   ├── Gisele.cpp
│   ├── Fase.cpp
│   └── Jogo.cpp
├── main.cpp
└── README.md
```

---

## Como compilar

### Requisitos
- Compilador com suporte a **C++17** (g++ 7+ ou clang++ 5+)

### Compilação (Linux / macOS)
```bash
g++ -std=c++17 -Wall src/*.cpp main.cpp -o gisele
```

### Compilação (Windows — MinGW)
```bash
g++ -std=c++17 -Wall src\*.cpp main.cpp -o gisele.exe
```

---

## Como executar

```bash
./gisele        # Linux / macOS
gisele.exe      # Windows
```

---

## Controles

| Tecla | Ação             |
|-------|------------------|
| `p`   | Pular            |
| `a`   | Agachar          |
| `q`   | Sair do jogo     |

---

## Mecânica

- A passarela tem **700 metros** de extensão.
- A velocidade aumenta a cada **10 segundos** de jogo.
- **Banana** → zera as rosas; 3 bananas = game over.
- **Câmera** → ofusca a tela por 1 segundo; 3 câmeras = game over.
- **Rosa** → adiciona pontos ao placar final.