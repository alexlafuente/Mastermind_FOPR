#include <iostream>
#include <vector>
#include <random>

using namespace std;

typedef vector < vector<int> > Matriu;
typedef vector < vector<char> > MatriuText;

// Exp: Llegeix vector numèric o textual, en base a un booleà que determina si el valor és numèric
// Pre: Agafa un vector numèric, un vector textual i un booleà.
// Post: Buit
void mostraMatriu(vector<int> &seq, vector<char> &txt, bool num){
    if(num){
        int mida = seq.size();
        for(int i = 0; i < mida; ++i){
            cout << seq[i];
        }
    }
    else{
        int mida = txt.size();
        for(int i = 0; i < mida; ++i){
            cout << txt[i];
        }
    }
}

// Exp: Crea el vector amb la correspondència (els encerts) entre el codi correcte i la jugada.
// Pre: Agafa el vector amb el codi i el vector amb la jugada del jugador B.
// Post: Retorna el vector amb la correspondència (els encerts) entre el codi correcte i la jugada.
vector<char> encerts(const vector<int> &codi, const vector<int> &jugada){
//  Declarem un vector amb la correspondència de la jugada respecte el codi, que posteriorment mostrarem per pantalla.
    vector<char> sortida(4);
    for(int i = 0; i<4; ++i){
        for(int j = 0; j<4; ++j){
//          Inv: Sortida conté per a la posició i, la correspondència de la posició i del vector jugada amb la del vector codi, representada amb un caràcter.
            if(jugada[i] == codi[i]){
                sortida[i] = 'X';
            }
            else if(jugada[i] == codi[j]){
                sortida[i] = 'O';
            }
            if(sortida[i] != 'X' and sortida[i] != 'O'){
                sortida[i] = '-';
            }
        }
    }
    
    return sortida;
}

// Exp: Invertir la seqüència d'un vector.
// Pre: Agafa el vector auxiliar, que conté girada la seqüència del codi/jugada.
// Post: Retorna el vector auxiliar girat.
vector<int> ordena(const vector<int> &aux){
    int mida = aux.size();
    vector<int> girat(mida);
    int i = 0;
    int j = mida - 1;
    while(i < mida and j >= 0){
//      Inv: girat conté a la posició i, l'element d'aux a la posició j.
        girat[i] = aux[j];
        ++i;
        --j;
    }
    
    return girat;
}

// Exp: A partir del nombre natural amb 4 caràcters introduit pel jugador, crea un vector amb la seqüència.
// Pre: Agafa el booleà jugadorA, que és l'indicador del jugador i el nombre de l'intent > 0.
// Post: Retorna la seqüència del codi/jugada.
vector<int> separa(bool jugadorA, int intent){
//  Declarem un vector que contindrà la seqüència del codi/jugada.
    vector<int> separat;
    int n;
    cin>>n;
    while(n < 0){
//      Inv: n és un enter que conté el codi introduit pel jugador.
        cout << "Error: Codi secret incorrecte." << endl;
        if(jugadorA){
            cout << "Jugador A, escull el codi secret: " << endl;
        }
        else{
            cout << "Jugador B, intent " << intent << ": " << endl;
        }
        cin>>n;
    }
//  Declarem un vector, del qual cada element contindrà una xifra del codi introduit, encara que l'ordre dels elements serà el contrari al dessitjat.
    vector<int> aux;
    while(n != 0){
/*      Inv: l'espai del vector aux conté l'última xifra d'n.
        n conté el nombre corresponent al codi, fins la xifra que s'emmagatzema a aux en aquella iteració.
*/
        aux.push_back(n%10);
        n = n/10;
    }
//  Per obtenir el vector amb el codi ordenat, haurem d'invertir l'ordre dels elements.
    separat = ordena(aux);
    
    return separat;
}

// Exp: Detecta si hi ha nombres repetits al vector o si algun nombre és igual a 0.
// Pre: Agafa un vector.
// Post: Retorna trobat si hi ha algun valor repetit a la seqüència.
bool hiHaRepetitsOzeros(const vector<int> &codi){
    bool trobat = false;
    int mida = codi.size();
    int i = 0;
    while(not trobat and i < mida){
/*      Inv: j s'inicialitza a 0, i determina la posició de l'element del vector, la qual variarà i es compararà constantment amb l'element en la
        posició i, que es mantindrà constant fins que j hagi recorregut tot el vector.
*/        
        int j = 0;
        while(not trobat and j < mida){
//          Inv: trobat és fals si al vector no hi ha algun 0 o nombre repetit.
            if(codi[j] == 0){
                trobat = true;
            }
            if(i == j){
                ++j;
            }
            if(codi[i] == codi[j]){
                trobat = true;
            }
            ++j;
        }
        ++i;
    }
        
    return trobat;
}

// Exp: Genera un nombre aleatori entre els nombres min i max (ambdós inclosos).
// Pre: min < max
// Post: retorna un nombre generat aleatòriament entre min i max.
int aleatori(int min, int max){
    static std::random_device device{};
    static std::default_random_engine engine{ device() };
    std::uniform_int_distribution<int> distribution{ min, max };
    return distribution(engine);
}

// Exp: Genera un codi aleatori.
// Pre: Buit.
// Post: Retorna el vector amb la seqüència numèrica amb el codi secret determinat aleatoriament.
vector<int> codiRandom(){
//  Declarem un vector que contingui el codi.
    vector<int> codi;
//  Declarem el nombre mínim i màxim, els quals determinaran el rang del nombre generat aleatoriament.
    int min = 1;
    int max = 9;
    for(int i = 0; i < 4; ++i){
//      Inv: l'element i de codi, conté un nombre generat per la funció aleatori.
        codi.push_back(aleatori(min, max));
        while(hiHaRepetitsOzeros(codi)){
//          Inv: l'element i de codi, conté un nombre generat per la funció aleatori.
            codi[i] = aleatori(min, max);
        }
    }
    
    return codi;
}

// Exp: Genera un codi manual.
// Pre: Buit.
// Post: Retorna el vector amb la seqüència numèrica amb el codi secret introduit per l'usuari.
vector<int> codiManual(){
//  Declarem un vector que contingui el codi.
    vector<int> codi;
    bool jugadorA = true;
    bool trobat = false;
    cout << endl;
    while(not trobat){
/*      Inv: codi conté el vector corresponent a la seqüència introduida pel jugador a. mida conté el tamany del vector codi.
 *      trobat és vertader si la mida del vector és 4 i no n'hi han repetits o zeros.
 */
        cout << "Jugador A, escull el codi secret: " << endl;
        codi = separa(jugadorA, trobat);
        int mida = codi.size();
        if(mida == 4 and not hiHaRepetitsOzeros(codi)){
            trobat = true;
        }
        else{
        cout << "Error: Codi secret incorrecte." << endl;
        }
    }

    return codi;
}

// Exp: Codi principal, que determina l'estructura del joc.
// Pre: Agafa el booleà aleatori, que és l'indicador del mode de joc.
// Post: buit.
void joc(bool aleatori){
//  Declarem el vector que contindrà el codi de 4 xifres, escollit pel jugador A.
    vector<int> codi(4);
    if(aleatori){
        codi = codiRandom();
    }
    else{
        codi = codiManual();
    }
//  Declarem les matrius que contindran els nombres de els intents, cada jugada i cada correspondència entre la jugada i el codi.
    Matriu intents(10, vector<int>(2));
    Matriu jugades(10, vector<int>(4));
    MatriuText sortides(10, vector<char>(4));
//  Declarem el vector que contindrà la jugada del jugador B.
    vector<int> jugada;
//  Declarem un booleà que determina si la jugada del jugador B és igual al codi del jugador A.
    bool trobat = false;
    int intent = 1;
    bool jugadorA = false;
    while(not trobat and intent <= 10){
//      Inv: correcte és vertader si el codi/jugada introduit pel jugador és vàlid, i s'inicialitza com a fals.
        bool correcte = false;
        cout << endl;
        while(not correcte){
/*          Inv: jugada conté la seqüència escollida pel jugador B.
            mida conté el tamany del vector jugada.
            jugades[intent - 1] conté la seqüència escollida pel jugador B, quan a aquesta no hi ha nombres repetits o zeros, i té 4 elements.
*/
            cout << "Jugador B, intent " << intent << ": " << endl;
            jugada = separa(jugadorA, intent);
            int mida = jugada.size();
            if(mida == 4 and not hiHaRepetitsOzeros(jugada)){
                correcte = true;
//              Assignem el valor de la fila per a l'intent.
                jugades[intent - 1] = jugada;
            }
            else{
                cout << "Error: Intent incorrecte." << endl;
            }
        }
//      Assignem els valors de les files per a cada intent.
        for(int i = 0; i<10; ++i){
            for(int j = 0; j<2; ++j){
//              Inv: Intents té a la seva posició i, j el valor enter corresponent per a crear el nombre de l'intent.
                if(j == 0 and i < 9){
                    intents[i][j] = 0;
                }
                else if(j == 0 and i == 9){
                    intents[i][j] = 1;
                }
                else{
                    intents[i][j] = (i+1)%10;
                }
            }
        }
//      Assignem el valor de la fila per a l'intent.
        sortides[intent - 1] = encerts(codi, jugada);
//      Mostrem per pantalla la informació de totes les jugades fetes a la partida.
        cout << "Jugades:" << endl;
        for(int i = 0; i <= intent - 1; ++i){
/*          Inv: num indica si el vector de la matriu que volem mostrar, està format per nombres enters (num = true) o caràcters (num = false).
            S'inicialitza com a true.
*/
            bool num = true;
//          Mostra per pantalla el vector amb el nombre d'intents.
            mostraMatriu(intents[i], sortides[i], num);
            cout << "   ";
//          Mostra per pantalla el vector amb les jugades del jugador B.
            mostraMatriu(jugades[i], sortides[i], num);
            cout << "   ";
//          Mostra per pantalla el vector amb la correspondència de la jugada i el codi.
            mostraMatriu(intents[i], sortides[i], not num);
            cout << endl;
        }
        if(codi == jugada){
            trobat = true;
        }
        else{
            ++intent;
        }
    }
    cout << endl;
    if(trobat){
      cout << "Felicitats jugador B!! Has guanyat!!" << endl;
    }
    else{
        cout << "Has esgotat els 10 intents." << endl << "El codi secret era ";
        bool num = true;
//      Mostra el vector amb el codi del jugador A.
        mostraMatriu(codi, sortides[9], num);
        cout << endl << endl;
    }
}

// Exp: Selecciona el mode de joc.
// Pre: Buit
// Post: Retorna vertader si el caràcter introduit és 'M'.
bool mode(){
    bool trobat = false;
    char res;
    while(not trobat){
/*      Inv: res conté un caràcter introduit per l'usuari.
 *      trobat és vertader si res == M o res == A.
 */
        cin >> res;
        if(res == 'M' or res == 'A'){
            trobat = true;
        }
//      Si el valor introduit no és un dels indicats, avisa de l'error i torna a demanar un valor.
        else{
            cout << "Error: Mode de joc incorrecte." << endl;
            cout << "Quin mode de joc vols triar, Manual (M)/ Aleatori (A)? : " << endl;
        }
    }       
    bool manual = false;
    if(trobat){
        if(res == 'M'){
            manual = true;
        }
    }
    
    return manual;
}

int main(){
    cout << "BENVINGUT AL JOC MASTERMIND!!" << endl << endl;
    cout << "Quin mode de joc vols triar, Manual (M)/ Aleatori (A)? : " << endl;
    bool aleatori = true;
    if(mode()){
        joc(not aleatori);
    }
    else{
        joc(aleatori);
    }
}