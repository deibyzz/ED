
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
     * @post Libera los recursos ocupados por el video. El video destruido no podrá volver a usarse, salvo que se vuelva a realizar sobre él otra operación de construcción.
     */
    ~Video();

    /**
     * @brief Operador de indexación
     * @param V Referencia al video a asignar
     * @post Destruye el video que llama al operador de asignación y copia la información de V
     * @return una referencia al objeto implícito
     */
    Video &operator=(const Video &V);

    /**
     * @brief Metodo para consultar el numero de fotogramas de un video
     * @return Numero de fotogramas del video
     * @post Consulta el size del vector de imagenes y devuelve el numero de fotogramas que contiene
     */
    int size() const;

    /**
     * @brief Operador para asignar un fotograma al video
     * @param foto Posición del vector que queremos consultar
     * @pre 0 <= foto < size()
     * @post Consulta la imagen asociada al fotograma foto-ésimo del vídeo
     * @return La imagen asociada al fotograma foto-ésimo del vídeo
     */
    Image &operator[](int foto);

    /**
     * @brief Operador para consultar un fotograma del vídeo
     * @param foto Posición del vector que queremos consultar
     * @pre 0 <= foto < size()
     * @post Consulta la imagen asociada al fotograma foto-ésimo del vídeo
     * @return La imagen asociada al fotograma foto-ésimo del vídeo
     */
    const Image &operator[](int foto)const;

    /**
    * @brief Metodo para asignar un nuevo fotograma al video
    * @param k Posición del vector donde insertar la imagen
    * @param I Referencia a la imagen a insterar
    * @pre 0 <= k < size()
    * @post Devuelve el video modificado con el nuevo fotograma
    */
    void Insertar(int k, const Image &I);

    /**
    * @brief Metodo para eliminar el fotograma de la posición dada por un entero k.
    * @param k Posición del vector donde borrar la imagen
    * @pre 0 <= k < size()
    * @post Devuelve el video modificado con un fotograma menos
    */
    void Borrar(int k);

    /**
    * @brief Leer un vídeo de disco.
    * @param path La ruta al directorio donde se almacena una secuencia temporal de fotogramas
    * @pre El directorio al que lleva path debe contener una secuencia temporal de fotogramas
    * @post Devuelve true si la lectura tiene éxito y false en caso contrario
    */
    bool LeerVideo(const string & path);

    /**
    * @brief Escribe un video en el disco
    * @param path la ruta al directorio donde se almacenará la secuencia temporal de fotogramas
    * @param prefijo el nombre que se le asignará a cada fotograma acompañado de 01,...,0n según el número de fotograma
    * @pre El directorio especificado en `path` debe contener la secuencia de fotogramas con nombres  que sigan el
    * formato <prefijo>_01.pgm, <prefijo>_02.pgm, ..., <prefijo>_0n.pgm, donde n es el número de fotogramas.
    * @post Devuelve true si la lectura tiene éxito y false en caso contrario
    *
    * @example
    * Video v;
    * v.EscribirVideo("usuario/videos/ejemplo/", "video_ejemplo");
    */
    bool EscribirVideo(const string & path, const string &prefijo)const;
};

#endif //PRACTICA2_VIDEO_H
