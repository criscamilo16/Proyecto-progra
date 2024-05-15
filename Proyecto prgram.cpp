#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct Fecha{
    int anio;
    int mes;
    int dia;
    
};
struct temperatura{
    float tem;
    Fecha fecha;
};
//funcion que determina si los datos proporcinados entran en el lapso de tiempo//
bool examinarLapso(const Fecha& fecha,const Fecha& fechaInicio,const Fecha& fechaFin){
    if(fecha.anio<fechaInicio.anio || fecha.anio>fechaFin.anio ){
        return false;
    }
     if(fecha.mes<fechaInicio.anio || fecha.mes>fechaFin.anio ){
        return false;
}
 if(fecha.dia<fechaInicio.anio || fecha.dia>fechaFin.anio ){
        return false;
 }return false;
}
int main(){
    fstream archivo("datos_metereologicos.txt");
    float tempMaxima=100.0;
    float tempMinima=-100.0;
    temperatura dato;
Fecha fechaInicio,fechaFin;
cout<<"ingrese la fecha de inicio del lapso que desea verificar: "<<endl;
cin>>fechaInicio.anio>>fechaInicio.mes>>fechaInicio.dia;
cout<<"ingrese la fecha de fin del lapso que desea verificar: "<<endl;
cin>>fechaFin.anio>>fechaFin.mes>>fechaFin.dia;
//abre el archivo//
if(archivo.is_open()){
    string linea;
    //estas lineas meten los datos del archivo txt a las variables para su inspeccion//
    while(getline(archivo,linea)){
         stringstream ss(linea);
            ss >> dato.fecha.anio >> dato.fecha.mes >> dato.fecha.dia >> dato.tem;
//inspeccion de temperaturas//
if(examinarLapso(dato.fecha,fechaInicio,fechaFin)){
    if(dato.tem>tempMaxima){
        tempMaxima=dato.tem;
    }if(dato.tem<tempMinima){
        tempMinima=dato.tem;
    }
}
 }//salida de datos//
    archivo.close();
    cout<<"Temperatura Mayor Registrada: "<<tempMaxima<<"°c"<<endl;
    cout<<"Temperatura Menor Registrada: "<<tempMinima<<"°c"<<endl;
}else{
    cout<<"No se pudo abrir el archivo"<<endl;
}
return 0;
}
