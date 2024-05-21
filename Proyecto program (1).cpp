//Se hizo uso de el codigo acssi para la salida de caracteres especiales. Estructura: char(numero del caracter especial)
#include <iostream>
#include <iomanip> //setw()
#include <fstream> //lectura y escritura de archivos
#include <sstream> //Obtencion de las lineas de texto a modo de string
#include <string> // Manejo de strings

using namespace std;

//struc para almacenar las fechas y buscar el nombre del mes correspondiente al numero

struct fecha {
    int anio, mes, dia;
    
    //constructor por parametros del struc
    
    fecha(int anio, int mes, int dia) { 
        this->anio = anio;
        this->mes = mes;
        this->dia = dia;
    }
    
    //Funcion para obtener el nomre del mes dependiendo del número correspondiente
    
    string obtenerNombreMes() {
        switch (mes) {
            case 1: return "Enero";
            case 2: return "Febrero";
            case 3: return "Marzo";
            case 4: return "Abril";
            case 5: return "Mayo";
            case 6: return "Junio";
            case 7: return "Julio";
            case 8: return "Agosto";
            case 9: return "Septiembre";
            case 10: return "Octubre";
            case 11: return "Noviembre";
            case 12: return "Diciembre";
        }
    }
};

//Struct para almacenar los datos de un año correspondiente para la realización de salidas y distintas operaciones

struct datosAnio {
    int anio, mes;
    float temperatura, porcentHumedad;
    string clima;
    
    //constructor por parametros del struc
    
    datosAnio(int anio = 0, int mes = 0, float temperatura = 0, float porcentHumedad = 0, string clima = "") {
        this->anio = anio;
        this->mes = mes;
        this->temperatura = temperatura;
        this->porcentHumedad = porcentHumedad;
        this->clima = clima;
    }
};

//Struct que almacena los datos del archvio txt para su posterior utilizacion en las disitintas opciones que ofrece la aplicacion

struct condicionMeteorologica {
    string clima;
    float presionAtm;
    float humedad;
    float velocidadViento;
    float temperatura;
    int anio;
    int mes;
    int dia;
    
    //Constructor vacio del struct para poder inicializarlo sin necesidad de ingresar los datos
    
    condicionMeteorologica(){};
    
    //constructor por parametros del struc

    condicionMeteorologica(int anio, int mes, int dia, float temper, float humedad, float velVient, float presion, string clima){
        this->presionAtm = presion;
		this->clima = clima;
        this->humedad = humedad;
        this->velocidadViento = velVient;
        this->temperatura = temper;
        this->anio = anio;
        this->mes = mes;
        this->dia = dia;
    }
};

//Funicion para la cracion o edicion de un archivo txt el cual registra a los usuarios

void registrarUsuario(string user, string password) {
    ofstream archivo("usuarios.bin", ios_base::app | ios_base::binary);

    if (archivo.is_open()) {
        // Obtiene el tamanio de la cadena del nombre de user
        int tamUser = static_cast<int>(user.size());
        // Obtiene el tamanio de la cadena de la password
        int tamPassword = static_cast<int>(password.size());

        // Escribe el tamanio del nombre de usuario en el archivo
        archivo.write((char*)&tamUser, sizeof(int));
        // Escribe los caracteres del nombre de usuario en el archivo
        archivo.write(user.c_str(), tamUser);
        // Escribe el tamanio de la contraseña en el archivo
        archivo.write((char*)&tamPassword, sizeof(int));
        // Escribe los caracteres de la contraseña en el archivo
        archivo.write(password.c_str(), tamPassword);

        // Cierra el archivo
        archivo.close();
        // Muestra un mensaje indicando que el usuario se registro exitosamente
        cout << "Usuario registrado exitosamente" << endl;
    } else {
        // Muestra un mensaje de error si el archivo no se pudo abrir
        cout << "No se pudo abrir el archivo o no existe actualmente una base de datos" << endl;
    }
}

bool iniciarSesion(string user, string password) {
    ifstream archivo("usuarios.bin", ios_base::in | ios_base::binary);

    if (archivo.is_open()) {
        while (true) {
            int tamUser, tamPassword;

            // Lee el tamaño del nombre de usuario desde el archivo
            archivo.read((char*)&tamUser, sizeof(int));
            if (archivo.eof()) break; // Si se alcanza el fin del archivo, se sale del bucle

            // Lee los caracteres del nombre de usuario
            string usuario(tamUser, '\0');
            archivo.read(&usuario[0], tamUser);

            // Lee el tamaño de la contraseña desde el archivo
            archivo.read((char*)&tamPassword, sizeof(int));

            // Lee los caracteres de la contraseña
            string contrasenia(tamPassword, '\0');
            archivo.read(&contrasenia[0], tamPassword);

            // Compara el nombre de usuario y la contraseña leídos con los proporcionados
            if (user == usuario && password == contrasenia) {
                archivo.close(); // Cierra el archivo
                return true; // Retorna true si las credenciales coinciden
            }
        }
        archivo.close(); // Cierra el archivo al final del bucle
    } else {
        // Muestra un mensaje de error si no se pudo abrir el archivo
        cout << "No se pudo abrir el archivo." << endl;
    }
    return false; // Retorna false si no se encuentran coincidencias
}

//Funcion para leer y almacenar los datos del archivo txt en un arreglo
void leerArchivo(condicionMeteorologica DatosMet[], int& cantidadDatos) {
	//declaracion de datos maximos que puede almacenar el programa
    const int datosMaximos = 10000;
    cantidadDatos = 0;
    
    //Lectura del archivo datos meteorologicos.txt
    ifstream entrada("datos_meteorologicos.txt");
    //Verificacion de correcta apertura
    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    string linea;
    
    //lectura de la primera linea, no se almacena ya que es un encabezado
    getline(entrada, linea);
    
    //Lectura de los datos
    while (getline(entrada, linea)) {
    	//obtencion de linea por linea
        stringstream meteorologico(linea);
        string fecha, temperaturaStr, humedadStr, velocidadVientoStr, presionStr, estadoClima;
        //Lectura de la fecha para realizar la revision de si se encuentra en el formato especificado YYYY-MM-DD
        meteorologico >> fecha;
        
        //Encuentra los "-" y devuelve su posicion
        size_t primerGuion = fecha.find('-');
        size_t segundoGuion = fecha.find('-', primerGuion + 1);
        //Verifica mediante el npos (posicion inexistente) para verificar si se encuentra en el formato especificado
        if (primerGuion == string::npos || segundoGuion == string::npos) {
            cout << "Formato de fecha inv" << char(160) << "lido: " << fecha << endl;
        } else {
        	//Declaracion de anio, mes, dia en las posiciones hasta las que se encontraron los "-"
	        string anioStr = fecha.substr(0, primerGuion);
	        string mesStr = fecha.substr(primerGuion + 1, segundoGuion - primerGuion - 1);
	        string diaStr = fecha.substr(segundoGuion + 1);
	        
	        //Casteo de string a int para ejecutar las funciones de comparacion
	        int anio = stoi(anioStr);
	        int mes = stoi(mesStr);
	        int dia = stoi(diaStr);
	        
	        //lecutra de los demas datos del archivo
	        meteorologico >> temperaturaStr >> humedadStr >> velocidadVientoStr >> presionStr;
	        //castep de string a float para la ejecucion del as demas funciones
	        float temperatura = stof(temperaturaStr);
	        float humedad = stof(humedadStr);
	        float velocidadViento = stof(velocidadVientoStr);
	        float presion = stof(presionStr);
	        
	        getline(meteorologico, estadoClima);
	        //Almacenamiento de los datos en un arreglo de struct 
	        DatosMet[cantidadDatos] = condicionMeteorologica(anio, mes, dia, temperatura, humedad, velocidadViento, presion, estadoClima);
	        //Cuantificacion de los datos
	        cantidadDatos++;
    	}
    }
    //Cerrar archivo
    entrada.close();
}

//Funcion para volver a escribir todos los datos del archivo txt despues de su organizacon por fechas
void escribirArchivo(condicionMeteorologica DatosMet[], int cantidadDatos) {
    // Abrir el archivo con extensión .txt en modo de salida (out)
    ofstream archivo("datos_meteorologicos.txt");
    //Verificacion de apertura
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    // Escribir el encabezado
    archivo << "Fecha Temperatura (C) Humedad (%) Velocidad del Viento (km/h) Presión Atmosférica (hPa) Condición Meteorológica" << endl;
    
    // Escribir los datos en el archivo
    for (int i = 0; i < cantidadDatos; ++i) {
        archivo << DatosMet[i].anio << "-" << (DatosMet[i].mes < 10 ? "0" : "") << DatosMet[i].mes << "-" << (DatosMet[i].dia < 10 ? "0" : "") << DatosMet[i].dia << " " << DatosMet[i].temperatura << " " << DatosMet[i].humedad << " " << DatosMet[i].velocidadViento << " " << DatosMet[i].presionAtm << " " << DatosMet[i].clima << endl;
    }
    //Cerrar el archivo
    archivo.close();
}
//Funcion para ordenar las nuevas fechas que ingrese el usuario
void ordenarPorFecha(condicionMeteorologica DatosMet[], int cantidadDatos) {
	//Aplicación de bucle burbuja 
    for (int i = 0; i < cantidadDatos - 1; ++i) {
        for (int j = 0; j < cantidadDatos - i - 1; ++j) {
        	//Revision de anio, mes y dia para su organizacion
            if (DatosMet[j].anio > DatosMet[j + 1].anio || (DatosMet[j].anio == DatosMet[j + 1].anio && DatosMet[j].mes > DatosMet[j + 1].mes) || (DatosMet[j].anio == DatosMet[j + 1].anio && DatosMet[j].mes == DatosMet[j + 1].mes && DatosMet[j].dia > DatosMet[j + 1].dia)) {
				condicionMeteorologica temp = DatosMet[j];
                DatosMet[j] = DatosMet[j + 1];
                DatosMet[j + 1] = temp;
            }
        }
    }
}
// Función para verificar si una fecha está dentro de un rango de fechas dado
bool esFechaEnRango(int anio, int mes, int dia, int anioInicio, int mesInicio, int diaInicio, int anioFin, int mesFin, int diaFin) {
    if (anio < anioInicio || anio > anioFin) return false;
    if (anio == anioInicio && (mes < mesInicio || (mes == mesInicio && dia < diaInicio))) return false;
    if (anio == anioFin && (mes > mesFin || (mes == mesFin && dia > diaFin))) return false;
    return true;
}
//Funcion que calcula la temperatura Maxima del lapso de tiempo//
float examinarTemMax(condicionMeteorologica  DatosMet[],int cantidadDatos, int anioInicio, int mesInicio, int diaInicio, int anioFin, int mesFin, int diaFin, int& anioMax, int& mesMax, int& diaMax) {
    //Se coloca -1000.0 para poder generar la primera iteracion
	float tempMaxima=-1000.0;
    //Se verifica que la fecha ingresada este dentro del rango y se comienza a hacer la comparacion de datos 
    for (int i=0;i<cantidadDatos;i++){
        if (esFechaEnRango(DatosMet[i].anio, DatosMet[i].mes, DatosMet[i].dia, anioInicio, mesInicio, diaInicio, anioFin, mesFin, diaFin) && DatosMet[i].temperatura > tempMaxima){
        	//Se guardan dichos datos en una variable en caso de que se cumpla la condicion y como se paso dicha variable por referencia se modifica
			tempMaxima = DatosMet[i].temperatura;
        	anioMax = DatosMet[i].anio;
            mesMax = DatosMet[i].mes;
            diaMax = DatosMet[i].dia;
        }
    }
	return tempMaxima;
}
//Funcion que calcula la temperatura Minima del lapso de tiempo
float examinarTempMin(condicionMeteorologica  DatosMet[],int cantidadDatos, int anioInicio, int mesInicio, int diaInicio, int anioFin, int mesFin, int diaFin, int& anioMin, int& mesMin, int& diaMin){
    //Se coloca 1000.0 para poder generar la primera iteracion
	float tempMinima=1000.0;
    for(int i=0;i<cantidadDatos;i++){
    	//Se verifica que la fecha ingresada este dentro del rango y se comienza a hacer la comparacion de datos 
         if (esFechaEnRango(DatosMet[i].anio, DatosMet[i].mes, DatosMet[i].dia, anioInicio, mesInicio, diaInicio, anioFin, mesFin, diaFin) && DatosMet[i].temperatura<tempMinima){
        	//Se guardan dichos datos en una variable en caso de que se cumpla la condicion y como se paso dicha variable por referencia se modifica
			tempMinima = DatosMet[i].temperatura;
        	anioMin = DatosMet[i].anio;
        	mesMin = DatosMet[i].mes;
        	diaMin = DatosMet[i].dia; 
		}
    }
	return tempMinima;
}
//Funcion que calcula la temperatura promedio del lapso de tiempo
float promedioTemp(int cantidadDatos, condicionMeteorologica DatosMet[], int anio, int mes) {
    float sumaTemp = 0, promedioTemperatura = 0;
    int contadorDatosTemp= 0;
    
    for (int i = 0; i < cantidadDatos; i++) {
    	//Se verifica que tanto el año como el mes sea el mismo y se comienzan a sumar sus temperaturas
    	if (DatosMet[i].anio == anio && DatosMet[i].mes == mes) {
        	sumaTemp += DatosMet[i].temperatura;
        	//Se contabilizan los datos ya que es sobre lo que se va a dividir
        	contadorDatosTemp++;
		}
    } 
	//Si no hay datos entonces se retornara 0 y si si se realizara la division de la suma sobre la cantidad de datos  
    if (contadorDatosTemp > 0) {
       promedioTemperatura = sumaTemp / contadorDatosTemp;
    }
    return cantidadDatos > 0 ? promedioTemperatura : 0;
 }
//Funcion para encontar el promedio de humedad y determinar la condicion meteorologica en la que se da
float promHumedadMes(int cantidadDatos, condicionMeteorologica DatosMet[], const string& criterio, int anio, int mes, datosAnio arregloAnio[]) {
    float sumaNublado = 0, sumaSoleado = 0, sumaLluvioso = 0;
    int contadorNublado = 0, contadorSoleado = 0, contadorLluvioso = 0;
    
    for (int i = 0; i < cantidadDatos; i++) {
    	//Se verifica que el año y el mes sean los mismos para efectuar la suma de sus humedades
        if (DatosMet[i].anio == anio && DatosMet[i].mes == mes) {
        	//Se verifica la condicion meteorologica para hacer suma de la humedad correspondiente a la misma
            if (DatosMet[i].clima == "Nublado") {
                sumaNublado += DatosMet[i].humedad;
                contadorNublado++;
            } else if (DatosMet[i].clima == "Soleado") {
                sumaSoleado += DatosMet[i].humedad;
                contadorSoleado++;
            } else if (DatosMet[i].clima == "Lluvioso") {
                sumaLluvioso += DatosMet[i].humedad;
                contadorLluvioso++;
            }
        }
    }
    //Se verifica que el divisor no sea 0 y se efectuala divison, si es 0 se retorna 0
    float promedioNublado = (contadorNublado != 0) ? sumaNublado / contadorNublado : 0;
    float promedioSoleado = (contadorSoleado != 0) ? sumaSoleado / contadorSoleado : 0;
    float promedioLluvioso = (contadorLluvioso != 0) ? sumaLluvioso / contadorLluvioso : 0;
    //Se verifica si se quiere encontrar el mayor o el menor promedio
    if (criterio == "mayor") {
    	float mayorPromedio = 0;
    	//Si todas las condiciones son igual a 0 idica que no hay datos
    	if (promedioNublado == 0 && promedioSoleado == 0 && promedioLluvioso == 0){
    		arregloAnio->clima = "No hay datos";
    		return mayorPromedio;
		}
		//Se verifica cual es el mayor de los tres promedios
        mayorPromedio = promedioNublado;
        arregloAnio->clima = "Nublado";
        if (promedioSoleado > mayorPromedio) {
            arregloAnio->clima = "Soleado";
            mayorPromedio = promedioSoleado;
        }
        if (promedioLluvioso > mayorPromedio) {
            arregloAnio->clima = "Lluvioso";
            mayorPromedio = promedioLluvioso;
        }
        return mayorPromedio;
    } else {
    	float menorPromedio = 0;
    	//Si todas las condiciones son igual a 0 idica que no hay datos
    	if (promedioNublado == 0 && promedioSoleado == 0 && promedioLluvioso == 0){
    		arregloAnio->clima = "No hay datos";
    		return menorPromedio;
		}
		//Se verifica cual es el menor de los tres promedios
        menorPromedio = promedioNublado;
        arregloAnio->clima = "Nublado";
        if (promedioSoleado < menorPromedio) {
            arregloAnio->clima = "Soleado";
            menorPromedio = promedioSoleado;
        }
        if (promedioLluvioso < menorPromedio) {
            arregloAnio->clima = "Lluvioso";
            menorPromedio = promedioLluvioso;
        }
        return menorPromedio;
    }
}
//Funcion para econtrar el mayor año dentro de los datos meteorologicos
int encontrarMayorAnio(const condicionMeteorologica DatosMet[], int cantidadDatos) {
    int mayorAnio = DatosMet[0].anio;
    for (int i = 1; i < cantidadDatos; ++i) {
        if (DatosMet[i].anio > mayorAnio) {
            mayorAnio = DatosMet[i].anio;
        }
    }
    return mayorAnio;
}
//Funcion para econtrar el menor año dentro de los datos meteorologicos
int encontrarMenorAnio(const condicionMeteorologica DatosMet[], int cantidadDatos) {
    int menorAnio = DatosMet[0].anio;
    for (int i = 1; i < cantidadDatos; ++i) {
        if (DatosMet[i].anio < menorAnio) {
            menorAnio = DatosMet[i].anio;
        }
    }
    return menorAnio;
}
//Funcion para realizar la salida indicada de los promedios del promedio de humedad (mayor o menor) junto con la condicon meteorologica de lo determian
void salidaPromedio(ofstream& salida, int cantidadDatos, condicionMeteorologica DatosMet[], const string& criterio, const string& salidaConsola) {
    //Se inicializa el struct fecha para poder hacer llamado de la funcion obtenerNombreMes
	fecha inicializador(0, 0, 0);
	//Se llama las funciones de mayor y menor anio para que el programa sepa de donde hasta donde iterar
    int mayorAnio = encontrarMayorAnio(DatosMet, cantidadDatos);
	int menorAnio = encontrarMenorAnio(DatosMet, cantidadDatos);
	const int cantidadAnios = mayorAnio - menorAnio + 1;
	//Se calculan la cantidad de messe para saber que tan grande va a ser el arreglo de los datos
	const int cantidadMeses = cantidadAnios * 12;
	datosAnio arregloAnio[cantidadMeses];
	int indice = 0;

    for (int j = menorAnio; j <= mayorAnio; j++) {
        for (int k = 1; k <= 12; k++) {
        	//Se llama la funcion para calcular el mayor o menor promedio de humedad segun se indique
            float promedioH = promHumedadMes(cantidadDatos, DatosMet, criterio, j, k, &arregloAnio[indice]);
            //Se almacenan los datos en el struct arregloAnio
            arregloAnio[indice] = datosAnio(j, k, 0, promedioH, arregloAnio[indice].clima);
            indice++;
        }
    }
    //Se realiza la salida en consola para que el usuario vea los resultados
    if(salidaConsola == "SI"){
	    for (int i = 0; i < cantidadMeses; i++) {
	        inicializador.mes = arregloAnio[i].mes;
	        //Se obtiene el nombre del mes del mes dependiendo de su numero
	        string nombreMes = inicializador.obtenerNombreMes();
	        //Se coloca setw de la libreria iomanip para que se vea mejor esteticamente
	        cout << setw(10) << arregloAnio[i].anio << setw(15) << nombreMes << setw(20) << arregloAnio[i].porcentHumedad << "%" << setw(24) << arregloAnio[i].clima << endl;
	    }
	} else {
		//Salida de los datos en el archivo de salida .txt 
	    for (int i = 0; i < cantidadMeses; i++) {
	    	//Se obtiene el nombre del mes del mes dependiendo de su numero
	        inicializador.mes = arregloAnio[i].mes;
	        string nombreMes = inicializador.obtenerNombreMes();
	        salida << setw(10) << arregloAnio[i].anio << setw(15) << nombreMes << setw(20) << arregloAnio[i].porcentHumedad << "%" << setw(24) << arregloAnio[i].clima << endl;
	    }
	}
}
//Funcion para calcular la probabilidad de incendio
void probabilidadIncendio(ofstream& salida, int cantidadDatos, condicionMeteorologica DatosMet[], const string& salidaConsola, int dia, int mes, int anio) {
    bool encontrado = false; // Bandera para verificar si se encontró la fecha
    for (int i = 0; i < cantidadDatos; i++) {
        if (DatosMet[i].dia == dia && DatosMet[i].mes == mes && DatosMet[i].anio == anio) {
            encontrado = true; // Se encontro la fecha
            string probabilidad;
            //Se verifica si se cumple alguna de las condiciones para que se de o no se de un incendio
            if (DatosMet[i].temperatura > 35 && DatosMet[i].clima == "Soleado" && DatosMet[i].velocidadViento >= 7 && DatosMet[i].velocidadViento <= 10) {
                probabilidad = "ALTA";
            } else if (DatosMet[i].velocidadViento >= 3 && DatosMet[i].velocidadViento <= 5 && DatosMet[i].temperatura >= 25 && DatosMet[i].temperatura <= 35) {
                probabilidad = "EXISTENTE";
            } else if (DatosMet[i].velocidadViento < 2 && DatosMet[i].temperatura >= 15 && DatosMet[i].temperatura <= 20) {
                probabilidad = "INEXISTENTE";
            } else {
            	//Si no simplemente es inexistente
                probabilidad = "INEXISTENTE";
            }
            //Se hace la salida en consola
            if (salidaConsola == "SI"){
                cout << "Probabilidad de Incendio: \"" << probabilidad << "\"" << endl;
                cout << setw(24) << "Velocidad del viento: " <<  DatosMet[i].velocidadViento << " Km/h" << endl;
                cout << setw(24) << "Temperatura: " <<  DatosMet[i].temperatura << " " << char(167) << "C" << endl;
                cout << endl;
            } else {
            	//Se hace la salida en el archivo .txt
                salida << "Probabilidad de Incendio: \"" << probabilidad << "\"" << endl;
                salida << setw(24) << "Velocidad del viento: " <<  DatosMet[i].velocidadViento << " Km/h" << endl;
                salida << setw(24) << "Temperatura: " <<  DatosMet[i].temperatura << " °C" << endl;
                salida << endl;
            }
            break; // Salir del bucle después de encontrar la fecha
        }
    }
    //Si no se encuentra la fecha se imprimen en la cosola y en el archivo de salida .txt lo siguiente
    if (!encontrado) {
        if (salidaConsola == "SI") {
            cout << "No se encontraron datos para la fecha proporcionada." << endl;
        } else {
            salida << "No se encontraron datos para la fecha proporcionada." << endl;
        }
    }
}

void probabilidadTormenta(ofstream& salida, int cantidadDatos, condicionMeteorologica DatosMet[], const string& salidaConsola, int dia, int mes, int anio) {
    bool encontrado = false; // Bandera para verificar si se encontró la fecha
    for (int i = 0; i < cantidadDatos; i++) {
        if (DatosMet[i].dia == dia && DatosMet[i].mes == mes && DatosMet[i].anio == anio) {
            encontrado = true; // Se encontró la fecha
            string probabilidad;
            //Se verifica si se cumple alguna de las condiciones para que se determine la probabilidad de tormenta
            if (DatosMet[i].presionAtm > 1010 && DatosMet[i].clima == "Lluvioso" && DatosMet[i].humedad > 70) {
                probabilidad = "ALTA PROBABILIDAD DE TORMENTA";
            } else if (DatosMet[i].presionAtm < 1010 && DatosMet[i].clima == "Lluvioso" && DatosMet[i].humedad > 70) {
                probabilidad = "ALTA PROBABILIDAD DE LLUVIA FUERTE";
            } else {
            	//Si no simplemente es inexistente
                probabilidad = "INEXISTENTE";
            }
            //Se hace la salida en consola
            if (salidaConsola == "SI"){
                cout << "Probabilidad: \"" << probabilidad << "\"" << endl;
                cout << setw(24) << "Presión Atmosférica: " <<  DatosMet[i].presionAtm << " hPa" << endl;
                cout << setw(24) << "Humedad: " <<  DatosMet[i].humedad << " %" << endl;
                cout << setw(24) << "Condici" << char(162) << "n Meteorol" << char(162) << "gica: " <<  DatosMet[i].clima << endl;
                cout << endl;
            } else {
            	//Se hace la salida en el archivo .txt
                salida << "Probabilidad: \"" << probabilidad << "\"" << endl;
                salida << setw(24) << "Presión Atmosférica: " <<  DatosMet[i].presionAtm << " hPa" << endl;
                salida << setw(24) << "Humedad: " <<  DatosMet[i].humedad << " %" << endl;
                salida << setw(24) << "Condición Meteorológica: " <<  DatosMet[i].clima << endl;
                salida << endl;
            }
            break; // Salir del bucle después de encontrar la fecha
        }
    }
    //Si no se encuentra la fecha se imprimen en la cosola y en el archivo de salida .txt lo siguiente
    if (!encontrado) {
        if (salidaConsola == "SI") {
            cout << "No se encontraron datos para la fecha proporcionada." << endl;
        } else {
            salida << "No se encontraron datos para la fecha proporcionada." << endl;
        }
    }
}
int main() {
	
	string usuario;
	string password;
	//Se hace un arreglo con las opciones de inicio de sesion
	string opciones[3] = {"Iniciar sesion = 1 ", "Registrarse = 2", "Salir = 3"};
	int opcion;

	do {
    	for(int i = 0; i < 3; i++) {
    		//Se hace la salida de dicho meni
        	cout << i + 1 << "." << opciones[i] <<endl;
    	}
    cout<< "Seleccione una opcion: ";
    cin>> opcion;

    switch(opcion) {
        case 1:
            cout<< "Ingrese su nombre de usuario:";
            cin>> usuario;
            cout<< "Ingrese su contrasenia:";
            cin>> password;
            //Se hace la validadcion de si el usuario se encuentra en la base de datos
            if(iniciarSesion(usuario, password)) {
                cout<< "Inicio de sesión exitoso." << endl;
                //Se declara como la cantidad maxima de datos a analizar (datos que van dentro del arreglo de structs)
                const int datosMaximos = 10000;
    			condicionMeteorologica DatosMet[datosMaximos];
    			int cantidadDatos = 0;
    			int opcion;
    			int anioInicio, mesInicio, diaInicio;
    			int anioFin, mesFin, diaFin;
    			int anioMax, anioMin, mesMax, mesMin, diaMax, diaMin;
    			//Salida del menu de opciones a realizar
    			cout << "Este es un sistema de informaci" << char(162) << "n integral para poder establecer las mediciones del clima y el ambiente, el cual funciona para poder tomar y prevenir cat" << char(160) << "strofes clim" << char(160) << "ticas. Este sistema dise" << char(164) << "ado para el IDEAM tiene como objetivo principal realizar un an" << char(160) << "lisis exhaustivo de los datos recopilados por una variedad de fuentes, incluyendo medidores de calidad del aire y sat" << char(130) << "lites." << endl;
    
    			cout << "Se" << char(164) << "or" << char(64) << " ingrese la opci" << char(162) << "n de la acci" << char(162) << "n que desea realizar:" << endl;
    			cout << "1. Filtrar y mostrar la temperatura m"<< char(160) << "xima dentro de un rango de tiempo especificado." << endl;
    			cout << "2. Filtrar y mostrar la temperatura m" << char(161) << "nima dentro de un rango de tiempo especificado." << endl;
    			cout << "3. Calcular el promedio de temperatura durante un mes determinado." << endl;
    			cout << "4. Calcular el promedio de humedad en relaci" << char(162) << "n con una condici" << char(162) << "n meteorol" << char(162) << "gica dada, determinando con qu" << char(130) << " condici" << char(162) << "n se presenta el mayor porcentaje de humedad en un mes." << endl;
    			cout << "5. Calcular el promedio de humedad en relaci" << char(162) << "n con una condici" << char(162) << "n meteorol" << char(162) << "gica dada, determinando con qu" << char(130) << " condici" << char(162) << "n se presenta el menor porcentaje de humedad en un mes." << endl;
			    cout << "6. Calcular la probabilidad de incendio, teniendo en cuenta la temperatura, velocidad del viento y la condici" << char(162) << "n meteorol" << char(162) << "gica:" << endl << "a. Si la temperatura es mayor a 35 grados Celsius y la condici" << char(162) << "n meteorol" << char(162) << "gica es soleada con una velocidad del viento entre 7 y 10 kil" << char(162) << "metros por hora, entonces hay una alta probabilidad de incendio." << endl;
				cout << "b. Si la velocidad del viento est" << char(160) << " entre 3 y 5 kil" << char(162) << "metros por hora y la temperatura est" << char(160) << " entre 25 y 35 grados Celsius, entonces se considera que la temperatura es ligeramente alta y existe una probabilidad de incendio." << endl;
				cout << "c. Si la velocidad del viento es menor a 2 kil" << char(162) << "metros por hora y la temperatura est" << char(160) << " entre 20 y 15 grados Celsius, entonces se considera que la temperatura es normal y no hay probabilidad de incendio." << endl;
				cout << "7. Calcular la probabilidad de una tormenta, teniendo en cuenta la presi" << char(162) << "n atmosf" << char(130) << "rica, humedad y condici" << char(162) << "n meteorol" << char(162) << "gica:" << endl << "a. Si la presi" << char(162) << "n atmosf" << char(130) << "rica es mayor a 1010 hPa y la condici" << char(162) << "n meteorol" << char(162) << "gica es lluviosa, con una humedad mayor al 70%, entonces hay una alta probabilidad de tormenta." << endl;
				cout << "b. Si la presi" << char(162) << "n atmosf" << char(130) << "rica es menor a 1010 hPa y la condici" << char(162) << "n meteorol" << char(162) << "gica es lluviosa, con una humedad mayor al 70%, entonces hay una alta probabilidad de lluvia fuerte." << endl;
			    cout << "8. Salir del programa." << endl;	
			    cout << "9. Ingresar datos a los datos meteorologicos." << endl;
			    //Se declara continuar ya que posteriormente 
			    bool continuar;
			    //Se abre el archivo de salida para escritura y se coloca ios_base::app para que se siga escribiendo en el archivo y no se borre la informacion
			    //El ios_base es para realizar un salto de linea a la hora de comenzar a escribir los datos 
			    ofstream salida("salidaProyecto.txt", ios_base::app);
			    if (salida.is_open()){
			    	
				    int opcion;
				    bool continuar = true;
				    //Se hace la salida del nombre del usuario en el .txt
				    salida << "Usuario: " << usuario << endl;
				    salida << "Informe: " << endl;
				    //Se efectua este bucle siempre y cuando continuar sea verdadero
				    do {
				    	//Se realiza la lectura de datos del archivo y se almacenan en el arreglo DatosMet
				    	//Se efectua dentro del bucle por si el usuario llega a ingresar nueva informacion
				    	leerArchivo(DatosMet, cantidadDatos);
				        cout << "Ingrese una opcion ( 0 - 9 ): " << endl;
				        cin >> opcion;
				        //Si se ingresa un valor por fuera del rango pide al usuario ingresar uan opcion valida nuevamente 
				        if (opcion < 0 || opcion > 9) {
				            cout << "Usted ingreso un valor fuera de los valores del menú: " << endl;
				            cout << "Ingrese un valor valido nuevamente: " << endl;
				        } else if (opcion >= 1 && opcion <= 7) {
				        	if (opcion == 1) {
				        		//Se especifica el rango de tiempo en el que se desea ver la temperatura maxima
				        		cout << "Especifique el rango de tiempo: "<< endl;
				        		cout << "Fecha inicial: " << endl << "A" << char(164) << "o:";
								cin >> anioInicio;
								cout << "Mes: ";
								cin >> mesInicio;
								cout << "Dia: ";
								cin >> diaInicio; 
								cout << "Fecha final: " << endl << "A" << char(164) << "o:";
								cin >> anioFin;
								cout << "Mes: ";
								cin >> mesFin;
								cout << "Dia: ";
								cin >> diaFin; 
								//Se llama la funcion para poder efectuar la salida de datos
				        		float tempMaxima = examinarTemMax(DatosMet, cantidadDatos, anioInicio, mesInicio, diaInicio, anioFin, mesFin, diaFin, anioMax, mesMax, diaMax);
				        		//Se realiza la salida tanto en consola como en el archivo de salida .txt
								cout << "Temperatura maxima Registrada: " << tempMaxima << char (248) << "C" << " el " << anioMax << "-" << mesMax << "-" << diaMax << " en el lapso " << anioInicio << "-" << mesInicio << "-" << diaInicio<< " hasta " << anioFin << "-" << mesFin << "-" << diaFin << endl;
				        		salida << "Temperatura maxima Registrada: " << tempMaxima << " °C" << " el " << anioMax << "-" << mesMax << "-" << diaMax << " en el lapso " << anioInicio << "-" << mesInicio << "-" << diaInicio<< " hasta " << anioFin << "-" << mesFin << "-" << diaFin << endl;
							} else if ( opcion == 2) {
								//Se especifica el rango de tiempo en el que se desea ver la temperatura maxima
								cout << "Especifique el rango de tiempo: "<< endl;
				        		cout << "Fecha inicial: " << endl << "A" << char(164) << "o:";
								cin >> anioInicio;
								cout << "Mes: ";
								cin >> mesInicio;
								cout << "Dia: ";
								cin >> diaInicio; 
								cout << "Fecha final: " << endl << "A" << char(164) << "o:";
								cin >> anioFin;
								cout << "Mes: ";
								cin >> mesFin;
								cout << "Dia: ";
								cin >> diaFin; 
								//Se llama la funcion para poder efectuar la salida de datos
				        		float tempMinima = examinarTempMin(DatosMet, cantidadDatos, anioInicio, mesInicio, diaInicio, anioFin, mesFin, diaFin, anioMin, mesMin, diaMin);
				        		//Se realiza la salida tanto en consola como en el archivo de datos .txt
								cout << "Temperatura minima Registrada: " << tempMinima << char (248) << "C" << " el " << anioMin << "-" << mesMin << "-" << diaMin << " en el lapso " << anioInicio << "-" << mesInicio << "-" << diaInicio<< " hasta" << anioFin << "-" << mesFin << "-" << diaFin << endl;
				        		salida << "Temperatura minima Registrada: " << tempMinima << " °C"<< " el " << anioMin << "-" << mesMin << "-" << diaMin << " en el lapso " << anioInicio << "-" << mesInicio << "-" << diaInicio<< " hasta" << anioFin << "-" << mesFin << "-" << diaFin << endl;
							} else if ( opcion == 3) {
								//Se realiza la especificacion al usuario de cual es el anio en el que desea ver el promedio de su temperatura
								cout << "Ingrese el a" << char(164) << "o y el mes (en n" << char(163) << "mero) dentro del cu" << char(160) << "l se calcular" << char(160) << " el promedio de la temperatura: " << endl;
								int anio, mes;
								cout << "A" << char(164) << "o: ";
								cin >> anio;
								cout << "Mes: ";
								cin >> mes;
								//Se llena un struct fecha para poder operar correctamente los datos
								fecha promedioTemperatura(anio, mes, 0);
								//Se llama la funcio obtener nombre mes para saber el con que mes se esta trabajando 
								string nombreMes = promedioTemperatura.obtenerNombreMes();
								//Se calcula el promedio de temeperatura con la funcio 
								float promTemp = promedioTemp(cantidadDatos, DatosMet, anio, mes);
								//Se hace salida tanto en consola como en el archivo de salida .txt
								cout << "El promedio para el a" << char(164) << "o " << anio << ", mes " << nombreMes << " es: " << promTemp << char(167) << "C" << endl; 
								salida << "El promedio para el año " << anio << ", mes " << nombreMes << " es: " << promTemp << " °C" << endl; 
							} else if (opcion == 4) {
								//Se escribe el encabezado de la tabla en la consola
				                cout << "Mayor Humedad:" << endl << endl;
				                cout << setw(10) << "A" << char(164) << "o" << setw(15) << "Mes" << setw(20) << "Humedad Promedio" << setw(24) << "Condici" << char(162) << "n Meteorol" << char(162) << "gica" << endl;
				                //Se llama la funcion y se imprimen todos los valores sus promedios de humedad y con que condicion se da la mayor
								salidaPromedio(salida, cantidadDatos, DatosMet, "mayor", "SI");
				                cout << endl;
				                
				                //Lo mismo pero en el archivo de salida .txt
				    			salida << "Mayor Humedad:" << endl << endl;
				  				salida << setw(10) << "Año" << setw(15) << "Mes" << setw(20) << "Humedad Promedio" << setw(24) << "Condición Meteorológica" << endl;
							    salidaPromedio(salida, cantidadDatos, DatosMet, "mayor", "NO");
							    salida << endl;
				            } else if (opcion == 5) {
				            	//Se escribe el encabezado de la tabla en la consola
				                cout << "Menor Humedad:" << endl << endl;
				                cout << setw(10) << "A" << char(164) << "o" << setw(15) << "Mes" << setw(20) << "Humedad Promedio" << setw(24) << "Condici" << char(162) << "n Meteorol" << char(162) << "gica" << endl;
				                //Se llama la funcion y se imprimen todos los valores sus promedios de humedad y con que condicion se da la menor
								salidaPromedio(salida, cantidadDatos, DatosMet, "menor", "SI");
				                cout << endl;
				                
				                 //Lo mismo pero en el archivo de salida .txt
				                salida << "Menor Humedad:" << endl << endl;
								salida << setw(10) << "Año" << setw(15) << "Mes" << setw(20) << "Humedad Promedio" << setw(24) << "Condición Meteorológica" << endl;
								salidaPromedio(salida, cantidadDatos, DatosMet, "menor", "NO");
								salida << endl;
				            } else if (opcion == 6) {
				            	//Se establece la fecha en la que se desea calcular la probabilidad de incendio
				            	cout << "Ingrese la fecha en la que desea ver si hay probabilidad de incendio" << endl;
				            	int anio, mes, dia;
				            	cout << "A" << char(164) << "o: ";
								cin >> anio;
								cout <<"Mes: ";
								cin >> mes;
								cout << "Dia: ";
								cin >> dia;
								//Se hace el llamdo de la funcion con si y no para la salida tanton en consola como en el archivo .txt
				                probabilidadIncendio(salida, cantidadDatos, DatosMet, "SI", dia, mes, anio);
				                probabilidadIncendio(salida, cantidadDatos, DatosMet, "NO", dia, mes, anio);
				            } else if ( opcion == 7) {
				            	//Se establece la fecha en la que se desea calcular la probabilidad de tormenta
				            	cout << "Ingrese la fecha en la que desea ver si hay probabilidad de tormenta" << endl;
				            	int anio, mes, dia;
				            	cout << "A" << char(164) << "o: ";
								cin >> anio;
								cout <<"Mes: ";
								cin >> mes;
								cout << "Dia: ";
								cin >> dia;
								//Se hace el llamdo de la funcion con si y no para la salida tanton en consola como en el archivo .txt
				                probabilidadTormenta(salida, cantidadDatos, DatosMet, "SI", dia, mes, anio);
				                probabilidadTormenta(salida, cantidadDatos, DatosMet, "NO", dia, mes, anio);
							}
							//Se pregunta si se desea continuar
				            cout << char(168) <<  "Desea continuar? SI = 1 || NO = 2" << endl;
				            int seguir;
				            cin >> seguir;
				            //Si se ingresa un valor fuera del rango se repite el ingreso hasta que este dentro del rango
				            while (seguir < 1 || seguir > 2) {
				                cout << "Ingrese un valor valido nuevamente: " << endl;
				                cin >> seguir;
				            }
				            //Si se ingresa un va a acutar como una condicion boolena que indicara que si, de lo contrario va a se un no
				            continuar = (seguir == 1);
				        } else if (opcion == 8) {
				        	//Opcion para cerrar la sesion en el programa
				            cout << "Usted sali" << char(162) << " del programa." << endl;
				            continuar = false;
				        } else if (opcion == 9) {
				        	//Se hace el ingreso de todos los datos requeridos en el struct 
				       		int anio, mes, dia;
			        		float presionAtm, humedad, velocidadViento, temperatura;
							string clima;								
							cout << "Ingrese el a" << char(164) << "o: ";
							cin >> anio;
							cout << "Ingrese el mes (n"<< char(163) << "mero): ";
							cin >> mes;
							cout << "Ingrese el dia: ";
							cin >> dia;
							cout << "Ingrese la tempertatura (" << char(167) << "C): ";
							cin >> temperatura;
							cout << "Ingrese el porcentaje de humedad: ";
							cin >> humedad;
							cout << "Ingrese la velocidad del viento (km/h): ";
							cin >> velocidadViento;
							cout << "Ingrese la presi" << char(162) << "n atmosf"<< char(130) << "rica (hPa): ";
							cin >> presionAtm;
							cout << "Ingrese la condici" << char(162) << "n meteorol" << char(162) << "gica (Nublado, Soleado, Lluvioso): ";
							//Se hace un cin.ignore para que pueda tomar de manera correcta los valores de la condion meteorologica
							cin.ignore();
							//Se hace la verificacion de que sea una de las tres
							while (clima != "Nublado" && clima != "Soleado" && clima != "Lluvioso") {
				                cout << "Ingrese un valor valido nuevamente: " << endl;
				                getline(cin, clima);
				            }
							
							//Se llena el struct con los datos y se aumenta la cantidad de datos
    						DatosMet[cantidadDatos] = condicionMeteorologica(anio, mes, dia, temperatura, humedad, velocidadViento, presionAtm, clima);
    						cantidadDatos++;
    						
    						//Se ordena por fechas y se vuelva a escribir los datos en el archivo datos_meteorologicos.txt
    						ordenarPorFecha(DatosMet, cantidadDatos);
    						escribirArchivo(DatosMet, cantidadDatos);
						}
						//Si se dice que no se desea continuar se cierra la sesion
				    } while (continuar);	
				}
            } else {
                cout << "Nombre de usuario o contrasenia incorrectos." << endl;
                cout << "Intente nuevamente o registese" << endl;
            }
            break;
        case 2:
            cout<< "Ingrese un nombre de usuario:";
            cin>> usuario;
            cout<< "Ingrese una contrase" << char(164) << "a:";
            cin>> password;
            //El usuario y contraseña del usuario se guardan en el .bin con ayuda de la funcion
            registrarUsuario(usuario, password);
            cout<< "Usuario registrado exitosamente." << endl;
            break;
        case 3:
            cout<< "Saliendo del programa..." << endl;
            break;
        default:
            cout<< "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
	} while(opcion!= 3);
return 0;
}

