#include <stdio.h>


void lomituslajittelu(int alku, int loppu, int taulukko[], int aputaulukko[]){

  if (loppu <= alku) {
      return;     //tänne mennään kun taulukossa on enää yksi arvo
  }

int keskikohta = (alku + loppu) / 2;


lomituslajittelu(alku, keskikohta, taulukko, aputaulukko);     //lajitellaa vasen puoli taulukosta
lomituslajittelu(keskikohta + 1, loppu, taulukko, aputaulukko); //lajitellaan oikea puoli taulukosta



int vasen_osoitin = alku;       // vasen_osoitin näyttää vasemman alitaulukon alkukohdan
int oikea_osoitin = keskikohta + 1;        // oikea_osoitin tekee saman oikealle alitaulukolle
int k;      //k on vain loopin muuttuja


//iteroidaan jokainen arvo alusta loppuun, jotta pääsemme
for (k = alku; k <= loppu; k++) {
    if (vasen_osoitin == keskikohta + 1) {      //jos vasen_osoitin ei enää pääse pidemmälle, asetetaan aputaulukkoon
        aputaulukko[k] = taulukko[oikea_osoitin];
        ++oikea_osoitin;
    } else if (oikea_osoitin == loppu + 1) {        //sama homma oikealle osoittimelle
        aputaulukko[k] = taulukko[vasen_osoitin];
        ++vasen_osoitin;
    } else if (taulukko[vasen_osoitin] < taulukko[oikea_osoitin]) {    //vasen osoitin osoittaa pienempään arvoon
        aputaulukko[k] = taulukko[vasen_osoitin];
        ++vasen_osoitin;
    } else {        //oikea osoitin osoittaa pienempään arvoon
        aputaulukko[k] = taulukko[oikea_osoitin];
        ++oikea_osoitin;
    }
}


for (k = alku; k <= loppu; k++) {      //lopuksi siirretään aputaulukon arvot taulukkoon
    taulukko[k] = aputaulukko[k];
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


int main() {
  int apu[6], i;

  int A[6] = {
    [0] = 3 ,
    [1] = 1 ,
    [2] = 6,
    [3] = 5 ,
    [4] = 2,
    [5] = 4, };


  lomituslajittelu(0, 5, A, apu);

  printf("Lomituslajiteltu taulukko:\n");

  for (i = 0; i < 6; ++i)
     printf("%d\n", A[i]);

  tarkista_jarjestys(A);
  return 0;
}
