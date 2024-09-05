#include <iostream>
#include <vector>
#include <fstream> 
#include <random>
#include "../Algoritmos/algoritmos_TTP.cpp"
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

void pdc_ts(int enfoque_pdc){

    //Parametros TS PDC

    int iteraciones = 1000;
    vector<int> largos_listas_equipos = {8,4,2}; //largos en cada fase
    vector<int> largos_listas_fechas = {12,6,3}; //largos en cada fase
    vector<vector<int>>  probabilidades_operadores = {{10,10,10,35,35},{20,20,20,20,20},{26,27,27,10,10}}; //probalidades en cada fase

    //Parametros instancia

    int contador_fila = 0;

    int numero_solicitudes;
    int cantidad_equipos;
    int fecha_limite_vacaciones;

    vector<int> equipos_fuertes;
    vector<int> equipos_libertadores;
    vector<int> equipos_prelibertadores;
    vector<int> equipos_sudamericana;

    vector<int> equipos_zona_norte;
    vector<int> equipos_zona_centro;
    vector<int> equipos_zona_sur;
    vector<int> equipos_zonas_vacaciones;
    vector<int> equipos_santiago;

    vector<int> fechas_previas_prelibertadores;
    vector<int> fechas_posteriores_prelibertadores;
    vector<int> fechas_previas_libertadores;
    vector<int> fechas_posteriores_libertadores;
    vector<int> fechas_previas_sudamericana;
    vector<int> fechas_posteriores_sudamericana;
    
    vector<vector<int>> solicituedes_visitante;

    // ----------------------------------------------------- LECTURA INSTANCIA ------------------------------------------------------

    ifstream file("Funciones_Ligas/instanciaPDC.txt");

    string line;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila == 1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 2){ // equipos libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_libertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 3){ // equipos pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_prelibertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 4){ // equipos sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 5){ // equipos zona norte
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_norte.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 6){ // equipos zona centro
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_centro.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 7){ // equipos zona sur
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_sur.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 8){ // equipos zona vacaciones
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zonas_vacaciones.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 9){ // equipos de santiago
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_santiago.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 10){ // fechas previas pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 11){ // fechas posteriores pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 12){ // fechas previas libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 13){ // fechas posteriores libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 14){ // fechas previas sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == 15){ // fechas posteriores sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 16){
                fecha_limite_vacaciones = stoi(line);
            }
            else if (contador_fila == 17){ // solicitudes visitante
                numero_solicitudes = stoi(line);
            }
            else{
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            contador_fila++;
        }
    }
    else { 
        cout << "Unable to open file\n";
    }

    // se asume que los equipos participantes en pre libertadores van a acceder a libertadores

    for (int i = 0; i < equipos_prelibertadores.size(); i++){
        equipos_libertadores.push_back(equipos_prelibertadores[i]);
    }

    // -------------------------------------------------- FIN LECTURA INSTANCIA ------------------------------------------------------

    // generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(16);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);

    // calendarizacion generada con TS
    vector<vector<vector<int>>> ruedas_TS = tabu_search_pdc(enfoque_pdc, rueda1_inicial, rueda2_inicial, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante, largos_listas_equipos, largos_listas_fechas, probabilidades_operadores, iteraciones);

    vector<vector<int>> rueda1_TS = ruedas_TS[0];
    vector<vector<int>> rueda2_TS = ruedas_TS[1];
    
    int evaluacion_actual_TS = funcion_evaluacion_pdc(enfoque_pdc, rueda1_TS, rueda2_TS, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);
    
    print_calendarizacion(rueda1_TS, rueda2_TS);
    cout << "\nFixture PDC TS" << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_TS << endl;
    cout << "\nCosto restricciones: " << endl;

    print_costo_restricciones_pdc(enfoque_pdc, rueda1_TS, rueda2_TS, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores,
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores,
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);
    cout << "\n";

    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de TS" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_TS = hc_pdc(enfoque_pdc, rueda1_TS, rueda2_TS, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    int evaluacion_actual_HCMM_TS = funcion_evaluacion_pdc(enfoque_pdc, rueda1_TS, rueda2_TS, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);


    print_calendarizacion(ruedas_HCMM_TS[0], ruedas_HCMM_TS[1]);
    cout << "\nFixture HCMM_TS" << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_TS << endl;
    cout << "\n";

    print_costo_restricciones_pdc(enfoque_pdc, ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);


    // -------------------------------------------------- REVISIONES ------------------------------------------------------

    /*

    // contandos fechas disputadas de local por rueada
    for (int i = 0; i < 16; i++){
        int contador = 0;
        for (int j = 0; j < 15; j++){
            if (rueda1_TS[i][j] > 0){
                contador++;
            }
        }
        cout << "Equipo " << i+1 << " juega " << contador << " partidos de local en la rueda 1" << endl;
    }
    

    // revisiones que este correcto el fixture respecto a restricciones base
    
    cout << "Contando signos negativos por columna" << endl;

    cout << "Rueda 1" << endl;

    for (int i = 0; i < 15; i++){
        int contador = 0;
        for (int j = 0; j < 16; j++){
            if (rueda1_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    cout << "Rueda 2" << endl;

    for (int i = 0; i < 15; i++){
        int contador = 0;
        for (int j = 0; j < 16; j++){
            if (rueda2_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }
    

    int contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 15; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_TS[i][j]);
            for (int k = 0; k < 15; k++){ // rueda2
                if (abs(rueda2_TS[i][k]) == rival_primera_rueda){
                    if (rueda1_TS[i][j] > 0 && rueda2_TS[i][k] > 0 || rueda1_TS[i][j] < 0 && rueda2_TS[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }

    cout << "Errores encontrados: " << contador_errores_localias_inversas << endl;

    int contador_errores_sumatoria_columna = 0;
    int suma_col;

    //rueda 1
    for (int i = 0; i < 15; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 16; j++){ // por equipo
            suma_col += abs(rueda1_TS[j][i]);
        }
        if (suma_col != 136){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 15; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 16; j++){ // por equipo
            suma_col += abs(rueda2_TS[j][i]);
        }
        if (suma_col != 136){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    vector<int> equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for (int i = 0; i <16; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 15; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_TS[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 15; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_TS[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    int error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 15; j++){
        for (int i = 0; i < 16; i++){
            int rival = abs(rueda1_TS[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_TS[i][j] > 0 && rueda1_TS[rival-1][j] > 0 || rueda1_TS[i][j] < 0 && rueda1_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 15; j++){
        for (int i = 0; i < 16; i++){
            int rival = abs(rueda2_TS[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+17 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_TS[i][j] > 0 && rueda2_TS[rival-1][j] > 0 || rueda2_TS[i][j] < 0 && rueda2_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+17 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;
    */
}

void pdc_sa(int enfoque_pdc){

    // Parametros SA PDC

    int tempertura = 4058;
    float tasa_enfriamiento = 0.9722; 
    int cambios_temperatura = 25;
    int cantidad_iteraciones = 5000;

    //Parametros instancia

    int contador_fila = 0;

    int numero_solicitudes;
    int cantidad_equipos;
    int fecha_limite_vacaciones;

    vector<int> equipos_fuertes;
    vector<int> equipos_libertadores;
    vector<int> equipos_prelibertadores;
    vector<int> equipos_sudamericana;

    vector<int> equipos_zona_norte;
    vector<int> equipos_zona_centro;
    vector<int> equipos_zona_sur;
    vector<int> equipos_zonas_vacaciones;
    vector<int> equipos_santiago;

    vector<int> fechas_previas_prelibertadores;
    vector<int> fechas_posteriores_prelibertadores;
    vector<int> fechas_previas_libertadores;
    vector<int> fechas_posteriores_libertadores;
    vector<int> fechas_previas_sudamericana;
    vector<int> fechas_posteriores_sudamericana;
    
    vector<vector<int>> solicituedes_visitante;

    // ----------------------------------------------------- LECTURA INSTANCIA ------------------------------------------------------

    ifstream file("Funciones_Ligas/instanciaPDC.txt");

    string line;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila == 1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 2){ // equipos libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_libertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 3){ // equipos pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_prelibertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 4){ // equipos sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 5){ // equipos zona norte
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_norte.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 6){ // equipos zona centro
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_centro.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 7){ // equipos zona sur
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_sur.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 8){ // equipos zona vacaciones
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zonas_vacaciones.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 9){ // equipos de santiago
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_santiago.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 10){ // fechas previas pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 11){ // fechas posteriores pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 12){ // fechas previas libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 13){ // fechas posteriores libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 14){ // fechas previas sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == 15){ // fechas posteriores sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 16){
                fecha_limite_vacaciones = stoi(line);
            }
            else if (contador_fila == 17){ // solicitudes visitante
                numero_solicitudes = stoi(line);
            }
            else{
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            contador_fila++;
        }
    }
    else { 
        cout << "Unable to open file\n";
    }

    // se asume que los equipos participantes en pre libertadores van a acceder a libertadores

    for (int i = 0; i < equipos_prelibertadores.size(); i++){
        equipos_libertadores.push_back(equipos_prelibertadores[i]);
    }

    // -------------------------------------------------- FIN LECTURA INSTANCIA ------------------------------------------------------

    // generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(16);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);

    // calendarizacion generada con SA
    vector<vector<vector<int>>> ruedas_SA = sa_pdc(enfoque_pdc, rueda1_inicial, rueda2_inicial, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante, tempertura, cantidad_iteraciones, tasa_enfriamiento, cambios_temperatura);

    vector<vector<int>> rueda1_SA = ruedas_SA[0];
    vector<vector<int>> rueda2_SA = ruedas_SA[1];
    
    int evaluacion_actual_SA = funcion_evaluacion_pdc(enfoque_pdc, rueda1_SA, rueda2_SA, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    print_calendarizacion(rueda1_SA, rueda2_SA);
    cout << "\nFixture PDC SA" << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_SA << endl;

    cout << "\nCosto de restricciones" << endl;
    print_costo_restricciones_pdc(enfoque_pdc, rueda1_SA, rueda2_SA, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores,
    equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores,
    fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de SA" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_SA = hc_pdc(enfoque_pdc, rueda1_SA, rueda2_SA, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    int evaluacion_actual_HCMM_SA = funcion_evaluacion_pdc(enfoque_pdc, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);
    cout << "\nFixture HCMM_SA" << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_SA << endl;
    cout << "\n";

    print_calendarizacion(ruedas_HCMM_SA[0], ruedas_HCMM_SA[1]);

    print_costo_restricciones_pdc(enfoque_pdc, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    // -------------------------------------------------- REVISIONES ------------------------------------------------------

    /*
    cout << "\n";

    //cout << "Rueda 1" << endl;

    for (int i = 0; i < 15; i++){
        int contador = 0;
        for (int j = 0; j < 16; j++){
            if (rueda1_SA[j][i] < 0){
                contador++;
            }
        }
        //cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    //cout << "Rueda 2" << endl;

    for (int i = 0; i < 15; i++){
        int contador = 0;
        for (int j = 0; j < 16; j++){
            if (rueda2_SA[j][i] < 0){
                contador++;
            }
        }
        //cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    int contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 15; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_SA[i][j]);
            for (int k = 0; k < 15; k++){ // rueda2
                if (abs(rueda2_SA[i][k]) == rival_primera_rueda){
                    if (rueda1_SA[i][j] > 0 && rueda2_SA[i][k] > 0 || rueda1_SA[i][j] < 0 && rueda2_SA[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }
    

    cout << "Errores encontrados: " << contador_errores_localias_inversas << endl;

    int contador_errores_sumatoria_columna = 0;
    int suma_col;

    //rueda 1
    for (int i = 0; i < 15; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 16; j++){ // por equipo
            suma_col += abs(rueda1_SA[j][i]);
        }
        if (suma_col != 136){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 15; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 16; j++){ // por equipo
            suma_col += abs(rueda2_SA[j][i]);
        }
        if (suma_col != 136){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    vector<int> equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    for (int i = 0; i <16; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 15; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_SA[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 15; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_SA[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    int error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 15; j++){
        for (int i = 0; i < 16; i++){
            int rival = abs(rueda1_SA[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_SA[i][j] > 0 && rueda1_SA[rival-1][j] > 0 || rueda1_SA[i][j] < 0 && rueda1_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 15; j++){
        for (int i = 0; i < 16; i++){
            int rival = abs(rueda2_SA[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+17 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_SA[i][j] > 0 && rueda2_SA[rival-1][j] > 0 || rueda2_SA[i][j] < 0 && rueda2_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+17 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;
    */
}

void epl_ts_1314(){ 

    // Parmetros TS EPL 13/14

    int iteraciones = 1000;
    vector<int> largos_listas_equipos = {10,5,2}; //largos en cada fase
    vector<int> largos_listas_fechas = {16,8,3}; //largos en cada fase
    vector<vector<int>>  probabilidades_operadores = {{10,10,10,35,35},{20,20,20,20,20},{26,27,27,10,10}}; //probalidades en cada fase
   
    // ---------------------------------------------------- lectura de instanica EPL ----------------------------------------------------

    int contador_fila = 0;
    int numero_solicitudes;
    vector<int> aux_distancias;

    int cantidad_equipos;
    int fecha_boxing_day;
    int fecha_new_year;
    int distancia_optima;
    vector<int> equipos_fuertes;
    vector<int> equipos_UCL;
    vector<int> equipos_UEL;
    vector<int> equipos_UECL;
    vector<int> equipos_emparejados;
    vector<int> fechas_previas_FA_Cup;
    vector<int> fechas_posteriores_FA_Cup;
    vector<int> fechas_previas_UCL;
    vector<int> fechas_posteriores_UCL;
    vector<int> fechas_previas_UEL;
    vector<int> fechas_posteriores_UEL;
    vector<int> fechas_previas_UECL;
    vector<int> fechas_posteriores_UECL;
    vector<int> fechas_bank_holidays;
    vector<vector<int>> solicituedes_visitante; // tuplas [equipo,fecha]
    vector<vector<int>> distancias;

    ifstream file("Funciones_Ligas/instanciaPL1314.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        // Read each line from the file and store it in the 
        // 'line' variable. 
        while (getline(file, line)) { 
            //cout << line << endl;
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila <= cantidad_equipos){ //distancias
                //cout << "Equipo: " << line << endl;
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                //cout << vstrings[19] << endl;

                aux_distancias.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    if (vstrings[i] == "M"){
                        aux_distancias.push_back(10000);
                    }
                    else{
                        aux_distancias.push_back(stoi(vstrings[i]));
                    }
                }
                distancias.push_back(aux_distancias);
            }
            else if (contador_fila == cantidad_equipos+1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+2){ // equipos UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+3){ // equipos UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+4){ // equipos UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+5){ // equipos emparejados
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_emparejados.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+6){ // fechas previas FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+7){ // fechas posteriores FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+8){ // fechas previas UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+9){ // fechas posteriores UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+10){ // fechas previas UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+11){ // fechas posteriores UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+12){ // fechas previas UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+13){ // fechas posteriores UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+14){ // numero solicituedes visitante
                numero_solicitudes = stoi(line);
            }
            else if(contador_fila >= cantidad_equipos+15 && contador_fila < cantidad_equipos+15 + numero_solicitudes){ //solicitudes visitante
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            else if(contador_fila == cantidad_equipos+ 15 + numero_solicitudes){ // fechas bank holidays
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_bank_holidays.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == cantidad_equipos+ 16 + numero_solicitudes){ // fecha boxing day
                fecha_boxing_day = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 17 + numero_solicitudes){ // fecha new year
                fecha_new_year = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 18 + numero_solicitudes){ // distancia optima
                distancia_optima = stoi(line);
            }
            contador_fila++;
        } 
  
        // Close the file stream once all lines have been 
        // read. 
        file.close(); 
    } 
    else { 
        // Print an error message to the standard error 
        // stream if the file cannot be opened. 
        cout << "Unable to open file\n";
    }

    // Los premios entregados en el Conference League son similares a los de la Europa League y se disputan en las mismas fechas
    // Por este motivo, se va a incluir a los equipos de confernce en la lista de equipos que juegan la UEL para no modificar mas restricciones

    for (int i = 0; i < equipos_UECL.size(); i++){
        if (equipos_UECL[i] != 0){
            equipos_UEL.push_back(equipos_UECL[i]);
        }
    }

    // En vista que la PL es mucho mas imporante que la UEL, las restricciones 102d y 102f solo se consideran que el equipo que juega la UEL es fuerte
    // Eliminando equipos no fuertes de los que disputan la UEL

    vector<int> equipos_UEL_aux = equipos_UEL;
    for (int i = 0; i < equipos_UEL_aux.size(); i++){
        if (find(equipos_fuertes.begin(), equipos_fuertes.end(), equipos_UEL_aux[i]) == equipos_fuertes.end()){
            equipos_UEL.erase(remove(equipos_UEL.begin(), equipos_UEL.end(), equipos_UEL_aux[i]), equipos_UEL.end());
        }
    }


    // ------------------------------------------------- fin lectura de instanica EPL ---------------------------------------------------

    // generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(20);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);
    
    // calendarizacion generada con TS
    vector<vector<vector<int>>> ruedas_TS = tabu_search_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_inicial, rueda2_inicial, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias, largos_listas_equipos, largos_listas_fechas, probabilidades_operadores, iteraciones);

    vector<vector<int>> rueda1_TS = ruedas_TS[0];
    vector<vector<int>> rueda2_TS = ruedas_TS[1];

    int evaluacion_actual_TS = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_TS = distancia_festivos(rueda1_TS, rueda2_TS, distancias, fecha_boxing_day, fecha_new_year);

    print_calendarizacion(rueda1_TS, rueda2_TS);
    cout << "\nFixture TS" << endl;
    cout << "Distancia total: " << distancia_total_TS << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_TS << endl;
    cout << "\n";

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de TS" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_TS = hill_climbing_epl_mejor_mejora(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    int evaluacion_actual_HCMM_TS = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_HCMM_TS = distancia_festivos(ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], distancias, fecha_boxing_day, fecha_new_year);

    print_calendarizacion(ruedas_HCMM_TS[0], ruedas_HCMM_TS[1]);
    cout << "\nFixture HCMM_TS" << endl;
    cout << "Distancia total: " << distancia_total_HCMM_TS << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_TS << endl;
    cout << "\n";

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
 
    // -------------------------------------------------- REVISIONES ------------------------------------------------------
    /*

    // para revision de HC

    rueda1_TS = ruedas_HCMM_TS[0];
    rueda2_TS = ruedas_HCMM_TS[1];

    cout << "Contando signos negativos por columna" << endl;

    cout << "Rueda 1" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda1_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    cout << "Rueda 2" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda2_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 19; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_TS[i][j]);
            for (int k = 0; k < 19; k++){ // rueda2
                if (abs(rueda2_TS[i][k]) == rival_primera_rueda){
                    if (rueda1_TS[i][j] > 0 && rueda2_TS[i][k] > 0 || rueda1_TS[i][j] < 0 && rueda2_TS[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }

    cout << "Errores encontrados: " << contador_errores_localias_inversas << endl;

    contador_errores_sumatoria_columna = 0;

    //rueda 1
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda1_TS[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda2_TS[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <20; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 19; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_TS[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 19; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_TS[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda1_TS[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_TS[i][j] > 0 && rueda1_TS[rival-1][j] > 0 || rueda1_TS[i][j] < 0 && rueda1_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda2_TS[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_TS[i][j] > 0 && rueda2_TS[rival-1][j] > 0 || rueda2_TS[i][j] < 0 && rueda2_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;
    */

} 

void epl_sa_1314(){

    // Parametros SA EPL 13/14

    int tempertura = 897;
    float tasa_enfriamiento = 0.958; 
    int cambios_temperatura = 12;
    int cantidad_iteraciones = 5000;
    int iter_sin_mejora = 300;
    float tasa_recalentamiento = 1; // si es 1 no hay reheat

    //Parametros instancia
   
    // ---------------------------------------------------- lectura de instanica EPL ----------------------------------------------------

    int contador_fila = 0;
    int numero_solicitudes;
    vector<int> aux_distancias;

    int cantidad_equipos;
    int fecha_boxing_day;
    int fecha_new_year;
    int distancia_optima;
    vector<int> equipos_fuertes;
    vector<int> equipos_UCL;
    vector<int> equipos_UEL;
    vector<int> equipos_UECL;
    vector<int> equipos_emparejados;
    vector<int> fechas_previas_FA_Cup;
    vector<int> fechas_posteriores_FA_Cup;
    vector<int> fechas_previas_UCL;
    vector<int> fechas_posteriores_UCL;
    vector<int> fechas_previas_UEL;
    vector<int> fechas_posteriores_UEL;
    vector<int> fechas_previas_UECL;
    vector<int> fechas_posteriores_UECL;
    vector<int> fechas_bank_holidays;
    vector<vector<int>> solicituedes_visitante; // tuplas [equipo,fecha]
    vector<vector<int>> distancias;

    ifstream file("Funciones_Ligas/instanciaPL1314.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        // Read each line from the file and store it in the 
        // 'line' variable. 
        while (getline(file, line)) { 
            //cout << line << endl;
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila <= cantidad_equipos){ //distancias
                //cout << "Equipo: " << line << endl;
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                //cout << vstrings[19] << endl;

                aux_distancias.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    if (vstrings[i] == "M"){
                        aux_distancias.push_back(10000);
                    }
                    else{
                        aux_distancias.push_back(stoi(vstrings[i]));
                    }
                }
                distancias.push_back(aux_distancias);
            }
            else if (contador_fila == cantidad_equipos+1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+2){ // equipos UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+3){ // equipos UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+4){ // equipos UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+5){ // equipos emparejados
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_emparejados.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+6){ // fechas previas FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+7){ // fechas posteriores FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+8){ // fechas previas UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+9){ // fechas posteriores UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+10){ // fechas previas UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+11){ // fechas posteriores UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+12){ // fechas previas UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+13){ // fechas posteriores UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+14){ // numero solicituedes visitante
                numero_solicitudes = stoi(line);
            }
            else if(contador_fila >= cantidad_equipos+15 && contador_fila < cantidad_equipos+15 + numero_solicitudes){ //solicitudes visitante
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            else if(contador_fila == cantidad_equipos+ 15 + numero_solicitudes){ // fechas bank holidays
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_bank_holidays.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == cantidad_equipos+ 16 + numero_solicitudes){ // fecha boxing day
                fecha_boxing_day = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 17 + numero_solicitudes){ // fecha new year
                fecha_new_year = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 18 + numero_solicitudes){ // distancia optima
                distancia_optima = stoi(line);
            }
            contador_fila++;
        } 
  
        // Close the file stream once all lines have been 
        // read. 
        file.close(); 
    } 
    else { 
        // Print an error message to the standard error 
        // stream if the file cannot be opened. 
        cout << "Unable to open file\n";
    }

    // Los premios entregados en el Conference League son similares a los de la Europa League y se disputan en las mismas fechas
    // Por este motivo, se va a incluir a los equipos de confernce en la lista de equipos que juegan la UEL para no modificar mas restricciones

    for (int i = 0; i < equipos_UECL.size(); i++){
        if (equipos_UECL[i] != 0){
            equipos_UEL.push_back(equipos_UECL[i]);
        }
    }

    // En vista que la PL es mucho mas imporante que la UEL, las restricciones 102d y 102f solo se consideran que el equipo que juega la UEL es fuerte
    // Eliminando equipos no fuertes de los que disputan la UEL

    vector<int> equipos_UEL_aux = equipos_UEL;
    for (int i = 0; i < equipos_UEL_aux.size(); i++){
        if (find(equipos_fuertes.begin(), equipos_fuertes.end(), equipos_UEL_aux[i]) == equipos_fuertes.end()){
            equipos_UEL.erase(remove(equipos_UEL.begin(), equipos_UEL.end(), equipos_UEL_aux[i]), equipos_UEL.end());
        }
    }


    // ------------------------------------------------- fin lectura de instanica EPL ---------------------------------------------------

    //generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(20);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);
    
    // calendarizacion generada con SA
    vector<vector<vector<int>>> ruedas_SA = sa_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_inicial, rueda2_inicial, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias, tempertura, cantidad_iteraciones, tasa_enfriamiento, cambios_temperatura, iter_sin_mejora, tasa_recalentamiento);

    vector<vector<int>> rueda1_SA = ruedas_SA[0];
    vector<vector<int>> rueda2_SA = ruedas_SA[1];

    int evaluacion_actual_SA = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_SA = distancia_festivos(rueda1_SA, rueda2_SA, distancias, fecha_boxing_day, fecha_new_year);

    print_calendarizacion(rueda1_SA, rueda2_SA);
    cout << "\nFixture SA" << endl;
    cout << "Distancia total: " << distancia_total_SA << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_SA << endl;
    cout << "\n";

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de SA" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_SA = hill_climbing_epl_mejor_mejora(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    int evaluacion_actual_HCMM_SA = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_HCMM_SA = distancia_festivos(ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], distancias, fecha_boxing_day, fecha_new_year);

    cout << "\nFixture HCMM_SA" << endl;
    cout << "Distancia total: " << distancia_total_HCMM_SA << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_SA << endl;
    cout << "\n";

    print_calendarizacion(ruedas_HCMM_SA[0], ruedas_HCMM_SA[1]);

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    // -------------------------------------------------- REVISIONES ------------------------------------------------------

    /*

    // para revision de HC

    rueda1_SA = ruedas_HCMM_SA[0];
    rueda2_SA = ruedas_HCMM_SA[1];

    cout << "Contando signos negativos por columna" << endl;

    cout << "Rueda 1" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda1_SA[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    cout << "Rueda 2" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda2_SA[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }
    

    int contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 19; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_SA[i][j]);
            for (int k = 0; k < 19; k++){ // rueda2
                if (abs(rueda2_SA[i][k]) == rival_primera_rueda){
                    if (rueda1_SA[i][j] > 0 && rueda2_SA[i][k] > 0 || rueda1_SA[i][j] < 0 && rueda2_SA[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }

    cout << "\nErrores encontrados: " << contador_errores_localias_inversas << endl;

    int contador_errores_sumatoria_columna = 0;
    int suma_col;

    //rueda 1
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda1_SA[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda2_SA[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    vector<int> equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <20; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 19; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_SA[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 19; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_SA[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    int error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda1_SA[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_SA[i][j] > 0 && rueda1_SA[rival-1][j] > 0 || rueda1_SA[i][j] < 0 && rueda1_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda2_SA[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_SA[i][j] > 0 && rueda2_SA[rival-1][j] > 0 || rueda2_SA[i][j] < 0 && rueda2_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;

    */
} 

void epl_ts_2324(){

    // Parmetros TS EPL 23/24

    int iteraciones = 100;
    vector<int> largos_listas_equipos = {10,5,2}; //largos en cada fase
    vector<int> largos_listas_fechas = {16,8,3}; //largos en cada fase
    vector<vector<int>>  probabilidades_operadores = {{10,10,10,35,35},{20,20,20,20,20},{26,27,27,10,10}}; //probalidades en cada fase
   
    // ---------------------------------------------------- lectura de instanica EPL ----------------------------------------------------

    int contador_fila = 0;
    int numero_solicitudes;
    vector<int> aux_distancias;

    int cantidad_equipos;
    int fecha_boxing_day;
    int fecha_new_year;
    int distancia_optima;
    vector<int> equipos_fuertes;
    vector<int> equipos_UCL;
    vector<int> equipos_UEL;
    vector<int> equipos_UECL;
    vector<int> equipos_emparejados;
    vector<int> fechas_previas_FA_Cup;
    vector<int> fechas_posteriores_FA_Cup;
    vector<int> fechas_previas_UCL;
    vector<int> fechas_posteriores_UCL;
    vector<int> fechas_previas_UEL;
    vector<int> fechas_posteriores_UEL;
    vector<int> fechas_previas_UECL;
    vector<int> fechas_posteriores_UECL;
    vector<int> fechas_bank_holidays;
    vector<vector<int>> solicituedes_visitante; // tuplas [equipo,fecha]
    vector<vector<int>> distancias;

    ifstream file("Funciones_Ligas/instanciaPL2324.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        // Read each line from the file and store it in the 
        // 'line' variable. 
        while (getline(file, line)) { 
            //cout << line << endl;
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila <= cantidad_equipos){ //distancias
                //cout << "Equipo: " << line << endl;
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                //cout << vstrings[19] << endl;

                aux_distancias.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    if (vstrings[i] == "M"){
                        aux_distancias.push_back(10000);
                    }
                    else{
                        aux_distancias.push_back(stoi(vstrings[i]));
                    }
                }
                distancias.push_back(aux_distancias);
            }
            else if (contador_fila == cantidad_equipos+1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+2){ // equipos UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+3){ // equipos UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+4){ // equipos UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+5){ // equipos emparejados
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_emparejados.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+6){ // fechas previas FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+7){ // fechas posteriores FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+8){ // fechas previas UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+9){ // fechas posteriores UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+10){ // fechas previas UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+11){ // fechas posteriores UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+12){ // fechas previas UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+13){ // fechas posteriores UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+14){ // numero solicituedes visitante
                numero_solicitudes = stoi(line);
            }
            else if(contador_fila >= cantidad_equipos+15 && contador_fila < cantidad_equipos+15 + numero_solicitudes){ //solicitudes visitante
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            else if(contador_fila == cantidad_equipos+ 15 + numero_solicitudes){ // fechas bank holidays
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_bank_holidays.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == cantidad_equipos+ 16 + numero_solicitudes){ // fecha boxing day
                fecha_boxing_day = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 17 + numero_solicitudes){ // fecha new year
                fecha_new_year = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 18 + numero_solicitudes){ // distancia optima
                distancia_optima = stoi(line);
            }
            contador_fila++;
        } 
  
        // Close the file stream once all lines have been 
        // read. 
        file.close(); 
    } 
    else { 
        // Print an error message to the standard error 
        // stream if the file cannot be opened. 
        cout << "Unable to open file\n";
    }

    // Los premios entregados en el Conference League son similares a los de la Europa League y se disputan en las mismas fechas
    // Por este motivo, se va a incluir a los equipos de confernce en la lista de equipos que juegan la UEL para no modificar mas restricciones

    for (int i = 0; i < equipos_UECL.size(); i++){
        if (equipos_UECL[i] != 0){
            equipos_UEL.push_back(equipos_UECL[i]);
        }
    }

    // ------------------------------------------------- fin lectura de instanica EPL ---------------------------------------------------

    // generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(20);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);
    
    // calendarizacion generada con TS
    vector<vector<vector<int>>> ruedas_TS = tabu_search_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_inicial, rueda2_inicial, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias, largos_listas_equipos, largos_listas_fechas, probabilidades_operadores, iteraciones);

    vector<vector<int>> rueda1_TS = ruedas_TS[0];
    vector<vector<int>> rueda2_TS = ruedas_TS[1];

    int evaluacion_actual_TS = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_TS = distancia_festivos(rueda1_TS, rueda2_TS, distancias, fecha_boxing_day, fecha_new_year);


    print_calendarizacion(rueda1_TS, rueda2_TS);
    cout << "\nFixture TS" << endl;
    cout << "Distancia total: " << distancia_total_TS << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_TS << endl;
    cout << "\nCosto de restricciones" << endl;
    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de TS" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_TS = hill_climbing_epl_mejor_mejora(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_TS, rueda2_TS, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    int evaluacion_actual_HCMM_TS = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_HCMM_TS = distancia_festivos(ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], distancias, fecha_boxing_day, fecha_new_year);

    print_calendarizacion(ruedas_HCMM_TS[0], ruedas_HCMM_TS[1]);
    cout << "\nFixture HCMM_TS" << endl;
    cout << "Distancia total: " << distancia_total_HCMM_TS << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_TS << endl;
    cout << "\n";

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_TS[0], ruedas_HCMM_TS[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
 
    // -------------------------------------------------- REVISIONES ------------------------------------------------------

    /*

    // para revision de HC

    rueda1_TS = ruedas_HCMM_TS[0];
    rueda2_TS = ruedas_HCMM_TS[1];

    cout << "Contando signos negativos por columna" << endl;

    cout << "Rueda 1" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda1_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    cout << "Rueda 2" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda2_TS[j][i] < 0){
                contador++;
            }
        }
        cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 19; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_TS[i][j]);
            for (int k = 0; k < 19; k++){ // rueda2
                if (abs(rueda2_TS[i][k]) == rival_primera_rueda){
                    if (rueda1_TS[i][j] > 0 && rueda2_TS[i][k] > 0 || rueda1_TS[i][j] < 0 && rueda2_TS[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }

    cout << "Errores encontrados: " << contador_errores_localias_inversas << endl;

    contador_errores_sumatoria_columna = 0;

    //rueda 1
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda1_TS[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda2_TS[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <20; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 19; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_TS[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 19; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_TS[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda1_TS[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_TS[i][j] > 0 && rueda1_TS[rival-1][j] > 0 || rueda1_TS[i][j] < 0 && rueda1_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda2_TS[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_TS[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_TS[i][j] > 0 && rueda2_TS[rival-1][j] > 0 || rueda2_TS[i][j] < 0 && rueda2_TS[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;
    */
} 

void epl_sa_2324(){

    // Parametros SA EPL 23/24

    int tempertura = 1000;
    float tasa_enfriamiento = 0.8; 
    int cambios_temperatura = 5;
    int cantidad_iteraciones = 50;
    int iter_sin_mejora = 50;
    float tasa_recalentamiento = 1.1;

    //Parametros instancia
   
    // ---------------------------------------------------- lectura de instanica EPL ----------------------------------------------------

    int contador_fila = 0;
    int numero_solicitudes;
    vector<int> aux_distancias;

    int cantidad_equipos;
    int fecha_boxing_day;
    int fecha_new_year;
    int distancia_optima;
    vector<int> equipos_fuertes;
    vector<int> equipos_UCL;
    vector<int> equipos_UEL;
    vector<int> equipos_UECL;
    vector<int> equipos_emparejados;
    vector<int> fechas_previas_FA_Cup;
    vector<int> fechas_posteriores_FA_Cup;
    vector<int> fechas_previas_UCL;
    vector<int> fechas_posteriores_UCL;
    vector<int> fechas_previas_UEL;
    vector<int> fechas_posteriores_UEL;
    vector<int> fechas_previas_UECL;
    vector<int> fechas_posteriores_UECL;
    vector<int> fechas_bank_holidays;
    vector<vector<int>> solicituedes_visitante; // tuplas [equipo,fecha]
    vector<vector<int>> distancias;

    ifstream file("Funciones_Ligas/instanciaPL2324.txt"); 
  
    // String to store each line of the file. 
    string line; 
  
    if (file.is_open()) { 
        // Read each line from the file and store it in the 
        // 'line' variable. 
        while (getline(file, line)) { 
            //cout << line << endl;
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila <= cantidad_equipos){ //distancias
                //cout << "Equipo: " << line << endl;
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                //cout << vstrings[19] << endl;

                aux_distancias.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    if (vstrings[i] == "M"){
                        aux_distancias.push_back(10000);
                    }
                    else{
                        aux_distancias.push_back(stoi(vstrings[i]));
                    }
                }
                distancias.push_back(aux_distancias);
            }
            else if (contador_fila == cantidad_equipos+1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+2){ // equipos UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+3){ // equipos UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+4){ // equipos UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+5){ // equipos emparejados
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_emparejados.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+6){ // fechas previas FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+7){ // fechas posteriores FA Cup
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_FA_Cup.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+8){ // fechas previas UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+9){ // fechas posteriores UCL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UCL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+10){ // fechas previas UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+11){ // fechas posteriores UEL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UEL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+12){ // fechas previas UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+13){ // fechas posteriores UECL
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_UECL.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == cantidad_equipos+14){ // numero solicituedes visitante
                numero_solicitudes = stoi(line);
            }
            else if(contador_fila >= cantidad_equipos+15 && contador_fila < cantidad_equipos+15 + numero_solicitudes){ //solicitudes visitante
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            else if(contador_fila == cantidad_equipos+ 15 + numero_solicitudes){ // fechas bank holidays
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_bank_holidays.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == cantidad_equipos+ 16 + numero_solicitudes){ // fecha boxing day
                fecha_boxing_day = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 17 + numero_solicitudes){ // fecha new year
                fecha_new_year = stoi(line);
            }
            else if(contador_fila == cantidad_equipos+ 18 + numero_solicitudes){ // distancia optima
                distancia_optima = stoi(line);
            }
            contador_fila++;
        } 
  
        // Close the file stream once all lines have been 
        // read. 
        file.close(); 
    } 
    else { 
        // Print an error message to the standard error 
        // stream if the file cannot be opened. 
        cout << "Unable to open file\n";
    }

    // Los premios entregados en el Conference League son similares a los de la Europa League y se disputan en las mismas fechas
    // Por este motivo, se va a incluir a los equipos de confernce en la lista de equipos que juegan la UEL para no modificar mas restricciones

    for (int i = 0; i < equipos_UECL.size(); i++){
        if (equipos_UECL[i] != 0){
            equipos_UEL.push_back(equipos_UECL[i]);
        }
    }

    // ------------------------------------------------- fin lectura de instanica EPL ---------------------------------------------------
    
    //generando calendarizacion inicial
    vector<vector<int>> rueda1_inicial = creacion_fixture_inicial(20);
    vector<vector<int>> rueda2_inicial = generacion_rueda_mirrored(rueda1_inicial);
    
    // calendarizacion generada con SA
    vector<vector<vector<int>>> ruedas_SA = sa_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_inicial, rueda2_inicial, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias, tempertura, cantidad_iteraciones, tasa_enfriamiento, cambios_temperatura, iter_sin_mejora, tasa_recalentamiento);

    vector<vector<int>> rueda1_SA = ruedas_SA[0];
    vector<vector<int>> rueda2_SA = ruedas_SA[1];

    int evaluacion_actual_SA = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_SA = distancia_festivos(rueda1_SA, rueda2_SA, distancias, fecha_boxing_day, fecha_new_year);

    print_calendarizacion(rueda1_SA, rueda2_SA);
    cout << "\nFixture SA" << endl;
    cout << "Distancia total: " << distancia_total_SA << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_SA << endl;

    cout << "\nCosto de restricciones" << endl;
    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    
    // -------------------------------------------------- HILL CLIMBING ------------------------------------------------------

    cout << "\nAplicando Hill Climbing mejor mejora con solucion de SA" << endl;

    vector<vector<vector<int>>> ruedas_HCMM_SA = hill_climbing_epl_mejor_mejora(distancia_optima, fecha_boxing_day, fecha_new_year, rueda1_SA, rueda2_SA, equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);

    int evaluacion_actual_HCMM_SA = funcion_evaluacion_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    int distancia_total_HCMM_SA = distancia_festivos(ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], distancias, fecha_boxing_day, fecha_new_year);

    cout << "\nFixture HCMM_SA" << endl;
    cout << "Distancia total: " << distancia_total_HCMM_SA << endl;
    cout << "Valor evaluacion: " << evaluacion_actual_HCMM_SA << endl;
    cout << "\n";

    print_calendarizacion(ruedas_HCMM_SA[0], ruedas_HCMM_SA[1]);

    print_costo_restricciones_epl(distancia_optima, fecha_boxing_day, fecha_new_year, ruedas_HCMM_SA[0], ruedas_HCMM_SA[1], equipos_fuertes, equipos_UCL, equipos_UEL, equipos_UECL, equipos_emparejados, fechas_previas_FA_Cup, fechas_posteriores_FA_Cup, fechas_previas_UCL, fechas_posteriores_UCL, fechas_previas_UEL, fechas_posteriores_UEL, fechas_previas_UECL, fechas_posteriores_UECL, fechas_bank_holidays, solicituedes_visitante, distancias);
    

    // -------------------------------------------------- REVISIONES ------------------------------------------------------
    /*

    // para revision de HC

    rueda1_SA = ruedas_HCMM_SA[0];
    rueda2_SA = ruedas_HCMM_SA[1];

    //cout << "Contando signos negativos por columna" << endl;

    //cout << "Rueda 1" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda1_SA[j][i] < 0){
                contador++;
            }
        }
        //cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    //cout << "Rueda 2" << endl;

    for (int i = 0; i < 19; i++){
        int contador = 0;
        for (int j = 0; j < 20; j++){
            if (rueda2_SA[j][i] < 0){
                contador++;
            }
        }
        //cout << "Fecha " << i+1 << ": " << contador << endl;
    }

    int contador_errores_localias_inversas = 0;

    //revisando que las localias esten invertidas por equipos
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 19; j++){ //rueda1
            int rival_primera_rueda = abs(rueda1_SA[i][j]);
            for (int k = 0; k < 19; k++){ // rueda2
                if (abs(rueda2_SA[i][k]) == rival_primera_rueda){
                    if (rueda1_SA[i][j] > 0 && rueda2_SA[i][k] > 0 || rueda1_SA[i][j] < 0 && rueda2_SA[i][k] < 0){
                        cout << "Error en localias inversas equipos " << i+1 << " y " << rival_primera_rueda << endl;
                        contador_errores_localias_inversas++;
                    }
                }
            }
        }
    }

    cout << "\nErrores encontrados: " << contador_errores_localias_inversas << endl;

    int contador_errores_sumatoria_columna = 0;
    int suma_col;

    //rueda 1
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda1_SA[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+1 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    //rueda 2
    for (int i = 0; i < 19; i++){ // por fecha
        suma_col = 0;
        for (int j = 0; j < 20; j++){ // por equipo
            suma_col += abs(rueda2_SA[j][i]);
        }
        if (suma_col != 210){
            cout << "Error en la suma de la fecha " << i+20 << endl;
            contador_errores_sumatoria_columna++;
        }
    }

    cout << "Errores encontrados suma fecha: " << contador_errores_sumatoria_columna << endl;

    //revision de que en cada rueda un equipo se enfrente a todos los demas
    vector<int> equipos_enfrentados = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <20; i++){
        //rueda 1
        vector<int> rivales_aux = equipos_enfrentados;
        auto it = std::find(rivales_aux.begin(), rivales_aux.end(), i+1); 
        if (it != rivales_aux.end()) { 
            rivales_aux.erase(it); 
        }
        for(int j = 0; j < 19; j++){
            auto it2 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda1_SA[i][j])); 
            if (it2 != rivales_aux.end()) { 
                rivales_aux.erase(it2); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 1, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
        //rueda 2
        rivales_aux = equipos_enfrentados;
        auto it3 = std::find(rivales_aux.begin(), rivales_aux.end(), i+1);
        if (it3 != rivales_aux.end()) { 
            rivales_aux.erase(it3); 
        }
        for(int j = 0; j < 19; j++){
            auto it4 = std::find(rivales_aux.begin(), rivales_aux.end(), abs(rueda2_SA[i][j])); 
            if (it4 != rivales_aux.end()) { 
                rivales_aux.erase(it4); 
            }
        }
        if (rivales_aux.size() != 0){
            cout << "Error en rueda 2, equipo " << i+1 << " no se enfrenta a todos los demas" << endl;
        }
    }

    //revision de consistencia por fecha
    // si i juega contra j, entonces j debe jugar contra i (ademas los signos deben ser contrarios)

    int error_consistencia_fecha = 0;

    //revisando rueda 1
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda1_SA[i][j]);

            // rival debe jugar contra i+1
            if(abs(rueda1_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda1_SA[i][j] > 0 && rueda1_SA[rival-1][j] > 0 || rueda1_SA[i][j] < 0 && rueda1_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+1 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }

    //revisando rueda 2
    for (int j = 0; j < 19; j++){
        for (int i = 0; i < 20; i++){
            int rival = abs(rueda2_SA[i][j]);
            // rival debe jugar contra i+1
            if(abs(rueda2_SA[rival-1][j]) != i+1){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", el equipo " << rival << " no enfrenta a " << i+1 << endl;
                error_consistencia_fecha++; 
            }

            // signos deben ser contrarios    
            if (rueda2_SA[i][j] > 0 && rueda2_SA[rival-1][j] > 0 || rueda2_SA[i][j] < 0 && rueda2_SA[rival-1][j] < 0){
                cout << "Error en consistencia de fecha " << j+20 << " entre equipos " << i+1 << " y " << rival << ", ambos tienen la misma condicion" << endl;
                error_consistencia_fecha++;
            }
        }
    }
    
    cout << "Errores en consistencia de fecha: " << error_consistencia_fecha << endl;
    */
} 

void revision_pdc_24(){

    vector<vector<int>> original_rueda1, original_rueda2;

    vector<int> t1_original_rueda1 = {-16,-12,6,2,-8,9,-11,13,-3,7,-5,-14,4,-10,15};
    vector<int> t2_original_rueda1 = {5,14,-15,-1,12,-13,16,8,-4,-6,10,-7,3,11,-9};
    vector<int> t3_original_rueda1 = {-7,11,-4,9,14,-6,5,-10,1,-15,-16,12,-2,13,-8};
    vector<int> t4_original_rueda1 = {-9,13,3,-12,7,-5,6,-11,2,-10,15,-8,-1,16,-14};
    vector<int> t5_original_rueda1 = {-2,16,-13,6,-10,4,-3,15,11,-14,1,-9,8,-12,7};
    vector<int> t6_original_rueda1 = {-13,7,-1,-5,15,3,-4,-12,10,2,-8,16,-14,9,-11};
    vector<int> t7_original_rueda1 = {3,-6,10,13,-4,-15,12,-14,9,-1,11,2,-16,8,-5};
    vector<int> t8_original_rueda1 = {-11,15,-16,-10,1,-14,13,-2,12,-9,6,4,-5,-7,3};
    vector<int> t9_original_rueda1 = {4,-10,12,-3,11,-1,14,-16,-7,8,-13,5,15,-6,2};
    vector<int> t10_original_rueda1 = {-14,9,-7,8,5,-12,-15,3,-6,4,-2,11,-13,1,-16};
    vector<int> t11_original_rueda1 = {8,-3,14,15,-9,-16,1,4,-5,13,-7,-10,12,-2,6};
    vector<int> t12_original_rueda1 = {-15,1,-9,4,-2,10,-7,6,-8,16,14,-3,-11,5,-13};
    vector<int> t13_original_rueda1 = {6,-4,5,-7,16,2,-8,-1,14,-11,9,-15,10,-3,12};
    vector<int> t14_original_rueda1 = {10,-2,-11,16,-3,8,-9,7,-13,5,-12,1,6,-15,4};
    vector<int> t15_original_rueda1 = {12,-8,2,-11,-6,7,10,-5,-16,3,-4,13,-9,14,-1};
    vector<int> t16_original_rueda1 = {1,-5,8,-14,-13,11,-2,9,15,-12,3,-6,7,-4,10};

    vector<int> t1_original_rueda2 = {16,12,-6,-2,8,-9,11,-13,3,-7,5,14,-4,10,-15};
    vector<int> t2_original_rueda2 = {-5,-14,15,1,-12,13,-16,-8,4,6,-10,7,-3,-11,9};
    vector<int> t3_original_rueda2 = {7,-11,4,-9,-14,6,-5,10,-1,15,16,-12,2,-13,8};
    vector<int> t4_original_rueda2 = {9,-13,-3,12,-7,5,-6,11,-2,10,-15,8,1,-16,14};
    vector<int> t5_original_rueda2 = {2,-16,13,-6,10,-4,3,-15,-11,14,-1,9,-8,12,-7};
    vector<int> t6_original_rueda2 = {13,-7,1,5,-15,-3,4,12,-10,-2,8,-16,14,-9,11};
    vector<int> t7_original_rueda2 = {-3,6,-10,-13,4,15,-12,14,-9,1,-11,-2,16,-8,5};
    vector<int> t8_original_rueda2 = {11,-15,16,10,-1,14,-13,2,-12,9,-6,-4,5,7,-3};
    vector<int> t9_original_rueda2 = {-4,10,-12,3,-11,1,-14,16,7,-8,13,-5,-15,6,-2};
    vector<int> t10_original_rueda2 = {14,-9,7,-8,-5,12,15,-3,6,-4,2,-11,13,-1,16};
    vector<int> t11_original_rueda2 = {-8,3,-14,-15,9,16,-1,-4,5,-13,7,10,-12,2,-6};
    vector<int> t12_original_rueda2 = {15,-1,9,-4,2,-10,7,-6,8,-16,-14,3,11,-5,13};
    vector<int> t13_original_rueda2 = {-6,4,-5,7,-16,-2,8,1,-14,11,-9,15,-10,3,-12};
    vector<int> t14_original_rueda2 = {-10,2,11,-16,3,-8,9,-7,13,-5,12,-1,-6,15,-4};
    vector<int> t15_original_rueda2 = {-12,8,-2,11,6,-7,-10,5,16,-3,4,-13,9,-14,1};
    vector<int> t16_original_rueda2 = {-1,5,-8,14,13,-11,2,-9,-15,12,-3,6,-7,4,-10};

    original_rueda1.push_back(t1_original_rueda1);
    original_rueda1.push_back(t2_original_rueda1);
    original_rueda1.push_back(t3_original_rueda1);
    original_rueda1.push_back(t4_original_rueda1);
    original_rueda1.push_back(t5_original_rueda1);
    original_rueda1.push_back(t6_original_rueda1);
    original_rueda1.push_back(t7_original_rueda1);
    original_rueda1.push_back(t8_original_rueda1);
    original_rueda1.push_back(t9_original_rueda1);
    original_rueda1.push_back(t10_original_rueda1);
    original_rueda1.push_back(t11_original_rueda1);
    original_rueda1.push_back(t12_original_rueda1);
    original_rueda1.push_back(t13_original_rueda1);
    original_rueda1.push_back(t14_original_rueda1);
    original_rueda1.push_back(t15_original_rueda1);
    original_rueda1.push_back(t16_original_rueda1);

    original_rueda2.push_back(t1_original_rueda2);
    original_rueda2.push_back(t2_original_rueda2);
    original_rueda2.push_back(t3_original_rueda2);
    original_rueda2.push_back(t4_original_rueda2);
    original_rueda2.push_back(t5_original_rueda2);
    original_rueda2.push_back(t6_original_rueda2);
    original_rueda2.push_back(t7_original_rueda2);
    original_rueda2.push_back(t8_original_rueda2);
    original_rueda2.push_back(t9_original_rueda2);
    original_rueda2.push_back(t10_original_rueda2);
    original_rueda2.push_back(t11_original_rueda2);
    original_rueda2.push_back(t12_original_rueda2);
    original_rueda2.push_back(t13_original_rueda2);
    original_rueda2.push_back(t14_original_rueda2);
    original_rueda2.push_back(t15_original_rueda2);
    original_rueda2.push_back(t16_original_rueda2);

    // ---------------------------------------------------- lectura de instanica PDC ----------------------------------------------------

    //Parametros instancia

    int contador_fila = 0;

    int numero_solicitudes;
    int cantidad_equipos;
    int fecha_limite_vacaciones;

    vector<int> equipos_fuertes;
    vector<int> equipos_libertadores;
    vector<int> equipos_prelibertadores;
    vector<int> equipos_sudamericana;

    vector<int> equipos_zona_norte;
    vector<int> equipos_zona_centro;
    vector<int> equipos_zona_sur;
    vector<int> equipos_zonas_vacaciones;
    vector<int> equipos_santiago;

    vector<int> fechas_previas_prelibertadores;
    vector<int> fechas_posteriores_prelibertadores;
    vector<int> fechas_previas_libertadores;
    vector<int> fechas_posteriores_libertadores;
    vector<int> fechas_previas_sudamericana;
    vector<int> fechas_posteriores_sudamericana;
    
    vector<vector<int>> solicituedes_visitante;

    // ----------------------------------------------------- LECTURA INSTANCIA ------------------------------------------------------

    ifstream file("Funciones_Ligas/instanciaPDC.txt");

    string line;

    if (file.is_open()) { 
        while (getline(file, line)) { 
            if (contador_fila == 0){
                cantidad_equipos = stoi(line);
                //cout << "Cantidad de equipos: " << cantidad_equipos << endl;
            }
            else if (contador_fila == 1){ // equipos fuertes
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_fuertes.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 2){ // equipos libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_libertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 3){ // equipos pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_prelibertadores.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 4){ // equipos sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 5){ // equipos zona norte
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_norte.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 6){ // equipos zona centro
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_centro.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 7){ // equipos zona sur
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zona_sur.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 8){ // equipos zona vacaciones
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_zonas_vacaciones.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 9){ // equipos de santiago
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    equipos_santiago.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 10){ // fechas previas pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 11){ // fechas posteriores pre libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_prelibertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 12){ // fechas previas libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 13){ // fechas posteriores libertadores
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene cada palabra de la linea
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_libertadores.push_back(stoi(vstrings[i]));
                }  
            }
            else if (contador_fila == 14){ // fechas previas sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_previas_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if (contador_fila == 15){ // fechas posteriores sudamericana
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end); // vstrings tiene
                for (int i = 0; i < vstrings.size(); i++){
                    fechas_posteriores_sudamericana.push_back(stoi(vstrings[i]));
                }
            }
            else if(contador_fila == 16){
                fecha_limite_vacaciones = stoi(line);
            }
            else if (contador_fila == 17){ // solicitudes visitante
                numero_solicitudes = stoi(line);
            }
            else{
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);
                vector<int> aux_solicitud;
                aux_solicitud.clear();
                for (int i = 0; i < vstrings.size(); i++){
                    aux_solicitud.push_back(stoi(vstrings[i]));
                }
                solicituedes_visitante.push_back(aux_solicitud);
            }
            contador_fila++;
        }
    }
    else { 
        cout << "Unable to open file\n";
    }

    // se asume que los equipos participantes en pre libertadores van a acceder a libertadores

    for (int i = 0; i < equipos_prelibertadores.size(); i++){
        equipos_libertadores.push_back(equipos_prelibertadores[i]);
    }

    cout << "Enfoque Balanceado" << endl;

    int evaluacion_actual = funcion_evaluacion_pdc(1, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Evaluacion: " << evaluacion_actual << endl;

    print_costo_restricciones_pdc(1, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Enfoque Clasicos" << endl;

    evaluacion_actual = funcion_evaluacion_pdc(2, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Evaluacion: " << evaluacion_actual << endl;

    print_costo_restricciones_pdc(2, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);    

    cout << "Enfoque Zonas" << endl;

    evaluacion_actual = funcion_evaluacion_pdc(3, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Evaluacion: " << evaluacion_actual << endl;

    print_costo_restricciones_pdc(3, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Enfoque Torneos Internacionales" << endl;

    evaluacion_actual = funcion_evaluacion_pdc(4, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

    cout << "Evaluacion: " << evaluacion_actual << endl;

    print_costo_restricciones_pdc(4, original_rueda1, original_rueda2, fecha_limite_vacaciones, equipos_fuertes, equipos_libertadores, equipos_prelibertadores, 
        equipos_sudamericana, equipos_zona_norte, equipos_zona_centro, equipos_zona_sur, equipos_zonas_vacaciones, equipos_santiago, fechas_previas_prelibertadores, fechas_posteriores_prelibertadores, 
        fechas_previas_libertadores, fechas_posteriores_libertadores, fechas_previas_sudamericana, fechas_posteriores_sudamericana, solicituedes_visitante);

}