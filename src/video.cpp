
#include "video.h"

#include <algorithm>
#include <assert.h>
//COMPLETAR POR EL ESTUDIANTE

void read_directory(const std::string& name, vector<string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

        v.push_back(dp->d_name);

    }
    closedir(dirp);
}

/**************************************************/
Video::Video() {
    Video(0);
}


/**************************************************/
Video::Video(int n){
    assert(n >= 0);
    seq.reserve(n);
}
/**************************************************/
Video::Video(const Video &V){
    seq=V.seq;
}
/**************************************************/
Video::~Video() {
    seq.clear();
}
/**************************************************/
Video &Video::operator=(const Video &V){
    seq=V.seq;
}
/**************************************************/
int Video::size() const{
    return(seq.size());
}
/**************************************************/
Image &Video::operator[](int foto){
    assert (foto >= 0 && foto < seq.size());
    return(seq[foto]);
}

const Image &Video::operator[](int foto)const{
    assert (foto >= 0 && foto < seq.size());
    return(seq[foto]);
}

void Video::Insertar(int k, const Image &I){
    seq.insert(seq.begin()+k,I);
}

void Video::Borrar(int k){
    seq.erase(seq.begin() + k);
}

bool Video::LeerVideo(const string &path){

    //USA read_directory PARA LEER los fichero de un directorio
    bool exito=true;
    vector<string> v;
    read_directory(path, v);

    std::sort(v.begin(), v.end());

    Image imagen;
    int i = 2;
    seq.clear();

    while(i < v.size() && exito) {
        string nombre = path + v[i];
        exito = imagen.Load(nombre.c_str());
        seq.push_back(imagen);
        ++i;
    }

    return(exito);
}

bool Video::EscribirVideo(const string & path, const string &prefijo)const{

    bool exito=true;
    std::filesystem::path filepath =path;
    bool filepathExists = std::filesystem::is_directory(filepath);

    if (!filepathExists){

        bool created_new_directory= std::filesystem::create_directory(filepath);
        if (!created_new_directory){
            cout<<"No se puede crear el directorio "<<path<<endl;
            return false;
        }
        else{
            cout<<" Se ha creado el directorio "<< path<<endl;
        }
    }

    Image imagen;
    int i = 0;
    while(exito && (i < seq.size())) {
        imagen = seq.at(i);
        string ruta = path + "/" + prefijo + "_0" + to_string(i);
        exito = imagen.Save(ruta.c_str());
        ++i;
    }

    return exito;
}
