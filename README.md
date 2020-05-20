# POO_Project-3

➢ Cerinte comune tuturor temelor:
1. utilizarea sabloanelor 2. utilizarea STL 3. utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const 4. utilizarea conceptelor de RTTI raportat la template-uri 5. tratarea excepțiilor 6. citirea informațiilor complete a n obiecte, memorarea și afișarea acestora;
Cerințe generale aplicate fiecărei teme din acest fișier: - să se identifice și să se implementeze ierarhia de clase; - clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor; - clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate, iar operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă referire la implementarea acestuia în clasa de baza).

➢ Cerinte specifice fiecarei teme: Tema 6 - Farmacie

Se dorește implementarea unei aplicații OOP care sa permita gestionarea activității unor farmacii apartinand proprietarului X. Pentru fiecare farmacie se cunoaște cel puțin denumirea, numărul de angajați și profiturile pe fiecare luna. Farmaciile pot fi și online. În acest caz se cunoaște doar adresa web, numărul de vizitatori și discountul utilizat. Structura de date: vector sau list <tuple<web, nr_vizitatori, discount>> se rețin farmaciile online 

Cerința suplimentară: - Să se adauge toate campurile relevante pentru modelarea acestei probleme. - Să se construiască clasa template GestionareFarmacii care sa conțină informații despre diversele tipuri de farmacii. Clasa conține indexul farmaciei (incrementat automat la adaugarea unei noi file), id-ul lanțului (constant) și o structura de obiecte, alocată dinamic. Sa se supraincarce operatorul += pentru inserarea unei noi farmacii online în structura. - Să se construiască o specializare pentru tipul Farmacie_online care sa conțină și să afișeze doar numărul total de vizitatori ai farmaciilor online.
