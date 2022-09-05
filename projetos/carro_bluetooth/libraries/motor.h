class Motor {
    // Variável do pino como pública para acesso das funções
    public:
        int portaArduino;

    // Construtor da classe definindo parâmetro para porta
    Motor(int porta) {
        portaArduino = porta;
    }

    // Função para retornar em qual porta está o objeto
    int porta() {
        return portaArduino;
    }

    // Função para ligar o motor conforme o pino definido pelo usuário na função main
    void ligarMotor() {
        digitalWrite(portaArduino, HIGH);
    }

    // Função para desligar o motor conforme o pino definido pelo usuário na função main
    void desligarMotor() {
        digitalWrite(portaArduino, LOW);
    }
};