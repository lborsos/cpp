#include <iostream>

using namespace std;

int sol[20], n=5, el_maxim=2 ;

int verifica(int poz)
{
    return 1;
}

void afiseaza()
{
    for (int i=0; i<n; i++)
        cout << sol[i] << " ";
    cout << endl;
}


// ---=== ceea ce e important incepe de aici: ===---
void bkt(int poz)   // generez elementul de pe pozitia poz
{
    if (poz==n) afiseaza(); // daca cumva este ultimul element (pozitiile sunt de la 0 la n-1 si cand ajung la n inseamna ca am depasit deja - de la 0 la n-1 au fost deja generate corect)
    else // altfel incerc sa generez elementul de pe pozitia poz
        for(int i=0; i<el_maxim; i++) // parcurg spatiul de valori posibile pentru pozitia poz: de la 0 pana la el_maxim
        {
            sol[poz]=i; // pun in solutie, pe pozitia poz valoarea nou generata
            if(verifica(poz)) // verific daca elementul nou adaugat este ok pe acea pozitie
                bkt(poz+1);   // si daca e ok, trec la urmatoarea pozitie
        }
}

int main()
{
    bkt(0);
    return 0;
}
