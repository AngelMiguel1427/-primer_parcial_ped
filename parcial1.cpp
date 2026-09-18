#include <iostream>
#include <cmath>
using namespace std;


struct PuntoTrayectoria{
    int Id;
    string Nombre;
    float Coordenadas[3];
    float DistanciaOrigen;
    string Clasificacion;
    float capacidadMaxima = 10;
};

void registrarPunto(PuntoTrayectoria &punto){
    cout << "Ingrese el ID del punto: ";
    cin >> punto.Id;
    cout << "Ingrese el nombre del punto: ";
    cin >> ws;
    getline(cin, punto.Nombre);
    cout << "Ingrese las coordenada (x) del punto: ";
    cin >> punto.Coordenadas[0];
    cout << "Ingrese las coordenada (y) del punto: ";
    cin >> punto.Coordenadas[1];
    cout << "Ingrese las coordenada (z) del punto: ";
    cin >> punto.Coordenadas[2];
    
}

float calcularDistancia(PuntoTrayectoria &punto){
    float distanciaOrigen = sqrt(pow(punto.Coordenadas[0], 2) + pow(punto.Coordenadas[1], 2) + pow(punto.Coordenadas[2], 2));//use este metodo por que era mas efieciente
    punto.DistanciaOrigen = distanciaOrigen;
    return distanciaOrigen;
}

void clasificarPunto(PuntoTrayectoria &punto){
    if (punto.DistanciaOrigen <= 5) {
        punto.Clasificacion = "CERCANO";
    } else if (punto.DistanciaOrigen > 5 && punto.DistanciaOrigen <= 10) {
        punto.Clasificacion = "INTERMEDIO";
    } else if (punto.DistanciaOrigen > 10 && punto.DistanciaOrigen <= 20) {
        punto.Clasificacion = "LEJANO";
    } else {
        punto.Clasificacion = "EXTREMO";
    }
}

int main (){
    PuntoTrayectoria punto;
    registrarPunto(punto);
    float distanciaOrigen = calcularDistancia(punto);
    clasificarPunto(punto);
    cout << "La distancia del punto respecto al origen es: " << distanciaOrigen << endl;
    cout << "La clasificacion del punto es: " << punto.Clasificacion << endl;



}