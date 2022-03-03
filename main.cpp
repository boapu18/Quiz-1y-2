#include <iostream>

using namespace std;
/**
Analisis de Algoritmos
Quiz #1 y #2
María Paula Bolaños Apú
2021026046
**/

class Noticia{
protected:
    string titulo;
    string fecha;
    string reportero;
public:
    Noticia(string, string, string);
    virtual void getInfo();
};

Noticia::Noticia(string elTitulo, string laFecha, string elReportero){
        titulo = elTitulo;
        fecha = laFecha;
        reportero = elReportero;
}
void Noticia::getInfo(){
    cout <<  "Titulo: " << titulo << " Fecha: " << fecha << " Reportero: " << reportero;
}


class NoticiaPaper : public Noticia{
private:
    string foto;
public:
    NoticiaPaper(string, string, string, string);
    void getInfo();
};

NoticiaPaper::NoticiaPaper(string elTitulo, string laFecha, string elReportero, string laFoto) : Noticia(elTitulo, laFecha, elReportero){
    foto = laFoto;
}

void NoticiaPaper::getInfo(){
    Noticia::getInfo();
    cout << " Foto: " << foto << endl;
}

class NoticiaDigital : public Noticia{
private:
    string media;
public:
    NoticiaDigital(string, string, string, string);
    void getInfo();
};

NoticiaDigital::NoticiaDigital(string elTitulo, string laFecha, string elReportero, string laMedia) : Noticia(elTitulo, laFecha, elReportero){
    media = laMedia;
}

void NoticiaDigital::getInfo(){
    Noticia::getInfo();
    cout << " Media: " << media << endl;
}

class NoticiaRadio : public Noticia{
private:
    string url;
public:
    NoticiaRadio(string, string, string, string);
    void getInfo();
};

NoticiaRadio::NoticiaRadio(string elTitulo, string laFecha, string elReportero, string elURL) : Noticia(elTitulo, laFecha, elReportero){
    url = elURL;
}
void NoticiaRadio::getInfo(){
    Noticia::getInfo();
    cout << " URL: " << url << endl;
}




int main(){

    Noticia *laNoticia1 = new NoticiaPaper("Rusia en guerra", "02/03/2022", "María Paula Bolaños", "Direccion a foto");
    Noticia *laNoticia2 = new NoticiaDigital("Rusia en guerra", "02/03/2022", "María Paula Bolaños", "Direccion a media");
    Noticia *laNoticia3 = new NoticiaRadio("Rusia en guerra", "02/03/2022", "María Paula Bolaños", "url");
    Noticia *vector[3] = {laNoticia1, laNoticia2, laNoticia3};
    for (int i = 0; i < 3; i++){
        vector[i]->getInfo();
    }
    return 0;
}
