#include "image.h"
#include "video.h"
#include <iostream>
using namespace std;
Video Rebobinar(const Video &V){
    int n = V.size();
    Video Rebobinado(n);
    for(int i=n-1; i>=0; i--) {
        Rebobinado.Insertar(n-i-1, V[i]);
    }
    return Rebobinado;
}

void Instrucciones() {
    cerr << "El programa debe ejecutarse con dos argumentos donde ambos sean directorios" << endl;
    cerr << "Arg1= Directorio desde el que se lee el video" << endl
         << "Argc2= Directorio en el que se guardará el video rebobinado";
}

int main(int argc, char * argv[]){
    if(argc != 3) {
        Instrucciones();
        return 1;
    }

    Video v;
    if(!v.LeerVideo(argv[1])) {
        Instrucciones();
        return 2;
    }

    Video rebobinado = Rebobinar(v);

    if(!rebobinado.EscribirVideo(argv[2],"REBOBINADO-")) {
        Instrucciones();
        return 3;
    }
    return 0;
}
