class Motor {
    public:
        int portaArduino;

    Motor(int porta) {
        portaArduino = porta;
    }

    int porta() {
        return portaArduino;
    }

    void ligarMotor() {
        digitalWrite(portaArduino, HIGH);
    }

    void desligarMotor() {
        digitalWrite(portaArduino, LOW);
    }
};