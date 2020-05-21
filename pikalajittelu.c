#include <stdio.h>


void vaihda_paikkaa(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int jaetaan (int taulukko[], int alku, int loppu)
{
    int pivot = taulukko[loppu];    // pivot
    int i = (alku - 1);  // Index of smaller element

    for (int j = alku; j <= loppu- 1; j++)
    {
        // If current element is smaller than the pivot
        if (taulukko[j] < pivot)
        {
            i++;    // increment index of smaller element
            vaihda_paikkaa(&taulukko[i], &taulukko[j]);
        }
    }
    vaihda_paikkaa(&taulukko[i + 1], &taulukko[loppu]);
    return (i + 1);

}

void pikalajittelu(int taulukko[], int alku, int loppu)
{
    if (alku < loppu)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = jaetaan(taulukko, alku, loppu);

        // Separately sort elements before
        // partition and after partition
        pikalajittelu(taulukko, alku, pi - 1);
        pikalajittelu(taulukko, pi + 1, loppu);
    }
}

void tarkista_jarjestys(int taulukko[]){
  int j;

  size_t n = sizeof(taulukko)/sizeof(taulukko[0]);

  for (j = 0; j <  n; ++j ){

    if (taulukko[j] < taulukko[j+1]){
      printf("Lajittelu onnistui!\n");
    }
    else{
      printf("Lajittelu ei onnistunut.\n");

    }

  }
}



int main()
{

      int A[] = {10, 7, 8, 9, 1, 5};
      int n = 6;
      pikalajittelu(A, 0, 5);



    printf("Pikalajiteltu taulukko:\n");

    for ( int i = 0; i < 6; ++i){
       printf("%d\n", A[i]);
     }

    tarkista_jarjestys(A);


    return 0;

}
