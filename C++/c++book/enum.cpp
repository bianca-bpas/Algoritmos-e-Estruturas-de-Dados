#include <iostream>
#include <string>

class TrafficLight {
public:
    // Definindo uma enumeração dentro da classe
    enum State {
        RED,    // 0
        YELLOW, // 1
        GREEN   // 2
    };

private:
    State currentState;  // Variável que mantém o estado atual

public:
    // Construtor para definir o estado inicial
    TrafficLight(State initialState = RED) : currentState(initialState) {}

    // Função para obter o nome do estado como string
    std::string getState() const {
        switch (currentState) {
            case RED: return "Red";
            case YELLOW: return "Yellow";
            case GREEN: return "Green";
            default: return "Unknown";
        }
    }

    // Função para alterar o estado
    void changeState() {
        // Ciclo entre os estados: Red -> Yellow -> Green -> Red
        currentState = static_cast<State>((currentState + 1) % 3);
    }

    // Função para mostrar o estado atual
    void showCurrentState() const {
        std::cout << "Current Traffic Light State: " << getState() << std::endl;
    }
};

int main() {
    // Criando um objeto TrafficLight com estado inicial GREEN
    TrafficLight light(TrafficLight::GREEN);

    // Exibindo o estado atual
    light.showCurrentState();

    // Alterando o estado
    light.changeState();
    light.showCurrentState();

    light.changeState();
    light.showCurrentState();

    light.changeState();
    light.showCurrentState();

    return 0;
}
