#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// Generar pregunta nueva
void generateQuestion(int& num1, int& num2) {
    num1 = rand() % 10 + 1;  // Número aleatorio entre 1 y 10
    num2 = rand() % 10 + 1;  // Número aleatorio entre 1 y 10
    cout << "Cuanto es " << num1 << " * " << num2 << "?" << endl;
}

// Mensaje de retroalimentación
string getRandomMessage(const vector<string>& messages) {
    int index = rand() % messages.size();
    return messages[index];
}

int main() {
    srand(time(0));  // Inicializar la semilla para generación de números aleatorios

    vector<string> correctMessages = { "Muy bien!", "Excelente!", "Buen trabajo!", "Bravo, eres un campeon!", "¡Fantastico!", "¡Sigue asi!" };
    vector<string> incorrectMessages = { "Uf! No es correcta, por favor intenta de nuevo.", "Incorrecto. Intenta una vez más.", "No te rindas! Trata de nuevo.", "Tú puedes, sigue intentando.", "¡Casi! Intentalo de nuevo." };

    int correctAnswers = 0;
    int num1, num2, answer;

    for (int i = 0; i < 15; ++i) {
        generateQuestion(num1, num2);
        cin >> answer;

        if (answer == num1 * num2) {
            cout << getRandomMessage(correctMessages) << endl;
            ++correctAnswers;
        }
        else {
            cout << getRandomMessage(incorrectMessages) << endl;
            --i;  // Mantener la misma pregunta
        }
    }

    int percentage = (correctAnswers * 100) / 15;
    if (percentage <= 70) {
        cout << "Obtuviste un " << percentage << "% de respuestas correctas. Sugiero que repitas el ejercicio." << endl;
    }
    else {
        cout << "Obtuviste un " << percentage << "% de respuestas correctas. ¡Felicitaciones! Puedes continuar al siguiente nivel." << endl;
    }

    return 0;
}