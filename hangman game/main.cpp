#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <time.h>
#include <random>
#include <vector>
#include <ctime>
#include <set>
#include <list>
#include <iterator>
#include <bits/stdc++.h>

using namespace std;
void menu();
int scorFinal, nrCuvinteGhicite;

string array1[20] = { "+---------------------------------+", "|             HANGMAN             | ", "+---------------------------------+", "|                                 |", "|                                 |", "|                                 |", "|                                 |", "|                                 |", "+---------------------------------+", "|        Available letters        |", "+---------------------------------+", "|    a b c d e f g h i j k l m    |", "|    n o p q r s t u v w x y z    |", "+---------------------------------+", "|          Guess the word         |", "+---------------------------------+", "+---------------------------------+" };
string array2[20] = { "+---------------------------------+", "|             HANGMAN             | ", "+---------------------------------+", "|                |                |", "|                O                |", "|               /|\\               |", "|                |                |", "|               / \\               |", "+---------------------------------+", "|        Available letters        |", "+---------------------------------+", "|    a b c d e f g h i j k l m    |", "|    n o p q r s t u v w x y z    |", "+---------------------------------+", "|          Guess the word         |", "+---------------------------------+", "+---------------------------------+" };
string array3[20] = { "+---------------------------------+", "|             HANGMAN             | ", "+---------------------------------+", "|                                 |", "|                                 |", "|                                 |", "|                                 |", "|                                 |", "+---------------------------------+", "|        Available letters        |", "+---------------------------------+", "|    a b c d e f g h i j k l m    |", "|    n o p q r s t u v w x y z    |", "+---------------------------------+", "|          Guess the word         |", "+---------------------------------+", "+---------------------------------+" };

class Cuvant {
    int lungime;
    int vieti;
    string cuvantCorect;
    string cuvantAscuns;
public:
    Cuvant();
    Cuvant(string);
    friend istream& operator >>(istream&, Cuvant&);
    friend ostream& operator <<(ostream&, Cuvant&);
    int getLungime()const {
        return this->lungime;
    }
    int getVieti()const {
        return this->vieti;
    }
    string getCuvant() {
        return this->cuvantAscuns;
    }
    string afisare() {
        return this->cuvantCorect;
    }
    void setCuvantAscuns() {
        string s = "";
        //cout << "cuvant = " << cuvant << endl;    //debugging stuff
        for (int i = 0; i < this->cuvantCorect.length(); i++) {
            if (i == 0 || i == this->cuvantCorect.length() - 1 || this->cuvantCorect[i] == this->cuvantCorect[0] || this->cuvantCorect[i] == this->cuvantCorect[this->cuvantCorect.length() - 1])
                s += this->cuvantCorect[i];
            else if (i < this->cuvantCorect.length() && i != 0 && i != this->cuvantCorect.length() - 1)
                s += "_";
        }
        this->cuvantAscuns = s;
    }
    void setCuvantAscuns2(string newCuvant) {
        this->cuvantAscuns = newCuvant;
    }
    void setLungime(int newLungime) {
        this->lungime = newLungime;
    }
    void setVieti(int newVieti) {
        vieti = newVieti;
    }
    void setCuvant(string newCuvant) {
        cuvantCorect = newCuvant;
    }

};

Cuvant::Cuvant() {
    this->lungime = 0;
    this->vieti = 5;
}

Cuvant::Cuvant(string cuvantCorect) {           // creăm cuvantul ascuns sub forma "ba_a_a"
    this->cuvantCorect = cuvantCorect;
    this->lungime = cuvantCorect.length();
    this->vieti = 5;

    for (int i = 0; i < this->cuvantCorect.length(); i++)
        if (i == 0 || i == this->cuvantCorect.length() - 1)
            this->cuvantAscuns[i] = this->cuvantCorect[i];
        else
            this->cuvantAscuns[i] = '_';
}

istream& operator >> (istream& fil, Cuvant& c) {
    string line;
    vector<string> lines;

    srand(time(0));     // setam timpu pe 0
    ifstream file("cuvinte.txt");
    int total_lines = 0;

    while (getline(file, line)) {
        total_lines++;
        lines.push_back(line);      // adaugam in vectorul stl
    }

    int random_number = rand() % total_lines;       // luam random din fisier
    c.setCuvant(lines[random_number]);
    c.setLungime(lines[random_number].length());
    c.setCuvantAscuns();
}

ostream& operator << (ostream& os, Cuvant& c) {
    os << c.getCuvant() << endl;
    os << c.getLungime();
}

class User {
    string nume;
    int scorMax;
    int nrCuvGhicite;
public:
    User();
    User(string);
    friend istream& operator >>(istream&, User&);
    friend ostream& operator <<(ostream&, User&);

    void setScor(int newScore) {
        this->scorMax = newScore;
    }

    int getScor() const {
        return this->scorMax;
    }

    void setNrCuvGhicite(int nrCuvGhicite1) {
        this->nrCuvGhicite = nrCuvGhicite1;
    }

    int getNrCuvGhicite() const {
        return this->nrCuvGhicite;
    }

    void setNume(string nume2) {
        this->nume = nume2;
    }

    string getNume() {
        return this->nume;
    }
};

User::User() {
    this->scorMax = 0;
}

istream& operator >> (istream& in, User& u) {
    in >> u.nume;

    return in;
}

ostream& operator << (ostream& out, User& u) {
    ofstream g("scor.txt", ios::in | ios::app);
    g << u.nume << " ";
    g << u.scorMax << " ";
    g << u.nrCuvGhicite << endl;
    return out;
}

class Citire {
    string c;
public:
    Citire();
    string getChar() {
        return this->c;
    }
    friend istream& operator >>(istream&, Citire&);

};

istream& operator >> (istream& in, Citire& caracter) {
    in >> caracter.c;
    return in;
}

Citire::Citire() {
    this->c = "NULL";
}

void Joc() {
    Cuvant a;
    int nrVieti = a.getVieti();
    cout << "> "; cin >> a;
    cout << a << endl;
    system("cls");
    int ok = 0, ok1 = 0;
    int desen = 0;
    while (nrVieti >= 0) {


        // aici desenez omuletul
        string message = a.getCuvant();
        bool front = true;
        for (int i = message.length(); i < 33; i++) {  // aici am folosit niste fuctii bool pentru a centra frumos
            if (front) {    // i < 33 deoarece sunt 33 de "-" in "+---------------------------------+"
                message = " " + message;
            }
            else {
                message = message + " ";
            }
            front = !front; // aici practic tot isi schimba valoarea din true in false si din false in true etc. pana cand se centreaza
        }


        for (int i = 0; i < 20; i++) {
            if (i == 16) {   // penultima linie este inlocuita cu noul cuvant
                cout << "|" << message << "|" << endl;
            }

            cout << array1[i] << endl;
        }


        // pana aici il desenez


        ok1 = 0;        // resetez ok1
        // cout << "nrVieti: " << nrVieti << endl;      /// debug
        // cout << "ok: " << ok << endl;            /// debug
        //User u;
        //cin>>u;
        //cout<<u;
        Citire caracter;
        cout << "> "; cin >> caracter;
        string nrCaractere = a.afisare();       // Retine cuvantul corect
        string caracterAux = caracter.getChar();

        // aici ma joc putin cu designul jocului  si fac sa dispara literele care au fost introduse deja

        if (caracterAux.length() == 1) {
            string y;
            for (int i = 11; i <= 12; i++) {
                string x = array1[i];
                //cout << "x: " << x << endl;   // debug
                y = "";
                for (int j = 0; j < x.length(); j++) {
                    //cout << "y: " << y << endl;
                    if (caracterAux[0] == x[j]) {
                        y += " ";
                        // array1[i][j] = " ";  // debug
                    }
                    else y += array1[i][j];
                }
                if (i == 11)
                    array1[11] = y;
                else array1[12] = y; // pe 11 si pe 12 se gasesc literele care trebuie sa fie inlocuite

            }
        }

        if (caracterAux.length() == nrCaractere.length()) {             // 1 - verific daca cel introdus = cel din fisier
            if (nrCaractere == caracterAux) {
                nrVieti = 5;
                a.setVieti(nrVieti);
                a.setCuvantAscuns2(caracterAux);
                for (int i = 0; i < 20; i++)
                    array1[i] = array3[i];
                //cout << a.getCuvant() << endl;
                ok = 1;
                system("cls");
            }

            else {  // o gramada de incercari si formule mai tarziu, am gasit raspunsul
                nrVieti--;  // cum sa desenez omuletul cand utilizatorul pierde din vieti
                a.setVieti(nrVieti);
                ok = 0;
                desen++;
                int my_variable = desen + 2;
                array1[my_variable] = array2[my_variable];
                system("cls");
            }

        }

        if (caracterAux.length() == 1) {                        //     2 - verific pe rand fiecare litera din cuvantul din fisier cu cea introdusa
            for (int i = 0; i < nrCaractere.length(); i++) {
                if (caracterAux[0] == nrCaractere[i]) {
                    string cuvantAux = a.getCuvant();
                    cuvantAux[i] = caracterAux[0];
                    a.setCuvantAscuns2(cuvantAux);
                    system("cls");
                    ok = 1;
                }
                else ok1++;     //  practic vreau sa numar daca o parcurs tot cuvantu fara a gasi o litera asemanatoare.
            }
            // cout << "ok1: " << ok1 << endl;          /// debug
           //  cout << "nrCaractere.length(): " << nrCaractere.length() << endl;        /// debug
            if (ok1 == nrCaractere.length()) {  // daca nu o gasit nicio litera asemanatoare, atunci logic ar fi ca ok1 sa fie = nrCaractere.length()  (adica lungimea cuvantului ascuns)
                nrVieti--;
                a.setVieti(nrVieti);
                ok = 0;

                desen++;
                int my_variable = desen + 2;
                array1[my_variable] = array2[my_variable];
                system("cls");
            }

        }

        else if (caracterAux.length() > 1 && caracterAux.length() < nrCaractere.length()) {
            nrVieti--;
            a.setVieti(nrVieti);
            ok = 0;
            ok1 = 0;
            desen++;
            int my_variable = desen + 2;
            array1[my_variable] = array2[my_variable];
            system("cls");
        }

        if (a.getCuvant() == nrCaractere) {                         // 3
            nrVieti = 5;
            a.setVieti(nrVieti);
            a.setCuvantAscuns2(nrCaractere);
            for (int i = 0; i < 20; i++)
                array1[i] = array3[i];

            ok = 1;
            ok1 = 0;
            system("cls");
        }

        if (a.getCuvant() == nrCaractere) {

            for (int i = 0; i < 20; i++)
                array1[i] = array3[i];

            // cout << "nrCaracatere: " << nrCaractere.length() << endl;        /// debug
            scorFinal += nrCaractere.length();
            // cout << "1. scorFinal: " << scorFinal << endl;       /// debug
            cin >> a;
            cout << a << endl;
            desen = 0;
            nrCuvinteGhicite++;
            system("cls");
        }


    }
    cout << endl << "GAME OVER!" << endl;

    User m;
    if (scorFinal > 0) {
        cout << "Numele: ";
        cin >> m;
        // string numeUser = m.getNume();
        // m.setNume(numeUser);
        m.setScor(scorFinal);
        m.setNrCuvGhicite(nrCuvinteGhicite);
        cout << m << endl;

        cout << endl;
        cout << "Clasament pentru " << m.getNume() << ": " << endl;
        cout << endl;
        fstream clasament;
        clasament.open("scor.txt", ios::in);
        string nume1;
        int scor;
        int nrCuv;
        int contor = 0;
        while (clasament >> nume1 >> scor >> nrCuv) {   // Introduc numele pe care vreau sa mi-l afisez
            if (m.getNume() == nume1) {
                contor++;       // contor pentru a arata frumos pe ecran.
                cout << contor << ". " << "Scor: " << scor << " ---> " << nrCuv << " cuvinte" << endl;
                // parcurc fisieru si afisez doar acolo unde am gasit utilizatorul introdus de la tastatura
            }
        }
        clasament.close();
    }

    for (int i = 0; i < 20; i++)
        array1[i] = array3[i];

    int n;
    cout << "Inapoi la meniu? ( 1 / 0 )" << endl;
    cout << "> "; cin >> n;
    if (n == 1) {
        system("cls");
        menu();
    }

    else exit(0);
}

void CautaPersoana() {
    User m;

    set<string> Nume;

    string NumeDorit;


    fstream g;
    g.open("scor.txt", ios::in);
    string nume1;
    int scor;
    int nrCuv;
    int contor = 0;
    while (g >> nume1 >> scor >> nrCuv) {   // am creat un set pentru a pune doar numele o singura data
        Nume.insert(nume1);
    }
    g.close();
    int c1 = 0, c2 = 0;

    cout << "+-------+" << endl;
    for (auto e : Nume) {
        cout << e << endl;
        c1++;
    }

    cout << "+-------+" << endl;
    int ok = 0;
    do {
        c2 = 0;

        cout << endl << "Numele dorit: " << endl;
        cout << "> "; cin >> NumeDorit;     // Introduc numele pe care vreau sa mi-l afisez
        cout << endl;
        for (auto e : Nume) {
            // cout << e << " e " << endl;          /// debug
            c2++;
            if (e == NumeDorit) {
                fstream g;
                g.open("scor.txt", ios::in);
                string nume1;
                int scor;
                int nrCuv;
                int contor = 0;
                while (g >> nume1 >> scor >> nrCuv) {   // aici caut in fisieru "scor" NumeDorit
                    if (nume1 == NumeDorit) {
                        contor++;
                        cout << contor << ". " << "Scor: " << scor << " ---> " << nrCuv;
                        if (nrCuv == 1)
                            cout << " cuvant" << endl;
                        else cout << " cuvinte" << endl;
                    }

                }
                c2--;
                g.close();
                ok = 1;
            }

        }
        if (c1 == c2) {
            cout << "Numele introdus este gresit! Introduceti din nou: " << endl;
        }
    } while (ok == 0);    // daca cumva am scris numele gresit, il pot introduce din nou.


    cout << endl;
    int n;
    cout << "Inapoi la meniu? ( 1 / 0 )" << endl;
    cout << "> "; cin >> n;
    if (n == 1) {
        system("cls");
        menu();
    }

    else exit(0);
}

void Clasament() {
    set<string> Nume;
    list<string> Nume1;
    fstream g;
    int v[100], v1[100];

    g.open("scor.txt", ios::in);
    string nume1;
    int scor;
    int nrCuv;
    int c = 0;
    int contor = 0;
    while (g >> nume1 >> scor >> nrCuv) {

        Nume.insert(nume1); // am creat un set din STL pentru a pune doar numele o singura data
    }
    g.close();

    g.open("scor.txt", ios::in);
    //string nume1;
    //int scor;
    //int nrCuv;
    //int c = 0;
    //int contor = 0;
    while (g >> nume1 >> scor >> nrCuv) {

        for (auto e : Nume) {
            contor++;
            if (e == nume1) {

                v[contor] += scor;
                v1[contor] += nrCuv;    // pun in vectori scorul persoanei si din cate cuvinte e alcatuit scorul
                // cout << "e: " << e << "; v[" << contor << "] = " << v[contor] << endl;  ///  debug
            }
        }
        contor = 0;
    }

    contor = 0;
    for (auto e : Nume) {
        contor++;
        c++;
        cout << contor << ". " << e << ": ";
        for (int i = contor; i <= c; i++)
            cout << v[i] << " --> " << v1[i] << " cuvinte " << endl;
    }
    g.close();

    int n;
    cout << "Inapoi la meniu? ( 1 / 0 )" << endl;
    cout << "> "; cin >> n;
    if (n == 1) {
        system("cls");
        menu();
    }

    else exit(0);

}

void Tutorial() {
    cout << "+-----------------------------------------------------TUTORIAL-----------------------------------------------------+" << endl;
    cout << endl << " 1. Poti introduce o (1) singura litera pe rand sau poti incerca sa ghicesti tot cuvantul din prima." << endl;
    cout << " 2. Daca ai introdus mai mult de o singura litera si mai putin decat lungimea cuvantului, ai pierdut o (1) viata." << endl;
    cout << " 3. Daca ai introdus o litera deja ghicita de doua sau mai multe ori, nu pierzi nicio viata." << endl;
    cout << " 4. Daca ai introdus o litera gresita de doua sau mai multe ori, ai pierdut o (1) viata." << endl;
    cout << endl << "+------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << endl; cout << endl; cout << endl;

    int n;
    cout << "Inapoi la meniu? ( 1 / 0 )" << endl;
    cout << "> "; cin >> n;
    if (n == 1) {
        system("cls");
        menu();
    }

    else exit(0);
}

void menu() {

    int n;
    cout << "+---------MENIU---------+" << endl;
    cout << "| 1. Incepe Joc         |" << endl;
    cout << "| 2. Cauta Persoana     |" << endl;
    cout << "| 3. Vezi Clasament     |" << endl;
    cout << "| 4. Tutorial           |" << endl;
    cout << "| 0. Exit               |" << endl;
    cout << "+-----------------------+" << endl;
    cin >> n;

    switch (n) {
    case 1: {
        system("cls");

        for (int i = 0; i < 20; i++)
            array1[i] = array3[i];

        Joc();
    }

    case 2: {
        system("cls");
        CautaPersoana();
    }

    case 3: {
        system("cls");
        Clasament();
    }

    case 4: {
        system("cls");
        Tutorial();
    }
    case 0: {
        exit(0);
    }
    default: {
        int ok = 0;
        int chestie;        // reia inputul
        cout << "Comanda invalida. Introduceti din nou." << endl;
        while (!ok) {
            cout << "> "; cin >> chestie;
            if (chestie == 1) {
                ok = 1;
                system("cls");
                Joc();
            }

            else if (chestie == 2) {
                ok = 1;
                system("cls");
                CautaPersoana();
            }

            else if (chestie == 3) {
                ok = 1;
                system("cls");
                Clasament();
            }

            else if (chestie == 4) {
                ok = 1;
                system("cls");
                Tutorial();
            }
            else if (chestie == 0)
                exit(0);
            else {
                cout << "Comanda invalida. Introduceti din nou." << endl;
            }
        }
        system("cls");
        menu();
    }
    }
}

int main() {
    for (int i = 0; i < 20; i++)
        array1[i] = array3[i];
    menu();
    return 0;
}
