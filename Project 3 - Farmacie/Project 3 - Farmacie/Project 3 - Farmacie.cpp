#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class MyException : public exception {

public:
    MyException() noexcept {}
    MyException(const MyException&) noexcept = default;
    virtual ~MyException() noexcept = default;
    MyException& operator= (const MyException&) noexcept = default;

    virtual const char* what() const noexcept {
        return "Introduceti o optiune valida!\n";
    }
};

//-------------------------------------------------------------------------------------------------------

class Farmacie {
    string denumire;
    int nr_angajati;
    vector<int> profit; //profiturile pe fiecare luna

public:
    Farmacie();
    Farmacie(string, int, vector<int>);
    virtual ~Farmacie();
    Farmacie(const Farmacie& other);

    friend istream& operator>>(istream&, Farmacie& other);
    friend ostream& operator<<(ostream&, Farmacie& other);
    Farmacie& operator=(const Farmacie& other);

    virtual void afisare() { cout << *this << endl; }
    virtual void citire() { cin >> *this; }

    string Getdenumire() const { return denumire; }
    void Setdenumire(string val) { denumire = val; }

    int Getnr_angajati()  const { return nr_angajati; }
    void Setnr_angajati(int val) { nr_angajati = val; }

    vector<int> Getprofit() const { return profit; }
    void Setprofit(vector<int> val) { profit = val; }
};

Farmacie::Farmacie()
{
    denumire = "Farmacie";
    nr_angajati = 0;
    profit.resize(12); //profitul pe 12 luni initializat cu 0
    fill(profit.begin(), profit.end(), 0);

}

Farmacie::Farmacie(string den, int nra, vector<int> prof)
{
    denumire = den;
    nr_angajati = nra;
    profit = prof;
}

Farmacie::~Farmacie() {}

Farmacie::Farmacie(const Farmacie& other)
{
    denumire = other.denumire;
    nr_angajati = other.nr_angajati;
    profit = other.profit;
}

istream& operator>>(istream& in, Farmacie& other)
{
    string sir;
    int nr;

    cout << "Denumire: ";
    in >> other.denumire;

    cout << "Numar angajati: ";
    in >> sir;

    for (int i = 0; i < sir.length(); i++)
    {
        try
        {
            if (sir[i] < '0' || sir[i]>'9') //ma asigur ca introduc cate o cifra
                throw 1;
        }
        catch (int a)
        {
            cout << "Valoare invalida pentru numarul de angajati.\n";
            return in;
        }
    }
    nr = stoi(sir); //transform din string in int
    other.nr_angajati = nr;

    for (int i = 0; i < other.profit.size(); i++)
    {
        cout << "Profit aferent lunii " << i + 1 << ": ";
        in >> sir;
        for (int i = 0; i < sir.length(); i++)
        {
            try
            {
                if (sir[i] < '0' || sir[i]>'9')
                    throw 1;
            }
            catch (int a)
            {
                cout << "Valoare invalida pentru profit.\n";
                return in;
            }
        }
        nr = stoi(sir);
        other.profit[i] = nr;
    }
    return in;
}

ostream& operator<<(ostream& out, Farmacie& other)
{
    out << "Denumire: ";
    out << other.denumire << endl;

    out << "Numar angajati: ";
    out << other.nr_angajati << endl;

    cout << "Luna: \t\tIan\tFeb\tMar\tApr\tMai\tIun\tIul\tAug\tSep\tOct\tNov\tDec" << endl;
    cout << "Profit: \t";
    for (int i = 0; i < other.profit.size(); i++)
        out << other.profit[i] << "\t";
    cout << endl;

    return out;
}

Farmacie& Farmacie::operator=(const Farmacie& other)
{
    this->denumire = other.denumire;
    this->nr_angajati = other.nr_angajati;
    this->profit = other.profit;
    return *this;
}

//---------------------------------------------------------------------------------------------------

class FarmacieOnline : public Farmacie
{
    string adresa_web;
    int nr_vizitatori;
    double discount;
public:
    FarmacieOnline();
    FarmacieOnline(string, int, double);
    virtual ~FarmacieOnline();
    FarmacieOnline(const FarmacieOnline& other);

    friend istream& operator>>(istream&, FarmacieOnline& other);
    friend ostream& operator<<(ostream&, FarmacieOnline& other);
    FarmacieOnline& operator=(const FarmacieOnline& other);

    void afisare() { cout << *this << endl; }
    void citire() { cin >> *this; }

    string Getadresa_web() const { return adresa_web; }
    void Setadresa_web(string val) { adresa_web = val; }

    int Getnr_vizitatori() const { return nr_vizitatori; }
    void Setnr_vizitatori(int val) { nr_vizitatori = val; }

    double Getdiscount() const { return discount; }
    void Setdiscount(double val) { discount = val; }
};

FarmacieOnline::FarmacieOnline()
{
    adresa_web = "www.myadress.com";
    nr_vizitatori = 0;
    discount = 0;
}

FarmacieOnline::FarmacieOnline(string adr, int nrviz, double disc)
{
    adresa_web = adr;
    nr_vizitatori = nrviz;
    discount = disc;
}

FarmacieOnline::~FarmacieOnline() { }

FarmacieOnline::FarmacieOnline(const FarmacieOnline& other)
{
    adresa_web = other.adresa_web;
    nr_vizitatori = other.nr_vizitatori;
    discount = other.discount;
}

istream& operator>>(istream& in, FarmacieOnline& other)
{
    string sir;
    int nr;

    cout << "Adresa Web: ";
    in >> other.adresa_web;

    cout << "Numar vizitatori: ";
    in >> sir;

    for (int i = 0; i < sir.length(); i++)
    {
        try
        {
            if (sir[i] < '0' || sir[i]>'9')
                throw 1;
        }
        catch (int a)
        {
            cout << sir << endl;
            cout << "Valoare invalida pentru numarul de vizitatori.\n";
            return in;
        }
    }
    nr = stoi(sir);
    other.nr_vizitatori = nr;

    cout << "Discount: ";
    in >> sir;
    for (int i = 0; i < sir.length(); i++)
    {
        try
        {
            if (sir[i] < '0' || sir[i]>'9')
                throw 1;
        }
        catch (int a)
        {
            cout << "Valoare invalida pentru discount.\n";
            return in;
        }
    }
    nr = stoi(sir);
    other.discount = nr;

    return in;
}

ostream& operator<<(ostream& out, FarmacieOnline& other)
{
    out << "Adresa Web: ";
    out << other.adresa_web << endl;

    out << "Numar vizitatori: ";
    out << other.nr_vizitatori << endl;

    out << "Discount: ";
    out << other.discount << "%" << endl;

    return out;
}

FarmacieOnline& FarmacieOnline::operator=(const FarmacieOnline& other)
{
    this->adresa_web = other.adresa_web;
    this->nr_vizitatori = other.nr_vizitatori;
    this->discount = other.discount;
    return *this;
}

//----------------------------------------------------------------------------------------------------

template <class T> class GestionareFarmacii
{
    int index;
    const int id = 12345;
    T** lant;
public:
    GestionareFarmacii()
    {
        index = 0;
        lant = new T * [index];
    }

    GestionareFarmacii(int index_farm, T** lant_farm)
    {
        index = index_farm;

        lant = new T * [index];
        for (int i = 0; i < index; i++)
            lant[i] = lant_farm[i];
    }

    virtual ~GestionareFarmacii()
    {
        delete[] lant;
    }

    GestionareFarmacii(const GestionareFarmacii& other)
    {
        index = other.index;
        lant = other.lant;
    }

    friend istream& operator>>(istream& in, GestionareFarmacii& other)
    {
        int op2;

        cout << "Index: ";
        in >> other.index;

        other.lant = new T * [other.index];
        try
        {
            for (int i = 0; i < other.index; i++)
            {
                cout << "\nSelectati tipul farmaciei: " << i + 1 << "\n";
                cout << "1. Farmacie Fizica\n";
                cout << "2. Farmacie Online\n";
                cout << "Selectati optiunea:";
                cin >> op2;
                try
                {
                    if (op2 < 1 || op2>2)
                        throw 1;
                }
                catch (int a)
                {
                    cout << "Optiune Invalida!\n";
                    return in;
                }

                switch (op2) {
                case 1: {
                    Farmacie* c = new Farmacie;
                    c->citire();
                    other.lant[i] = static_cast<Farmacie*>(c);
                    break;
                }
                case 2: {
                    FarmacieOnline* c = new FarmacieOnline;
                    c->citire();
                    other.lant[i] = dynamic_cast<FarmacieOnline*>(c);
                    break;
                }
                }
            }
        }
        catch (...)
        {
            cout << "S-a gasit o problema...";
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, GestionareFarmacii& other)
    {
        out << "Index: ";
        out << other.index << endl;

        out << "ID: ";
        out << other.id << endl;

        out << "Gestiunea farmaciilor: \n" << endl;
        for (int i = 0; i < other.index; i++)
        {
            out << "Farmacia nr " << i + 1 << endl;
            other.lant[i]->afisare();
        }
        return out;
    }

    GestionareFarmacii& operator=(const GestionareFarmacii& other)
    {
        this->index = other.index;
        this->lant = other.lant;
        return *this;
    }

    GestionareFarmacii& operator+=(T& other)
    {
        T** vect;

        vect = new T * [index + 1];
        for (int i = 0; i < index; i++)
            vect[i] = lant[i];

        vect[index] = &other;
        index++;
        lant = vect;

        return *this;
    }

    int Getindex() const { return index; }
    void Setindex(int val) { index = val; }

    int Getid() const { return id; }
    void Setid(int val) { id = val; }

    T** Getlant() const { return lant; }
    void Setlant(T** val) { lant = val; }

    void afisare() { cout << *this << endl; }
    void citire() { cin >> *this; }
};

//-------------------------------------------------------------------------------------------

template <> class GestionareFarmacii <FarmacieOnline>
{
    int total_vizitatori_online;
    int index;
    const int id = 12345;
    FarmacieOnline** lant;

public:
    GestionareFarmacii()
    {
        total_vizitatori_online = 0;
        index = 0;
        lant = new FarmacieOnline * [index];
    }

    GestionareFarmacii(int index_farm, FarmacieOnline** lant_farm, int total_viz)
    {
        index = index_farm;

        lant = new FarmacieOnline * [index];
        for (int i = 0; i < index; i++)
            lant[i] = lant_farm[i];

        total_vizitatori_online = total_viz;
    }

    virtual ~GestionareFarmacii()
    {
        delete[] lant;
    }

    GestionareFarmacii(const GestionareFarmacii& other)
    {
        total_vizitatori_online = other.total_vizitatori_online;
        index = other.index;
        lant = other.lant;
    }

    friend istream& operator>>(istream& in, GestionareFarmacii& other)
    {
        int op2;
        cout << "Index: ";
        in >> other.index;

        other.lant = new FarmacieOnline * [other.index];

        try
        {
            for (int i = 0; i < other.index; i++)
            {
                other.lant[i] = new FarmacieOnline;
                other.lant[i]->citire();
            }
        }
        catch (...)
        {
            cout << "S-a gasit o problema.";
            return in;
        }
        return in;
    }


    int calculeazaVizitatori()
    {
        total_vizitatori_online = 0;

        for (int i = 0; i < index; i++)
            total_vizitatori_online += lant[i]->Getnr_vizitatori();

        return total_vizitatori_online;
    }


    friend ostream& operator<<(ostream& out, GestionareFarmacii& other)
    {
        //Sa se afiseze doar numarul total de vizitatori ai farmaciilor online.

        int total = other.calculeazaVizitatori();

        out << "\nTotal vizitatori online: " << total << endl;
        return out;
    }

    GestionareFarmacii& operator=(const GestionareFarmacii& other)
    {
        this->index = other.index;
        this->lant = other.lant;
        return *this;
    }

    GestionareFarmacii& operator+=(FarmacieOnline& other)
    {
        FarmacieOnline** vect;

        vect = new FarmacieOnline * [index + 1];
        for (int i = 0; i < index; i++)
            vect[i] = lant[i];

        vect[index] = &other;
        index++;
        lant = vect;

        return *this;
    }

    int Getindex() const { return index; }
    void Setindex(int val) { index = val; }

    FarmacieOnline** Getlant() const { return lant; }
    void Setlant(FarmacieOnline** val) { lant = val; }

    void afisare() { cout << *this << endl; }
    void citire() { cin >> *this; }
};



//-------------------------------------------------------------------------------------------------------------------

void afisare_meniu() {
    std::cout << "MENIU\n";
    std::cout << "1. Citire, memorare, afisare n obiecte\n";
    std::cout << "2. Gestionare Farmacii Clasice si Online\n";
    std::cout << "3. Gestionare Farmacii Online (detalii despre nr de vizitatori online)\n";
    std::cout << "4. Exit\n";
}


int main()
{

    do {
        afisare_meniu();

        int op;
        cin >> op;

        if (op == 1) {


            Farmacie** b;
            int nrob, i, op2;

            cout << "Cate obiecte cititi?\n";
            cin >> nrob;

            try
            {
                if (nrob < 0)
                    throw 1;
            }
            catch (int a)
            {
                cout << "Valoare invalida pentru numarul obiectelor.";
                break;
            }

            b = new Farmacie * [nrob];
            for (int i = 0; i < nrob; i++)
            {
                cout << "\nSelectati tipul farmaciei cu nr: " << i + 1 << "\n";
                cout << "1. Farmacie Clasica\n";
                cout << "2. Farmacie Online\n";
                cout << "Optiunea selectata:";
                cin >> op2;


                try {
                    if (op2 < 1 || op2>2)
                        throw(MyException());
                }
                catch (exception& e) {
                    cout << e.what() << "\n";
                    break;
                }

                switch (op2) {

                case 1: {
                    Farmacie* c = new Farmacie;
                    c->citire();
                    b[i] = static_cast<Farmacie*>(c);
                    break;
                }

                case 2: {
                    FarmacieOnline* c = new FarmacieOnline;
                    c->citire();
                    b[i] = dynamic_cast<FarmacieOnline*>(c);
                    break;
                }

                case 3: {
                    break;

                }
                }
            }
            if (nrob > 0 && (op2 == 1 || op2 == 2)) {


                cout << "\nSe afiseaza:\n";

                for (int i = 0; i < nrob; i++)
                {
                    cout << "Farmacia nr " << i + 1 << endl;
                    b[i]->afisare();
                }
            }
            break;
        }
        //--------------------------------------------------------------------------------

        else if (op == 2) {

            Farmacie a[10];
            GestionareFarmacii <Farmacie> b;
            FarmacieOnline c[10];
            GestionareFarmacii <FarmacieOnline> d;

            int j = 0, k = 0, op3;
            while (1)
            {
                cout << "\nSUBMENIU - optiunea 2:\n";
                cout << "1. Adauga o farmacie Clasica\n";
                cout << "2. Adauga o farmacie Online\n";
                cout << "3. Afiseaza gestiunea farmaciei\n";
                cout << "4. Exit\n";
                cout << "Optiune: "; cin >> op3; cout << endl;


                try {
                    if (op3 < 1 || op3>4)
                        throw(MyException());
                }
                catch (exception& e) {
                    cout << e.what() << "\n";
                    break;
                }


                switch (op3)
                {
                case 1: {
                    a[j].citire();
                    b += a[j];
                    j++;
                    break;
                }
                case 2: {
                    c[k].citire();
                    b += c[k]; d += c[k];
                    k++;
                    break;
                }
                case 3: {
                    b.afisare(); //afisez toata gestiunea farmaciilor
                    d.afisare(); //afisez doar nr de vizitatori online
                    break;
                }
                case 4: {
                    break;
                }
                }
                if (op3 == 4)
                    break;
            }

        }
        //--------------------------------------------------------------------------------------


        else if (op == 3) {

            FarmacieOnline a[100];
            GestionareFarmacii <FarmacieOnline> b;
            int j = 0, op3;
            while (1)
            {
                cout << "\nSUBMENIU - optiunea 3\n";
                cout << "1. Adauga  o farmacie online\n";
                cout << "2. Afiseaza numarul de vizitatori\n";
                cout << "3. Exit\n";
                cout << "Optiune: "; cin >> op3; cout << endl;


                try {
                    if (op3 < 1 || op3>3)
                        throw(MyException());
                }
                catch (exception& e) {
                    cout << e.what() << "\n";
                    break;
                }


                switch (op3)
                {
                case 1: {
                    a[j].citire();
                    b += a[j];
                    j++;
                    break;
                }
                case 2: {
                    b.afisare();
                    break;
                }
                case 3: {
                    break;
                }
                }
                if (op3 == 3)
                    break;
            }

        }
        //-------------------------------------------------------------------------------------

        else if (op == 4) {
            break;
        }
        //-------------------------------------------------------------------------------------

        else {
            cout << "Introduceti o optiune valida dintre cele enumerate.\n\n";
        }

    }

    while (true);

    return 0;
}