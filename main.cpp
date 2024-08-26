#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Funciones_Ligas/funciones_ligas.cpp"
//#include "EPL_1314/TTP_EPL_SA_1314.cpp"
//#include "EPL_1314/TTP_EPL_TS_1314.cpp"
//#include "EPL_2324/TTP_EPL_SA_2324.cpp"
//#include "EPL_2324/TTP_EPL_TS_2324.cpp"
//#include "PDC/TTP_PDC_SA.cpp"
//#include "PDC/TTP_PDC_TS.cpp"
//#include "Algoritmos/algoritmos_TTP.cpp"


int main() {

    revision_pdc_24();

    int liga;
    int metodo_solucion;
    int temporada_epl;
    int enfoque_pdc;

    cout << "Selecciona la liga a calendarizar: " << endl;
    cout << "1. English Premier League" << endl;
    cout << "2. Primera Division Chilena" << endl;
    cin >> liga;

    cout << "Selecciona el metodo de solucion a utilizar: " << endl;
    cout << "1. Simulated Annealing" << endl;
    cout << "2. Tabu Search" << endl;
    cin >> metodo_solucion;

    if (liga == 1) {
        cout << "Selecciona la temporada a calendarizar: " << endl;
        cout << "1. 2013/14" << endl;
        cout << "2. 2023/24" << endl;
        cin >> temporada_epl;

        if (temporada_epl == 1) {
            if (metodo_solucion == 1) {

                cout << "Calendarizando EPL 2013/14 con Simulated Annealing\n" << endl;
                epl_sa_1314();

            } else if (metodo_solucion == 2) {

                cout << "Calendarizando EPL 2013/14 con Tabu Search\n" << endl;
                epl_ts_1314();

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else if (temporada_epl == 2) {
            if (metodo_solucion == 1) {
                
                cout << "Calendarizando EPL 2023/24 con Simulated Annealing\n" << endl;
                epl_sa_2324(); 

            } else if (metodo_solucion == 2) {
                
                cout << "Calendarizando EPL 2023/24 con Tabu Search\n" << endl;
                epl_ts_2324(); 

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else {
            cout << "Opcion no valida" << endl;
        }


    } else if (liga == 2) {
        cout << "Selecciona el enfoque de la Primera Division Chilena: " << endl;
        cout << "1. Balanceado" << endl;
        cout << "2. Clasicos" << endl;
        cout << "3. Zonas" << endl;
        cout << "4. Torneos internacionales " << endl;
        cin >> enfoque_pdc;

        if (enfoque_pdc ==1){
            if (metodo_solucion == 1) {

                cout << "Calendarizando PDC enfoque balanceado con Simulated Annealing\n" << endl;
                pdc_sa(enfoque_pdc);


            } else if (metodo_solucion == 2) {
                
                cout << "Calendarizando PDC enfoque balanceado con Tabu Search\n" << endl;
                pdc_ts(enfoque_pdc);

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else if (enfoque_pdc ==2){
            if (metodo_solucion == 1) {

                cout << "Calendarizando PDC enfoque clasicos con Simulated Annealing\n" << endl;
                pdc_sa(enfoque_pdc);

            } else if (metodo_solucion == 2) {

                cout << "Calendarizando PDC enfoque clasicos con Tabu Search\n" << endl;
                pdc_ts(enfoque_pdc);

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else if (enfoque_pdc ==3){
            if (metodo_solucion == 1) {
                
                cout << "Calendarizando PDC enfoque zonas con Simulated Annealing\n" << endl;
                pdc_sa(enfoque_pdc);

            } else if (metodo_solucion == 2) {

                cout << "Calendarizando PDC enfoque zonas con Tabu Search\n" << endl;
                pdc_ts(enfoque_pdc);

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else if (enfoque_pdc ==4){
            if (metodo_solucion == 1) {

                cout << "Calendarizando PDC enfoque torneos internacionales con Simulated Annealing\n" << endl;
                pdc_sa(enfoque_pdc);

            } else if (metodo_solucion == 2) {

                cout << "Calendarizando PDC enfoque torneos internacionales con Tabu Search\n" << endl;
                pdc_ts(enfoque_pdc);

            } else {
                cout << "Opcion no valida" << endl;
            }
        } else {
            cout << "Opcion no valida" << endl;
        }

    } else {
        cout << "Opcion no valida" << endl;
    }





    //cout << liga << endl;
    return 0;
}