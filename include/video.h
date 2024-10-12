
#ifndef PRACTICA2_VIDEO_H
#define PRACTICA2_VIDEO_H
#include "image.h"
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cmath>
#include <string>
#include <filesystem>
#include <iostream>
using namespace std;

//Lee los ficheros de un directorio
//name es el nombre del directorio
//v el vector donde almacena los nombres

void read_directory(const std::string& name, vector<string>& v);


class Video {
    /**
      @page repVideo Representación del TDA Video .

      @section invVideo Invariante de la representación.

      Un objeto válido 1 del TDA Video debe cumplir
        seq >= 0

      @section faVideo Función de abstracción

      Un objeto válido 1 del TDA Video representa un video en niveles de gris, de las dimensiones de las imagenes en la secuencia.

    **/
private:
    /**
     * @brief Vector de imágenes
     *
     * seq es un objeto de la clase vector, es un contenedor dinámico de una secuencia de imágenes que permite acceder a cualquiera de ellas por su posiciṕn.
     **/
    vector<Image> seq;
public:
    /**
     * @brief Constructor por defecto
     * @post Genera una instancia de la clase Video con una secuencia de 0 imágenes
     * @return Video, el objeto creado
     */
    Video();

    /**
     * @brief Constructor con parámetros
     * @param n Número de imágenes del video
     * @pre n >= 0
     * @post Genera una instancia de la clase Video con una secuencia de n imágenes vacías
     * @return Video, el objeto creado
     */
    Video(int n);

    /**
     * @brief Constructor de copia
     * @param V Referencia al video original a copiar
     * @post Genera una instancia de la clase Video igual a V
     * @return Video, el objeto creado
     */
    Video(const Video &V);

    /**
     * @brief Destructor
     * @post El objeto se destruye eliminando todas las imagenes de la secuencia
     * @return void
     */
    ~Video();

    /**
     * @brief Operador de asignación
     * @param V Referencia al video a asignar
     * @post Destruye el video que llama al operador de asignación y copia la información de V
     * @return una referencia al objeto implícito
     */
    Video &operator=(const Video &V);

    int size() const;

    Image &operator[](int foto);

    const Image &operator[](int foto)const;

    void Insertar(int k, const Image &I);

    void Borrar(int k);

    bool LeerVideo(const string & path);

    bool EscribirVideo(const string & path, const string &prefijo)const;
};

#endif //PRACTICA2_VIDEO_H
