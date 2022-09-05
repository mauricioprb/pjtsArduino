class Direcao {
    Servo servo;
          
    public:
        int portaServo;

    Direcao(int porta) {
        portaServo = porta;
    }

    int porta() {
        return servo.attach(portaServo);
    }

    void direita() {
        servo.write(5);
    }

    void esquerda() {
        servo.write(180);
    }

    void centro() {
        servo.write(90);
    }
};