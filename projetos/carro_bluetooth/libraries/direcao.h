class Direcao {
    // Instanciar objeto de controle do servo
    Servo servo;
          
    // Variável para definir a porta do servo
    public:
        int portaServo;

    // Construtor da classe definindo parâmetro para porta
    Direcao(int porta) {
        portaServo = porta;
    }

    // Função para retornar em qual porta está o objeto
    int porta() {
        return servo.attach(portaServo);
    }

    // Função para girar o servo para direita
    void direita() {
        servo.write(5);
    }

    // Função para girar o servo para esquerda
    void esquerda() {
        servo.write(180);
    }

    // Função para centralzar o servo
    void centro() {
        servo.write(90);
    }
};