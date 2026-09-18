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
    cout << "cuantos puntos desea registrar: ";
    int cantidad;
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++) {
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
PuntoTrayectoria* obtenerPuntoMasAlejado( PuntoTrayectoria puntos[], int cantidadPuntos) {
    if (cantidadPuntos <= 0) {
        return nullptr; 
    }
         
        PuntoTrayectoria* puntoCritico = &puntos[0];
        float mayorDistancia = calcularDistancia(*puntoCritico);

        for (int i = 1; i < cantidadPuntos; i++){
        float distanciaActual = calcularDistancia(puntos[i]);
        if (distanciaActual > mayorDistancia){
            mayorDistancia = distanciaActual;
            puntoCritico = &puntos[i];
        }
    }
    return puntoCritico;

}
void mostrarPunto(const PuntoTrayectoria& p){
    cout << "ID: " << p.Id << endl;
    cout << "Nombre: " << p.Nombre << endl;
    cout << "Coordenadas: (" << p.Coordenadas[0] << ", " << p.Coordenadas[1] << ", " << p.Coordenadas[2] << ")" << endl;
    cout << "Distancia al origen: " << p.DistanciaOrigen << endl;
    cout << "Clasificacion: " << p.Clasificacion << endl;
}
void corregirCoordenadas(PuntoTrayectoria &punto,float desplazamientoX,float desplazamientoY,float desplazamientoZ){
    cout << "Ingrese el desplazamiento en X: ";
    cin >> desplazamientoX;
    cout << "Ingrese el desplazamiento en Y: ";
    cin >> desplazamientoY;
    cout << "Ingrese el desplazamiento en Z: ";
    cin >> desplazamientoZ;
    punto.Coordenadas[0] += desplazamientoX;
    punto.Coordenadas[1] += desplazamientoY;
    punto.Coordenadas[2] += desplazamientoZ;
}
void generarReporte(PuntoTrayectoria puntos[], int cantidadPuntos) {
    int cercanos = 0, intermedios = 0, lejanos = 0, extremos = 0;
    float sumaDistancias = 0.0;

    for (int i = 0; i < cantidadPuntos; i++) {
        calcularDistancia(puntos[i]);
        clasificarPunto(puntos[i]);
        sumaDistancias += puntos[i].DistanciaOrigen;

        if (puntos[i].Clasificacion == "CERCANO") {
            cercanos++;
        } else if (puntos[i].Clasificacion == "INTERMEDIO") {
            intermedios++;
        } else if (puntos[i].Clasificacion == "LEJANO") {
            lejanos++;
        } else if (puntos[i].Clasificacion == "EXTREMO") {
            extremos++;
        }
    }


}

int main (){
    PuntoTrayectoria punto;
    registrarPunto(punto);
    calcularDistancia(punto);
    clasificarPunto(punto);
    
    mostrarPunto(punto);
    corregirCoordenadas(punto,0,0,0);
    cout << "la informacion del punto despues de la correcion es: " << endl;
     mostrarPunto(punto);
    return 0;

    




  
    

}