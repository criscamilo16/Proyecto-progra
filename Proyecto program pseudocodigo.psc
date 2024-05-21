// Simulaci�n del struct fecha
Funci�n struct_Fechas(anio,mes,dia)
	Dimensionar fecha(3)
	constructorF(fecha,anio,mes,dia)
FinFunci�n

// Constructor por parametros del struct fecha
Funci�n constructorF(fecha Por Referencia,anio,mes,dia)
	fecha[1] <- anio
	fecha[2] <- mes
	fecha[3] <- dia
FinFunci�n

// Funcion para obtener el nombre corresondiente al mes
Funci�n nombreMes <- obtenerNombreMes (mes)
	Seg�n mes Hacer
		1:
			nombreMes <- 'Enero'
		2:
			nombreMes <- 'Febrero'
		3:
			nombreMes <- 'Marzo'
		4:
			nombreMes <- 'Abril'
		5:
			nombreMes <- 'Mayo'
		6:
			nombreMes <- 'Junio'
		7:
			nombreMes <- 'Julio'
		8:
			nombreMes <- 'Agosto'
		9:
			nombreMes <- 'Septiembre'
		10:
			nombreMes <- 'Octubre'
		11:
			nombreMes <- 'Noviembre'
		12:
			nombreMes <- 'Diciembre'
		De Otro Modo:
			nombreMes <- 'Mes inv�lido'
	FinSeg�n
FinFunci�n

// Simulaci�n struct datosAnio
Funci�n datos <- struct_datosAnio (anio,mes,temperatura,porcentHumedad,clima)
	Dimensionar datosAnio(5)
	constructorDA(datosAnio,anio,mes,tempertatura,porcentHumedad,clima)
	datos <- datosAnio[5]
FinFunci�n

// Constructor por parametros del struct datosAnio
Funci�n constructorDA(datosAnio Por Referencia,anio,mes,temperatura,porcentHumedad,clima)
	datosAnio[1] <- anio
	datosAnio[2] <- mes
	datosAnio[3] <- temperatura
	datosAnio[4] <- porcentHumedad
	datosAnio[5] <- clima
FinFunci�n

// Simulaci�n struct condicionMeteorologica
Funci�n datos <- struct_condicionMeteorologica (anio,mes,dia,temperatura,porcentHumedad,velViento,presion,clima)
	Dimensionar condicionMeteorologica(8)
	constructorCM(condicionMeteorologica,anio,mes,dia,temperatura,porcentHumedad,velViento,presion,clima)
	datos <- condicionMeteorologica[8]
FinFunci�n

// Constructor por parametros del struct condicionMeteorologica;
Funci�n constructorCM(condicionMeteorologica Por Referencia,anio,mes,dia,temperatura,porcentHumedad,velViento,presion,clima)
	condicionMeteorologica[1] <- anio
	condicionMeteorologica[2] <- mes
	condicionMeteorologica[3] <- dia
	condicionMeteorologica[4] <- temperatura
	condicionMeteorologica[5] <- porcentHumedad
	condicionMeteorologica[6] <- velViento
	condicionMeteorologica[7] <- presion
	condicionMeteorologica[8] <- clima
FinFunci�n

// Funicion para la creacion o edicion de un archivo txt el cual registra a los usuarios
Funci�n registrarUsuario(user,password)
	Definir usuariosBin Como L�gico
	Definir textoUsuariosBin Como Cadena
	Si usuariosBin Entonces
		textoUsuarioBin <- user
		textoUsuarioBin <- password
		Escribir 'Usuario registrado exitosamente.'
	SiNo
		Escribir 'No se pudo abrir el archivo o no existe actualmente una base de datos'
	FinSi
FinFunci�n

Funci�n exitoso <- iniciarSesion(user,password)
	Definir usuariosBin Como L�gico
	Definir finArchivo Como L�gico
	Definir coincidencia Como L�gico
	Definir exitoso Como L�gico
	exitoso <- Falso
	coincidencia <- Falso
	// Simulamos la apertura del archivo
	usuariosBin <- Verdadero
	Si usuariosBin Entonces // Simula que el archivo se puede abrir correctamente
		// Simulamos la lectura de los datos del arch
		Definir tamUser Como Entero
		Definir tamPassword Como Entero
		Definir usuario Como Cadena
		Definir contrasenia Como Cadena
		Mientras (!finArchivo Y !coincidencia) Hacer
			Leer usuariosBin
			Si (user==usuario Y password==contrasenia) Entonces
				coincidencia <- Verdadero
				exitoso <- Verdadero
			SiNo
				exitoso <- Falso
			FinSi
		FinMientras
	SiNo
		Escribir 'No se pudo abrir el archivo'
	FinSi
FinFunci�n

Funci�n leerArchivo(DatosMet Por Referencia,cantidadDatos Por Referencia)
	cantidadDatos <- 0
	Definir datos_meteorologicosTxt Como L�gico
	Definir finArchivo Como L�gico
	Si !datos_meteorologicoTxt Entonces
		Escribir 'No se puede abrir el archivo'
	SiNo
		Definir linea Como Cadena
		Leer datos_meteorologicosTxt
		Mientras !finArchivo Hacer
			Definir anio, mes, dia Como Entero
			Definir temperatura, humedad, velViento, presion Como Real
			Definir clima, datos Como Cadena
			DatosMet[cantidadDatos] <- struct_condicionMeteorologica(anio,mes,dia,temperatura,humedad,velViento,presion,clima)
			cantidadDatos <- cantidadDatos+1
		FinMientras
	FinSi
FinFunci�n

Funci�n escribirArchivo(DatosMet,cantidadDatos)
	Definir datos_meteorologicos Como L�gico
	Definir textoDatos_meteorologicos Como Cadena
	Si datos_meteorologicos Entonces
		textoDatos_meteorologicos <- 'Fecha Temperatura (C) Humedad (%) Velocidad del Viento (km/h) Presi�n Atmosf�rica (hPa) Condici�n Meteorol�gica'
		Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
			textoDatos_meteorologicos <- DatosMet[1]
			textoDatos_meteorologicos <- DatosMet[2]
			textoDatos_meteorologicos <- DatosMet[3]
			textoDatos_meteorologicos <- DatosMet[4]
			textoDatos_meteorologicos <- DatosMet[5]
			textoDatos_meteorologicos <- DatosMet[6]
			textoDatos_meteorologicos <- DatosMet[7]
			textoDatos_meteorologicos <- DatosMet[8]
		FinPara
	SiNo
		Escribir 'No se pudo abrir el archivo o no existe actualmente una base de datos'
	FinSi
FinFunci�n

Funci�n ordenarPorFecha(DatosMet,cantidadDatos)
	Para i<-0 Hasta cantidadDatos-1 Con Paso 1 Hacer
		Para j<-0 Hasta cantidadDatos-i-1 Con Paso 1 Hacer
			Si (DatosMet[j]>DatosMet[j+1]) O (DatosMet[j]==DatosMet[j+1] Y DatosMet[j]>DatosMet[j+1]) O (DatosMet[j]==DatosMet[j+1] Y DatosMet[j]==DatosMet[j+1] Y DatosMet[j]>DatosMet[j+1]) Entonces
				Definir datosMetAux Como Entero
				datosMetAux <- DatosMet[j]
				DatosMet[j] <- DatosMet[j+1]
				DatosMet[j+1]<-datosMetAux
			FinSi
		FinPara
	FinPara
FinFunci�n

Funci�n esta <- esFechaRango(anio,mes,dia,anioInicio,mesInicio,diaInicio,anioFin,mesFin,diaFin)
	Definir esta Como L�gico
	Si (anio<anioInicio O anio>anioFin) Entonces
		esta <- Falso
	FinSi
	Si (anio==anioInicio Y (mes<mesInicio O (mes==mesInicio Y dia<diaInicio))) Entonces
		esta <- Falso
	FinSi
	Si (anio==anioFin Y (mes>mesFin O (mes==mesFin Y dia>diaFin))) Entonces
		esta <- Falso
	FinSi
	esta <- Verdadero
FinFunci�n

Funci�n tempMax <- examinarTempMax(DatosMet,cantidadDatos,anioInicio,mesInicio,diaInicio,anioFin,mesFin,diaFin,anioMax Por Referencia,mesMax Por Referencia,diaMax Por Referencia)
	Definir temperaturaMaxima Como Real
	Definir esta Como L�gico
	tempMaxima <- -1000.0
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		esta <- esFechaRango(anio,mes,dia,anioInico,mesInicio,diaInicio,anioFin,mesFin,diaFin)
		Si (esta Y DatosMet[4]>tempMaxima) Entonces
			tempMaxima <- DatosMet[i]
			anioMax <- DatosMet[i]
			mesMax <- DatosMet[i]
			diaMax <- DatosMet[i]
		FinSi
	FinPara
	tempMax <- tempMaxima
FinFunci�n

Funci�n tempMin <- examinarTempMin(DatosMet,cantidadDatos,anioInicio,mesInicio,diaInicio,anioFin,mesFin,diaFin,anioMin Por Referencia,mesMin Por Referencia,diaMin Por Referencia)
	Definir temperaturaMaxima Como Real
	Definir esta Como L�gico
	tempMinima <- 1000.0
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		esta <- esFechaRango(anio,mes,dia,anioInico,mesInicio,diaInicio,anioFin,mesFin,diaFin)
		Si (esta Y DatosMet[4]<tempMaxima) Entonces
			tempMinima <- DatosMet[i]
			anioMin <- DatosMet[i]
			mesMin <- DatosMet[i]
			diaMin <- DatosMet[i]
		FinSi
	FinPara
	tempMin <- tempMinima
FinFunci�n

Funci�n promTemp <- promedioTemp(cantiadadDatos,DatosMet,anio,mes)
	Definir sumaTemp, promedioTemperatura Como Real
	Definir contadorDatosTemp Como Entero
	sumaTemp <- 0
	promedioTemperatura <- 0
	contadorDatosTemp <- 0
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[1]==anio Y DatosMet[2]==mes) Entonces
			sumaTemp <- sumaTemp+DatosMet[4]
			contadorDatosTemp <- contadorDatosTemp+1
		FinSi
	FinPara
	promedioTemperatura <- sumaTemp/contadorDatosTemp
	promTemp <- promedioTemperatura
FinFunci�n

Funci�n promHum <- promeHumedadMes (cantidadDatos,DatosMet,criterio Por Referencia,anio,mes,arregloAnio Por Referencia)
	Definir sumanNublado, sumaSoleado, sumaLluvioso Como Real
	Definir contadorNublado, contadorSoleado, contadorLluvioso Como Entero
	sumaNublado <- 0
	sumaSoleado <- 0
	sumaLluvioso <- 0
	contadorNublado <- 0
	contadorSoleafo <- 0
	cotadorLluvioso <- 0
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[1]==anio Y DatosMet[2]==mes) Entonces
			Si (clima=='Nublado') Entonces
				sumaNublado <- sumaNublado+humedad
				contadorNublado <- contadorNublado+1
			FinSi
			Si (clima=='Soleado') Entonces
				sumaSoleado <- sumaSoleado+DatosMet[5]
				contadorSoleado <- contadorSoleado+1
			FinSi
			Si (clima=='Lluvioso') Entonces
				sumaLluvioso <- sumaLluvioso+DatosMet[5]
				contadorLluvioso <- contadorLluvioso+1
			FinSi
		FinSi
	FinPara
	Definir promedioNublado, promedioSoleado, promedioLluvioso Como Real
	promedioNublado <- sumaNublado/contadorNublado
	promedioSoleado <- sumaSoleado/contadorSoleado
	pormedioLluvioso <- sumaLluvioso/contaodrLluvioso
	Si (criterio=='mayor') Entonces
		Definir mayorPromedio Como Real
		mayorPromedio <- promedioNublado
		arregloAnio[5] <- 'Nublado'
		Si (promedioSoleado>mayorPromedio) Entonces
			arregloAnio[5] <- 'Soleado'
			mayorPromedio <- promedioSoleado
		FinSi
		Si (promedioLluvioso>mayorPromedio) Entonces
			arregloAnio[5] <- 'Lluvioso'
			mayorPromedio <- promedioLluvioso
		FinSi
		promHum <- mayorPromedio
	FinSi
	Si (criterio=='menor') Entonces
		Definir mayorPromedio Como Real
		menorPromedio <- promedioNublado
		arregloAnio[5] <- 'Nublado'
		Si (promedioSoleado<mayorPromedio) Entonces
			arregloAnio[5] <- 'Soleado'
			menorPromedio <- promedioSoleado
		FinSi
		Si (promedioLluvioso<mayorPromedio) Entonces
			arregloAnio[5] <- 'Lluvioso'
			menorPromedio <- promedioLluvioso
		FinSi
		promHum <- menorPromedio
	FinSi
FinFunci�n

Funci�n mayorAnio <- encontrarMayorAnio (DatosMet,cantidadDatos)
	Definir mayorAnio Como Entero
	mayorAnio <- DatosMet[1]
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[1]<mayorAnio) Entonces
			mayorAnio <- DatosMet[1]
		FinSi
	FinPara
	mayorAnio <- mayorAnio
FinFunci�n

Funci�n menorAnio <- encontrarMenorAnio (DatosMet,cantidadDatos)
	Definir menorAnio Como Entero
	menorAnio <- DatosMet[1]
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[1]<menorAnio) Entonces
			menorAnio <- DatosMet[1]
		FinSi
	FinPara
	menorAnio <- menorAnio
FinFunci�n

SubAlgoritmo salidaPromedio(salida,cantidadDatos,DatosMet,criterio,salidaConsola)
	mayorAnio <- encontrarMayorAnio(DatosMet,cantidadDatos)
	menorAnio <- encontrarMenorAnio(DatosMet,cantidadDatos)
	Definir cantidadAnios, cantidadMeses, indice Como Entero
	cantidadAnios <- mayorAnio-menorAnio+1
	cantidadMeses <- cantidadAnios*12
	Dimensionar arregloAnio(cantidadMeses)
	indice <- 0
	Para j<-menorAnio Hasta mayorAnio Con Paso 1 Hacer
		Para k<-1 Hasta 12 Con Paso 1 Hacer
			Definir promHum Como Real
			promHum <- promeHumedadMes(cantidadDatos,DatosMet,criterio,j,k,arregloAnio)
			arregloAnio <- struct_datosAnio(j,k,0,promHum,arregloAnio)
			indice <- indice+1
		FinPara
	FinPara
	Si (salidaConsola=='SI') Entonces
		Para i<-0 Hasta cantidadMeses Con Paso 1 Hacer
			nombreMes <- obtenerNombreMes(mes)
			Escribir arregloAnio[1], nombreMes, arregloAnio[4], arregloAnio[5]
		FinPara
	SiNo
		Para i<-0 Hasta cantidadMeses Con Paso 1 Hacer
			nombreMes <- obtenerNombreMes(mes)
			Escribir arregloAnio[1], nombreMes, arregloAnio[4], arregloAnio[5]
		FinPara
	FinSi
FinSubAlgoritmo

SubAlgoritmo probabilidad <- probabilidadIncendio (salida, cantidadDatos, DatosMet, salidaConsola, dia, mes, anio)
	Definir encontrado Como L�gico
	encontrado <- Falso
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[3]==dia Y DatosMet[2]==mes Y DatosMet[1]==anio) Entonces
			encontrado <- Verdadero
			Definir probabilidad Como Cadena
			Si (DatosMet[4]>35 Y clima=='Soleado' Y DatosMet[6]>=7 Y DatosMet[6]<=10) Entonces
				probabilidad <- 'ALTA'
				Si (DatosMet[6]>=3 Y DatosMet[6]<=5 Y DatosMet[4]>=25 Y DatosMet[4]<=35) Entonces
					probabilidad <- 'EXISTENTE'
					Si (DatosMet[6]<2 Y DatosMet[4]>=15 Y DatosMet[4]<=20) Entonces
						probabilidad <- 'INEXISTENTE'
					SiNo
						probabilidad <- 'INEXISTENTE'
					FinSi
				FinSi
			FinSi
			Si (salidaConsola=='SI') Entonces
				Escribir 'Probabilidad de Incendio:', probabilidad
				Escribir 'Velocidad del viento: ', DatosMet[6], ' Km/h'
				Escribir 'Temperatura: ', DatosMet[4], '�C'
			SiNo
				Escribir 'Probabilidad de Incendio:', probabilidad
				Escribir 'Velocidad del viento: ', DatosMet[6], ' Km/h'
				Escribir 'Temperatura: ', DatosMet[4], '�C'
			FinSi
		FinSi
	FinPara
	Si (!encontrado) Entonces
		Si (salidaConsola=='SI') Entonces
			Escribir 'No se encontraron datos para la fecha proporcionada.'
		SiNo
			Escribir 'No se encontraron datos para la fecha proporcionada.'
		FinSi
	FinSi
FinSubAlgoritmo

SubAlgoritmo probabilidad <- probabilidadTormenta (salida,cantidadDatos,DatosMet,salidaConsola,dia,mes,anio)
	Definir encontrado Como L�gico
	encontrado <- Falso
	Para i<-0 Hasta cantidadDatos Con Paso 1 Hacer
		Si (DatosMet[3]==dia Y DatosMet[2]==mes Y DatosMet[1]==anio) Entonces
			encontrado <- Verdadero
			Definir probabilidad Como Cadena
			Si (DatosMet[7]>1010 Y clima=='Lluvioso' Y DatosMet[5]>70) Entonces
				probabilidad <- 'ALTA PROBABILIDAD DE TORMENTA'
				Si (DatosMet[6]>=3 Y DatosMet[7]<1010 Y clima=='Lluvioso' Y DatosMet[5]<70) Entonces
					probabilidad <- 'ALTA PROBABILIDAD DE LLUVIA FUERTE'
				SiNo
					probabilidad <- 'INEXISTENTE'
				FinSi
			FinSi
		FinSi
		Si (salidaConsola=='SI') Entonces
			Escribir 'Probabilidad de tormenta:', probabilidad
			Escribir 'Presi�n Atmosf�rica: ', DatosMet[7], ' hPa'
			Escribir 'Humedad: ', DatosMet[5], '%'
			Escribir 'Condici�n Meteorol�gica', DatosMet[8]
		SiNo
			Escribir 'Probabilidad de tormenta:', probabilidad
			Escribir 'Presi�n Atmosf�rica: ', DatosMet[7], ' hPa'
			Escribir 'Humedad: ', DatosMet[5], '%'
			Escribir 'Condici�n Meteorol�gica', DatosMet[8]
		FinSi
	FinPara
	Si (!encontrado) Entonces
		Si (salidaConsola=='SI') Entonces
			Escribir 'No se encontraron datos para la fecha proporcionada.'
		SiNo
			Escribir 'No se encontraron datos para la fecha proporcionada.'
		FinSi
	FinSi
FinSubAlgoritmo

// Llamada al proceso principal
Algoritmo problema_IDEAM
	Definir usuario, password Como Cadena
	Dimensionar opciones(3)
	opciones[1] <- 'Iniciar sesion = 1 '
	opciones[2] <- 'Registrarse = 2'
	opciones[3] <- 'Salir = 3'
	Definir eleccion Como Entero
	Definir exitoso Como L�gico
	Repetir
		Para i<-0 Hasta 2 Con Paso 1 Hacer
			Escribir i+1, '.', opciones[i+1]
		FinPara
		Escribir 'Seleccione una opcion: '
		Leer eleccion
		Seg�n eleccion Hacer
			1:
				Escribir 'Ingrese su nombre de usuario: '
				Leer usuario
				Escribir 'Ingrese su contrasenia: '
				Leer password
				exitoso <- iniciarSesion(usuario,password)
				Si (exitoso) Entonces
					Escribir 'Inicio de sesi�n exitoso'
					Definir datosMaximos Como Entero
					datosMaximos <- 10000
					Dimensionar DatosMet(datosMaximos)
					Definir cantidadDatos, opcionMenu, anioInicio, mesInicio, diaInicio, anioFin, mesFin, diaFin, anioMax, anioMin, mesMax, mesMin, diaMax, diaMin Como Entero
					cantidadDatos <- 0
					Escribir 'Este es un sistema de informaci�n integral para poder establecer las mediciones del clima y el ambiente, el cual funciona para poder tomar y prevenir cat�strofes clim�ticas. Este sistema dise�ado para el IDEAM tiene como objetivo principal realizar un an�lisis exhaustivo de los datos recopilados por una variedad de fuentes, incluyendo medidores de calidad del aire y sat�lites.'
					Escribir 'Se�or@ usuario ingrese la opci�n de la acci�n que desea realizar'
					Escribir '1. Filtrar y mostrar la temperatura m�xima dentro de un rango de tiempo especificado'
					Escribir '2. Filtrar y mostrar la temperatura m�nima dentro de un rango de tiempo especificado'
					Escribir '3. Calcular el promedio de temperatura durante un mes determinado.'
					Escribir '4. Calcular el promedio de humedad en relaci�n con una condici�n meteorol�gica dada, determinando con qu� condici�n se presenta el mayor porcentaje de humedad en un mes.'
					Escribir '5. Calcular el promedio de humedad en relaci�n con una condici�n meteorol�gica dada, determinando con qu� condici�n se presenta el menor porcentaje de humedad en un mes.'
					Escribir '6. Calcular la probabilidad de incendio, teniendo en cuenta la temperatura, velocidad del viento y la condici�n meteorol�gica:'
					Escribir '		A. Si la temperatura es mayor a 35 grados Celsius y la condici�n meteorol�gica es soleada con una velocidad del viento entre 7 y 10 kil�metros por hora, entonces hay una alta probabilidad de incendio.'
					Escribir '		B. Si la velocidad del viento est� entre 3 y 5 kil�metros por hora y la temperatura est� entre 25 y 35 grados Celsius, entonces se considera que la temperatura es ligeramente alta y existe una probabilidad de incendio.'
					Escribir '		C. Si la velocidad del viento es menor a 2 kil�metros por hora y la temperatura est� entre 20 y 15 grados Celsius, entonces se considera que la temperatura es normal y no hay probabilidad de incendio.'
					Escribir '7. Calcular la probabilidad de una tormenta, teniendo en cuenta la presi�n atmosf�rica, humedad y condici�n meteorol�gica:'
					Escribir '		A. Si la presi�n atmosf�rica es mayor a 1010 hPa y la condici�n meteorol�gica es lluviosa, con una humedad mayor al 70%, entonces hay una alta probabilidad de tormenta.'
					Escribir ' 	B. Si la presi�n atmosf�rica es menor a 1010 hPa y la condici�n meteorol�gica es lluviosa, con una humedad mayor al 70%, entonces hay una alta probabilidad de lluvia fuerte.'
					Escribir '8. salir del programa.'
					Escribir '9. Ingresar datos a los datos meteorologicos'
					Definir continuar Como L�gico
					// Simulaci�n de apertura para escritura
					Definir salidaProyectoTxt Como L�gico
					Definir textoSalidaProyecto Como Cadena
					textoSalidaProyecto <- 'Usuario: '
					textoSalidaProyecto <- usuario
					textoSalidaProyecto <- 'Informe: '
					Repetir
						leerArchivo(DatosMet,cantidadDatos)
						Escribir 'Ingrese una opci�n ( 0 - 9 ): '
						Leer opcionMenu
						Si (opcionMenu<0 O opcionMenu>9) Entonces
							Escribir 'Usted ingreso un valor fuera de los valores del men�: '
							Escribir 'Ingrese un valor valido nuevamente: '
							Si (opcionMenu>=1 Y opcionMenu<=7) Entonces
								Si (opcionMenu==1) Entonces
									Escribir 'Especifique el rango de tiempo: '
									Escribir 'Fecha inicial: '
									Escribir 'A�o: '
									Leer anioInicio
									Escribir 'Mes: '
									Leer mesInicio
									Escribir 'Dia: '
									Leer diaInicio
									Escribir 'Fecha final: '
									Escribir 'A�o: '
									Leer anioFin
									Escribir 'Mes: '
									Leer mesFin
									Escribir 'Dia: '
									Leer diaFin
									Definir tempMaxima Como Real
									tempMaxima <- examinarTempMax(DatosMet,cantidadDatos,anioInicio,mesInicio,diaInicio,anioFin,mesFin,diaFin,anioMax,mesMax,diaMax)
									Escribir 'Temperatura maxima Registrada: ', tempMaxima, '�C el ', anioMax, '-', mesMax, '-', diaMax, ' en el lapso ', anioInicio, '-', mesInicio, '-', diaInicio, 'hasta', anioFin, '-', mesFin, '-', diaFin
								SiNo
									Si (opcionMenu==2) Entonces
										Escribir 'Especifique el rango de tiempo: '
										Escribir 'Fecha inicial: '
										Escribir 'A�o: '
										Leer anioInicio
										Escribir 'Mes: '
										Leer mesInicio
										Escribir 'Dia: '
										Leer diaInicio
										Escribir 'Fecha final: '
										Escribir 'A�o: '
										Leer anioFin
										Escribir 'Mes: '
										Leer mesFin
										Escribir 'Dia: '
										Leer diaFin
										Definir tempMinima Como Real
										tempMinima <- examinarTempMin(DatosMet,cantidadDatos,anioInicio,mesInicio,diaInicio,anioFin,mesFin,diaFin,anioMin,mesMin,diaMin)
										Escribir 'Temperatura minima Registrada: ', tempMaxima, '�C el ', anioMax, '-', mesMax, '-', diaMax, ' en el lapso ', anioInicio, '-', mesInicio, '-', diaInicio, 'hasta', anioFin, '-', mesFin, '-', diaFin
									SiNo
										Si (opcionMenu==3) Entonces
											Escribir 'Ingrese el a�o y el mes (en n�mero) dentro del cu�l se calcular� el promedio de la temperatura: '
											Definir anio, mes Como Entero
											Escribir 'A�o: '
											Leer anio
											Escribir 'Mes: '
											Leer mes
											nombreMes <- obtenerNombreMes(mes)
											Definir promTemp Como Real
											promTemp <- promedioTemp(cantiadadDatos,DatosMet,anio,mes)
											Escribir 'El promedio para el a�o', anio, ', mes', mes, ' es: ', promTemp, '�C'
										SiNo
											Si (opcionMenu == 4) Entonces
												Escribir "Mayor humerdad: "
												Escribir "A�o Mes Humedad Promedio Condici�n Meteorol�gica"
												salidaPromedio(salida,cantidadDatos,DatosMet, "mayor", "SI")
												salidaPromedio(salida,cantidadDatos,DatosMet, "mayor", "NO")
											SiNo
												Si(opcionMenu == 5) Entonces
													Escribir "Menor humerdad: "
													Escribir "A�o Mes Humedad Promedio Condici�n Meteorol�gica"
													salidaPromedio(salida,cantidadDatos,DatosMet, "menor", "SI")
													salidaPromedio(salida,cantidadDatos,DatosMet, "menor", "NO")
												SiNo
													Si(opcionMenu == 6)
														Escribir "Ingrese la fecha en la que desea ver si hay probabilidad de incendio"
														Definir anio, mes, dia Como Entero
														Escribir "A�o: "
														Leer anio
														Escribir "Mes: "
														Leer mes
														Escribir "Dia: "
														Leer dia
														probabilidad <- probabilidadIncendio (salida,cantidadDatos,DatosMet,"SI",dia,mes,anio)
														probabilidad <- probabilidadIncendio (salida,cantidadDatos,DatosMet,"NO",dia,mes,anio)
													SiNo
														Si(opcionMenu == 7)
															Escribir "Ingrese la fecha en la que desea ver si hay probabilidad de tormenta: "
															Definir anio, mes, dia Como Entero
															Escribir "A�o: "
															Leer anio
															Escribir "Mes: "
															Leer mes
															Escribir "Dia: "
															Leer dia
															probabilidad <- probabilidadTormenta (salida,cantidadDatos,DatosMet,"SI",dia,mes,anio)
															probabilidad <- probabilidadTormenta (salida,cantidadDatos,DatosMet,"NO",dia,mes,anio)
														FinSi
													FinSi
												FinSi
											FinSi
										FinSi
									FinSi
								FinSi
							FinSi
							Escribir "�Desea continuar? SI = 1 | NO = 2"
							Definir seguir Como Entero
							Leer seguir
							Mientras (seguir < 1 o seguir > 2)
								Escribir "Ingrese un valor valido nuevamente: "
								Leer seguir 
							FinMientras
							Si(seguir == 1) Entonces
								continuar = Verdadero
							FinSi
						SiNo
							Si(opcionMenu == 8) Entonces
								Escribir "Usted sali� del programa"
								continuar = Falso
							SiNo
								Si(opcion == 9) Entonces
									Definir anio, mes, dia Como Entero
									Definir presionAtm, humedad, velocidadViento, temperatura Como Real
									Definir clima Como Cadena
									Escribir "Ingrese el a�o: "
									Leer anio
									Escribir "Ingrese el mes: "
									Leer mes
									Escribir "Ingrese el dia: "
									Leer dia
									Escribir "Ingrese la temperatura (�C)"
									Leer temperatura
									Escribir "Ingrese el porcentaje de humedad: " 
									Leer humedad
									Escribir  "Ingrese la velocidad del viento (Km/h)"
									Leer velocidadViento
									Escribir "Ingrese la presi�n atmosf�rica (hPa)"
									Leer presionAtm
									Escribir "Ingrese la condic�n meteorol�gica (Nublado, Soleado, Lluvioso)"
									Leer clima
									Mientras (clima <> "Nublado" y clima <> "Soleado" y clima <> "Lluvioso")
										Escribir "Ingrese un valor valido nuevamente: "
										Leer clima
									FinMientras
									DatosMet[cantidadDatos] <- struct_condicionMeteorologica(anio,mes,dia,temperatura,humedad,velocidadViento,presionAtm,clima)
									cantidadDatos <- cantidadDatos + 1
									
									ordenarPorFecha(DatosMet,cantidadDatos)
									escribirArchivo(DatosMet,cantidadDatos)
								FinSi
							FinSi
						FinSi
					Hasta Que (continuar)
				SiNo
					Escribir "Nombre de usuario o contrasenia incorrectos."
					Escribir "Intente nuevamente o registese" 
				FinSi
			2:
				Escribir "Ingrese nombre de usuario"
				Leer usuario
				Escribir "Ingrese contrase�a"
				Leer password
				registrarUsuario(user,password)
				Escribir "Usuario registrado exitosamente."
			3:
				Escribir "Saliendo del programa..."
		FinSeg�n
	Hasta Que (eleccion=3)
FinAlgoritmo
