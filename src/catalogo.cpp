#include<map>

std::map < long long int , int > catalogo;

void aggiungi(long long int id) {
    catalogo[id]++;
}

void togli(long long int id) {
    catalogo[id]--;
}

int conta(long long int id) {
    return catalogo[id];
}

