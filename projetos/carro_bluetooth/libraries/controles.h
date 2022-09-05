#include "motor.h"
#include "direcao.h"

class Controles {
    private:
        Motor *frente;
        Motor *re;
        Direcao *direcao;
  
    public:
        int direita = 5;
        int esquerda = 180;
        int centro = 90;
    
        void controles(char comando) {
            switch (comando) {
                case 'S': // Parar motores
                    frente->desligarMotor();
                    re->desligarMotor();
                    direcao->centro();
                    break;
                    
                case 'F': // Andar para frente
                    frente->ligarMotor();
                    break;
                    
                case 'B': // Andar para trás
                    re->ligarMotor();
                    break;
                    
                case 'L': // Virar para a direita
                    direcao->direita();
                    break;
                    
                case 'R': // Virar para a esquerda
                    direcao->esquerda();
                    break;

                case 'I': // Andar para frente e direita
                    frente->ligarMotor();
                    direcao->direita();
                    break;

                case 'G': // Andar para frente e esquerda
                    frente->ligarMotor();
                    direcao->esquerda();
                break;

                case 'H': // Andar para trás e direita
                    re->ligarMotor();
                    direcao->direita();
                    break;

                case 'J': //  Andar para trás e esquerda
                    re->ligarMotor();
                    direcao->esquerda();
                    break;
            }
        }
};