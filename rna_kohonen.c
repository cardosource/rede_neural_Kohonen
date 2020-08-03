#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define nentrada 4
#define nneuronio 6

#define nexemplos 10

int main(){
float w[nentrada][nneuronio],errodes,tau,sigma0,sigma,eta,eta0;
int x,y,cont2,contt,epocas,k,l,k1,l1;
float entradas[nentrada][nexemplos],teste[nentrada][6],d[nneuronio],l2,h,deucl;
#

for(x=0; x < nentrada ; x++)
 for(y=0 ; y< nneuronio ; y++)
  w[y][x] = rand()%2 + 0.5;
printf("Numero de epocas de treinamento\n");
scanf("%d",&epocas);
printf("Vetores de exemplos de treinamento de entrada\n");
for (x=0; x < nentrada; x++)
 for(y=0; y < nexemplos; y++)
   scanf("%f ", &entradas[x][y]);
printf("Valores da taxa de aprendizagem inicial\n");
scanf("%f", &eta0);
printf("Erro minimo\n");
scanf("%f",&errodes);
printf("Largura efetiva inicial\n");
scanf("%f",&sigma0);
printf("Constante de tempo {TAU}\n");
scanf("%f",&tau);

system("clear");

printf("Pesos iniciais\n");
for(y=0; y < nentrada; y++){
  for(x=0; x < nneuronio; x++)
    printf("w[%d][%d] = %f \n",x,y,w[x][y]);
    
printf("Iniciando processo iterativo...\n");
for (x=0; x < epocas; x++){
 for(y=0; y < nexemplos; y++){
   for (contt=0; contt < nneuronio; contt++){
     d[contt] = 0;
     for(cont2=0; cont2 < nentrada; cont2)
       d[contt] = d[contt] + (entradas[cont2][y] - w[cont2][contt] ) * (entradas[cont2][y] - w[cont2][contt]);
     }
     //cal menor distancia
     
     deucl = d[0];
     for (contt = 0 ;contt < nneuronio; contt++)
       if (deucl >= d[contt]) deucl = d[contt];
     //teste parada
     if(deucl < errodes) break;
     for(contt=0; contt < nneuronio; contt++)
        if (deucl == d[contt]){
          k = (contt + 1) % 3;
          if( k == 0 ) k = 3;
          l = 1 + contt / 3;
          break;
          }
          
for(contt =0; contt < nneuronio; contt++){
//calc largura efetiva
  sigma = sigma0 * exp(-(x* nexemplos + y)/tau);
  //cal distancia leteral
  l2 = 0 ;
  k1 = (contt + 1 ) % 3;
  if( k1 == 0) k1 = 3;
  l1 = 1 + contt / 3 ;
  l2 = pow((k -k1),2) + pow((l - l1),2);
  //calc vizinhança topologica
  h = exp(-12/(2*sigma*sigma));
  //cal taca de aprendizagem
  eta = eta0*exp(-(x*nexemplos + y ) / tau);
 //calc ajuste oara peso dis arcos do neuronio
 for(cont2 = 0 ; cont2 < nentrada ;cont2++)
   w[cont2] [contt] = w[cont2][contt] + eta * h * (entradas[cont2][y] - w[cont2][contt]);
   }
  }
  
  //teste de parada
  
  if(deucl < errodes){
   printf("Finalizado pelo erro\n");
   break;
   }
   }
  
printf("Finalizado: \n - Pesos Finais");
for(contt = 0; contt < nentrada; contt++)
 for(cont2 = 0 ; cont2 < nneuronio; cont2)
   printf("w[%d][%d] = %f\n",contt,cont2,w[contt][cont2]);
printf("Testes de Entradas e Saidas\n");
for(cont2 = 0 ; cont2 < 5 ;  cont2++)
 for(contt = 0; contt < nentrada; contt++){
  if( cont2  < 3 ) teste[contt][cont2] = rand()%20;
  if(cont2 == 4){
    printf("Digite 1 entrada:");
    scanf("%f",&teste[contt][cont2]);
    }
    }

for(x=0 ;x < 5; x++){
 for(contt=0;contt < nneuronio; contt++){
  d[contt] = 0;
  for( cont2 = 0 ; cont2 < nentrada; cont2++)
    d[contt] = d[contt] + (teste[cont2][x] -w[cont2][contt]) * (teste[cont2][x] - w[cont2][contt]);
    }
    
//cal menor distancia

deucl = 0 ;
for( contt = 0 ; contt < nneuronio; contt++)
 if(deucl >= d[contt]) deucl = d[contt];
   printf("deucl = %f\n",deucl);

for( contt = 0; contt < nneuronio; contt++)
 if(deucl == d[contt]){
  k = (contt + 1 ) % 3;
  if ( k == 0) k = 3;
  l = 1 + contt / 3 ;
  break;
  }
printf("Entrada:\n");
for (y = 0 ; y < nentrada; y++)
 printf("%ft",teste[y][x]);
 printf("Neuronios Ativados: %d ( %d %d)\n",contt + 1,l,k);
 }
 system("clear");

 }
 }
