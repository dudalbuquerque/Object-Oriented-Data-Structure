//O arquivo [`notas_alunos.txt`](./src/notas_alunos.txt) possui uma lista de registros, cada um contendo um nome, um número de matrícula e uma nota.
//* Definir uma struct Aluno para esse tipo de registro
//* Ler esse arquivo para um array de structs do tipo Aluno
//* Calcular a média da turma
//* Imprimir a lista de alunos com nota maior ou igual à média

#include <iostream>
#include <string>
using namespace std;

// Definindo a estrutura Aluno
struct Aluno {
    string nome;
    int matricula;
    int nota;
};

int main(){
    Aluno* alunos = new Aluno;

    string nome = "none";
    while(nome != "END"){
        cout << "Enter student name: ";
        cout << "Enter registration: ";
        cout << "Enter grade: ";

    }

    return 0;
}