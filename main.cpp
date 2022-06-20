#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <vector>

#include "estruturas.hpp"
using namespace std; 

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;


int main(){

    string filename("j3048_10.sm");
    string word;
    vector<string> words;
    vector<string> words2;
    vector<string> words3;
    int i=0, temporario=0, auxiliar=0, aux_id=32;
    DadosDasTarefas DadosDasTarefas[MAX_TAREFAS];
    

    ifstream input_file("j3048_10.sm");
    
    if(!input_file.is_open()){
        cerr << "Não foi possivel abrir o arquivo- '" << filename << "'" << endl;
        

    }else{  
        input_file >> word;
        string space_delimiter = " ";
    
        while( !input_file.eof()){
            getline(input_file,word);
            size_t pos = 0;
            
            if(i==8){
               // cout <<"Linha: " << i << word << endl;
                while ((pos = word.find(space_delimiter)) != string::npos) { //Separa a string por ' '
                    words.push_back(word.substr(0, pos));
                    word.erase(0, pos + space_delimiter.length());
                }
               sscanf(words[22].data(), "%d", &QuantidadeDeRecursos); //converte string para inteiro
                
                cout << QuantidadeDeRecursos <<endl;
                
            }

            if(i==14){
               //cout <<"Linha: " << i << word << endl;
                pos = 0;
                while ((pos = word.find(space_delimiter)) != string::npos) { //Separa a string por ' '
                    words2.push_back(word.substr(0, pos));
                    word.erase(0, pos + space_delimiter.length());
                }
               sscanf(words2[8].data(), "%d", &QuantidadeDeTarefas);
               if(QuantidadeDeTarefas==0){
                   sscanf(words2[9].data(), "%d", &QuantidadeDeTarefas);
               } //converte string para inteiro
                cout << QuantidadeDeTarefas <<endl;
                
            }

           
            if(i>=18){
                
                if(i<=(18+(QuantidadeDeTarefas+1))){

                    pos = 0;
                    while ((pos = word.find(space_delimiter)) != string::npos) { //Separa a string por ' '
                       words3.push_back(word.substr(0, pos));
                        word.erase(0, pos + space_delimiter.length());
                    }
                   
                   if(i<=26){
                        sscanf(words3[3].data(), "%d", &(DadosDasTarefas[temporario].Id)); //converte string para inteiro
                        sscanf(words3[21].data(), "%d", &(DadosDasTarefas[temporario].QuantidadeDeSucessores));
                        
                        
                        sscanf(words3[32].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[0]));//Armazena o id dos sucessores
                           
                        if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[0]==0)){
                            sscanf(words3[31].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[0]));
                        }

                        sscanf(words3[35].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[1]));//Armazena o id dos sucessores
                           
                        if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[1]==0)){
                            sscanf(words3[34].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[1]));
                            if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[1]==0)){
                                sscanf(words3[33].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[1]));
                            }
                        } 

                        sscanf(words3[36].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[2]));//Armazena o id dos sucessores
                           
                        /*if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[2]==0)){
                            sscanf(words3[35].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[2]));
                            if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[2]==0)){
                                sscanf(words3[36].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[2]));
                            }
                        }    */                  
                           
                            
                        
                        
                   }else if(i<=116){
                       sscanf(words3[2].data(), "%d", &(DadosDasTarefas[temporario].Id)); //converte string para inteiro
                       sscanf(words3[20].data(), "%d", &(DadosDasTarefas[temporario].QuantidadeDeSucessores));

                       sscanf(words3[30].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[auxiliar]));//Armazena o id dos sucessores
                           
                        if((DadosDasTarefas[temporario].QuantidadeDeSucessores!=0) && (DadosDasTarefas[temporario].IdSucessores[auxiliar]==0)){
                            sscanf(words3[31].data(), "%d", &(DadosDasTarefas[temporario].IdSucessores[auxiliar]));
                        }
                   }else{
                       sscanf(words3[1].data(), "%d", &(DadosDasTarefas[temporario].Id)); //converte string para inteiro
                       sscanf(words3[19].data(), "%d", &(DadosDasTarefas[temporario].QuantidadeDeSucessores));
                   }
                     
                    cout << DadosDasTarefas[temporario].Id << " " << DadosDasTarefas[temporario].QuantidadeDeSucessores << " " 
                    << DadosDasTarefas[temporario].IdSucessores[0] << " " <<  DadosDasTarefas[temporario].IdSucessores[1] << " " << DadosDasTarefas[temporario].IdSucessores[2] <<endl;
                    
                    temporario++;
                }                                
                    
                
            }
            
            words3.clear();
            
            
            i++; 

        }
            
        input_file.close();

        
    }






    return 0;

}


